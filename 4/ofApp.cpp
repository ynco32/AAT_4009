#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    gravitySet = ofVec3f(0.0, 2.5f);
    
    for (int i = 0; i < count; i++){
        random = ofRandom(255);
        balls[i].color.setHsb(random, 255,255, 150);
        if (random > 100){
            balls[i].gravity.set(ofRandom(0.01, 0.3) - 0.4, ofRandom(0.01, 0.3) - 0.4);
        } else{
            if (random > 200){
                balls[i].gravity.set(ofRandom(0.31, 0.75) - 0.4, ofRandom(0.31, 0.75) - 0.4);
            } else{
                balls[i].gravity.set(ofRandom(0.76, 1.0) - 0.4, ofRandom(0.76, 1.0) - 0.4);
            }
        }
        
    }
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < count; i++){
        balls[i].addForce(balls[i].gravity);
        balls[i].updateBall();
    }
    
    checkCollision();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i< count; i++){
        balls[i].drawFrame();
    }
    
    if (mouseY > ofGetHeight() /2 ){
        ofSetColor(178,113,36);
    }  else {
        ofSetColor(217, 4, 41);
    }
    
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


void ofApp::checkCollision(){
    int i, j;
    for(i = 0; i < numBalls; i++){
        for (j = i + 1; j < numBalls; j++){
            if (ofDist(balls[i].location.x, balls[i].location.y, balls[j].location.x, balls[j].location.y) < 50){
                balls[i].collision(&balls[j]);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
//    hue = ofRandom(255);
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
