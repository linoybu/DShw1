
#include "Pokimon.h"
#include "AVLTree.h"
#include "pair.h"
#include "exception.h"
#include <stdlib.h>

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
