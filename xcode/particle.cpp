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
    mass = (rand() % 200) + 1;
    //cout << mass << "   " ;
    //mass = 1;
    perl = Perlin();
    
}

void particle::draw(){
   
    

    gl::drawSphere(vec3(pos.x,pos.y,0), size);

    
}

void particle::update(vec2 m){
    
    //attract towards mouse
    dir = m - pos;
    vec2 dirN;
    if(dir != vec2(0,0)){
        dirN = glm::normalize(dir);
    }
    //repelSpeed = 9000/ repelSpeed;
    
    
    
    if(glm::length(dir) < 20){
        //pos = pos - (dirN * speed);
    }else{
        pos = pos + (dirN * speed);
    }
    
    
    
    //repel from other particles
    float repelL = glm::length(repel);
    
    //make sure they are moving , but not too fast
    if(repelL  > 20.0f){
        repel = glm::normalize(repel);
        repel = repel * 20.0f;
        
    }else if(repelL  < 2.0f && repelL != 0){
        repel = glm::normalize(repel);
        repel = repel * 2.0f;
    }
    
    pos += repel ;
    repel = vec2(0,0);
    
    vec2 perp = vec2(- dirN.y, dirN.x);
    pos += perp / 5.0f;
    
    
    if(pos.x < 0){
        pos.x = 0;
    }else if(pos.x > getWindowWidth()){
        pos.x = getWindowWidth();
    }
    if(pos.y < 0){
        pos.y = 0;
    }else if(pos.y > getWindowHeight()){
        pos.y = getWindowHeight();
    }
    
    //float t = app::getElapsedSeconds() * 0.01f;
    //vec3 per = vec3(pos.x, pos.y, t);
    //float noise = perl.fBm(per) * 15 ;
    //pos += vec2(cos(noise) , sin(noise) );
    
    //cout << pos << "    ";
    //if(distance(pos, getWindowCenter()) < size){
    //    alive = false;
    //}
}