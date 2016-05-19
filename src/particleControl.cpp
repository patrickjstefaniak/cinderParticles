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
        particle p = particle(0,0);
        mParticles.push_back(p);
    }
    mousePos = getWindowCenter();
    
    
}

void particleControl::draw(){
    for(particle &p: mParticles){
        p.draw();
    }
}

void particleControl::update(){
    for(list<particle>::iterator p = mParticles.begin(); p != mParticles.end();){
        //if(!(p->alive)){
         //   p =  mParticles.erase(p);
        //}else{
        
            list<particle>::iterator q = p;
            for(++q; q != mParticles.end(); ++q){
                vec2 dis = p->pos - q->pos;
                float disSq = glm::distance2(p->pos, q->pos);
                float radSq = 5000;
                if(disSq < radSq){
                    float f = (radSq/disSq - 1.0f) * 0.01f;
                    dis = glm::normalize(dis) * f;
                    p->repel += f * dis / p->mass;
                    q->repel -= f * dis / q->mass;
                }
                
            //}
            
        }
        p->update(mousePos);
        ++p;
    }
}

void particleControl::clicked(vec2 m){
    create(m);
    if(mParticles.size() > 100){
        mParticles.erase(mParticles.begin());
    }
}

void particleControl::create(vec2 mpos){
    particle p = particle(mpos.x, mpos.y );
    mParticles.push_back(p);
}

void particleControl::mMove(vec2 m){
    mousePos = m;
}