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

Trainer::Trainer(const Trainer& trainer) :
		id(trainer.id), bestPokimon(trainer.bestPokimon),
		pokimonTree(new AVLTree<Pokimon,pair<int,int>,CompareKeysForTrainerTree>(*(trainer.pokimonTree)))
		{
		}


bool Trainer::operator==(const Trainer& trainer) {
	return (this->id == trainer.id);

}
Trainer::~Trainer() {
	delete pokimonTree;
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
	bestPokimon = &this->pokimonTree->getMax();

}
void Trainer::removePokimon(pair<int, int>& key) {


	Pokimon* pokimon = (this->pokimonTree)->deleteVertice(key);
	delete pokimon;
	try{
	bestPokimon = &pokimonTree->getMax(); //using = operator
	} catch (EmptyTree& e) {
			this->setBestPokimon(NULL);
	}

}

 Pokimon* Trainer::findPokimon(int id,int level){
 pair<int,int> key =pair<int,int>(level,id);
 return &(this->pokimonTree->find(key));
 //if the pokimon not in the tree we throw exception "NotINTheTree"
}



int Trainer::getNumberOfPokimons() {
	return ((this->pokimonTree)->getNumOfVertices());
}
