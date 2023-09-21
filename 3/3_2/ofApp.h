#pragma once

#include "ofMain.h"
#include "Ball.hpp"
#define count 10
#define numBalls 10

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        void mouseMoved(int x, int y );
    void drawConnectors();
    void checkCollision();
    
    ofVec2f gravity;
    Ball balls[10];
    ofColor dogColor;

		void keyPressed(int key);
		void keyReleased(int key);
		
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
