//
//  Ball.hpp
//  assignemtn3_2
//
//  Created by Yunji Choe on 2021/10/13.
//

#ifndef Ball_hpp
#define Ball_hpp

#include "ofMain.h"
//#include "ofxVectorMath.h"
#define otherOBjsCount 2

class Ball{
public:
    Ball();
    void addForce(ofVec2f force);
    void updateBall();
    ofVec3f location;
    ofVec3f velocity;
    ofVec3f acceleration;
    float mass;
    float size;
    float maximum_velocity;
    float bounce;
    ofColor color;
    
    void drawFrame();
    void collision(Ball* b1);
};

#endif /* Ball_hpp */
