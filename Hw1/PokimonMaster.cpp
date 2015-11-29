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
	IsTrainer(int const key):key(key){

	}

	bool operator()(const Trainer& trainer)const{
		if(trainer.getId()==key){
			return true;
		}
		return false;
	}
};


	Trainer* PokimonMaster::findTrainer(int id){
		const IsTrainer isTrainer = IsTrainer(id);
		Iterator<Trainer> found = this->trainerList.find(isTrainer);
		if(found==trainerList.end()){
			return NULL;
		}
		return &(*found);
	}
	Pokimon& PokimonMaster::findPokimonInIdTree(int id){
		Pokimon& pokimon = this->idPokimonTree->find(id);
		return pokimon;
	}
	Pokimon& PokimonMaster::findPokimonInLevelTree(int id){
		Pokimon pokimon1 = findPokimonInIdTree(id);
		int level = pokimon1.getLevel();
		pair<int,int> key = pair<int,int>(level,id);
		Pokimon& pokimon =  this->levelPokimonTree->find(key);
		return pokimon;


	}

	void PokimonMaster::addPokimonInIdTree(Pokimon& pokimon){
		int id = pokimon.getId();
		this->idPokimonTree->addVertices(&pokimon,&id);
		this->bestPokimon = &(idPokimonTree->getMax());
	}
	void PokimonMaster::addPokimonInLevelTree(Pokimon& pokimon){
		int id = pokimon.getId();
		int level = pokimon.getLevel();
		pair<int,int> key = pair<int,int>(level,id);
		this->levelPokimonTree->addVertices(&pokimon,&key);
		this->bestPokimon = &(levelPokimonTree->getMax());
	}

PokimonMaster::PokimonMaster():
		trainerList(List<Trainer>()),
		idPokimonTree(new AVLTree<Pokimon,int,compareByID>()),
		levelPokimonTree(new AVLTree<Pokimon,pair<int,int>,compareByLevel>()),
		bestPokimon(NULL)
{

}
//
//PokimonMaster::PokimonMaster(PokimonMaster& pmaster):
//		trainerList(pmaster.trainerList),
//		idPokimonTree(pmaster.idPokimonTree),
//		levelPokimonTree(pmaster.levelPokimonTree)
//		,bestPokimon(pmaster.bestPokimon)
//{
//
//}


PokimonMaster::~PokimonMaster() {
//	delete trainerList;
	delete idPokimonTree;
	delete levelPokimonTree;
}

void PokimonMaster::addTrainer(int id){
	if(id<0){
		throw InvaildInput();
	}
	if(this->findTrainer(id)){
		throw Failure();
	}
	Trainer newTrainer =  Trainer(id);
	trainerList.insert(newTrainer,trainerList.end());
}
//ALLOCATION_ERROR - In case of an allocation error.
//	 *                INVALID_INPUT - If DS==NULL or if trainerID <= 0.
//	 *                FAILURE - If trainerID is already in the DS.
//	 *                SUCCESS - Otherwise.
void PokimonMaster::CatchPokemon(int pokemonID, int trainerID, int level){
	if(trainerID<=0||pokemonID<=0||level<=0){
		throw InvaildInput();
	}
	Pokimon pokimon = Pokimon(pokemonID,level,trainerID);
	Trainer* trainer = findTrainer(trainerID);
	if(!trainer){
		throw Failure();
	}
	trainer->addPokimon(pokimon);
	addPokimonInIdTree(pokimon);
	addPokimonInLevelTree(pokimon);
}
void PokimonMaster::FreePokemon(int pokemonID){
	if(pokemonID<=0){
		throw InvaildInput();
	}
	Pokimon* pokimon = this->idPokimonTree->deleteVertice(pokemonID);
	int id = pokimon->getId();
	int level = pokimon->getLevel();
	int trainerId = pokimon->getTrainerId();
	Trainer* trainer = findTrainer(trainerId);
	pair<int,int> key = pair<int,int>(level,id);
	trainer->removePokimon(key);
	Pokimon* pokimon2 = this->levelPokimonTree->deleteVertice(key);
	delete pokimon;
	delete pokimon2;

}
void PokimonMaster::LevelUp(int pokemonID, int levelIncrease){

}
void PokimonMaster::EvolvePokemon(int pokemonID, int evolvedID){
	if(pokemonID<=0||evolvedID<=0){
		throw InvaildInput();
	}
	Pokimon* pokimon = this->idPokimonTree->deleteVertice(pokemonID);
	int id = pokimon->getId();
	int level = pokimon->getLevel();
	int trainerId = pokimon->getTrainerId();
	Trainer* trainer = findTrainer(trainerId);
	pair<int,int> key = pair<int,int>(level,id);
	trainer->removePokimon(key);
	Pokimon* pokimon2 = this->levelPokimonTree->deleteVertice(key);
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

