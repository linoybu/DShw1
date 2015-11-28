/*
 * Pokimon.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: linoy
 */

#include "Pokimon.h"

Pokimon::Pokimon(int id, int level) :
		id(id), level(level) {
	if (id <= 0 || level <= 0) {
		throw InvaildInput();
	}
}

Pokimon::Pokimon(const Pokimon& pokimon) :
		id(pokimon.id), level(pokimon.level) {

}

void Pokimon::operator=(const Pokimon& pokimon) {
	this->id = pokimon.id;
	this->level = pokimon.level;
}

Pokimon::~Pokimon() {
	// Default detractor
}

void Pokimon::setId(int id) {
	if (id <= 0) {
		throw InvaildInput();
	}
	this->id = id;
}

int Pokimon::getId() {
	return this->id;

}

int const Pokimon::getId() const {
	return this->id;

}
void Pokimon::setLevel(int level) {
	if (level <= 0) {
		throw InvaildInput();
	}
	this->level = level;
}

int Pokimon:: getLevel() {
	return this->level;
}
int const Pokimon:: getLevel()const {
	return this->level;
}

