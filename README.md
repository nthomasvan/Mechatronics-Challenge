# Mechatronics Challenge

## Electrical

The wiring schematic of the challenge was drawn using the Fritzing program. The breadboard and schematic views of the wiring can be found below (Refer to Figure 1 and 2).

![Breadboard View](electrical/Schematic/Mechatronics-Challenge_bb.jpg)
<p align ="center"><b>Figure 1 </b> - Wiring Breadboard View </p>

![Schematic View](electrical/Schematic/Mechatronics-Challenge_schem.jpg)
<p align ="center"><b>Figure 2 </b> - Wiring Schematic View</p>

<b>GPS Connections</b>

The pin connections for the GPS module can be found in the table below (Refer to Table 1). The TX (serial transmit) pin of the Carloop GPS Photon Shield sends out the GPS data, which is then read by the RX (receive) pin of the microcontroller. The RX pin of the shield module is connected to the TX pin of the microcontroller for GPS module configurations.  Lastly, based on the datasheet for the SAM-M8Q GPS module, the power supply voltage is 3.0V, which is supplied from the 3V3 pin of the Particle Photon microcontroller to the Vin pin of the shield. 

![GPS Table](electrical/GPS_PinConnect.JPG)
<p align ="center"><b>Table 1 </b> - GPS Pin Connections</p>

<b>Accelerometer Connections</b>

The pin connections for the accelerometer sensor can be found in the table below (Refer to Table 2). The LIS3DH library and datasheet heavily influenced many of the pin choices.  The accelerometer sensor, like the GPS module, uses a 3.0V power supply, thus utilizes the same Vin to 3V3 pin connection between the Carloop GPS Photon Shield and Particle Photon microcontroller, respectively.  The SPI interface was utilized in this pin set up. The ACCEL_CS (chip select) pin of the shield is connected to the A2 pin of the Particle Photon in order to set it to LOW state for the SPI interface. By default, the pin is set to HIGH, which is the I2C interface set up. The SPI MOSI (Master Out Slave In) pin is connected to the A5 pin in order to allow data to be sent from the microcontroller to the sensor. The SPI MISO (Master In Slave Out) pin sends data from the sensor to the processor through the A4 pin. Lastly, The SPI CLK pin is connected to the A3 pin of the microcontroller

![Accelerometer Table](electrical/Accel_PinConnect.JPG)
<p align ="center"><b>Table 2 </b> - GPS Pin Connections</p>


## Coding

For the code portion of this challenge, the LIS3DH and Carloop libraries were utilized in order to gather the necessary data. The code is split up in three sections:  setup, loop, and methods. In the setup section, the sensors and libraries are initialized and the data rate is set for the serial data transmission. In the loop section, the methods that were written to log the data are being called on. The methods section contains multiple functions to gather data and to print them out in a legible fashion. The methods also check for valid data and logs whether or not the data is truly valid or missing on the console. The code examples from both the LIS3DH and Carloop libraries were used as templates. Refer to [Code](src/mechatronics_challenge.cpp).

LIS3DH Accelerometer library: https://github.com/rickkas7/LIS3DH

Carloop Library: https://github.com/carloop/carloop-library

## Mechanical

All drawings for the enclosure can be found [here](https://github.com/nthomasvan/Mechatronics-Challenge/tree/Mechatronics-Challenge/mechanical/Engineering_Drawings). The overall design was centered around the Carloop adapter with the Particle Photon and Carloop GPS module connected. There are two openings in the enclosure for the OBD-II connector and the USB Micro B connector. The opening for the USB connector allows for easy access for typical operations such as code changes, debugging, etc. Likewise, the opening for the OBD-II connector is meant for the direct connection between the module to a system such as test benches, vehicles, etc . The enclosure itself was also designed to be a snug fit to minimize the shifting of the components within the box. Lastly, the top cover is fastened onto the base enclosure using four allen bolts for quick entry in the event that any of the modules will need to be replaced. 

For future design improvements, the enclosure could be modified with fasteners/snap-hook fixtures within the box to secure the components directly to the container to prevent any movements even further. In addition, progressing to a snap-fit assembly design would reduce the amount of loose parts and increase the speed of accessibility to the components.


![Assembly_GIF](mechanical/Assembly_Explode.gif)

