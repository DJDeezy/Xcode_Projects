//
//  BluePiece.cpp
//  Connect4
//
//  Created by Diego Jimenez on 4/29/15.
//
//

#include "BluePiece.h"


// set constant members
const string BluePiece::m_Name = "Blue";
const ofColor BluePiece::m_MainColor = ofColor(40, 60, 255);
const ofColor BluePiece::m_SecondaryColor = ofColor(10, 30, 160);
int BluePiece::m_PiecesOnBoard = 0;

//
//--------------------------------------------------------------
// Ctor
//--------------------------------------------------------------
//

BluePiece::BluePiece(const float &a_X, const float &a_Y, const float &a_R) {
  setPosition(a_X, a_Y);
  setRadius(a_R);
  m_PiecesOnBoard++;
  
  m_Number = piecesOnBoard();
  
  m_Start = m_End = 0;  // used in dropDown function
  
  m_Shown = false;  // not visible
  m_Dropped = false; // has not been dropped
  m_Dropping = false; // is not dropping
  m_Resized = false; // has not been resized
}

//
//--------------------------------------------------------------
// Copy Ctor
//--------------------------------------------------------------
//

BluePiece::BluePiece(const BluePiece &original) {
  setPosition(original.getX(), original.getY());
  setRadius(original.getRadius());
  m_PiecesOnBoard = original.piecesOnBoard();
  
  m_Number = original.getNumber();
  
  m_Start = original.m_Start;
  m_End  = original.m_End;
  
  m_Shown = original.m_Shown;
  m_Dropped = original.dropped();
  m_Dropping = original.dropping();
  m_Resized = original.resized();
}

//
//--------------------------------------------------------------
// Setters
//--------------------------------------------------------------
//

void BluePiece::setPosition(const float &x, const float &y) {
  (x > -getRadius()) ? setX(x) : setX(getDiameter());
  (y > -getRadius()) ? setY(y) : setY(getDiameter());
}

void BluePiece::setRadius(const float &r) {
  m_Radius = (r > 0) ? r : 20;
}

//
//--------------------------------------------------------------
// Resize
//--------------------------------------------------------------
//

void BluePiece::resize(const float &x, const float &y, const float &r) {
  float xOffset, yOffset;
  setPosition(x, y);
  setRadius(r);
  m_Resized = true;  // set resized boolean
}

//
//--------------------------------------------------------------
// Display
//--------------------------------------------------------------
//

void BluePiece::show() {
  m_Shown = true;
}

