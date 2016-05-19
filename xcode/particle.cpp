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
    posx = x;
    posy = y;
    size = 3;
    tann = false;
}

void particle::draw(vec2 m){
    //
    
    
    vec2 toM = m - vec2(posx, posy);
    //draw shorter lines ! normalizing ... . dunno how its working
    float time = app::getElapsedSeconds() ;
    float dist = glm::length(toM) * 0.05f;
    
    float sinOff;
    
    if(tann){
        sinOff = tan(dist - time) * 100.0f;
    }else{
        sinOff = sin(dist - time) * 100.0f;
    }
    
    vec2 norm = glm::normalize(toM) * size;
    vec2 newL = m + norm * sinOff;
    
    //posx = constrain(newL.x, 0.0f, getWindowWidth()-  1.0f);
    //posy = constrain(newL.y, 0.0f, getWindowHeight() - 1.0f);
    

    gl::drawSphere(vec3(posx,posy,constrain(newL.y, -1000.0f, 1000.0f)), size);

    //gl::drawVector( vec3(posx, posy,0.0), vec3(posx + norm.x, posy + norm.y, 0.0) );
}

