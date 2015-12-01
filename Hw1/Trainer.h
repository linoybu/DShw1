/*
 * trainer.h
 *
 *  Created on: 26 ���� 2015
 *      Author: Lior
 */

#include "Pokimon.h"
#include "AVLTree.h"
#include "pair.h"
#include "exception.h"
#include <stdlib.h>

///***TODO do we need this class? we have this function on pokimon
////** key = level value =ID
//class CompareKeysForTrainerTree {
//public:
//	int operator()(pair<int,int>& key1, pair<int,int>& key2) {
//		//first we compare by level
//		if(key1.getKey()!=key2.getKey()){
//			return (key1.getKey()-key2.getKey());
//		}// if the levels are equals we compare by id
//	return (key2.getValue()-key1.getValue());
//	// smallest id is bigger key therefore we return key2-key1
//	}
//};

/****************************Trainer class*************************************/
class Trainer {
	int id;
	Pokimon* bestPokimon;
	// the keys at the trainer's pokimons tree are pairs of (level,id)
	AVLTree< Pokimon,pair<int,int>, compareByLevel>* pokimonTree ;

public:
	Trainer(int id);
	Trainer(const Trainer& );//- we don't want to copy trainer
	bool operator==(const Trainer& trainer);
	virtual ~Trainer();
	int const getId() const;
	void setBestPokimon(Pokimon* pokimon);
	Pokimon* getBestPokimon();
	void addPokimon(Pokimon& pokimon);
	void removePokimon(pair<int,int>& key);
	int getNumberOfPokimons();
	Pokimon* findPokimon(int id,int level);
	AVLTree< Pokimon,pair<int,int>, compareByLevel>*  gettree(){
		return pokimonTree;
	}


};
