/*
 * An example that uses the partial update function of the Adafruit eInk display.
 * Copyright 2021, Digame Systems. All rights reserved.
 * 
 * NOTE: Be sure to update your SPI bus pinouts in digameDisplay.h
 */

#include "digameDisplay.h"

#include <Wire.h>

//****************************************************************************************
// Device initialization                                   
//****************************************************************************************
void setup()
{
    String compileDate = F(__DATE__);
    String compileTime = F(__TIME__);
       
    Serial.begin(115200);   // Intialize terminal serial port
    delay(1000);

    Wire.begin();
   
    Serial.println("*****************************************************");
    Serial.println("Adafruit Partial Update Example");
    Serial.println("  Using the GxEPD2.h Library by Jean-Marc Zingg.");
    Serial.println("  https://github.com/ZinggJM/GxEPD2");
    Serial.println("Copyright 2021, Digame Systems. All rights reserved.");
    Serial.println();
    Serial.print("Compiled on ");
    Serial.print(compileDate);
    Serial.print(" at ");
    Serial.println(compileTime); 
    Serial.println("*****************************************************");
    Serial.println();
    Serial.println("RUNNING!");  
    Serial.println(); 

    display.init(0);
    displaySplashScreen();
    delay(5000);
    displayCountScreen(0);
    showValue(0);

}

//************************************************************************
// Main Loop
//************************************************************************

double count = 0;
long int t1, t2;

void loop()
{ 
   t1=millis();
   count++;
   showValue(count);
   t2=millis();
   Serial.print("Update Time: ");
   Serial.println(t2-t1);
}
