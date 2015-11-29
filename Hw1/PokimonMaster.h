/*
 * PokimonMaster.h
 *
 *  Created on: Nov 28, 2015
 *      Author: linoy
 */

#ifndef POKIMONMASTER_H_
#define POKIMONMASTER_H_
#include "Pokimon.h"
#include "Trainer.h"
#include "mtmtest.h"
#include "AVLTree.h"
#include "pair.h"
using std::cout;
using std::endl;
#include <stdlib.h>
#include "list.h"

class PokimonMaster {
	List<Trainer> trainerList;
	AVLTree<Pokimon, int, compareByID>* idPokimonTree;
	AVLTree<Pokimon, pair<int, int>, compareByLevel>* levelPokimonTree;
	Pokimon* bestPokimon;

	Trainer* findTrainer(int id); //TODO -LINOY
	Pokimon& findPokimonInIdTree(int id); //TODO -LIOR
	Pokimon& findPokimonInLevelTree(int id); //TODO -LINOY
	void addPokimonInIdTree(Pokimon& pokimon); //TODO -LIOR
	void addPokimonInLevelTree(Pokimon& pokimon); //TODO -LINOY

public:
	PokimonMaster();
//	PokimonMaster(PokimonMaster& pmaster);
	virtual ~PokimonMaster();
	void addTrainer(int id);
	//ALLOCATION_ERROR - In case of an allocation error.
//	 *                INVALID_INPUT - If DS==NULL or if trainerID <= 0.
//	 *                FAILURE - If trainerID is already in the DS.
//	 *                SUCCESS - Otherwise.
	void CatchPokemon(int pokemonID, int trainerID, int level);
	void FreePokemon(int pokemonID);
	void LevelUp(int pokemonID, int levelIncrease); //TODO -LIOR
	void EvolvePokemon(int pokemonID, int evolvedID);
	void GetTopPokemon(int trainerID, int *pokemonID); //TODO -LIOR
	void GetAllPokemonsByLevel(int trainerID, int **pokemons,
			int *numOfPokemon); //TODO -LIOR
	void UpdateLevels(int stoneCode, int stoneFactor); //TODO - to be or not to be:)
	void Quit(); //TODO -LINOY
	void printAllTrees();

};

class fatherMatchSon1 {
public:
	bool IsTrue;
	fatherMatchSon1() {
		this->IsTrue = true;
	}
	void operator()(Node<Pokimon,int>* ptr) {
		if (ptr->getLeftSon() == NULL && ptr->getRightSon() != NULL) {
			this->IsTrue = (this->IsTrue
					&& (ptr->getRightSon()->getFather() == ptr));
			return;
		}

		if (ptr->getLeftSon() != NULL && ptr->getRightSon() == NULL) {
			this->IsTrue = (this->IsTrue
					&& (ptr->getLeftSon()->getFather() == ptr));
			return;
		}
		if (ptr->getLeftSon() != NULL && ptr->getRightSon() != NULL) {
			return;
		}
		this->IsTrue = (this->IsTrue && (ptr->getLeftSon()->getFather() == ptr)
				&& (ptr->getRightSon()->getFather() == ptr));

	}
};

class fatherMatchSon2 {
public:
	bool IsTrue;
	fatherMatchSon2() {
		this->IsTrue = true;
	}
	void operator()(Node<Pokimon,pair<int,int> >* ptr) {
		if (ptr->getLeftSon() == NULL && ptr->getRightSon() != NULL) {
			this->IsTrue = (this->IsTrue
					&& (ptr->getRightSon()->getFather() == ptr));
			return;
		}

		if (ptr->getLeftSon() != NULL && ptr->getRightSon() == NULL) {
			this->IsTrue = (this->IsTrue
					&& (ptr->getLeftSon()->getFather() == ptr));
			return;
		}
		if (ptr->getLeftSon() != NULL && ptr->getRightSon() != NULL) {
			return;
		}
		this->IsTrue = (this->IsTrue && (ptr->getLeftSon()->getFather() == ptr)
				&& (ptr->getRightSon()->getFather() == ptr));

	}
};

class print {
public:
	void operator()(int x, Pokimon& value) {
		cout << value << ",";
	}
};

class print2 {
public:
	void operator()(pair<int,int> x, Pokimon& value) {
		cout << value << ",";
	}
};

#endif /* POKIMONMASTER_H_ */
