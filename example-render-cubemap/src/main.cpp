#include "ofMain.h"
#include "ofApp.h"

int main(int argc, char** argv){

  ofGLFWWindowSettings settings;
  settings.glVersionMajor = 4;
  settings.glVersionMinor = 1;
  //    settings.windowMode = OF_WINDOW;
  settings.width = 1280;
  settings.height = 720;
  //    settings.multiMonitorFullScreen=true;
  shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
  // mainWindow->setWindowTitle("Multiverse - MAIN");
  // mainWindow->setWindowPosition(0, 0);

  shared_ptr<ofApp> mainApp(new ofApp());
  ofRunApp(mainWindow, mainApp);
  ofRunMainLoop();

  //ofSetupOpenGL(800, 600, OF_WINDOW);
  //ofRunApp(new ofApp());
}
