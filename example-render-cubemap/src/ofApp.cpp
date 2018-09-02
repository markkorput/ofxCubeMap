#include "ofApp.h"

void ofApp::setup() {
  mCubeMap.load(
    "lmcity_lf.jpg",
    "lmcity_rt.jpg",
    "lmcity_up.jpg",
    "lmcity_dn.jpg",
    "lmcity_ft.jpg",
    "lmcity_bk.jpg"
  );
}

void ofApp::update() {

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
