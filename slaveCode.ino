/*
   Author : Kunchala Anil
   Purpose : This is a Slave Code for Simple Master Slave Commuinucation between Two
   Arduinos Commincating Via I2C Protocol Using Wire Library
   The Master Requests Data from The Slava And Slave Responds With the Data of Specfied Length
   Contact me Via : anilkunchalaece@gmail.com
*/

#include<Wire.h> //Include the Wire Library

void setup() {
  // put your setup code here, to run once:
Wire.begin(8); // Initialize the I2C Communcation with Address as 8
Wire.onRequest(receiveHandler); //Make an ISR to Process Requests from Master
}

void loop() {
  // put your main code here, to run repeatedly:

}

void receiveHandler(){
int val = analogRead(A0); // Read the analog Input Value from Potentiometer Connected to the String
//int len; 
//if(val<10){
//  len = 1;
//}else if(val < 100){
//  len = 2;
//}else if(val < 1000){
//  len = 3;
//}
/*
 * http://www.cplusplus.com/reference/cstdlib/itoa/
 * itoa Function
 * char *  itoa ( int value, char * str, int base );
Convert integer to string (non-standard function)
Converts an integer value to a null-terminated string using the specified base and stores the result in the array given by str parameter.

Parameters
value
Value to be converted to a string.
str
Array in memory where to store the resulting null-terminated string.
base
Numerical base used to represent the value as a string, between 2 and 36, where 10 means decimal base, 16 hexadecimal, 8 octal, and 2 binary.

Return Value
A pointer to the resulting null-terminated string, same as parameter str.

 */

char valC[10]; // Define the Variable to store the Sesor Data
itoa(val,valC,10); // Convert the Int into String
Wire.write(valC); // Send the Value to Master
}

