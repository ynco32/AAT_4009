#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    totalPixels = GRABBED_VID_WIDTH * GRABBED_VID_HEIGHT * 3;

    videoIn.initGrabber(GRABBED_VID_WIDTH, GRABBED_VID_HEIGHT);

    text.allocate(GRABBED_VID_WIDTH, GRABBED_VID_HEIGHT, GL_RGB);
    
    
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    int baud = 9600;
    serial.setup("/dev/cu.usbmodem14401", baud);
}


//--------------------------------------------------------------
void ofApp::update(){
    videoIn.update();
    if (videoIn.isFrameNew()) {
        for (int j = 0; j++; j <4){
            count[j] = 0;
        }
        int totalPixels = GRABBED_VID_WIDTH * GRABBED_VID_HEIGHT * 3;
        unsigned char* tempPixels = videoIn.getPixels().getData();
        for (int i = 0; i < totalPixels; i += 3) {
            unsigned char r = abs(tempPixels[i] - dataPixels[i]);
            unsigned char g = abs(tempPixels[i + 1] - dataPixels[i + 1]);
            unsigned char b = abs(tempPixels[i + 2] - dataPixels[i + 2]);
            int diff = r + g + b;
            if (diff > 70) {
                drawingPixels[i] = 255;
                drawingPixels[i + 1] = 255;
                drawingPixels[i + 2] = 255;
                
                int pl = i/3;
                
                if (i < totalPixels/4 ){
                    count[0]++;
                } else if (i < totalPixels /2){
                    count[1]++;
                } else if (i < 3 * totalPixels/4){
                    count[2]++;
                } else{
                    count[3]++;
                }
                
            }
            else {
                drawingPixels[i] = tempPixels[i];
                drawingPixels[i + 1] = tempPixels[i + 1];
                drawingPixels[i + 2] = tempPixels[i + 2];
            }
        }
        
        key = max(count);
        sendData = key;
        cout << sendData << endl;
        memcpy(dataPixels, tempPixels, totalPixels); // copy pixels
        text.loadData(drawingPixels, GRABBED_VID_WIDTH, GRABBED_VID_HEIGHT, GL_RGB);
    }     // they are loaded into an ofTexture object.

}

char ofApp::max(int section[4]){
    char max_out = '1';
    int max_num = section[0];
    for (int i = 0; i < 4; i++){
        if (max_num < section[i]){
            max_num = section[i];
            max_out = (char)(i + 48);
        } else {
            continue;
        }
    }
    cout << max_out << endl;
    return max_out;
}

void ofApp::draw() {
    ofSetColor(255,255,255);
    videoIn.draw(20, 20);

    text.draw(20 + GRABBED_VID_WIDTH, 20, GRABBED_VID_WIDTH, GRABBED_VID_HEIGHT);
}


