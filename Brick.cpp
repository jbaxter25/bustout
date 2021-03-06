//Brick.cpp
//Jordan Baxter

#include "Brick.h"
#include "GameWorld.h"
#include "Powerup.h"

Brick::Brick(float y, float x, char c) {
	int chance = ofRandom(100);
	this->box = ofRectangle(x, y, ofGetWidth() / 12, ofGetHeight() / 25);
	this->strength = this->setStrength(c);
	this->startStrength = this->setStrength(c);
	this->color = this->setColor(c);
	this->startColor = this->setColor(c);
	if (c == ' ') {
		this->exists = false;
	}
	else {
		this->exists = true;
	}
	
	if (chance > 90 && this->exists) {
		this->powerup = true;
	}
	else {
		this->powerup = false;
	}
}



void Brick::damage() {
	this->strength -= 1;
	if (this->strength == 3) {
		this->color = setColor('o');
	}
	else if (this->strength == 2) {
		this->color = setColor('y');
	}
	else if (this->strength == 1) {
		this->color = setColor('g');
	}
	else if (this->strength == 0) {
		this->exists = false;
		if (this->powerup == true) {
			
		}
	}
}

void Brick::draw() {
	if (this->exists) {
		ofSetColor(this->color);
		ofDrawRectangle(this->box);
	}
}

void Brick::godHand() {
	this->exists = false;
}

ofColor Brick::setColor(char c) {
	if (c == 'r') {
		return ofColor(234, 41, 0);
	}
	else if (c == 'o') {
		return ofColor(234, 96, 0);
	}
	else if (c == 'y') {
		return ofColor(234, 210, 0);
	}
	else if (c == 'g') {
		return ofColor(44, 222, 0);
	}
	else {
		return ofColor(0);
	}
}

int Brick::setStrength(char c) {
	if (c == 'r') {
		return 4;
	}
	else if (c == 'o') {
		return 3;
	}
	else if (c == 'y') {
		return 2;
	}
	else if (c == 'g') {
		return 1;
	}
	else {
		return 0;
	}
}

bool Brick::getExists() {
	return this->exists;
}

ofRectangle Brick::getStructure() {
	return this->box;
}

float Brick::getX() {
	return this->box.x;
}

float Brick::getY() {
	return this->box.y;
}

float Brick::getW() {
	return this->box.width;
}

float Brick::getH() {
	return this->box.height;
}

void Brick::reset(){
	this->strength = this->startStrength;
	this->color = this->startColor;
	this->exists = true;
}