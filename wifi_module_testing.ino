#include "Enes100.h"
void setup() {
  // put your setup code here, to run once:
  Enes100.begin("magic_mike", MATERIAL, 11, 9, 8);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  if (Enes100.updateLocation()) {
    Enes100.print("Our y location: ");
    Enes100.println(Enes100.location.y);
    Enes100.print("Our x location: ");
    Enes100.println(Enes100.location.x);
    Enes100.print("Our theta: ");
    Enes100.println(Enes100.location.theta);
  }
}
