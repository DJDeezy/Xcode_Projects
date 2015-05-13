//
//  GamePieceSet.h
//  Connect4
//
//  Created by Diego Jimenez on 4/30/15.
//
//

#ifndef Connect4_GamePieceSet_h
#define Connect4_GamePieceSet_h

#include "ofApp.h"
#include "RedPiece.h"
#include "BluePiece.h"
#include <vector>
#include <string>
using namespace std;


class GamePieceSet {
private:
  vector<GamePiece*> m_RedPieces;
  vector<GamePiece*> m_BluePieces;
  vector<GamePiece*> m_Pieces;
  
  int m_RedIndex;
  int m_BlueIndex;
  
  float m_PieceRadius;
  
  bool m_Turn;  // Player1: true, Player2: false
  int m_PiecesCreated;
public:
  // ctor
  GamePieceSet(const float & = 40);
  // copy ctor
  GamePieceSet(const GamePieceSet &);
  // dtor
  ~GamePieceSet();
  
  // setters
  void setRadius(const float &);
  
  // create pieces
  bool createRedPiece(const ofPoint &, const float &, const float &);
  bool createBluePiece(const ofPoint &, const float &, const float &);
  
  // getters
  vector<GamePiece*> getRedPieces() const { return m_RedPieces; }
  vector<GamePiece*> getBluePieces() const { return m_BluePieces; }
  vector<GamePiece*> getPieces() const { return m_Pieces; }
  int numberOfRedPieces() const { return m_RedIndex; }
  int numberOfBluePieces() const { return m_BlueIndex; }
  int numberOfPieces() const { return m_PiecesCreated; }
  
  float getPieceRadius() const { return m_PieceRadius; }
  
  bool player1Turn() const { return m_Turn; }
  bool player2Turn() const { return !m_Turn; }
  
  // actions
  bool placePiece(const ofPoint &, const float &);
  void showCreatedPieces();
  
  void resize(const vector<ofPoint> &, const vector<string> &, const float &);
  
  void reset();
};


#endif
