//
//  particleControl.cpp
//  particles1
//
//  Created by Patrick Stefaniak on 5/18/16.
//
//

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "particleControl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

particleControl::particleControl(int n){
    float xnum = getWindowWidth() /30;
    float ynum = getWindowHeight() /30 ;
    mousePos = vec2(0,0);
    
    for(int x = 0; x <= xnum ; x++){
        for(int y = 0; y <= ynum ; y++){
            mParticles.push_back(particle((x * 30) , (y * 30)  ));
        }
    }
    
}

void particleControl::draw(){
    for(particle &p: mParticles){
        p.draw(mousePos);
    }
}

void particleControl::update(vec2 m){
    mousePos = m;
}

void particleControl::clicked(){
    for(particle &p: mParticles){
        p.tann = ! p.tann;
    }
}