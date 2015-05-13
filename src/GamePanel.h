//
//  GamePanel.h
//  Connekt4
//
//  Created by Ajay Kumar on 5/7/15.
//
//

#ifndef __Connekt4__GamePanel__
#define __Connekt4__GamePanel__

#include "GamePiece.h"
#include "RedPiece.h"
#include "BluePiece.h"


class GamePanel:public GamePiece {
  float width;
  float height;
  int multiple;
  
public:
  GamePanel (const float &, const float &, const float &, const int &);
  
  // Bool
  bool player1Turn;
  
  // Setters
  void setWidth(const float &);
  void setHeight();
  void resize(float);
  void backgroundUpdate();
  void intializeBackground();
  
  // Getters
  float getWidth() { return width; }
  float getHeight() { return height; }
  virtual void showObj();
};

#endif
