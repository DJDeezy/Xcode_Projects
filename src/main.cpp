#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
  float screenWidth = 800;
  
  ofSetupOpenGL(screenWidth, 25.0*screenWidth/32.0, OF_WINDOW);   // <-------- setup the GL context
  //ofSetupOpenGL(1024,768,OF_WINDOW);  // old setup

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
