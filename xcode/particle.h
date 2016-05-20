//
//  particle.h
//  particles1
//
//  Created by Patrick Stefaniak on 5/18/16.
//
//
#include "cinder/Perlin.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#pragma once

class particle {
public:
    particle () {}
    particle (float x, float y);
    
    void draw();
    void update(vec2 m);
    
    float       size, speed, mass;
    vec2        dir, pos, repel, prevPPos;
    bool        alive;
    Perlin      perl;
};