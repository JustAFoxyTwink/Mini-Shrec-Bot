/**
 * @file drive_train.cpp
 * @author Evan Garrison
 * @brief implementation file for DriveTrain class
 * @version 0.1
 * @date 2021-05-29
 * 
 * @copyright Copyright (c) 2021
 * 
 * @details 
 * Contains all the Constructor and function definitions/implementations for the DriveTrain class.
 * In general, when we create classes, its standard procedure to split them into two files - the
 * header file and the implementation file. This is the implementation file, where we take all the functions
 * declared in the header file, and actually write out all the code for each.
 */

//includes the header file, that contains all the declarations
#include "drive_train.h"

/**
 * @brief Construct a new Drive Train:: Drive Train object
 * 
 * @param leftChannel1 1st Channel for left motor
 * @param leftChannel2 2nd Channel for left motor
 * @param rightChannel1 1st Channel for right motor
 * @param rightChannel2 2nd Channel for right motor
 * 
 * @details
 * What is this?
 * This is a constructor. It's essentially a special function thats run whenever a DriveTrain is created.
 * So, in the driver file-mini_shrec_bot.ino in my program, this Constructor is run on line 25 - DriveTrain drive(leftA, leftB, rightA, rightB);
 * This is where you put code needed to initialize a new DriveTrain, like setting pinModes, and setting speeds.
 * 
 * Whats with 'this->'?
 * 'this' is a pointer (a variable that points to an object) that every class has. It points to the class itself. You can access functions and/or variables
 * in the class a pointer points to using the operator '->'. Technically I don't actually have to use the 'this' pointer in most of the cases that I do-in implementation
 * files you automatically have access to both the public and private members of the class without having to use 'this'. The reason I use it throughout
 * this file is for clarification - since each of these functions/constructors has parameters that are very similar to the names of variables
 * within the class declaration, 'this' gives me an easy way to make it clear which variables I'm refering to-the variables local to that function, or the variables used
 * throughout the class. If i were to use 'this->left1 = 1;' it would be the same as doing this: 'left1 = 1;' As I said before, I'm just using it for clarification.
 */
DriveTrain::DriveTrain(int leftChannel1, int leftChannel2, int rightChannel1, int rightChannel2) {
    setChannels(leftChannel1, leftChannel2, rightChannel1, rightChannel2); //sets channels for DriveTrain

    //set the pinModes for each channel
    pinMode(this->left1, OUTPUT);
    pinMode(this->left2, OUTPUT);
    pinMode(this->right1, OUTPUT);
    pinMode(this->right2, OUTPUT);

    //we know that this function will throw an exception (more on that later in the file), so this try catch block will handle that.
    try {
        setSpeeds(255, 255); //set the initial speeds
    }
    catch (String s) {
        Serial.println(s); //prints an error message out to the serial monitor
    }
    setDirections(NEUTRAL, NEUTRAL); //Make sure the motors are stopped when a Drive Train is created
}

/**
 * @brief Construct a new Drive Train:: Drive Train object
 * 
 * @param leftChannel1 1st channel for left motor
 * @param leftChannel2 2nd channel for left motor
 * @param leftChannelS speed control channel for left motor - THIS MUST BE A PIN WITH PWM
 * @param rightChannel1 1st channel for right motor
 * @param rightChannel2 2nd channel for right motor
 * @param rightChannelS speed control channel for right motor - THIS MUST BE A PIN WITH PWM
 * 
 * @details
 * Wait, didn't we already write one of these?
 * Why yes, we did. This is an overloaded constructor-an additional constructor that accepts different parameters. I don't actually use this
 * constructor in my program, I've just included it for future use. This Constructor accepts two more parameters, which are used for two additional
 * channels that can control the speed of the motors. You don't have to use these additional channels, or this constructor. However, if you don't use
 * those channels or this Constructor, you won't be able to set the speed of the motors. The motors will just be either on or off. I've purposely designed
 * the setSpeed function so that it doesn't work if you didn't use this constructor.
 */
DriveTrain::DriveTrain(int leftChannel1, int leftChannel2, int leftChannelS, int rightChannel1, int rightChannel2, int rightChannelS) {
    setChannels(leftChannel1, leftChannel2, leftChannelS, rightChannel1, rightChannel2, rightChannelS); //set channels for new DriveTrain

    //set pins for left motor channels
    pinMode(this->left1, OUTPUT);
    pinMode(this->left2, OUTPUT);
    pinMode(this->leftSChannel, OUTPUT);

    //sets pins for right motor channels
    pinMode(this->right1, OUTPUT);
    pinMode(this->right2, OUTPUT);
    pinMode(this->rightSChannel, OUTPUT);

    setSpeeds(255, 255); //set initial speeds for DriveTrain object
    setDirections(NEUTRAL, NEUTRAL); //make sure that the DriveTrain is stopped when its first created.
}

