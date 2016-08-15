#include "ofApp.h"
//
//#define CAMX 1280
//#define CAMY 720

int CAMX = 0;
int CAMY = 0;
int dither_type = 0;


int x_r = 4;
int y_r = 4;

string filen = "/Users/a/Documents/Reeds_at_the_Swan_Lake_Nature_Study_Area.jpg";
//--------------------------------------------------------------
void ofApp::setup(){
    //cam.setup(CAMX, CAMY);
    res.allocate(CAMX, CAMY, OF_IMAGE_COLOR);
    
    //img.load("/Users/a/Pictures/inspires/Untitled-3.png");
    res.load(filen);
    res.update();
    CAMX = res.getWidth();
    CAMY = res.getHeight();

    //res_pix = res.getPixels();
}

int quantize(const size_t bits_to_del, unsigned char in) {
    return (in < 127) ? 255 : 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    //cam.update();
    res.getPixelsRef().resize(CAMX/x_r,CAMY/y_r, OF_INTERPOLATE_NEAREST_NEIGHBOR);
    res.update();

    if(true) {
        if(dither_type == 0) {
            dither.dither_ordered(res, res, 8);
            res.getPixelsRef().resize(CAMX,CAMY,OF_INTERPOLATE_NEAREST_NEIGHBOR);
            res.update();
        } else if (dither_type == 1) {
            dither.dither_floyd_steinberg(res, res);
            res.getPixelsRef().resize(CAMX,CAMY,OF_INTERPOLATE_NEAREST_NEIGHBOR);
            res.update();
            //res.getPixelsRef().resize(CAMX*8,CAMY*8,OF_INTERPOLATE_NEAREST_NEIGHBOR);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float h = ofGetHeight();
    float w = CAMX * (h/CAMY);
    
    res.draw(0, 0, w, h);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '0') {
        res.load(filen);
        res.update();

        dither_type = 0;
        ofLog() << "floyd!" << std::endl;
    } else if (key == '1') {
        res.load(filen);
        res.update();

        dither_type = 1;
        ofLog() << "floyd!" << std::endl;
    } else if (key == 's') {
        res.save("result_" + ofGetTimestampString() + ".png");
    }

    res.load(filen);

    if(key == OF_KEY_UP) {
        y_r++;
    } else if (key == OF_KEY_DOWN) {
        y_r--;
    } else if (key == OF_KEY_LEFT) {
        x_r--;
    } else if (key == OF_KEY_RIGHT) {
        x_r++;
    }
    
    x_r = ofClamp(x_r, 1, 100);
    y_r = ofClamp(y_r, 1, 100);
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