void BluePiece::showObj() {
  if(shown()) {
    ofColor lineColor(40, 80); // dark gray line color
    ofColor centerColor(40, 70); // gray overlay color
    
    //
    //--------------------------------------------------------------
    // Animate
    //--------------------------------------------------------------
    //
    
    dropDown();
    
    //
    //--------------------------------------------------------------
    // Outer Circle
    //--------------------------------------------------------------
    //
    
    // Set line width
    glLineWidth((1.0/30.0)*getDiameter());
    // Set main color
    ofSetColor(getColor());
    ofCircle(getX(), getY(), getDiameter());  // outer rim of piece
    
    //
    //--------------------------------------------------------------
    // Lines
    //--------------------------------------------------------------
    //
    
    glLineWidth(1.0/20.0*getDiameter());
    ofSetColor(lineColor); // set current color to shadow color
    
    // 0
    ofLine(getX()+getDiameter(), getY(), getX()-getDiameter(), getY());
    // PI/12
    ofLine(getX()+(getDiameter()*cos(PI/12)), getY()-(getDiameter()*sin(PI/12)), getX()+(getDiameter()*cos(13*PI/12)), getY()-(getDiameter()*sin(13*PI/12)));
    // 2*PI/12
    ofLine(getX()+(getDiameter()*cos(2*PI/12)), getY()-(getDiameter()*sin(2*PI/12)), getX()+(getDiameter()*cos(14*PI/12)), getY()-(getDiameter()*sin(14*PI/12)));
    // 3*PI/12
    ofLine(getX()+(getDiameter()*cos(3*PI/12)), getY()-(getDiameter()*sin(3*PI/12)), getX()+(getDiameter()*cos(15*PI/12)), getY()-(getDiameter()*sin(15*PI/12)));
    // 4*PI/12
    ofLine(getX()+(getDiameter()*cos(4*PI/12)), getY()-(getDiameter()*sin(4*PI/12)), getX()+(getDiameter()*cos(16*PI/12)), getY()-(getDiameter()*sin(16*PI/12)));
    // 5*PI/12
    ofLine(getX()+(getDiameter()*cos(5*PI/12)), getY()-(getDiameter()*sin(5*PI/12)), getX()+(getDiameter()*cos(17*PI/12)), getY()-(getDiameter()*sin(17*PI/12)));
    // 6*PI/12
    ofLine(getX(), getY()-getDiameter(), getX(), getY()+getDiameter());
    // 7*PI/12
    ofLine(getX()+(getDiameter()*cos(7*PI/12)), getY()-(getDiameter()*sin(7*PI/12)), getX()+(getDiameter()*cos(19*PI/12)), getY()-(getDiameter()*sin(19*PI/12)));
    // 8*PI/12
    ofLine(getX()+(getDiameter()*cos(8*PI/12)), getY()-(getDiameter()*sin(8*PI/12)), getX()+(getDiameter()*cos(20*PI/12)), getY()-(getDiameter()*sin(20*PI/12)));
    // 9*PI/12
    ofLine(getX()+(getDiameter()*cos(9*PI/12)), getY()-(getDiameter()*sin(9*PI/12)), getX()+(getDiameter()*cos(21*PI/12)), getY()-(getDiameter()*sin(21*PI/12)));
    // 10*PI/12
    ofLine(getX()+(getDiameter()*cos(10*PI/12)), getY()-(getDiameter()*sin(10*PI/12)), getX()+(getDiameter()*cos(22*PI/12)), getY()-(getDiameter()*sin(22*PI/12)));
    // 11*PI/12
    ofLine(getX()+(getDiameter()*cos(11*PI/12)), getY()-(getDiameter()*sin(11*PI/12)), getX()+(getDiameter()*cos(23*PI/12)), getY()-(getDiameter()*sin(23*PI/12)));
    
    //
    //--------------------------------------------------------------
    // Inner Circle
    //--------------------------------------------------------------
    //
    
    //
    //  Cutout center lines
    //
    
    // Cover inner lines
    ofSetColor(getColor()); // set main color
    ofCircle(getX(), getY(), getDiameter()-(0.7/3.0*getDiameter()));
    
    //
    //  Place inner shadow
    //
    
    // Darker center of piece
    ofSetColor(getSecondaryColor());  // inner shadow color
    ofCircle(getX(), getY(), getDiameter()-(0.35*getDiameter()));
    
    //
    // Place inner highlights
    //
    
    // Darker center of piece
    ofSetColor(getColor(), 80); // Set center color
    ofCircle(getX()+(0.35*getDiameter())/7, getY()+(0.35*getDiameter())/7, getDiameter()-(0.35*getDiameter())-(0.35*getDiameter())/7);
    
    //
    //--------------------------------------------------------------
    // 4 Emblem
    //--------------------------------------------------------------
    //
    
    // Emblem stroke width
    float emblemStroke = (1.0/20.0*getDiameter());
    
    float VerticalX = getX()+(2.0/30.0*getDiameter());
    float VerticalY1 = getY()-(1.25/3.0*getDiameter());
    float VerticalY2 = getY()+(1.25/3.0*getDiameter());
    float HorizontalX1 = getX()-(1.25/3.0*getDiameter());
    float HorizontalX2 = getX()+(0.2*getDiameter());
    float HorizontalY = getY()+(1.0/30.0*getDiameter());
    
    
    ofSetColor(getSecondaryColor());
    glLineWidth(emblemStroke*2); // thick line
    
    //
    //  Shadow
    //
    
    // Points
    ofCircle(VerticalX+(1.0/20.0*getDiameter()), VerticalY1+(1.0/20.0*getDiameter()), emblemStroke);
    ofCircle(HorizontalX1+(1.0/20.0*getDiameter()), HorizontalY+(1.0/20.0*getDiameter()), emblemStroke);
    ofCircle(HorizontalX2+(1.0/20.0*getDiameter()), HorizontalY+(1.0/20.0*getDiameter()), emblemStroke);
    ofCircle(VerticalX+(1.0/20.0*getDiameter()), VerticalY2+(1.0/20.0*getDiameter()), emblemStroke);
    
    // Lines
    ofLine(VerticalX+(1.0/20.0*getDiameter()), VerticalY1+(1.0/20.0*getDiameter()), VerticalX+(1.0/20.0*getDiameter()), VerticalY2+(1.0/20.0*getDiameter()));
    ofLine(VerticalX+(1.0/20.0*getDiameter()), VerticalY1+(1.0/20.0*getDiameter()), HorizontalX1+(1.0/20.0*getDiameter()), HorizontalY+(1.0/20.0*getDiameter()));
    ofLine(HorizontalX1+(1.0/20.0*getDiameter()), HorizontalY+(1.0/20.0*getDiameter()), HorizontalX2+(1.0/20.0*getDiameter()), HorizontalY+(1.0/20.0*getDiameter()));
    
    //
    //  Hightlight
    //
    
    ofSetColor(getColor()); // set main color
    
    // Points
    ofCircle(VerticalX, VerticalY1, emblemStroke);
    ofCircle(HorizontalX1, HorizontalY, emblemStroke);
    ofCircle(HorizontalX2, HorizontalY, emblemStroke);
    ofCircle(VerticalX, VerticalY2, emblemStroke);
    
    // Lines
    ofLine(VerticalX, VerticalY1, VerticalX, VerticalY2);
    ofLine(VerticalX, VerticalY1, HorizontalX1, HorizontalY);
    ofLine(HorizontalX1, HorizontalY, HorizontalX2, HorizontalY);
  }
}

//
//--------------------------------------------------------------
// Actions
//--------------------------------------------------------------
//

void BluePiece::drop(const float &start, const float &end, const float &rate) {
  m_Dropping = true;
  show();
  dropDown(start, end, rate);
}

bool BluePiece::dropDown(const float &yStart, const float &yEnd, const float &rate) {
  static float inc = (abs(rate) >= 1) ? abs(rate) : 3*getRadius()/8;
  if(inc != 3*getRadius()/8)
    inc = 3*getRadius()/8;
  
  if(yStart != yEnd && dropping()) {
    m_Start = yStart;
    m_End = yEnd;
    setY(m_Start);
  }
  else if(resized()) {
    m_End = getY();
  }
  else if(dropping() && !dropped()) {
    setY(getY()+inc);
    if(getY() >= m_End) {
      setY(m_End);
      m_Dropping = false;
      m_Dropped = true;
    }
  }
  return dropped();
}
