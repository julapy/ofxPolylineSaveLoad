//
//  ofxPolylineSaveLoad.cpp
//  Created by Lukasz Karluk on 18/05/2014.
//

#include "ofxPolylineSaveLoad.h"

void ofxPolylineSave(ofPolyline & poly, string xmlPath) {
    ofXml xml;
    xml.addChild("poly");
    xml.setAttribute("closed", ofToString(poly.isClosed()));
    for(int i=0; i<poly.size(); i++) {
        ofPoint & point = poly.getVertices()[i];
        
        xml.addChild("point");
        xml.setToChild(i);
        xml.setAttribute("x", ofToString(point.x));
        xml.setAttribute("y", ofToString(point.y));
        xml.setToParent();
    }

    xml.save(xmlPath);
}

void ofxPolylineLoad(ofPolyline & poly, string xmlPath) {
    ofXml xml;
    bool bLoaded = xml.load(xmlPath);
    if(bLoaded == false) {
        return;
    }
    
    xml.setTo("poly");
    bool bClosed = ofToInt(xml.getAttribute("closed"));
    
    poly.clear();
    
    int numOfPoints = xml.getNumChildren();
    for(int i=0; i<numOfPoints; i++) {
        xml.setToChild(i);
        float x = ofToFloat(xml.getAttribute("x"));
        float y = ofToFloat(xml.getAttribute("y"));
        
        poly.addVertex(x, y);
    }
    
    if(bClosed == true) {
        poly.close();
    }
}