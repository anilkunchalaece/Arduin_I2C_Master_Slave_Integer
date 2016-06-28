/*
   Author : Kunchala Anil
   Purpose : This is a Master Code for Simple Master Slave Commuinucation between Two
   Arduinos Commincating Via I2C Protocol Using Wire Library
   The Master Requests Data from The Slava And Slave Responds With the Data of Specfied Length
   Contact me Via : anilkunchalaece@gmail.com
*/

#include<Wire.h> //include the wire library
const byte len = 10; //Fixed length of received Variable (This is the default Value we can these if The Recieved value is more than this)
char valR[len]; // Variable to Store the Received String
char valF[len]; // Variable to Store the Processed String
byte valF_Index = 0; //Index for VaF

void setup() {
  Wire.begin();// Start the Initialize the I2C Communcation. Address is Optional for Master
  Serial.begin(9600); //Start the Seril Communcation to check the received byte
}

void loop() {
  /*
     please refer to the Nick Gammon Site for Request and Response : Reply 4
     Site address : http://www.gammon.com.au/i2c
     Wire.requestFrom does not return until the data is available (or if it fails to become available). Thus it is not necessary to do a loop waiting for Wire.available after doing Wire.requestFrom.

    For example:


    Wire.requestFrom (SLAVE_ADDRESS, responseSize);
    while (Wire.available () < responseSize) { }  // <---- not necessary

    Therefore the only reasonable way of doing the Wire.requestFrom is:


    if (Wire.requestFrom (SLAVE_ADDRESS, responseSize) == 0)
      {
      // handle error - no response
      }
    else
      {
      // data received, now use Wire.read to obtain it.
      }

  */

  if (Wire.requestFrom(8, 10)) 
  {
        for (int i = 0; i < len; i++)
            {
                valR[i] = Wire.read(); // Read the 10 Bytes from Slave
            }
  } else {
            Serial.println("Something is Wrong.. Please Check");
          }
/*
 * Process the received data
 * the length Of the Data we Received Changes According to the Our Sensor value 
 * Potentiometer Changed from 0-1023. We take maximum length of String as 10 bytes
 * So Extra Bytes Come as ASCII value 255(Google It) So we Need to Discard those Extra bytes
 */
  for (int j = 0; j < len; j++)
  {

    if ((char)valR[j] != (char)255) 
            {
              valF[valF_Index] = valR[j];
              valF_Index++;
            }

  }
  valF[valF_Index] = '\0';
  Serial.println(valF);
  //After Printing Reinitialize the ValF_Index
  valF_Index = 0;
  delay(1000);
}

