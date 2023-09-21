#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    sobelHorizontal[0][0] = -1;
    sobelHorizontal[0][1] = 0;
    sobelHorizontal[0][2] = 1;
    sobelHorizontal[1][0] = -2;
    sobelHorizontal[1][1] = 0;
    sobelHorizontal[1][2] = 2;
    sobelHorizontal[2][0] = -1;
    sobelHorizontal[2][1] = 0;
    sobelHorizontal[2][2] = 1;
    
    sobelVertical[0][0] = 1;
    sobelVertical[0][1] = 2;
    sobelVertical[0][2] = 1;
    sobelVertical[1][0] = 0;
    sobelVertical[1][1] = 0;
    sobelVertical[1][2] = 0;
    sobelVertical[2][0] = -1;
    sobelVertical[2][1] = -2;
    sobelVertical[2][2] = -1;
    
    
    prewittHorizontal[0][0] = 1;
    prewittHorizontal[0][1] = 1;
    prewittHorizontal[0][2] = 1;
    prewittHorizontal[1][0] = 0;
    prewittHorizontal[1][1] = 0;
    prewittHorizontal[1][2] = 0;
    prewittHorizontal[2][0] = -1;
    prewittHorizontal[2][1] = -1;
    prewittHorizontal[2][2] = -1;
    
    
    prewittVertical[0][0] = 1;
    prewittVertical[0][1] = 0;
    prewittVertical[0][2] = -1;
    prewittVertical[1][0] = 1;
    prewittVertical[1][1] = 0;
    prewittVertical[1][2] = -1;
    prewittVertical[2][0] = 1;
    prewittVertical[2][1] = 0;
    prewittVertical[2][2] = -1;
    
    
    
    img.loadImage("test.jpg");
    int heightVal = img.getHeight();
    int widthVal = img.getWidth();
    edgeDetectedData = new unsigned char[widthVal* heightVal * 3];
    updateImg = true;
}


//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(255, 255, 255);
    if (updateImg){
//#ifdef USING_COLOR
//        edgeDetect3D();
//#else
        edgeDetect2D();
//#endif
        updateImg = false;
    }
}



//--------------------------------------------------------------
void ofApp::draw(){
    if (img.isAllocated()){
        img.draw(0,0);
        newImg.draw(600,0);
    }
}



void ofApp::edgeDetect2D(){
    int xPx, yPx, i, j, sum, sumY, sumX = 0;
    unsigned char* originalImageData = img.getPixels().getData();
    int heightVal = img.getHeight();
    int widthVal = img.getWidth();
    for (yPx = 0; yPx < heightVal; yPx++){
        for (xPx = 0; xPx < widthVal; xPx++){
            sumX = 0; sumY = 0;
            if (yPx == 0) sum = 0;
            else if ( xPx == 0) sum = 0;
            else {
                for (i =-1; i <= 1; i++){
                    sumX = sumX + (int)originalImageData[(yPx + j) * widthVal + xPx + i] * sobelHorizontal[i+1][j+1];
                }
            for ( i = -1; i <= 1; i++){
                for (j = -1; j <= 1; j++)
                    sumY = sumY + (int)originalImageData[(yPx + j) * widthVal + xPx + i] * sobelVertical[i+1][j+1];
                }
            sum = abs(sumX) + abs(sumY);
            }
        if (sum > 255) sum = 255;
        if (sum < 210) sum = 0;
        edgeDetectedData[yPx*widthVal + xPx] = 255 - (unsigned char)(sum);
        }
    }
    newImg.setFromPixels(edgeDetectedData, widthVal, heightVal, OF_IMAGE_GRAYSCALE, false);
}

void ofApp::edgeDetect3D(){
    unsigned char* imgPixels = img.getPixels().getData();
    unsigned int x, y, nWidth, nHeight;
    int firstPix, secondPix, dwRhreshold;
    int horizLength = nWidth*3;
    long horizOffset = horizLength - nWidth*3;
    nHeight = img.getHeight() - 2;
    nWidth = img.getWidth() -2;

    for (y = 0; y < nHeight; ++y){
        for ( x = 0; x < nWidth; ++x){
            long above = x * 3 + y * horizLength;
            long center = above + horizLength;
            long below = center + horizLength;
            firstPix = setPixel(imgPixels, 0, above, center, below, prewittHorizontal);
            secondPix = setPixel(imgPixels, 0, above, center, below, prewittVertical);
            edgeDetectedData[3+center] = max(dwRhreshold, min((int)sqrt(pow(firstPix,2)+pow(secondPix,2)), 255));

            firstPix = setPixel(imgPixels, 1, above, center, below, prewittHorizontal);
            secondPix = setPixel(imgPixels, 1, above, center, below, prewittVertical);
            edgeDetectedData[4+center] = max(dwRhreshold, min((int)sqrt(pow(firstPix,2)+pow(secondPix,2)), 255));

            firstPix = setPixel(imgPixels, 2, above, center, below, prewittHorizontal);
            secondPix = setPixel(imgPixels, 2, above, center, below, prewittVertical);
            edgeDetectedData[5+center] = max(dwRhreshold, min((int)sqrt(pow(firstPix,2)+pow(secondPix,2)), 255));
        }
    }
    newImg.setFromPixels(edgeDetectedData, img.getWidth(), img.getHeight(), OF_IMAGE_COLOR, true);
}

int ofApp::setPixel(unsigned char* px, int startPixel, int above, int center, int below, int matrix[][3]){
    return (
            (px[startPixel + above] * matrix[0][0]) +
            (px[startPixel + 3 + above] * matrix[0][1]) +
            (px[startPixel + 6 + above] * matrix[0][2]) +
            (px[startPixel + center] * matrix[1][0]) +
            (px[startPixel + 3 + center] * matrix[1][1]) +
            (px[startPixel + 6 + center] * matrix[1][2]) +
            (px[startPixel + below] * matrix[2][0]) +
            (px[startPixel + 3 + below] * matrix[2][1]) +
            (px[startPixel + 6 + below] * matrix[2][2])
            );
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
