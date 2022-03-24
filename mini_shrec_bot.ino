/**
 * @file mini_shrec_bot.ino
 * @author Evan Garrison (garrisev@oregonstate.edu)
 * @brief main driver file for my SHREC arduino robot
 * @version 0.1
 * @date 2021-05-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "drive_train.h" //includes custom-made DriveTrain class

int //pins used for motor controller
leftA = 9,
leftB = 10,
rightA = 11,
rightB = 12,

leftS = 5,
rightS = 6;

bool do_drive = false;
bool do_drive_debounce = false;

/**
 * Drivetrain declaration and definition.
 * Creates a new instance of DriveTrain called drive,
 * with pins leftA, leftB, rightA, rightB
 */
DriveTrain drive(leftA, leftB, leftS, rightA, rightB, rightS);


void setup()
{
    Serial.begin(9600);

    pinMode(2, INPUT_PULLUP);
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
    if (digitalRead(2)) {
        do_drive_debounce = true;
    }
    else if (do_drive_debounce) {
        do_drive_debounce = false;
        do_drive = !do_drive;
    }
    if (do_drive) {
        drive.set(150, 150);
        delay(2000);
        drive.set(75, -75);
        delay(1000);
        drive.set(0, 0);
        delay(5000);
    }

    Serial.println("Pin 2: " + digitalRead(2));
    Serial.println("do_drive: " + do_drive);
    Serial.println("do_drive_debounce: " + do_drive_debounce);
}