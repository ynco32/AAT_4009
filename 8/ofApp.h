#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofSoundPlayer music1;
		ofSoundPlayer music2;

		ofTrueTypeFont font;
		ofTrueTypeFont font2;

	/*
		ofxPanel SoundControl;
		ofxPanel gui;
		ofxFloatSlider pan1, pan2;

		ofxToggle Loop, Multiplay, Position;
		ofxToggle Loop2, Multiplay2, Position2;
		bool showGui = false;
		*/

		int loop = 0;
		int multi = 0;
		int posi = 1;
		int pan = 0;

		bool multiB = false;
		bool loopB = false;

};
