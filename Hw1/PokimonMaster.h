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
	std::list<Trainer> trainerList;
	AVLTree<Pokimon,int,compareByID> idPokimonTree;
	AVLTree<Pokimon,pair<int,int>,compareByLevel> levelPokimonTree;
	Pokimon* bestPokimon;

	Trainer* findTrainer(int id); //TODO -LINOY
	Pokimon& findPokimonInIdTree(int id);//TODO -LIOR
	Pokimon& findPokimonInLevelTree(int id);//TODO -LINOY
	void addPokimonInIdTree(Pokimon& pokimon);//TODO -LIOR
	void addPokimonInLevelTree(Pokimon& pokimon);//TODO -LINOY


public:
	PokimonMaster(); //TODO -LIOR
	virtual ~PokimonMaster();//TODO -LINOY
	void addTrainer(int id);//TODO -LINOY
	//ALLOCATION_ERROR - In case of an allocation error.
//	 *                INVALID_INPUT - If DS==NULL or if trainerID <= 0.
//	 *                FAILURE - If trainerID is already in the DS.
//	 *                SUCCESS - Otherwise.
	void CatchPokemon(int pokemonID, int trainerID, int level);//TODO -LIOR
	void FreePokemon(int pokemonID);//TODO -LINOY
	void LevelUp(int pokemonID, int levelIncrease);//TODO -LIOR
	void EvolvePokemon( int pokemonID, int evolvedID);//TODO -LINOY
	void GetTopPokemon(int trainerID, int *pokemonID);//TODO -LIOR
	void GetAllPokemonsByLevel(int trainerID, int **pokemons, int *numOfPokemon);//TODO -LIOR
	void UpdateLevels(int stoneCode, int stoneFactor);//TODO - to be or not to be:)
	void Quit();//TODO -LINOY

};

#endif /* POKIMONMASTER_H_ */
