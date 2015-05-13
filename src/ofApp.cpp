#include "ofApp.h"
#include "GamePiece.h"
#include "RedPiece.h"
#include "BluePiece.h"
#include "GameBoard.h"
#include "GamePieceSet.h"
#include "MouseTrail.h"
#include "GamePanel.h"
#include <vector>

#include <iostream>
using namespace std;


//
//--------------------------------------------------------------
//  Global Variables
//--------------------------------------------------------------
//

float width = 800;  // screen width
float height = 25.0*width/32.0; // screen height
static bool winner = false;

ofColor pointerColor(140, 240, 255, 200); // light blue color

MouseTrail mouseTrail(10, width/80);  // Pointer tailing effect

//Objects

GameBoard board(width/8, height/4, width-width/8);

GamePanel gameP(0, 0, width, 4);


//
//--------------------------------------------------------------
//  Prototypes
//--------------------------------------------------------------
//

bool checkForWin(vector<string>, string);
void ripple(int = 0, int = 4);

//
//--------------------------------------------------------------
//  Setup
//--------------------------------------------------------------
//

void ofApp::setup(){
  ofSetFrameRate(60); // frame-rate
  ofSetCircleResolution(100); // circle resolution
}

//
//--------------------------------------------------------------
//  Update
//--------------------------------------------------------------
//

void ofApp::update(){
  mouseTrail.updateTracking();
  ripple();
  
  if(!winner) {
    vector<string> gamePieceVector = board.getSpaces();
    
    if(checkForWin(gamePieceVector, "Red")) {
      if(!winner) {
        ofSystemAlertDialog("Red Player Won!");
        winner = true;
      }
    }
    else if(checkForWin(gamePieceVector, "Blue")) {
      if(!winner) {
        ofSystemAlertDialog("Blue Player Won!");
        winner = true;
      }
    }
  }
}

//
//--------------------------------------------------------------
//  Draw
//--------------------------------------------------------------
//

void ofApp::draw(){
  ofSetColor(0);
  
  gameP.showObj();
  
  board.showObj();
  
  // Mouse Tracking
  ripple();
  mouseTrail.trail(pointerColor);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if(key == 114) {
    board.reset();
    winner = false;
  }
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
  ripple(1);  // Execute ripple
  
  if(board.placePiece(x, y))
    gameP.player1Turn = !gameP.player1Turn;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
  
  gameP.resize(w);
  board.resize(w-w/8);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//
//--------------------------------------------------------------
//  User Defined Functions
//--------------------------------------------------------------
//


bool checkForWin(vector<string> positions, string input){
  int i = 0;
  
  // loop to check for vertical win
  for(i; i<21; i++){
    if(positions[i] == input && positions[i+7] == input && positions[i+14] == input && positions[i+21] == input)
      return true;
  }
  
  // loop to check for horizontal win
  i=0;
  for(i; i<39; i++){
    if(i%7 == 4)
      i += 2;
    else{
      if(positions[i] == input && positions[i+1] == input && positions[i+2] == input && positions[i+3] == input)
        return true;
    }
  }
  
  // loop to check for l->r diagonal win
  i=0;
  for(i; i<17; i++){
    if(i%7 == 4)
      i += 2;
    else{
      if(positions[i] == input && positions[i+8] == input && positions[i+16] == input && positions[i+24] == input)
        return true;
    }
  }
  
  // loop to check for r->l diagonal win
  i=0;
  for(i; i<20; i++){
    if(i%7 == 0)
      i += 2;
    else{
      if(positions[i] == input && positions[i+6] == input && positions[i+12] == input && positions[i+18] == input)
        return true;
    }
  }
  
  return false;
}

//
// Mouse Ripple Effect
//

void ripple(int i, int inc) {
  
  static bool run = false;
  static float ripple = 0;
  static bool run2 = false;
  static float ripple2 = 0;
  static ofColor color(255, 200); // semi transparent white
  static float x, y, x2, y2;
  
  glLineWidth(3);
  
  // Trigger ripple
  if(i == 1 && ripple == 0) {
    run = true;
    x = ofGetMouseX();  // saves mouseX when clicked
    y = ofGetMouseY();  // saves mouseY when clicked
  }
  // Retrigger ripple
  else if(i == 1 && ripple > 2*inc) {
    run2 = true;
    x2 = ofGetMouseX();  // saves mouseX when clicked
    y2 = ofGetMouseY();  // saves mouseY when clicked
  }
  
  // Draw ripple & increment radius
  if(run) {
    ofSetColor(color, 255-(1.2*ripple));
    ofNoFill(); // remove fill
    ofCircle(x, y, ripple);
    ripple+=inc;
    if(ripple > 200) {
      ripple = 0;
      run = false;
    }
    ofFill(); // restore fill
  }
  
  if(run2) {
    ofSetColor(color, 255-(1.2*ripple2));
    ofNoFill(); // remove fill
    ofCircle(x2, y2, ripple2);
    ripple2+=inc;
    if(ripple2 > 200) {
      ripple2 = 0;
      run2 = false;
    }
    ofFill(); // restore fill
  }
}
