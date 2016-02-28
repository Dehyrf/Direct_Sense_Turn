//By Dehyrf, based on code from helscream, distributed under GNU GPL v3 


#include <Wire.h>
#include "compass.h"

#define Task_t 10          // Task Time in milli seconds

int dt=0;
unsigned long t;
// Main code -----------------------------------------------------------------
void setup(){


  pinMode(13, OUTPUT);
  
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(115200);
  // Serial.print("Setting up I2C ........\n");
  Wire.begin();
  compass_x_offset = 122.17;
  compass_y_offset = 230.08;
  compass_z_offset = 389.85;
  compass_x_gainError = 1.12;
  compass_y_gainError = 1.13;
  compass_z_gainError = 1.03;
  
  
  
  compass_init(2);
  compass_debug = 1;
  compass_offset_calibration(3);

  digitalWrite(13, HIGH);
}

// Main loop 
// Main loop -----------------------------------------------------------------
void loop(){
  
  t = millis();
 
  float load;
 
  
  digitalWrite(13,HIGH);
  
  compass_scaled_reading();
  
  Serial.print("x = ");
  Serial.println(compass_x_scaled);
  Serial.print("y = ");
  Serial.println(compass_y_scaled);
  Serial.print("z = ");
  Serial.println(compass_z_scaled);
  

  compass_heading();
  Serial.print ("bearing angle = ");
  Serial.print ((int)bearing);
  Serial.println(" Degrees");



if((bearing >= 0 && bearing <= 45) || (bearing > 315 && bearing <= 360))
{
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
}
if(bearing > 45 && bearing <= 135)
{
  digitalWrite(9, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}
if(bearing > 135 && bearing <= 225)
{
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
}
if(bearing > 225 && bearing <= 315)
{
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(12, LOW);
}

/*else
{
  digitalWrite(6, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(3, LOW);
}
*/

 /* dt = millis()-t;
  load = (float)dt/(Task_t/100);
  Serial.print ("Load on processor = ");
  Serial.print(load);
  Serial.println("%");
*/
  
  delay(66);
}

