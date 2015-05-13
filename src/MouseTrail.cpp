//
//  MouseTrail.cpp
//  Connect4
//
//  Created by Diego Jimenez on 5/2/15.
//
//

#include "MouseTrail.h"


//
//--------------------------------------------------------------
// Ctor
//--------------------------------------------------------------
//

MouseTrail::MouseTrail(const int &length, const float &width) {
  initializePoints(length);
  m_Length = m_Points.size();
  m_Width = (width > 0) ? width : 12;
}

//
//--------------------------------------------------------------
// Setters
//--------------------------------------------------------------
//

void MouseTrail::initializePoints(const int &l) {
  if(l > 0)
    m_Points.resize(l);
  else
    m_Points.resize(1);
  
  m_Points[0].x = ofGetMouseX();
  m_Points[0].y = ofGetMouseY();
}

void MouseTrail::updateTracking() {
  for(int i = getLength()-1; i > 0; i--) {
    m_Points[i].x = m_Points[i-1].x;
    m_Points[i].y = m_Points[i-1].y;
  }
  m_Points[0].x = ofGetMouseX();
  m_Points[0].y = ofGetMouseY();
}

void MouseTrail::trail(const ofColor &color) const {
  ofSetColor(color);
  for(int i = 0; i < getLength()-1; i++) {
    glLineWidth(getWidth()/(i+1));
    ofLine(m_Points[i].x, m_Points[i].y, m_Points[i+1].x, m_Points[i+1].y);
  }
  ofCircle(m_Points[0].x, m_Points[0].y, getWidth()*0.7);
}