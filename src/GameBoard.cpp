//
//  GameBoard.cpp
//  Connect4
//
//  Created by Diego Jimenez on 4/30/15.
//
//

#include "GameBoard.h"


//
//--------------------------------------------------------------
// Ctor
//--------------------------------------------------------------
//

GameBoard::GameBoard(const float &a_X, const float &a_Y, const float &a_XEnd) {
  
  setX(a_X);  // set left edge
  setY(a_Y);  // set top edge
  
  setXEnd(a_XEnd);  // set right edge
  setYEnd();  // set bottom edge
  
  // set board piece size
  m_Positions.resize(42);
  
  // set piece radius
  setPieceSize();
  
  m_PieceSet.setRadius(getPieceSize());
  
  initializePositions();
  initializeSpaces();
}

//
//--------------------------------------------------------------
// Setters
//--------------------------------------------------------------
//

void GameBoard::reset() {
  m_PieceSet.reset();
  initializeSpaces();
}

//
//--------------------------------------------------------------
// Setters
//--------------------------------------------------------------
//

void GameBoard::setXEnd(const float &xEnd) {
  m_XEnd = (xEnd > getX()) ? xEnd : getX()+800;
}

void GameBoard::setYEnd() {
  m_YEnd = getY()+(25.0*getWidth()/32.0);
}

void GameBoard::setPieceSize() {
  m_PieceSize = ((getWidth()-(getWidth()/8))/7);
}

//
//--------------------------------------------------------------
// Resize
//--------------------------------------------------------------
//

void GameBoard::resize(const float &w) {
  setX(w/8);
  setY(w/4);
  
  setXEnd(w);
  setYEnd();
  setPieceSize();
  initializePositions();
  
  m_PieceSet.resize(getPositions(), getSpaces(), getPieceRadius());
}

//
//--------------------------------------------------------------
// Initialize Points
//--------------------------------------------------------------
//

void GameBoard::initializePositions() {
  for(int i = 0; i < 42; i += 7) {
    
    //
    //--------------------------------------------------------------
    // X-coordinates
    //--------------------------------------------------------------
    //
    
    m_Positions[i+3].x = getX()+(getWidth()/2);  // middle
    //  left side
    m_Positions[i+2].x = m_Positions[i+3].x-(m_PieceSize+m_PieceSize/16); // middle-1
    m_Positions[i+1].x = m_Positions[i+2].x-(m_Positions[i+3].x-m_Positions[i+2].x);  // middle-2
    m_Positions[i].x = m_Positions[i+1].x-(m_Positions[i+3].x-m_Positions[i+2].x);  // left-most side
    // rigt side
    m_Positions[i+4].x = m_Positions[i+3].x+(m_Positions[i+3].x-m_Positions[i+2].x);  // middle+1
    m_Positions[i+5].x = m_Positions[i+4].x+(m_Positions[i+3].x-m_Positions[i+2].x);  // middle+2
    m_Positions[i+6].x = m_Positions[i+5].x+(m_Positions[i+3].x-m_Positions[i+2].x);  // rigt-most side
    
    
    //
    //--------------------------------------------------------------
    // Y-coordinates
    //--------------------------------------------------------------
    //
    
    if(i == 0) {
      m_Positions[i].y = getY()+(getPieceSize()/2)+getPieceSize()/8;
      m_Positions[i+1].y = getY()+(getPieceSize()/2)+getPieceSize()/8;
      m_Positions[i+2].y = getY()+(getPieceSize()/2)+getPieceSize()/8;
      m_Positions[i+3].y = getY()+(getPieceSize()/2)+getPieceSize()/8;
      m_Positions[i+4].y = getY()+(getPieceSize()/2)+getPieceSize()/8;
      m_Positions[i+5].y = getY()+(getPieceSize()/2)+getPieceSize()/8;
      m_Positions[i+6].y = getY()+(getPieceSize()/2)+getPieceSize()/8;
    }
    else {
      m_Positions[i].y = m_Positions[0].y+(i/7)*getPieceSize();
      m_Positions[i+1].y = m_Positions[0].y+(i/7)*getPieceSize();
      m_Positions[i+2].y = m_Positions[0].y+(i/7)*getPieceSize();
      m_Positions[i+3].y = m_Positions[0].y+(i/7)*getPieceSize();
      m_Positions[i+4].y = m_Positions[0].y+(i/7)*getPieceSize();
      m_Positions[i+5].y = m_Positions[0].y+(i/7)*getPieceSize();
      m_Positions[i+6].y = m_Positions[0].y+(i/7)*getPieceSize();
    }
  }
}

//
//--------------------------------------------------------------
// Initialize Spaces
//--------------------------------------------------------------
//

