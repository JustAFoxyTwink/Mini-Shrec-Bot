#include "drive_train.h"

int
leftA = 9,
leftB = 10,
rightA = 11,
rightB = 12;

DriveTrain drive(9, 10, 11, 12);


void setup()
{
    Serial.begin(9600);
}

void loop()
{
	drive.setDirections(DriveTrain::FORWARD, DriveTrain::FORWARD);
    delay(2000);

    drive.setDirections(DriveTrain::FORWARD, DriveTrain::REVERSE);
    delay(2000);

    drive.setDirections(DriveTrain::REVERSE, DriveTrain::REVERSE);
    delay(2000);

    drive.setDirections(DriveTrain::NEUTRAL, DriveTrain::NEUTRAL);
    delay(2000);
}
