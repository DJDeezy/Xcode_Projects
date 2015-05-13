//
//  RedPiece.h
//  Connect4
//
//  Created by Diego Jimenez on 4/29/15.
//
//

#ifndef Connect4_RedPiece_h
#define Connect4_RedPiece_h

#include "GamePiece.h"
#include "ofMain.h"
#include "ofPath.h"
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;


class RedPiece: public GamePiece {
private:
  // members
  const static string m_Name;
  const static ofColor m_MainColor; // Main color
  const static ofColor m_SecondaryColor;  // Secondary color
  float m_Radius;
  int m_Number;
  static int m_PiecesOnBoard;
  
  float m_Start;  // position to drop from
  float m_End;  // position to end drop
  
  // booleans
  bool m_Shown;
  bool m_Dropped;
  bool m_Dropping;
  bool m_Resized;
  
  // setters
  void setPosition(const float &, const float &);
  void setRadius(const float &);
  
  bool dropDown(const float & = 0, const float & = 0, const float & = 0);
  
public:
  // ctor
  RedPiece(const float & = 0, const float & = 0, const float & = 40);
  
  // copy ctor
  RedPiece(const RedPiece &);
  
  // resize
  void resize(const float &, const float &, const float &);
  
  // getters
  string getName() const { return m_Name; }
  ofColor getColor() const { return m_MainColor; }
  ofColor getSecondaryColor() const { return m_SecondaryColor; }
  float getRadius() const { return m_Radius; }
  float getDiameter() const { return m_Radius*2.0; }
  int getNumber() const { return m_Number; }
  int piecesOnBoard() const { return m_PiecesOnBoard; }
  
  // bools
  bool shown() const { return m_Shown; }
  bool dropped() const { return m_Dropped; }
  bool dropping() const { return m_Dropping; }
  bool resized() const { return m_Resized; }
  
  // show piece
  void show();
  virtual void showObj();
  
  // actions
  void drop(const float &, const float &, const float &);
};


#endif
