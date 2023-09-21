//
//  Ball.cpp
//  collision
//
//  Created by Yunji Choe on 2021/10/25.
//

#include "Ball.hpp"

Ball:: Ball(){
    mass = ofRandom(3,0) + 2.0;
    size = ofRandom(0.1, 10);
    bounce = 0.9;
    location.x = ofRandom(ofGetWidth());
    location.y = 0;
    gravity = ofVec3f(0.0, 2.5f);
}

void Ball::addForce(ofVec2f force){
    force/= mass;
    acceleration += force;
}

void Ball::drawFrame(){
    ofSetColor(color);

    ofCircle(location.x, location.y, size);
}

void Ball::updateBall(){
    velocity += acceleration;
    location += velocity;
    acceleration.set(0.0f, 0.0f, 0.0f);
    if (location.y > 800){
        velocity.y *= -bounce;
        location.y = 800;
    }
    if (location.y < 0){
        velocity.y *= -bounce;
        location.y = 0;
    }
    if (location.x > 1000){
        velocity.x *= -bounce;
        location.x = 1000;
    }
    if (location.x < 0){
        velocity.x *= -bounce;
        location.x = 0;
    }
}

void Ball::collision(Ball* b1){
    float newMass, diff, angle, newX, newY, newVelocityX, newVelocityY, fy21, sign, newSize;
    
    newMass = b1 -> mass/mass;
    newSize = b1 -> size/size;
    newX = b1 -> location.x - location.x;
    newY = b1 -> location.y - location.y;
    
    newVelocityX = b1 -> velocity.x - velocity.x;
    newVelocityY = b1 -> velocity.y - velocity.y;
    
    if ((newVelocityX * newX + newVelocityY * newY) >= 0) return;
    
    angle = newY/newX;
    diff = -2 * (newVelocityX + angle * newVelocityY)/((1+angle * angle) * (1+newMass));
    
    b1 -> velocity.x = b1 -> velocity.x + diff;
    b1 -> velocity.y = b1 -> velocity.y + angle * diff;
    
    velocity.x = velocity.x - newMass *diff;
    velocity.y = velocity.y - angle*newMass *diff;
    
    if (size*1.1 > 20){
        size = 20;
    } else {size = size *1.1;}
    
    fy21 = fabs(newY);
    if (fabs(newX) < fy21){
        if (newX < 0){
            sign = -1;
        } else {
            sign = 1;
        }
        newX = fy21 * sign;
    }
}
