//
//  particle.h
//  particles1
//
//  Created by Patrick Stefaniak on 5/18/16.
//
//

using namespace ci;
using namespace ci::app;
using namespace std;

#pragma once

class particle {
public:
    particle () {}
    particle (float x, float y);
    
    void draw(vec2 mpos);
    void update();
    
    float size;
    int posx, posy;
    
    bool tann;
};