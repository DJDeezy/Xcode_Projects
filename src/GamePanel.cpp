//
//  GamePanel.cpp
//  Connekt4
//
//  Created by Ajay Kumar on 5/7/15.
//
//

#include "GamePanel.h"

unsigned long last;
int counter;
ofColor col;
ofColor col2;
ofColor col3;
ofColor col4;

GamePanel::GamePanel (const float &x, const float &y, const float &width, const int &m) {
  if (x >= 0) {
    setX(x);
  }
  else {
    setX(0);
  }
  
  if (y >= 0) {
    setY(y);
  }
  else {
    setY(0);
  }
  
  if (m > 0) {
    multiple = m;
  }
  else {
    multiple = 4;
  }
  setWidth(width);
  setHeight();
  
  player1Turn = true;
}

void GamePanel::setWidth(const float &w) {
  if (w > 0) {
    width = w;
  }
  else {
    width = 100;
  }
}

void GamePanel::resize(float w) {
  setWidth(w);
  setHeight();
}

void GamePanel::setHeight() {
  height = (25 * getWidth() ) / 32;
}

void GamePanel::backgroundUpdate() {
  if(ofGetElapsedTimeMillis() - last > 50) {
    
    col.setHue(counter % 256);
    col2.setHue((counter + 60) % 256);
    col3.setHue((counter + 120) % 256);
    col4.setHue((counter + 180) % 256);
    counter += 1;
    last = ofGetElapsedTimeMillis();
  }
}

void GamePanel::intializeBackground() {
  last = ofGetElapsedTimeMillis();
  col.setHsb(0,255,255);
  col2.setHsb(0,255,255);
  col3.setHsb(0,255,255);
  col4.setHsb(0,255,255);
  counter = 0;
}

void GamePanel::showObj() {
  
  ofColor c1(160);
  ofColor c2(30);
  ofBackgroundGradient(c1, c2);
  
  
  RedPiece redP( getX()+getWidth() * 3 / 4, getY()+getHeight()/(2*multiple), getWidth()/64);
  redP.show();
  redP.showObj();
  
  
  BluePiece blueP(getX()+getWidth()/4, getY()+getHeight()/(2*multiple), getWidth()/64);
  blueP.show();
  blueP.showObj();
  
  //////
  
  if(player1Turn)
    ofSetColor(255,255,0);
  else
    ofSetColor(40, 60, 255);
  
  //Draw Pieces
  ofRectRounded((width*1/4)+(width/20),height/10, width/8,height/16,width/32);
  //ofSetColor(0,0,0);
  //ofDrawBitmapString("Player 1" ,width*1/4+(width/13), height/10+(width/34));
  
  
  //Player 2 Rectangle
  if(!player1Turn)
    ofSetColor(255,255,0);
  else
    ofSetColor(255, 30, 10);
  
  ofRectRounded(redP.getX()-(width/20)-(width/8),height/10, width/8,height/16,width/32);
  //ofSetColor(0,0,0);
  //ofDrawBitmapString("Player 2" ,width*1/2+(width/9), height/10+(width/34));
}