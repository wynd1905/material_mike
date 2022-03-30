/*
    Things to do:
    - Need to know what is the value type and unit of the angle theta
    - Need to know the units for x and y coordinates
    - Find out the ID number of the Aruco marker
    - If the speed for the analog pin is not effective, might need to swich to pwm pins
*/
#inlucde "Enes100.h"
#include <Math.h>

const double ARENA_LENGTH = 2056;
const double OTV_LENGTH = 3;
int leftMotorPin1 = A1;
int leftMotorPin2 = A2;
int rightMotorPin1 = A3;
int rightMotorPin2 = A4;

void setup(){
    Enes100.begin("Material_Mike", MATERIAL, 11, 8, 9);
    pinMode(leftMotorPin1, OUTPUT);
    pinMode(leftMotorPin2, OUTPUT);
    pinMode(rightMotorPin1, OUTPUT);
    pinMode(rightMotorPin2, OUTPUT);
    // Everything stop in the beginning
    digitalWrite(leftMotorPin1, LOW);
	  digitalWrite(leftMotorPin2, LOW);
	  digitalWrite(rightMotorPin1, LOW);
	  digitalWrite(rightMotorPin2, LOW);
}

void loop(){
    double x, y, theta = 0;
    bool isRunning = true; // Internal stopping mechanism if we want the program to stop
    if (Enes100.updateLocation()) {
        x = Enes100.location.x;
        y = Enes100.location.y;
        theta = Enes100.location.theta;
    }

    // MS5 Specific
    if (x < ARENA_LENGTH - OTV_LENGTH){
        goForward();
    } else {
        stopMoving();
    }
    delay(1000);
    turnLeft(theta);
    delay(1000);
    theta = Enes100.location.theta;
    turnRight(theta);
    delay(1000);
    theta = Enes100.location.theta;
    turnRight(theta);
    delay(1000);
    isRunning = false; // stop after one trial run for MS5
}

void goForward(){
    digitalWrite(leftMotorPin1, HIGH);
	  digitalWrite(leftMotorPin2, LOW);
	  digitalWrite(rightMotorPin1, HIGH);
	  digitalWrite(rightMotorPin2, LOW);
}

void goBackward(){
    digitalWrite(leftMotorPin1, LOW);
	  digitalWrite(leftMotorPin2, HIGH);
	  digitalWrite(rightMotorPin1, LOW);
	  digitalWrite(rightMotorPin2, HIGH);
}

void stopMoving(){
    digitalWrite(leftMotorPin1, LOW);
	  digitalWrite(leftMotorPin2, LOW);
	  digitalWrite(rightMotorPin1, LOW);
	  digitalWrite(rightMotorPin2, LOW);
}

void turnLeft(double angleValue){
    while (abs(angleValue - Enes100.location.theta) < 3.14/2){
        digitalWrite(leftMotorPin1, LOW);
	      digitalWrite(leftMotorPin2, LOW);
	      digitalWrite(rightMotorPin1, HIGH);
	      digitalWrite(rightMotorPin2, LOW);
        delay(1000);
    }
}

void turnRight(double angleValue){
    while (abs(angleValue - Enes100.location.theta)) < 3.14/2) {
        digitalWrite(leftMotorPin1, HIGH);
	      digitalWrite(leftMotorPin2, LOW);
	      digitalWrite(rightMotorPin1, LOW);
	      digitalWrite(rightMotorPin2, LOW);
        delay(1000);
    }
}
