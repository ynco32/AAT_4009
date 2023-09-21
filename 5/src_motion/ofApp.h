#pragma once

#include "ofMain.h"
#define GRABBED_VID_WIDTH 640
#define GRABBED_VID_HEIGHT 480

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
//    void draw();
    unsigned char drawingPixels[GRABBED_VID_WIDTH * GRABBED_VID_HEIGHT * 3];
    unsigned char dataPixels[GRABBED_VID_WIDTH * GRABBED_VID_HEIGHT * 3];
    ofVideoGrabber videoIn;
    ofTexture text;
    int totalPixels;
    
    ofSerial serial;
    char receivedData[10];
    char sendData;
    char key;
    char max(int section[4]);
    int count[4];
};
