/*********************************************************************
** Program Filename: drive_train.h
** Author: Evan Garrison
** Date: 05/28/2021
** Description: header file for DriveTrain Class, a class used to control
** motor controllers in arduino, specifically for a Drive Train
** Input: Channels for motor controllers, directions for the drivetrain, and speeds
** Output: Directions and speeds
*********************************************************************/

/**
 * This little bit probably looks a bit strange to ya. This is called a header guard, its
 * purpose to prevent you from including the file twice in your program. It checks if 
 * DRIVE_TRAIN_H is already defined, and if it isn't, then it defines DRIVE_TRAIN_H and runs
 * the rest of the file. If not, everything in this file is ignored. If you create your own class,
 * you'll probably want to use one of these. Also note that at the end of this file there's an extra
 * line-'#endif' This is the end of the header guard, if you make your own class and use a header guard, 
 * make sure to include that part!
 */
#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

//Includes standard library of arduino functions and classes (digitalWrite, pinMode, etc.)
#include "Arduino.h"

/**
 * This is the DriveTrain class declaration. Within it are all the fields and member functions of the
 * class. You'll notice its divided into two sections - public and private. all the items listed under
 * the public tag are available outside the class to any program that includes this class. The items in 
 * the private section are only available within the class-both the header file and implementation file.
 */
class DriveTrain {
    public:
        /**
         * This is a custom type that I created for the three directions that I saw that motors could be 
         * set to - forward, reverse, or stop. You can create a variable of the type direction by using
         * Direction as the type name, for example: Direction d = FORWARD;
         * Another interesting thing to note as that each value defined in direction also maps to an integer value:
         * They map to 0, 1, and 2 respectively. So you could also call Direction d = (Direction) 0; You have to add
         * Direction in paranthesis' in order to do that, it basically just lets the compiler know that you know
         * what you're doing. Its called typecasting. In order to use the Direction type outside this class, you'll have
         * to use a namespace, like this:
         * DriveTrain::Direction d = Drivetrain::FORWARD; *or* DriveTrain::Direction d = (Drivetrain::Direction) 0;
         */
        enum Direction {
            FORWARD,
            REVERSE,
            NEUTRAL
        };

        /**
         * This section has Constructors and functions. I'll put some brief descriptions of each here, but more detailed
         * descriptions will be in the implementation file; drive_train.cpp
         */
        DriveTrain(int leftChannel1, int leftChannel2, int rightChannel1, int rightChannel2); //Constructor w/o speed channels
        DriveTrain(int leftChannel1, int leftChannel2, int leftChannelS, int rightChannel1, int rightChannel2, int rightChannelS); //Constructor w/speed channels

        void setSpeeds(int leftS, int rightS); //function to set speeds of motors
        void getSpeeds(int &left, int &right); //function to retrieve speeds from motors
        void setDirections(Direction leftD, Direction rightD); //sets direction of motors
        void getDirections(Direction &left, Direction &right); //retrieves direction of motors
    private:
        int 
        left1, left2, leftSChannel, //Channels for left side motors
        leftSpeed, //speed, 0-255 of left motors
        right1, right2, rightSChannel, //Channels for right side motors
        rightSpeed; //speed, 0-255 of right motors
        Direction left, right; //Directions for left and right motors

        void setChannels(int leftChannel1, int leftChannel2, int rightChannel1, int rightChannel2); //set pins for motor controller channels
        void setChannels(int leftChannel1, int leftChannel2, int leftChannelS, int rightChannel1, int rightChannel2, int rightChannelS); //overloaded setChannels function, sets pins for motor controller channels including speed pins
};

//end of header guard
#endif