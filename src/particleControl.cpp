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
        
        
        //radius of sphere of influence for particle
        float zoneRadius = 300;
        
            list<particle>::iterator q = p;
            for(++q; q != mParticles.end(); ++q){
                
                vec2 dis = p->pos - q->pos;
                float disSq = glm::distance2(p->pos, q->pos);
                //percentage of position in sphere of other particle
                float percent = disSq / zoneRadius / zoneRadius;
                
                float lowThresh = 0.1f;
                float highThresh = 0.8f;
                //to repel close together particles
                if(percent < lowThresh){
                    float f = (lowThresh/percent - 1.0f) * 0.01f;
                    dis = glm::normalize(dis) * f;
                    p->repel += dis / p->mass;
                    q->repel -= dis / q->mass;
                /*
                }else if(percent < highThresh){
                    float threshDelta = highThresh - lowThresh;
                    float adjPercent = (percent - lowThresh) / threshDelta;
                    float F = (0.5f - cos(adjPercent * M_PI*2.0f)*0.5f+0.5f) * 0.01f;
                    if((p->repel != vec2(0,0)) && (q->repel != vec2(0))){
                        p->repel += glm::normalize(q->repel) * F;
                        q->repel += glm::normalize(p->repel) * F;
                    }
                */
                //to attract far away particles
                }else if(percent > highThresh){
                    float threshDelta = 1.0f - highThresh;
                    float adjustedPercent = (percent - highThresh) / threshDelta;
                    float f = (0.5f - cos(adjustedPercent * M_PI * 2.0f) * 0.5f + 0.5f) * 0.01f;
                    dis = glm::normalize(dis) * f;
                    p->repel -= dis / p->mass;
                    q->repel += dis / q->mass;
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