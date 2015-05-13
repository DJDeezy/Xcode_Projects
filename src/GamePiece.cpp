//
//  GamePiece.cpp
//  Connect4
//
//  Created by Diego Jimenez on 4/29/15.
//
//

#include "GamePiece.h"


// ctor
GamePiece::GamePiece(const float &a_X, const float &a_Y) {
  setX(a_X);
  setY(a_Y);
}

// setters
void GamePiece::setX(const float &x) { m_Point.x = x; }
void GamePiece::setY(const float &y) { m_Point.y = y; }
