#include "ofApp.h"
#define numOfCircle 20

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1000, 1000);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, 123);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    reachSegment(0, mouseX - 500, mouseY - 500);
    int i;
    for (i = 1; i < numSegments; i++){
        reachSegment(i, targetX, targetY);
    }
    for (i = numSegments -1; i >= 1; i--){
        positionSegment(i, i-1);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255, 255, 255, 150);
    ofSetColor(255, 100, 100, 30);
    for (int  i = 0; i<numSegments; i++){
        drawSegment(xPos[i], yPos[i], angle[i], (i+1)*2);
    }
    
    ofSetColor(100, 255, 100, 30);
    for (int  i = 0; i<numSegments; i++){
        drawSegment(xPos[i] + 50, yPos[i]+ 50, angle[i]* -30, (i+1)*2);
    }
    
    ofSetColor(100, 100, 255, 30);
    for (int  i = 0; i<numSegments; i++){
        drawSegment(xPos[i] + -50 , yPos[i]- 50, angle[i]* 30, (i+1)*2);
    }
    
    ofSetColor(100, 100, 100, 30);
    for (int  i = 0; i<numSegments; i++){
        drawSegment(xPos[i]+100, yPos[i]-100, angle[i] * 40, (i+1)*2);
    }
    
    ofSetColor(100, 155, 100, 30);
    for (int  i = 0; i<numSegments; i++){
        drawSegment(xPos[i] - 100, yPos[i]+ 100, angle[i]* -40, (i+1)*2);
    }
    
    ofSetColor(155, 100, 155, 30);
    for (int  i = 0; i<numSegments; i++){
        drawSegment(xPos[i] + -150 , yPos[i]- 150, angle[i]* 50, (i+1)*2);
    }
}
void ofApp::drawSegment(float x, float y, float a, float sw){
    glPushMatrix();
    glTranslated(x, y, 0);
    glRotatef(a, 0, 0, 0);
    ofCircle(500, 500, segLength);
    glPopMatrix();
}


void ofApp::positionSegment(int a, int b){
    xPos[b] = xPos[a] + sin(angle[a]) *segLength;
    yPos[b] = yPos[a] + sin(angle[a]) *segLength;
}

void ofApp::reachSegment(int i, float xin, float yin){
    float dx = xin - xPos[i];
    float dy = yin - yPos[i];
    angle[i] = atan2(dy,dx);
    targetX = xin - cos(angle[i]) * segLength;
    targetY = yin - sin(angle[i]) * segLength;
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
