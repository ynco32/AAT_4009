#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("video synth");
    ofSetWindowShape(1280, 720);
    ofSetFrameRate(60);
    ofBackground(ofColor::white);
    
    gui.setup("Parameters", "settings.xml");
    gui.add(countX.setup("count", 10, 0, 50));
    gui.add(stepX.setup("stepX", 20, 0,200));
    gui.add(twistX.setup("twistX", 5, -45, 45));
    gui.add(radius.setup("radius", 140, 10, 300));
    gui.add(center.setup("center", {ofGetWidth()*.5, ofGetHeight()*.5}, {0, 0}, {ofGetWidth(), ofGetHeight()}));
    gui.add(Background.setup("Background", 255,0,255));
    
    primGroup.setup("Primitive");
    primGroup.add(shiftY.setup("shiftY", 0.0, -1000.0, 1000.0));
    primGroup.add(angle.setup("angle", 0.0, - 90, 90));
    
    primGroup.add(size.setup("size", ofVec2f(6,6), ofVec2f(0,0), ofVec2f(20,20)));
    primGroup.add(color.setup("color", ofColor::black, ofColor(0,0,0,0), ofColor::white));
    
    gui.add(&primGroup);
    
    gui.loadFromFile("settings.xml");
    showGui = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(Background);
    
    float Scl = pow(Scale, 4.0f);
    ofScale(Scl, Scl);
//    ofRotate(Rotate);
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    drawGeometric();
}

void ofApp::drawGeometric(){
    ofSetColor(color);
    ofSetLineWidth(1.0);
    ofNoFill();
//    ofFill();
    ofBeginShape();
    for (int i = -countX; i <= countX; i++){
        ofPushMatrix();
        ofScale(size->x, size->y);
        ofTranslate(i*stepX, 0);
        ofRotate(i*twistX);
        ofTranslate(0, shiftY);
        
        float bezX1 = -10 + 200 * cos(angle);
        float bezY1 = -10 + 200 * sin(angle);
        float bezX2 = 10 + 100 * cos(angle);
        float bezY2 = 10 + 100 * sin(angle);
        
        ofVertex(50,100);
        ofBezierVertex(bezX1, bezY1, bezX2, bezY2, 200, 200);
        ofVertex(200,150);
        ofDrawCircle(center->x-radius * 0.5, center->y, radius );
        ofDrawCircle(center->x+radius * 0.5, center->y, radius );
        ofEndShape();
        ofPopMatrix();
    }
}


void ofApp::exit(){
    gui.saveToFile("settings.xml");
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
