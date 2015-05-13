//
//  GamePiece.h
//  Connect4
//
//  Created by Diego Jimenez on 4/29/15.
//
//

#ifndef Connect4_GamePiece_h
#define Connect4_GamePiece_h

#include "ofApp.h"

class GamePiece {
private:
  ofPoint m_Point;  // x & y coordinate
  
public:
  // ctor
  GamePiece(const float & = 0, const float & = 0);
  
  // setters
  void setX(const float &); // set x coordinate
  void setY(const float &); // set y coordinate
  
  // getters
  float getX() const { return m_Point.x; }
  float getY() const { return m_Point.y; }
  
  // display object
  virtual void showObj() = 0;
};


#endif