void GameBoard::initializeSpaces() {
  m_Spaces.resize(42);
  for(int i = 0; i < m_Spaces.size(); i++)
    m_Spaces[i] = "";
  
  m_Indecies.resize(7);
  for(int i = 0; i < m_Indecies.size(); i++)
    m_Indecies[i] = 5;
}

//
//--------------------------------------------------------------
// Display Object
//--------------------------------------------------------------
//

void GameBoard::showObj() {
  ofSetColor(255);  // white color
  ofRect(getX(), getY(), getWidth(), getHeight());  // draw background
  
  //
  //--------------------------------------------------------------
  // Draw Board Depth
  //--------------------------------------------------------------
  //
  
  ofSetColor(255, 230, 0);  // light yellow
  
  ofTriangle(getX(), getY(), getX()+getWidth()/32, getY()-getHeight()/32, getX()+getWidth()/32, getY()+getHeight()/32);
  ofRect(getX()+getWidth()/32, getY()-getHeight()/32, getWidth(), getHeight());
  
  ofSetColor(255, 160, 0);  // dark yellow
  
  ofTriangle(getX()+getWidth()/64, getY(), getX()+getWidth()/32+getWidth()/64, getY()-getHeight()/32, getXEnd()-getWidth()/32, getY()-getHeight()/32);
  //ofTriangle(getX()+getWidth()/32, getY(), getX()+getWidth()/16, getY()-getHeight()/32, getXEnd()-getWidth()/32, getY()-getHeight()/32);
  ofRect(getX()+getWidth()/16, getY()-getHeight()/32, getWidth()-getWidth()/16, getHeight());
  //ofTriangle(getXEnd(), getYEnd(), getXEnd()+getWidth()/32, getYEnd()-getHeight()/32, getXEnd(), getY());
  
  ofSetColor(255, 184, 0);  // yellow
  
  ofRect(getX()+getWidth()/32+getWidth()/64, getY()-getHeight()/32, getWidth()-getWidth()/64, getHeight());
  //ofRect(getX()+getWidth()/16, getY()-getHeight()/32, getWidth()-getWidth()/32, getHeight());
  ofTriangle(getXEnd(), getYEnd(), getXEnd()+getWidth()/32, getYEnd()-getHeight()/32, getXEnd(), getY());
  
  ofSetColor(255, 230, 0);  // light yellow
  
  ofTriangle(getXEnd(), getY(), getXEnd()+getWidth()/32, getY()-getHeight()/32, getXEnd()+getWidth()/64, getY()-getHeight()/32);
  ofTriangle(getXEnd()+getWidth()/64, getY()-getHeight()/32, getXEnd()-getWidth()/64, getY(), getXEnd(), getY());
  
  //ofTriangle(getXEnd(), getY(), getXEnd()+getWidth()/32, getY()-getHeight()/32, getXEnd(), getY()-getHeight()/32);
  //ofTriangle(getXEnd(), getY()-getHeight()/32, getXEnd()-getWidth()/32, getY(), getXEnd(), getY());
  
  //
  //--------------------------------------------------------------
  // Top Edges
  //--------------------------------------------------------------
  //
  
  for(int i = 0; i < 6; i++) {
    ofSetColor(255, 160, 0);  // dark yellow
    
    ofTriangle((m_Positions[i].x+m_Positions[i+1].x)/2, getY(), (m_Positions[i].x+m_Positions[i+1].x)/2+getWidth()/32-getWidth()/256, getY()-getHeight()/32, (m_Positions[i].x+m_Positions[i+1].x)/2+getWidth()/32-getWidth()/256, getY());
    
    ofSetColor(255, 230, 0);  // light yellow
    
    ofTriangle((m_Positions[i].x+m_Positions[i+1].x)/2-getWidth()/256, getY(), (m_Positions[i].x+m_Positions[i+1].x)/2+getWidth()/256, getY(), (m_Positions[i].x+m_Positions[i+1].x)/2+getWidth()/32+getWidth()/256, getY()-getHeight()/32);
    ofTriangle((m_Positions[i].x+m_Positions[i+1].x)/2+getWidth()/32-getWidth()/256, getY()-getHeight()/32, (m_Positions[i].x+m_Positions[i+1].x)/2+getWidth()/32+getWidth()/256, getY()-getHeight()/32, (m_Positions[i].x+m_Positions[i+1].x)/2-getWidth()/256, getY());
  }
  
  ofRect(getX()+getWidth()/32, getY()-getHeight()/32, getWidth()-getWidth()/128, getHeight()/128);
  
  //
  //--------------------------------------------------------------
  // Draw Board Spaces Backdrop
  //--------------------------------------------------------------
  //
  
  for(int i = 0; i < m_Positions.size(); i++) {
    ofSetColor(80);  // grey color
    ofCircle(m_Positions[i].x, m_Positions[i].y, m_PieceSize/2);
    //ofSetColor(0, 100);  // black color
    ofSetColor(255, 140, 0);
    // draw piece locations
    ofCircle(m_Positions[i].x, m_Positions[i].y, m_PieceSize/2);
    ofSetColor(80);  // grey color
    ofCircle(m_Positions[i].x+m_PieceSize/32, m_Positions[i].y+m_PieceSize/32, (m_PieceSize/2)-(m_PieceSize/32));
  }
  
  showPieces();
  
  ofSetColor(255, 230, 0);  // light yellow
  
  ofRect(getX()+getWidth()/128, getY()-getHeight()/128, getWidth()-getWidth()/128, getHeight()/128);
  
  glLineWidth(getPieceSize()/4);
  //ofSetColor(255);
  
  ofSetColor(255, 210, 0);  // bright yellow
  
  //
  //--------------------------------------------------------------
  // Fill Board Perimeter
  //--------------------------------------------------------------
  //
  
  // Top
  ofRect(getX(), getY(), getWidth(), getHeight()/42);
  // Bottom
  ofRect(getX(), getYEnd()-getHeight()/42, getWidth(), getHeight()/42);
  // Left
  ofRect(getX(), getY(), getWidth()/24, getHeight());
  // Right
  ofRect(getXEnd()-getWidth()/24, getY(), getWidth()/24, getHeight());
  
  for(int i = 0; i < 42; i += 7) {
    if(i < 35) {
      // Left Triangles
      ofTriangle(getX(), m_Positions[i].y+getHeight()/128, getX()+getWidth()/12, (m_Positions[i].y+m_Positions[i+7].y)/2, getX(), m_Positions[i+7].y-getHeight()/128);
      // Right Triangles
      ofTriangle(getXEnd(), m_Positions[i+6].y+getHeight()/128, getXEnd()-getWidth()/12, (m_Positions[i+6].y+m_Positions[i+13].y)/2, getXEnd(), m_Positions[i+13].y-getHeight()/128);
    }
    // Top Triangles
    ofTriangle(m_Positions[i/7].x+getWidth()/128, getY(), m_Positions[i/7+1].x-getWidth()/128, getY(), (m_Positions[i/7].x+m_Positions[i/7+1].x)/2, getY()+getHeight()/12);
    // Bottom Triangles
    ofTriangle(m_Positions[i/7].x+getWidth()/128, getYEnd(), m_Positions[i/7+1].x-getWidth()/128, getYEnd(), (m_Positions[i/7].x+m_Positions[i/7+1].x)/2, getYEnd()-getHeight()/12);
  }
  
  ofTriangle(getX(), getY(), m_Positions[0].x, getY(), getX(), m_Positions[0].y);
  ofTriangle(getXEnd(), getY(), m_Positions[6].x, getY(), getXEnd(), m_Positions[6].y);
  ofTriangle(getX(), getYEnd(), m_Positions[35].x, getYEnd(), getX(), m_Positions[35].y);
  ofTriangle(getXEnd(), getYEnd(), m_Positions[41].x, getYEnd(), getXEnd(), m_Positions[41].y);
  
  for(int i = 0; i < m_Positions.size(); i++) {
    
    //
    //--------------------------------------------------------------
    // Fill Board Space Between Circles
    //--------------------------------------------------------------
    //
    
    ofFill();
    ofSetColor(255, 210, 0);  // bright yellow
    
    if(i%7 >= 0 && i%7 < 6 && i < 35) {
      ofSetRectMode(OF_RECTMODE_CENTER);
      ofPushMatrix();
      ofTranslate((m_Positions[i].x+m_Positions[i+1].x)/2, (m_Positions[i].y+m_Positions[i+7].y)/2);
      ofRotateZ(45);
      ofRect(0/*(m_Positions[i].x+m_Positions[i+1].x)/2*/, 0/*(m_Positions[i].y+m_Positions[i+7].y)/2*/, m_PieceSize/2, m_PieceSize/2);
      ofPopMatrix();
      ofSetRectMode(OF_RECTMODE_CORNER);
    }
    
    //
    //--------------------------------------------------------------
    // Circle Rims Shadows
    //--------------------------------------------------------------
    //
    
    ofNoFill();
    glLineWidth(getPieceSize()/4);
    ofSetColor(0, 40);
    ofCircle(m_Positions[i].x+m_PieceSize/24, m_Positions[i].y+m_PieceSize/24, 31*m_PieceSize/64);
    
    ofSetColor(255, 180, 0);  // orange
    ofCircle(m_Positions[i].x, m_Positions[i].y, m_PieceSize/2);
  }
  
  //
  //--------------------------------------------------------------
  // Circle Rims Hightlights
  //--------------------------------------------------------------
  //
  
  glLineWidth(getPieceSize()/20);
  ofSetColor(255, 210, 0);
  
  for(int i = 0; i < m_Positions.size(); i++) {
    ofCircle(m_Positions[i].x, m_Positions[i].y, m_PieceSize/2);
  }
  
  ofFill(); // restore fill
  
  //glLineWidth(1);
  
}

