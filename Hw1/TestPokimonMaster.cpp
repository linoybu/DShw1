/*
 * TestPokimonMaster.cpp
 *
 *  Created on: Nov 29, 2015
 *      Author: linoy
 */
#include "Pokimon.h"
#include "mtmtest.h"
#include "AVLTree.h"
#include "pair.h"
#include "PokimonMaster.h"
using std::cout;
using std::endl;

class fatherMatchSon {
public:
	bool IsTrue;
	fatherMatchSon() {
		this->IsTrue = true;
	}
	;
	void operator()(Node<int, int>* ptr) {
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

class print
{
public:
	void operator()(int x, int value)
	{
		cout <<value << ",";
	}
};

bool testPokimonMaster(){
	PokimonMaster pokimonMaster = PokimonMaster();
	pokimonMaster.addTrainer(1);
	pokimonMaster.CatchPokemon(1,1,2);
	pokimonMaster.CatchPokemon(2,1,2);
	pokimonMaster.CatchPokemon(3,1,2);
	pokimonMaster.CatchPokemon(4,1,2);
	pokimonMaster.CatchPokemon(6,1,2);
	pokimonMaster.FreePokemon(1);
	pokimonMaster.FreePokemon(2);
	pokimonMaster.FreePokemon(3);
	pokimonMaster.FreePokemon(4);
	pokimonMaster.FreePokemon(6);
	return true;

}

int main(){
	testPokimonMaster();
}


