/*
 * PokimonMaster.cpp
 *
 *  Created on: Nov 28, 2015
 *      Author: linoy
 */

#include "PokimonMaster.h"
#include <algorithm>
class IsTrainer{
	int key;
public:
	IsTrainer(int key):key(key){

	}
	bool operator()(const Trainer& trainer){
		if(trainer.getId()==key){
			return true;
		}
		return false;
	}
};


	Trainer* PokimonMaster::findTrainer(int id){
		IsTrainer isTrainer = IsTrainer(id);
		std::list<Trainer>::iterator found = std::find_if(trainerList.begin(), trainerList.end(),isTrainer);
		if(found==trainerList.end()){
			return NULL;
		}
		return &(*found);
	}
	Pokimon& PokimonMaster::findPokimonInIdTree(int id){
		Pokimon& pokimon = this->idPokimonTree.find(id);
		return pokimon;
	}
	Pokimon& PokimonMaster::findPokimonInLevelTree(int id){
		Pokimon pokimon1 = findPokimonInIdTree(id);
		int level = pokimon1.getLevel();
		pair<int,int> key = pair<int,int>(id,level);
		Pokimon& pokimon =  this->levelPokimonTree.find(key);
		return pokimon;


	}

	void PokimonMaster::addPokimonInIdTree(Pokimon& pokimon){
		int id = pokimon.getId();
		this->idPokimonTree.addVertices(&pokimon,&id);
	}
	void PokimonMaster::addPokimonInLevelTree(Pokimon& pokimon){
		int id = pokimon.getId();
		int level = pokimon.getLevel();
		pair<int,int> key = pair<int,int>(id,level);
		this->levelPokimonTree.addVertices(&pokimon,&key);

	}

PokimonMaster::PokimonMaster() {
	// TODO Auto-generated constructor stub

}

PokimonMaster::~PokimonMaster() {
//	delete trainerList;
//	delete idPokimonTree;
//	delete levelPokimonTree;
}

void PokimonMaster::addTrainer(int id){
	if(this->findTrainer(id)){
		throw Failure();
	}
	Trainer newTrainer =  Trainer(id);
	trainerList.push_back(newTrainer);
}
//ALLOCATION_ERROR - In case of an allocation error.
//	 *                INVALID_INPUT - If DS==NULL or if trainerID <= 0.
//	 *                FAILURE - If trainerID is already in the DS.
//	 *                SUCCESS - Otherwise.
void PokimonMaster::CatchPokemon(int pokemonID, int trainerID, int level){
	Pokimon pokimon = Pokimon(pokemonID,level,trainerID);
	Trainer* trainer = findTrainer(trainerID);
	trainer->addPokimon(pokimon);
	addPokimonInIdTree(pokimon);
	addPokimonInLevelTree(pokimon);
}
void PokimonMaster::FreePokemon(int pokemonID){
	Pokimon* pokimon = this->idPokimonTree.deleteVertice(pokemonID);
	int id = pokimon->getId();
	int level = pokimon->getLevel();
	int trainerId = pokimon->getTrainerId();
	Trainer* trainer = findTrainer(trainerId);
	pair<int,int> key = pair<int,int>(id,level);
	trainer->removePokimon(key);
	Pokimon* pokimon2 = this->levelPokimonTree.deleteVertice(key);
	delete pokimon;
	delete pokimon2;

}
void PokimonMaster::LevelUp(int pokemonID, int levelIncrease){

}
void PokimonMaster::EvolvePokemon(int pokemonID, int evolvedID){
	Pokimon* pokimon = this->idPokimonTree.deleteVertice(pokemonID);
	int id = pokimon->getId();
	int level = pokimon->getLevel();
	int trainerId = pokimon->getTrainerId();
	Trainer* trainer = findTrainer(trainerId);
	pair<int,int> key = pair<int,int>(id,level);
	trainer->removePokimon(key);
	Pokimon* pokimon2 = this->levelPokimonTree.deleteVertice(key);
	delete pokimon;
	delete pokimon2;
	Pokimon pokimonToAdd = Pokimon(evolvedID,level,trainerId);
	this->addPokimonInIdTree(pokimonToAdd);
	this->addPokimonInLevelTree(pokimonToAdd);
	trainer->addPokimon(pokimonToAdd);
}

void PokimonMaster::GetTopPokemon(int trainerID, int *pokemonID){

}
void PokimonMaster::GetAllPokemonsByLevel(int trainerID, int **pokemons,
		int *numOfPokemon){

}
void PokimonMaster::UpdateLevels(int stoneCode, int stoneFactor){

}
void PokimonMaster::Quit(){
	// not usefull? we have a distractor.

}

