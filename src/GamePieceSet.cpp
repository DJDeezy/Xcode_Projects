//
//  GamePieceSet.cpp
//  Connect4
//
//  Created by Diego Jimenez on 4/30/15.
//
//

#include "GamePieceSet.h"


//
//--------------------------------------------------------------
//  Ctor
//--------------------------------------------------------------
//

GamePieceSet::GamePieceSet(const float &radius): m_RedIndex(0), m_BlueIndex(0), m_PiecesCreated(0) {
  m_RedPieces.resize(21);
  m_BluePieces.resize(21);
  
  setRadius(radius);
}

//
//--------------------------------------------------------------
//  Copy Ctor
//--------------------------------------------------------------
//

GamePieceSet::GamePieceSet(const GamePieceSet &original): m_RedIndex(original.numberOfRedPieces()), m_BlueIndex(original.numberOfBluePieces()), m_PieceRadius(original.getPieceRadius()), m_Turn(original.m_Turn), m_PiecesCreated(original.numberOfPieces()) {
  m_RedPieces.resize(21);
  m_BluePieces.resize(21);
  m_Pieces.resize(42);
  
  vector<GamePiece*> gP = original.getPieces();
  
  
  for(int p = 0, r = 0, b = 0; p < numberOfRedPieces(); p++) {
    RedPiece * rPtr = dynamic_cast<RedPiece*>(gP[p]);
    if(rPtr) {
      m_RedPieces[r] = new RedPiece(*rPtr);
      m_Pieces[p] = m_RedPieces[r];
      r++;
    }
    BluePiece * bPtr = dynamic_cast<BluePiece*>(gP[p]);
    if(bPtr) {
      m_BluePieces[r] = new BluePiece(*bPtr);
      m_Pieces[p] = m_BluePieces[r];
      b++;
    }
  }
}

//
//--------------------------------------------------------------
//  Dtor
//--------------------------------------------------------------
//

GamePieceSet::~GamePieceSet() {
  reset();  // delete used dynamic memory used
}

//
//--------------------------------------------------------------
//  Setters
//--------------------------------------------------------------
//

void GamePieceSet::setRadius(const float &radius) {
  m_PieceRadius = (radius > 0) ? radius : 0;
}

//
//--------------------------------------------------------------
//  Create Pieces
//--------------------------------------------------------------
//

bool GamePieceSet::createRedPiece(const ofPoint &position, const float &yStart, const float &radius) {
  if(numberOfRedPieces() < m_RedPieces.size()) {
    // create RedPiece
    m_RedPieces[m_RedIndex] = new RedPiece(position.x, position.y, radius);
    
    // add piece to m_Pieces
    m_Pieces.push_back(m_RedPieces[m_RedIndex]);
    
    vector<GamePiece*> temp = getRedPieces();
    RedPiece * rPtr = dynamic_cast<RedPiece*>(m_RedPieces[m_RedIndex]);
    if(rPtr)
      rPtr->drop(yStart, rPtr->getY(), 0);
    
    m_RedIndex++;
    m_PiecesCreated++;
    return true;
  }
  return false;
}

bool GamePieceSet::createBluePiece(const ofPoint &position, const float &yStart, const float &radius) {
  if(numberOfBluePieces() < m_BluePieces.size()) {
    // create BluePiece
    m_BluePieces[m_BlueIndex] = new BluePiece(position.x, position.y, radius);
    
    // add piece to m_Pieces
    m_Pieces.push_back(m_BluePieces[m_BlueIndex]);
    
    vector<GamePiece*> temp = getBluePieces();
    BluePiece * bPtr = dynamic_cast<BluePiece*>(m_BluePieces[m_BlueIndex]);
    if(bPtr)
      bPtr->drop(yStart, bPtr->getY(), 0);
    
    m_BlueIndex++;
    m_PiecesCreated++;
    return true;
  }
  return false;
}

//
//--------------------------------------------------------------
//  Place Piece
//--------------------------------------------------------------
//

bool GamePieceSet::placePiece(const ofPoint &point, const float &yStart) {
  if(player1Turn()) {
    m_Turn = false;
    return createRedPiece(point, yStart, getPieceRadius()/4);
  }
  else {
    m_Turn = true;
    return createBluePiece(point, yStart, getPieceRadius()/4);
  }
}

//
//--------------------------------------------------------------
//  Show Pieces
//--------------------------------------------------------------
//

void GamePieceSet::showCreatedPieces() {
  // show RedPiece(s)
  for(int i = 0; i < m_RedIndex; i++) {
    vector<GamePiece*> temp = getRedPieces();
    RedPiece * rPtr = dynamic_cast<RedPiece*>(temp[i]);
    if(rPtr)
      rPtr->showObj();
  }
  // show BluePiece(s)
  for(int i = 0; i < m_BlueIndex; i++) {
    vector<GamePiece*> temp = getBluePieces();
    BluePiece * rPtr = dynamic_cast<BluePiece*>(temp[i]);
    if(rPtr)
      rPtr->showObj();
  }
}

//
//--------------------------------------------------------------
//  Resize
//--------------------------------------------------------------
//

void GamePieceSet::resize(const vector<ofPoint> &points, const vector<string> &spaces, const float &radius) {
  
  setRadius(radius*4);
  
  int rIndex = 0;
  int bIndex = 0;
  
  // resizing pieces
  for(int i = 0; i < spaces.size(); i++) {
    if(spaces[i] == "Red") {
      vector<GamePiece*> temp = getRedPieces();
      RedPiece * rPtr = dynamic_cast<RedPiece*>(temp[rIndex]);
      if(rPtr)
        rPtr->resize(points[i].x, points[i].y, radius);
      
      rIndex++;
    }
    else if(spaces[i] == "Blue") {
      vector<GamePiece*> temp = getBluePieces();
      BluePiece * bPtr = dynamic_cast<BluePiece*>(temp[bIndex]);
      if(bPtr)
        bPtr->resize(points[i].x, points[i].y, radius);
      
      bIndex++;
    }
  }
}

//
//--------------------------------------------------------------
//  Reset
//--------------------------------------------------------------
//

void GamePieceSet::reset() {
  for(int r = 0; r < m_RedIndex; r++) {
    delete m_RedPieces[r];
  }
  m_RedIndex = 0;
  for(int b = 0; b < m_BlueIndex; b++) {
    delete m_BluePieces[b];
  }
  m_BlueIndex = 0;
  
  m_PiecesCreated = 0;
  m_Turn = true;
}
