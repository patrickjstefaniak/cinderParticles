//
//  particle.cpp
//  particles1
//
//  Created by Patrick Stefaniak on 5/18/16.
//
//

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

particle::particle(float x, float y){
    pos = vec2(x,y);
    size = 3;
    alive = true;
    speed = 1;
    dir = vec2(getWindowWidth()/2, getWindowHeight()/2) - vec2(x,y);
    dir = glm::normalize(dir);
}

void particle::draw(){
   
    

    gl::drawSphere(vec3(pos.x,pos.y,0), size);

    
}

void particle::update(){
    pos = pos + (dir * speed);
    if(distance(pos, getWindowCenter()) < size){
        alive = false;
    }
}