void GameBoard::showPieces() {
  m_PieceSet.showCreatedPieces();
}

//
//--------------------------------------------------------------
// Actions
//--------------------------------------------------------------
//

bool GameBoard::placePiece(const float &x, const float &y) {
  vector<ofPoint> coordinates = getPositions();
  
  if(x > getX() && x < m_XEnd && y > getY() && y < m_YEnd) {
    if(x > coordinates[0].x-getPieceSize()/2 && x < coordinates[0].x+getPieceSize()/2) {
      if(m_Indecies[0] == -1) return false;
      m_PieceSet.placePiece(coordinates[0+(7*m_Indecies[0])], getY()-getPieceSize());
      
      if(m_PieceSet.player2Turn())
        m_Spaces[7*m_Indecies[0]] = "Red";
      else
        m_Spaces[7*m_Indecies[0]] = "Blue";
      
      m_Indecies[0]--;
      return true;
    }
    else if(x > coordinates[1].x-getPieceSize()/2 && x < coordinates[1].x+getPieceSize()/2) {
      if(m_Indecies[1] == -1) return false;
      m_PieceSet.placePiece(coordinates[1+(7*m_Indecies[1])], getY()-getPieceSize());
      
      if(m_PieceSet.player2Turn())
        m_Spaces[1+7*m_Indecies[1]] = "Red";
      else
        m_Spaces[1+7*m_Indecies[1]] = "Blue";
      
      m_Indecies[1]--;
      return true;
    }
    else if(x > coordinates[2].x-getPieceSize()/2 && x < coordinates[2].x+getPieceSize()/2) {
      if(m_Indecies[2] == -1) return false;
      m_PieceSet.placePiece(coordinates[2+(7*m_Indecies[2])], getY()-getPieceSize());
      
      if(m_PieceSet.player2Turn())
        m_Spaces[2+7*m_Indecies[2]] = "Red";
      else
        m_Spaces[2+7*m_Indecies[2]] = "Blue";
      
      m_Indecies[2]--;
      return true;
    }
    else if(x > coordinates[3].x-getPieceSize()/2 && x < coordinates[3].x+getPieceSize()/2) {
      if(m_Indecies[3] == -1) return false;
      m_PieceSet.placePiece(coordinates[3+(7*m_Indecies[3])], getY()-getPieceSize());
      
      if(m_PieceSet.player2Turn())
        m_Spaces[3+7*m_Indecies[3]] = "Red";
      else
        m_Spaces[3+7*m_Indecies[3]] = "Blue";
      
      m_Indecies[3]--;
      return true;
    }
    else if(x > coordinates[4].x-getPieceSize()/2 && x < coordinates[4].x+getPieceSize()/2) {
      if(m_Indecies[4] == -1) return false;
      m_PieceSet.placePiece(coordinates[4+(7*m_Indecies[4])], getY()-getPieceSize());
      
      if(m_PieceSet.player2Turn())
        m_Spaces[4+7*m_Indecies[4]] = "Red";
      else
        m_Spaces[4+7*m_Indecies[4]] = "Blue";
      
      m_Indecies[4]--;
      return true;
    }
    else if(x > coordinates[5].x-getPieceSize()/2 && x < coordinates[5].x+getPieceSize()/2) {
      if(m_Indecies[5] == -1) return false;
      m_PieceSet.placePiece(coordinates[5+(7*m_Indecies[5])], getY()-getPieceSize());
      
      if(m_PieceSet.player2Turn())
        m_Spaces[5+7*m_Indecies[5]] = "Red";
      else
        m_Spaces[5+7*m_Indecies[5]] = "Blue";
      
      m_Indecies[5]--;
      return true;
    }
    else if(x > coordinates[6].x-getPieceSize()/2 && x < coordinates[6].x+getPieceSize()/2) {
      if(m_Indecies[6] == -1) return false;
      m_PieceSet.placePiece(coordinates[6+(7*m_Indecies[6])], getY()-getPieceSize());
      
      if(m_PieceSet.player2Turn())
        m_Spaces[6+7*m_Indecies[6]] = "Red";
      else
        m_Spaces[6+7*m_Indecies[6]] = "Blue";
      
      m_Indecies[6]--;
      return true;
    }
    else
      return  false;
  }
  return false;
}

