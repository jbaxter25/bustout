//Ball.h
//Jordan Baxter

#pragma once
#include "ofMain.h"

class GameWorld;
class Paddle;
class Brick;

class Ball {
public:
	Ball();
	void spawn();
	void move();
	void draw();
	void bounceWall();
	void bounceCeiling();
	void bounceBrick();
	void bouncePaddle(Paddle* paddle);
	void damageBrick(Brick* brick);
	bool hitPaddle(Paddle* &paddle);
	bool hitWall();
	bool hitCeiling();
	bool hitFloor();
	bool hitBrick(Brick* brick);
	


private:
	ofVec2f position;
	ofVec2f velocity;
	ofRectangle box;
	float r;
	float s;
	ofColor color;
	bool superBall;

};