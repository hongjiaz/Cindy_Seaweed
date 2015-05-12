#line 1 "grass"

#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:

#line 1 "grass"
ofPolyline movePolyline;
ofPolyline polyline;


void setup() {
    ofSetWindowShape(600, 600);
    // the window size
    for (int i=200; i>=-180; i-=9) polyline.addVertex(ofVec2f(0,i));
    // set the location 
    movePolyline = polyline;
    //set the polyline
}


void draw() {
    ofBackground(229);    
    // set the background color  
      for (int i=0; i<polyline.size(); i++) {
      //set the whole number
        ofVec3f normal = polyline.getNormalAtIndexInterpolated(i); 
        ofPushMatrix();    
        //set the basic looking of the grass
            ofTranslate(600/2, 600/2);
            //set the translate
            ofLine(movePolyline[i]-normal*(polyline.size() -i), movePolyline[i]+normal*(polyline.size() -i));
        ofPopMatrix();
        //push .. pop matrix
        ofPushMatrix();
            ofTranslate(600/2, 600/2);
            //set the translate
            movePolyline.draw(); 
            //draw the polyline
        ofPopMatrix();
        //push .. pop matrix
    }
    ofSetColor(0,153,77);    
    // the color of the grass
}

};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}

