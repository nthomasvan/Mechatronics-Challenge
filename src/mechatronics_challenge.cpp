// This #include statement was automatically added by the Particle IDE.
#include "lib1.h"

#include "application.h"

#include "Particle.h"
// This #include statement was automatically added by the Particle IDE.
#include <LIS3DH.h>

// This #include statement was automatically added by the Particle IDE.
#include <carloop.h>





void printValuesAtInterval();
void printValues();
void printFloat(float val, bool valid, int len, int prec);
void printDateTime(TinyGPSDate &d, TinyGPSTime &t);

SYSTEM_THREAD(ENABLED);

// This sample only uses serial, not data, so cellular is turned off to save data
SYSTEM_MODE(MANUAL);



// LIS3DH is connected as in the AssetTracker, to the primary SPI with A2 as the CS (SS) pin, and INT connected to WKP
LIS3DHSPI accel(SPI, A2, WKP);



Carloop<CarloopRevision2> carloop;


void setup() {
    Serial.begin(9600);
    carloop.begin();
    
    delay(5000);

	// Initialize Accelerometer Sensor
	LIS3DHConfig config;
	config.setAccelMode(LIS3DH::RATE_100_HZ);

	bool setupSuccess = accel.setup(config);
	Serial.printlnf("setupSuccess=%d", setupSuccess);
}

void loop() {
    carloop.update();
    printValuesAtInterval();
}

void printValuesAtInterval() {
    static const unsigned long interval = 1000;

    static unsigned long lastDisplay = 0;
    if(millis() - lastDisplay < 1000)
    {
        return;
    }
    lastDisplay = millis();
    printGPSValues();
    printAccelData();
}

void printGPSValues() //Method for capturing GPS data
{
    auto &gps = carloop.gps();
    // Ensure that the GPS state doesn't change while printing
    WITH_LOCK(gps) {
        Serial.print("GPS ");
        printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);
        printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);
        printDateTime(gps.date, gps.time);
        Serial.printf("%6d chars, %d checksum error", gps.charsProcessed(), gps.failedChecksum());
        Serial.println("");
    }
}

void printFloat(float val, bool valid, int len, int prec) //Method to log GPS data and Check for valid GPS location
{
    if(!valid) 
    {
        while(len-- > 1)
        {
            Serial.print('*');
        }
        Serial.print(' ');
    }
    else
    {
        char format[10];
        snprintf(format, sizeof(format), "%%%d.%df", len, prec);
        Serial.printf(format, val);
    }
}

void printDateTime(TinyGPSDate &d, TinyGPSTime &t)
{
    if (!d.isValid())
    {
        Serial.print("********** ");
    }
    else
    {
        Serial.printf("%02d/%02d/%02d ", d.month(), d.day(), d.year());
    }

    if (!t.isValid())
    {
        Serial.print("******** ");
    }
    else
    {
        Serial.printf("%02d:%02d:%02d ", t.hour(), t.minute(), t.second());
    }
}

void printAccelData(){
    
    Serial.print("Accelerometer Data:");
		LIS3DHSample sample;
		if (accel.getSample(sample)) {
			Serial.printlnf("\n %d,%d,%d", sample.x, sample.y, sample.z);
		}
		else {
			Serial.println("\n no sample");
		}
}
