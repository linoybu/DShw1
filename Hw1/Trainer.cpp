/*
 * trainer.cpp
 *
 *  Created on: 26 бреб 2015
 *      Author: Lior
 */

#include "Trainer.h"
#include "exception.h"
#include <stdlib.h>
#include <iostream>

Trainer::Trainer(int id) :
		id(id), bestPokimon(NULL), pokimonTree(
				new AVLTree<Pokimon, pair<int, int>, CompareKeysForTrainerTree>()) {
	if (id <= 0) {
		throw InvaildInput();
	}
}

bool Trainer::operator==(const Trainer& trainer) {
	return (this->id == trainer.id);

}
Trainer::~Trainer() {
	// Default detractor
}

int const Trainer::getId() const {
	return this->id;

}

void Trainer::setBestPokimon(Pokimon* pokimon) {
	this->bestPokimon = pokimon;
}

Pokimon* Trainer::getBestPokimon() {
	return (this->bestPokimon);

}
void Trainer::addPokimon(Pokimon& pokimon) {
	int id = pokimon.getId();
	int level = pokimon.getLevel();
	pair<int, int> key = pair<int, int>(level, id);
	(this->pokimonTree)->addVertices(&pokimon, &key);

//if this is the first pokimon we add
	if (!bestPokimon) {
		this->bestPokimon = &pokimon;
	} else {

		//check if we added better pokimon then "bestPokimon"
		int idBest = this->bestPokimon->getId(), levelBest =
				this->bestPokimon->getLevel();
		pair<int, int> keyBest = pair<int, int>(levelBest, idBest);
		CompareKeysForTrainerTree compare = CompareKeysForTrainerTree();
		if (compare(key, keyBest) > 0) {
			this->setBestPokimon(&pokimon);
		}
	}

}
void Trainer::removePokimon(pair<int, int>& key) {

	//prepare data to check if we will removed the "bestPokimon"
	int idBest = this->bestPokimon->getId(), levelBest =
			this->bestPokimon->getLevel();
	pair<int, int> keyBest = pair<int, int>(levelBest, idBest);
	CompareKeysForTrainerTree compare = CompareKeysForTrainerTree();

	//delete pokimon:
	Pokimon* pokimon = (this->pokimonTree)->deleteVertice(key);
	delete pokimon;

	//check if we will removed the "bestPokimon"
	try {
		if (compare(key, keyBest) == 0) {
			this->setBestPokimon(this->findBestPokimon());
		}
	} catch (EmptyTree& e) {
		this->setBestPokimon(NULL);
	}

}

Pokimon* Trainer::findBestPokimon() {
	return (&((this->pokimonTree)->getMax()));
}

int Trainer::getNumberOfPokimons() {
	return ((this->pokimonTree)->getNumOfVertices());
}
