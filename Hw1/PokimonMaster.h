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
#include <list>


class PokimonMaster {
	std::list<Trainer> list;
	AVLTree<Pokimon,int,compareByID> idPokimonTree;
	AVLTree<Pokimon,int,compareByLevel> levelPokimonTree;

public:
	PokimonMaster();
	virtual ~PokimonMaster();
	void addTrainer(int id);
	//ALLOCATION_ERROR - In case of an allocation error.
//	 *                INVALID_INPUT - If DS==NULL or if trainerID <= 0.
//	 *                FAILURE - If trainerID is already in the DS.
//	 *                SUCCESS - Otherwise.
	void CatchPokemon(int pokemonID, int trainerID, int level);
	void FreePokemon(int pokemonID);
	void LevelUp(int pokemonID, int levelIncrease);
	void EvolvePokemon( int pokemonID, int evolvedID);
	void GetTopPokemon(int trainerID, int *pokemonID);
	void GetAllPokemonsByLevel(int trainerID, int **pokemons, int *numOfPokemon);
	void UpdateLevels(int stoneCode, int stoneFactor);
	void Quit();

};

#endif /* POKIMONMASTER_H_ */
