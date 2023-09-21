#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(148,242,250);
    gravity = ofVec3f(0.0, 2.5f);
    for (int i = 0; i < count; i++){
        if (i * 5 < 255) balls[i].color = i * 50;
        else balls[i].color = 255;
    }
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < count; i++){
        balls[i].addForce(gravity);
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
//        dogColor = ();
    }  else {
        ofSetColor(217, 4, 41);
//        dogColor = (187, 255, 118);
    }
    
//    ofSetColor(dogColor);
    ofEllipse(ofGetWidth()/2, ofGetHeight(), 400, 400);
    ofEllipse(ofGetWidth()/2 + 200, ofGetHeight(),100, 200);
    ofEllipse(ofGetWidth()/2 - 200, ofGetHeight(),100, 200);
    ofSetColor(0);
    ofEllipse(ofGetWidth()/2+75, ofGetHeight() - 100, 50, 50);
    ofEllipse(ofGetWidth()/2-75, ofGetHeight() - 100, 50, 50);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    gravity.set(float(x) / ofGetWidth() - 0.7, (float)y / ofGetHeight() - 0.7);
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
