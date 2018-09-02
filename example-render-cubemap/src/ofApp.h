#include "ofMain.h"
#include "ofxCubeMap.h"

class ofApp : public ofBaseApp{

  public: // methods
    void setup() override;
    void update() override;
    void draw() override;

  private: // attributes
    ofxCubeMap mCubeMap;
    ofEasyCam mEasyCam;
};
