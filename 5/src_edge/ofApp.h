#ifndef _EDGE_APP
#define _EDGE_APP

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        int setPixel(unsigned char* px, int startPixel, int dep, int depthOfNextLine, int depthOfNextNextLine, int matrix[][3]);
        
        void edgeDetect2D();
        void edgeDetect3D();
        
        int sobelHorizontal[3][3];
        int sobelVertical[3][3];
        int prewittHorizontal[3][3];
        int prewittVertical[3][3];
        
        unsigned char* edgeDetectedData;
        ofImage img;
        ofImage newImg;
        bool updateImg;
    

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
