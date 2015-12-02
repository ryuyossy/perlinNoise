#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowPosition(2881, 0);
    ofSetWindowShape(1920,1080);
    ofToggleFullscreen();
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    
    fft.setup(pow(2.0, 12.0));
    
    width = ofGetWindowWidth();
    height = ofGetWindowHeight();
    
    myImage.allocate(ofGetWidth(), ofGetHeight(),OF_IMAGE_GRAYSCALE);
    
    pixels1 = myImage.getPixels();
    
    s=0;
    fade = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    fft.update();
    myImage.update();
    
    if (fade < 255) {
        fade += 0.001;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    buffer = fft.getBins();
    
    myImage.draw(0, s);

    // グラフに描画
    
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < buffer.size(); i++) {
            float noiseX = ofMap(i, 0, buffer.size(), 0, ofGetWidth());
            float noiseY = ofMap(buffer[i], 0, 1, ofGetHeight(), 0);
            int noiseVal = ofNoise(noiseX, noiseY) * 400;
            pixels1[j * width + i] = noiseVal * fade;
        }
    }
    
    s += 10+40*abs(sin(ofGetElapsedTimef()));
    
    
    if(s > ofGetWindowHeight()){
        s = 0;
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
