#ifndef _ASSIGNMENT3_1
#define _ASSIGNMENT3_1
#define numSegments 200
#define segLength 10

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    void reachSegment(int i, float xin, float yin);
    void positionSegment(int a, int b);
    void drawSegment(float x, float y, float a, float sw);
    float xPos[numSegments];
    float yPos[numSegments];
    float angle[numSegments];
    float targetX, targetY, randX, randY;
    
    
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

#endif
