#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "particle.h"
#include "particleControl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class particles1App : public App {
  public:
	void setup() override;
	void mouseMove( MouseEvent event ) override;
	void update() override;
	void draw() override;
    void mouseDown( MouseEvent event) override;
    
    particleControl pC;
    CameraPersp     cam;
};

void particles1App::setup()
{
    setWindowSize(800,600);
    
    pC = particleControl(50);
    cam.setPerspective(60,getWindowAspectRatio(), 1, 1000);
    gl::setMatrices(cam);
    cam.lookAt(vec3(getWindowWidth()/2, getWindowHeight()/2, 200), vec3(getWindowWidth()/2, getWindowHeight()/2, 0));
}

void particles1App::mouseMove( MouseEvent event )
{
    pC.update(event.getPos());
}
void particles1App::mouseDown( MouseEvent event)
{
    pC.clicked();
}

void particles1App::update()
{
    //pC.update();
}

void particles1App::draw()
{
    cam.setPerspective(60,getWindowAspectRatio(), 1, 2000);
    gl::setMatrices(cam);
    cam.lookAt(vec3(getWindowWidth()/2, getWindowHeight()/2, 1000), vec3(getWindowWidth()/2, getWindowHeight()/2, 0));
	gl::clear( Color( 0, 0, 0 ) );
    pC.draw();
}

CINDER_APP( particles1App, RendererGl(RendererGl::Options().msaa(4) ))
