#include "HX711.h"

#include <LiquidCrystal.h>
#define DOUT  8
#define CLK  9
HX711 scale;
float calibration_factor = 2230;
float units;  

void setup()
{
  Serial.begin(9600);
  scale.begin(DOUT, CLK);
  Serial.println("Press T to tare");
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  scale.tare();
} 
 void loop()
{ 
  units = scale.get_units(), 5;
  Serial.print("Weight: ");
  Serial.print(units,4); //displays the weight in 4 decimal places only for calibration
  Serial.println("grams");
  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == 't' || temp == 'T')
      scale.tare();  //Reset the scale to zero      
 }
}
