/*********************************************************************
** Program Filename: mini_shrec_bot.ino
** Author: Evan Garrison
** Date: 05/28/2021
** Description: main driver file for 'lil SHREC car.
*********************************************************************/

#include "drive_train.h" //includes custom-made DriveTrain class

int //pins used for motor controller
leftA = 9,
leftB = 10,
rightA = 11,
rightB = 12;

DriveTrain::Direction d = (DriveTrain::Direction) 0;

/**
 * Drivetrain declaration and definition.
 * Creates a new instance of DriveTrain called drive,
 * with pins leftA, leftB, rightA, rightB
 */
DriveTrain drive(leftA, leftB, rightA, rightB);


void setup()
{
    //Serial.begin(9600);
}

/**
 * To use the drivetrain created above, use the following format in loop():
 * to set a direction: drive.setDirection(left, right);
 * Where left and right are replaced with DriveTrain::FORWARD,
 * DriveTrain::REVERSE, or DriveTrain::NEUTRAL
 * Notice you have to preface the direction with DriveTrain::
 * This is because the custom type used for directions is declared and defined
 * in the DriveTrain class.
 */

void loop()
{
    //sets motors to forward for 2 seconds
	drive.setDirections(DriveTrain::FORWARD, DriveTrain::FORWARD);
    delay(2000);

    //sets motors to forward and reverse for 2 seconds, should make bot turn
    drive.setDirections(DriveTrain::FORWARD, DriveTrain::REVERSE);
    delay(2000);

    //sets motors to reverse for 2 seconds
    drive.setDirections(DriveTrain::REVERSE, DriveTrain::REVERSE);
    delay(2000);

    //stops motors for 2 seconds
    drive.setDirections(DriveTrain::NEUTRAL, DriveTrain::NEUTRAL);
    delay(2000);
}