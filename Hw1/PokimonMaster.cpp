/*
 * PokimonMaster.cpp
 *
 *  Created on: Nov 28, 2015
 *      Author: linoy
 */

#include "PokimonMaster.h"

PokimonMaster::PokimonMaster() {
	// TODO Auto-generated constructor stub

}

PokimonMaster::~PokimonMaster() {
	// TODO Auto-generated destructor stub
}

void PokimonMaster::addTrainer(int id){

}
//ALLOCATION_ERROR - In case of an allocation error.
//	 *                INVALID_INPUT - If DS==NULL or if trainerID <= 0.
//	 *                FAILURE - If trainerID is already in the DS.
//	 *                SUCCESS - Otherwise.
void PokimonMaster::CatchPokemon(int pokemonID, int trainerID, int level){

}
void PokimonMaster::FreePokemon(int pokemonID){

}
void PokimonMaster::LevelUp(int pokemonID, int levelIncrease){

}
void PokimonMaster::EvolvePokemon(int pokemonID, int evolvedID){

}
void PokimonMaster::GetTopPokemon(int trainerID, int *pokemonID){

}
void PokimonMaster::GetAllPokemonsByLevel(int trainerID, int **pokemons,
		int *numOfPokemon){

}
void PokimonMaster::UpdateLevels(int stoneCode, int stoneFactor){

}
void PokimonMaster::Quit(){

}

