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

    for(int count = n; count >= 0; count --){
        particle p = particle(0, 0);
        mParticles.push_back(p);
    }
    
    
    
}

void particleControl::draw(){
    for(particle &p: mParticles){
        p.draw();
    }
}

void particleControl::update(){
    for(list<particle>::iterator p = mParticles.begin(); p != mParticles.end();){
        if(!(p->alive)){
            p =  mParticles.erase(p);
        }else{
            p->update();
            ++p;
        }
    }
}

void particleControl::clicked(vec2 m){
    create(m);
}

void particleControl::create(vec2 mpos){
    particle p = particle(mpos.x, mpos.y);
    mParticles.push_back(p);
}