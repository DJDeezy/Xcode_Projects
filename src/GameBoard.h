//
//  GameBoard.h
//  Connect4
//
//  Created by Diego Jimenez on 4/30/15.
//
//

#ifndef Connect4_GameBoard_h
#define Connect4_GameBoard_h

#include "GamePieceSet.h"
#include <vector>


//
//--------------------------------------------------------------
//**************************************************************
// GameBoard Class Notes
//**************************************************************
//--------------------------------------------------------------
//
//  Parent class: GamePiece
//    - inherits x & y coordinates from GamePiece class
//
//  Ctor: Takes 3 float arguments
//    - x-Coordinate : inherited from parent (left edge of board)
//    - y-Coordinate : inherited from parent (top of board)
//    - xEnd-Coordinate (right edge of board)
//
//  Display:
//    To display GameBoard call showObj()
//
//--------------------------------------------------------------
//

class GameBoard: public GamePiece {
private:
  // Coordinates
  float m_XEnd;
  float m_YEnd;
  
  // Attributes
  float m_PieceSize;
  GamePieceSet m_PieceSet;  // game pieces
  
  ofColor m_Color;
  
  // Piece positions
  vector<ofPoint> m_Positions;
  
  vector<string> m_Spaces;
  
  vector<int> m_Indecies;
  
  // setters
  void setXEnd(const float &);
  void setYEnd();
  void setPieceSize();
  void initializePositions();
  void initializeSpaces();
  
public:
  // ctor
  GameBoard(const float & = 0, const float & = 0, const float & = 800);
  
  // reset
  void reset();
  
  // resize
  void resize(const float &);
  
  // getters
  float getXEnd() const { return m_XEnd; }
  float getYEnd() const { return m_YEnd; }
  float getWidth() const { return getXEnd()-getX(); }
  float getHeight() const { return (float)getYEnd()-getY(); }
  float getMidPointX() const { return getX()+getWidth()/2.0; }
  float getMidPointY() const { return getY()+getHeight()/2.0; }
  float getPieceSize() const { return m_PieceSize; }
  float getPieceRadius() const { return m_PieceSize/4; }
  vector<ofPoint> getPositions() const { return m_Positions; }
  vector<string> getSpaces() const { return m_Spaces; }
  
  bool player1Turn() const { return m_PieceSet.player1Turn(); }
  
  // display
  virtual void showObj();
  void showPieces();
  
  // actions
  bool placePiece(const float &, const float &);
};


#endif
