#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "Arduino.h"

class DriveTrain {
    public:
        enum Direction {
            FORWARD,
            REVERSE,
            NEUTRAL
        };

        DriveTrain(int leftChannel1, int leftChannel2, int rightChannel1, int rightChannel2);
        DriveTrain(int leftChannel1, int leftChannel2, int leftChannelS, int rightChannel1, int rightChannel2, int rightChannelS);

        void setSpeeds(int leftS, int rightS);
        void getSpeeds(int &left, int &right);
        void setDirections(Direction leftD, Direction rightD);
        void getDirections(Direction &left, Direction &right);
    private:
        int 
        left1, left2, leftSChannel, leftSpeed, 
        right1, right2, rightSChannel, rightSpeed;
        Direction left, right;

        void setChannels(int leftChannel1, int leftChannel2, int rightChannel1, int rightChannel2);
        void setChannels(int leftChannel1, int leftChannel2, int leftChannelS, int rightChannel1, int rightChannel2, int rightChannelS);
};

#endif