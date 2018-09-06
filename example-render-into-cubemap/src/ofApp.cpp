#include "ofApp.h"

void ofApp::setup() {
  // mCubeMap.load(
  //   "lmcity_lf.jpg",
  //   "lmcity_rt.jpg",
  //   "lmcity_up.jpg",
  //   "lmcity_dn.jpg",
  //   "lmcity_ft.jpg",
  //   "lmcity_bk.jpg"
  // );

  mCubeMap.init( 1024 );
}

void ofApp::update() {

  mCubeMap.setPosition(0,0,0);

  mCubeMap.drawInto2D([this](){
    // draw scene
    ofClear(0,0,0);

    ofSetColor(255, 0, 255);
    ofLine(0,0, this->mCubeMap.getWidth(), this->mCubeMap.getHeight() );
    ofLine(this->mCubeMap.getWidth(), 0, 0, this->mCubeMap.getHeight() );
  });

  mCubeMap.drawInto3D([](){
    // draw moving yellow ball
    float t = ofGetElapsedTimef();
    float factor = 0.5f;
    float radius = 10.0f;

    ofVec3f pos =
      ofVec3f(
        std::sin(t * factor),
        std::cos(t * factor),
        std::sin((t+1.5f) * factor)
      ) * radius;

    ofSetColor(255, 255, 0);
    ofFill();
    ofDrawSphere(pos, 1.0f);
  });
}

void ofApp::draw() {

  { mEasyCam.begin();
    {
      mCubeMap.bind();
      mCubeMap.drawSkybox( ofVec3f(0), 800 );
      mCubeMap.unbind();
    }

    mEasyCam.end();
  }
}