/**
 * @brief sets variables for the motor channels
 * 
 * @param leftChannel1 1st pin for left motor
 * @param leftChannel2 2nd pin for left motor
 * @param rightChannel1 1st pin for right motor
 * @param rightChannel2 2nd pin for right motor
 * 
 * @details
 * If you look back in the header file, you may notice that this function is in the private section of the class
 * declaration. Thats because I created this function (and the next function, which is just an overloaded version of
 * this one for the second constructor) exclusively for the purpose of setting the variables from the private section 
 * to the values that are specified in the constructor. I created this function in order to clear clutter from the 
 * constructor, as it was starting to look a bit long. Since I only want this function called by the constructor, there's 
 * no reason for it to be a public function.
 */
void DriveTrain::setChannels(int leftChannel1, int leftChannel2, int rightChannel1, int rightChannel2) {
    this->left1 = leftChannel1;
    this->left2 = leftChannel2;
    //for the version of this setchannels, I've set the left speed channel variable to -2 - since thats a nonsensical pin that can't possibly exist
    this->leftSChannel = -2; //why -2? It had a nice ring to it

    this->right1 = rightChannel1;
    this->right2 = rightChannel2;
    this->rightSChannel = -2; //same as before; I've set this pin to something nonsensical.
}

/**
 * @brief sets variables for the motor channels, including speed channels. Overloaded function
 * 
 * @param leftChannel1 1st pin for left motor
 * @param leftChannel2 2nd pin for left motor
 * @param leftChannelS pin for left motor speed control - MUST BE A PWM PIN
 * @param rightChannel1 1st pin for right motor
 * @param rightChannel2 2nd pin for right motor
 * @param rightChannelS pin for right motor speed control - MUST BE A PWM PIN
 * 
 * @details
 * Must like constructors, we can also overload functions. This one is meant for use by the second constructor, and is also
 * kept private since it doesn't need to be called by anything else.
 */
void DriveTrain::setChannels(int leftChannel1, int leftChannel2, int leftChannelS, int rightChannel1, int rightChannel2, int rightChannelS) {
    this->left1 = leftChannel1;
    this->left2 = leftChannel2;
    this->leftSChannel = leftChannelS; //for the overloaded function, lets actually give these channels a value that makes sense.

    this->right1 = rightChannel1;
    this->right2 = rightChannel2;
    this->rightSChannel = rightChannelS;
}

/**
 * @brief sets speed of motors. This function can only be used if you used the constructor with the speed control channels.
 * 
 * @param leftS speed to set the left motor to 
 * @param rightS speed to set the right motor to 
 */
void DriveTrain::setSpeeds(int leftS, int rightS) {
    this->leftSpeed = leftS; //set the speed variables so we can retrieve them if need be.
    this->rightSpeed = rightS;

    //see? those nonsensical pin values came in useful. Now we can check if you are able to control the speed, and if not, we'll throw an exception.
    if (this->leftSChannel == -2 && this->rightSChannel == -2) {
        this->leftSpeed = 255; //we always want the speed to be 255 if you can't control the speed
        this->rightSpeed = 255;
        throw "Unhandled Exception: Motor Controller speed channels were not specified!"; //Throws an exception to the caller
    }
    else { //if you can control the speeds of the motors, we'll set them here. To set output for PWM, we use analogWrite.
        analogWrite(leftSChannel, leftSpeed);
        analogWrite(rightSChannel, rightSpeed);
    }
}

/**
 * @brief gets speeds of the motors
 * 
 * @param left reference to left motor speed
 * @param right reference to right motor speed
 * 
 * @details
 * Whats with the & before each variable name?
 * This is what's called a reference - most parameters simply create a new variable, and copy the value passed to this new variable. This
 * is called passing by value. When we pass by reference, by appending & to the variable name, the original variable is passed to the function
 * instead, which saves memory and allows the function to actually change the value of the variable passed, a characteristic we make use of in this function.
 */
void DriveTrain::getSpeeds(int &left, int &right) {
    left = this->leftSpeed;
    right = this->rightSpeed;
}

/**
 * @brief set directions of motors
 * 
 * @param leftD left motor direction
 * @param rightD right motor direction
 */
void DriveTrain::setDirections(Direction leftD, Direction rightD) {
    //sets left and right direction variables to paramters passed
    this->left = leftD;
    this->right = rightD;

    //Switch for left motor direction
    switch (left) {
    case FORWARD:
        digitalWrite(left1, HIGH);
        digitalWrite(left2, LOW);
        break;

    case REVERSE:
        digitalWrite(left1, LOW);
        digitalWrite(left2, HIGH);
        break;
    
    case NEUTRAL:
    default:
        digitalWrite(left1, LOW);
        digitalWrite(left2, LOW);
        break;
    }

    //switch for right motor direction
    switch (right) {
    case FORWARD:
        digitalWrite(right1, HIGH);
        digitalWrite(right2, LOW);
        break;

    case REVERSE:
        digitalWrite(right1, LOW);
        digitalWrite(right2, HIGH);
        break;
    
    case NEUTRAL:
    default:
        digitalWrite(right1, LOW);
        digitalWrite(right2, LOW);
        break;
    }
}

/**
 * @brief gets directions each motor is running in 
 * 
 * @param left reference to left motor direction
 * @param right reference to right motor direction
 * 
 * @details
 * Just as before, we'll use pass by reference so we can give the two directions to the caller
 */
void DriveTrain::getDirections(Direction &left, Direction &right) {
    left = this->left;
    right = this->right;
}