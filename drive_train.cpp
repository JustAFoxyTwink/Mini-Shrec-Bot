#include "drive_train.h"

DriveTrain::DriveTrain(int leftChannel1, int leftChannel2, int rightChannel1, int rightChannel2) {
    setChannels(leftChannel1, leftChannel2, rightChannel1, rightChannel2);

    pinMode(this->left1, OUTPUT);
    pinMode(this->left2, OUTPUT);
    pinMode(this->right1, OUTPUT);
    pinMode(this->right2, OUTPUT);

    setSpeeds(255, 255);
    setDirections(NEUTRAL, NEUTRAL);
}

DriveTrain::DriveTrain(int leftChannel1, int leftChannel2, int leftChannelS, int rightChannel1, int rightChannel2, int rightChannelS) {
    setChannels(leftChannel1, leftChannel2, leftChannelS, rightChannel1, rightChannel2, rightChannelS);

    pinMode(this->left1, OUTPUT);
    pinMode(this->left2, OUTPUT);
    pinMode(this->leftSChannel, OUTPUT);

    pinMode(this->right1, OUTPUT);
    pinMode(this->right2, OUTPUT);
    pinMode(this->rightSChannel, OUTPUT);

    setSpeeds(255, 255);
    setDirections(NEUTRAL, NEUTRAL);
}

void DriveTrain::setChannels(int leftChannel1, int leftChannel2, int rightChannel1, int rightChannel2) {
    this->left1 = leftChannel1;
    this->left2 = leftChannel2;
    this->leftSChannel = -2;

    this->right1 = rightChannel1;
    this->right2 = rightChannel2;
    this->rightSChannel = -2;
}

void DriveTrain::setChannels(int leftChannel1, int leftChannel2, int leftChannelS, int rightChannel1, int rightChannel2, int rightChannelS) {
    this->left1 = leftChannel1;
    this->left2 = leftChannel2;
    this->leftSChannel = leftChannelS;

    this->right1 = rightChannel1;
    this->right2 = rightChannel2;
    this->rightSChannel = rightChannelS;
}

void DriveTrain::setSpeeds(int leftS, int rightS) {
    this->leftSpeed = leftS;
    this->rightSpeed = rightS;

    if (this->leftSChannel != -2 && this->rightSChannel != -2) {
        analogWrite(leftSChannel, leftSpeed);
        analogWrite(rightSChannel, rightSpeed);
    }
}

void DriveTrain::getSpeeds(int &left, int &right) {
    left = this->leftSpeed;
    right = this->rightSpeed;
}

void DriveTrain::setDirections(Direction leftD, Direction rightD) {
    this->left = leftD;
    this->right = rightD;

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

void DriveTrain::getDirections(Direction &left, Direction &right) {
    left = this->left;
    right = this->right;
}