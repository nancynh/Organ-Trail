//
//  main.cpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//
#include "ofMain.h"
#include "ofApp.h"

#define DISPLAY_MODE OF_WINDOW

int main() {
    ofSetupOpenGL(1000, 1000, OF_WINDOW);
    ofSetFrameRate(30);
    
    ofRunApp(new ofApp()); 
}
