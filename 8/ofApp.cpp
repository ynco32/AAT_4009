#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	font.load("Summer Calling.ttf", 22);
	font2.load("BodoniFLF-Roman", 10);

	music1.load("sample.wav");
	music2.load("sample2.mp3");
	
	music1.setPosition(posi*0.1f);
	music1.setPan(pan*0.1f);
	//music2.setPosition(posi);
	//music1.setPosition(posi);


	//music1.setVolume(0.75f);
	//music2.setVolume(0.75f);
	
	/*
	SoundControl.setup("SoundControl", "settings.xml");
	SoundControl.add(pan1.setup("Music1 Pan", 0.0f, -1.0f,1.0f));
	SoundControl.add(pan2.setup("Music2 Pan", 0.0f, -1.0f, 1.0f));

	music2.setPan(pan2);
	music1.setPan(pan1);


	
	
	SoundControl.add(Loop.setup("Music1 Loop",false));
	SoundControl.add(Multiplay.setup("Music1 multiplay", false));
	SoundControl.add(Position.setup("Music1 Position", false));

	SoundControl.add(Loop2.setup("Music2 Loop", false));
	SoundControl.add(Multiplay2.setup("Music2 multiplay", false));
	SoundControl.add(Position2.setup("Music2 Position", false));

	music1.setLoop(Loop);
	music1.setMultiPlay(Multiplay);
	music1.setPosition(Position);
	music2.setLoop(Loop2);
	music2.setMultiPlay(Multiplay2);
	music2.setPosition(Position2);
	

	SoundControl.loadFromFile("settings.xml");
	showGui = true;
	*/
//	music1.setMultiPlay(true);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofBackground(255, 255, 255);
	ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){

	//SoundControl.draw();
	
	ofSetColor(100,100,255);
	ofDrawRectangle(0, 0, ofGetWidth() / 2.0f, ofGetHeight());
	ofSetColor(255,100,100);
	ofDrawRectangle(ofGetWidth() / 2.0f, 0, ofGetWidth() / 2.0f, ofGetHeight());

	ofSetColor(255);
	font2.drawString("Loop: SPACEBAR      Multiplay: ENTER", 10, 30);
	font2.drawString("Control Pan: TAB       Control Position: ALT", 10, 40);
	font2.drawString("Drag:: X position: VOLUME      Y position: SPEED", 10, 50);



	if (music1.isPlaying()) ofSetColor(200);
	else ofSetColor(255);
	font.drawString("music 1", 50, 100);

	if (music2.isPlaying()) ofSetColor(200);
	else ofSetColor(255);
	font.drawString("music 2", ofGetWidth() / 2.0f+ 50, 100);

	
	if (loop == 0) {
		loopB = true;

		ofSetColor(200);
		ofDrawCircle( (ofGetWidth() / 2.0f - 300), (ofGetHeight() * 0.9), 40);
	}
	else {
		loopB = false;
		ofSetColor(100);
		ofDrawCircle(ofGetWidth() / 2.0f - 300, ofGetHeight() * 0.9, 40);
	}
	

	if (multi == 0) {
		multiB = true;
		ofSetColor(200);
		ofDrawTriangle(ofGetWidth() / 2.0f - 200, ofGetHeight() * 0.9, ofGetWidth() / 2.0f - 130, ofGetHeight() * 0.9, ofGetWidth() / 2.0f - 165, ofGetHeight() * 0.9 + 50);
		ofDrawTriangle(ofGetWidth() / 2.0f - 200, ofGetHeight() * 0.9 , ofGetWidth() / 2.0f - 130, ofGetHeight() * 0.9 , ofGetWidth() / 2.0f - 165, ofGetHeight() * 0.9 - 50);
	}
	else {
		multiB = false;
		ofSetColor(100);
		ofDrawTriangle(ofGetWidth() / 2.0f - 200, ofGetHeight() * 0.9, ofGetWidth() / 2.0f - 130, ofGetHeight() * 0.9, ofGetWidth() / 2.0f - 165, ofGetHeight() * 0.9 + 50);
	}

	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if (key == 13) {
		loop++;
		if (loop > 2) loop = 0;
		
	}
	
	else if (key == 32) {
		multi++;
		if (multi > 2) multi = 0;
		
	}

	else if (key == 18) {
		posi++;
		if (posi > 11) posi = 1;


	}
	else if (key == 9) {
		pan++;
		if (pan > 11) pan = -10;
	}
	

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (x >= 0 && x < ofGetWidth() / 2.0f) {
		music1.setSpeed( 0.1f + ( (float)(ofGetHeight() - y) / (float)ofGetHeight()) * 1.0f);
	}
	else if (x >= ofGetWidth() / 2.0f) {
		music2.setSpeed(0.1f + ((float)(ofGetHeight() - y) / (float)ofGetHeight()) * 1.0f);
	}



	if (x >= 0 && x < ofGetWidth() / 2.0f) {
		music1.setVolume(0.1f + ((float)(ofGetWidth() - x) / (float)ofGetWidth()) * 1.0f);
	}
	else if (x >= ofGetWidth() / 2.0f) {
		music2.setVolume(0.1f + ((float)(ofGetWidth() - x) / (float)ofGetWidth()) * 1.0f);
	}
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	if (x < ofGetWidth() / 2.0f) {
		if(music1.isPlaying()) music1.stop();
		else {
			music1.setLoop(loopB);
			music1.play();
		}
	}
	else if (x >= ofGetWidth() / 2.0f) {
		if (music2.isPlaying()) music2.stop();
		else {
			music2.setLoop(loopB);
			music2.play();
		}
	}


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
