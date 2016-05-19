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
#include "cinder/Perlin.h"

using namespace ci;
using namespace ci::app;
using namespace std;

particle::particle(float x, float y){
    pos = vec2(x,y);
    size = 3;
    alive = true;
    speed = 2;
    dir = vec2(getWindowWidth()/2, getWindowHeight()/2) - vec2(x,y);
    dir = glm::normalize(dir);
    repel = vec2(0);
    mass = (rand() % 20) + 1;
    //cout << mass << "   " ;
    //mass = 1;
    perl = Perlin();
    
}

void particle::draw(){
   
    

    gl::drawSphere(vec3(pos.x,pos.y,0), size);

    
}

void particle::update(vec2 m){
    dir = m - pos;
    vec2 dirN;
    if(dir != vec2(0,0)){
        dirN = glm::normalize(dir);
    }
    //repelSpeed = 9000/ repelSpeed;
    
    
    
    if(glm::length(dir) < 30){
        pos = pos - (dirN * speed);
    }else{
        pos = pos + (dirN * speed);
    }
    
    
    float rSpeed = 200;
    pos += repel * rSpeed;
    repel = vec2(0,0);
    
    float t = app::getElapsedSeconds() * 0.01f;
    vec3 per = vec3(pos.x, pos.y, t);
    float noise = perl.fBm(per) * 15 ;
    pos += vec2(cos(noise) , sin(noise) );
    
    //cout << pos << "    ";
    //if(distance(pos, getWindowCenter()) < size){
    //    alive = false;
    //}
}