//
//  MouseTrail.h
//  Connect4
//
//  Created by Diego Jimenez on 5/2/15.
//
//

#ifndef Connect4_MouseTrail_h
#define Connect4_MouseTrail_h

#include "ofApp.h"
#include <vector>
using namespace std;

class MouseTrail {
private:
  int m_Length;
  float m_Width;
  vector<ofPoint> m_Points;
  // helper
  void initializePoints(const int &);
public:
  // ctor
  MouseTrail(const int & = 5, const float & = 12);
  // setters
  void updateTracking();
  void trail(const ofColor &) const;
  // getters
  int getLength() const { return m_Length; }
  float getWidth() const { return m_Width; }
};


#endif
