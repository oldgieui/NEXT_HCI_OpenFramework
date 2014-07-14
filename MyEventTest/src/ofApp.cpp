#include "ofApp.h"
#include <cstdlib>
#include <math.h>


//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(50,50,50);
	mRadius = 50;
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(200,0,0,80);
	//ofCircle(mousePoint, 50);
/*	for(int i=0;i<circlePosition.size();i++) {
		ofCircle(circlePosition[i], mRadius);
	}
*/
	for (int i = 0; i < circles.size(); i++)
	{
		Circle c = circles[i];
		ofCircle(c.circlePosition, c.radius);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//mousePoint.x = x;
	//mousePoint.y = y;
	
	if (button == 0)
	{
		//circlePosition.push_back(ofPoint(x,y));
		Circle c;
		c.circlePosition = ofPoint(x,y);
		c.radius = mRadius;

		circles.push_back(c);
	}
	else if (button == 2 && circles.empty() == false)
	{
		//circlePosition.pop_back(); //마지막 것부터 지우기
		//circles.pop_back();
		int closestCircleNum;
		double closestDistance;
		for (int i = 0; i < circles.size(); i++)
		{
			Circle c = circles[i];
			double xLength = c.circlePosition.x - x;
			double yLength = c.circlePosition.y - y;
			double distance = sqrt((xLength * xLength) + (yLength * yLength));
			if (i == 0)
			{
				closestCircleNum = 0;
				closestDistance = distance;
			}
			else if (closestDistance > distance)
			{
				closestCircleNum = i;
				closestDistance = distance;
			}
		}
		circles.erase(circles.begin()+closestCircleNum);
	}
	else if (button == 1)
	{
		srand((unsigned int)time(NULL));
		mRadius = (rand()%10 + 1) * 10;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
