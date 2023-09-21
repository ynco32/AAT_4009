#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:

    ofxPanel gui;
    ofxIntSlider countX;
    ofxFloatSlider stepX;
    ofxFloatSlider twistX;
    ofxIntSlider countY;
    ofxFloatSlider stepY;
    ofxFloatSlider twistY;
    ofxFloatSlider pinchY;
    ofxFloatSlider radius;
    ofxVec2Slider center;
    
    ofxGuiGroup globalGroup;
    ofxFloatSlider Scale;
    ofxFloatSlider Rotate;
    ofxFloatSlider Background;
    
    ofxGuiGroup primGroup;
    ofxFloatSlider shiftY;
    ofxFloatSlider angle;
    ofxVec2Slider size;
    ofxColorSlider color;
    bool showGui = false;
        void setup();
		void update();
		void draw();
    void exit();
    void drawGeometric();

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
		
};
