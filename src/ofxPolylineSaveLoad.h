//
//  ofxPolylineSaveLoad.h
//  Created by Lukasz Karluk on 18/05/2014.
//

#pragma once

#include "ofMain.h"

void ofxPolylineSave(ofPolyline & poly, string xmlPath);
void ofxPolylineLoad(ofPolyline & poly, string xmlPath);