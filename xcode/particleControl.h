//
//  particleControl.h
//  particles1
//
//  Created by Patrick Stefaniak on 5/18/16.
//
//

#include "particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#pragma once

class particleControl {
public:
    particleControl () {}
    particleControl (int num);
    
    void draw();
    void create(vec2 mpos);
    void destroy();
    void update();
    void initialize();
    void clicked(vec2 m);
    void mMove(vec2 m);
    
    std::list<particle> mParticles;
    vec2                mousePos;
    
};
