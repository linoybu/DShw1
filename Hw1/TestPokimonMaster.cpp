/*
 * TestpokimonMaster.cpp
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
//
//class fatherMatchSon {
//public:
//	bool IsTrue;
//	fatherMatchSon() {
//		this->IsTrue = true;
//	}
//	;
//	void operator()(Node<int, int>* ptr) {
//		if (ptr->getLeftSon() == NULL && ptr->getRightSon() != NULL) {
//			this->IsTrue = (this->IsTrue
//					&& (ptr->getRightSon()->getFather() == ptr));
//			return;
//		}
//
//		if (ptr->getLeftSon() != NULL && ptr->getRightSon() == NULL) {
//			this->IsTrue = (this->IsTrue
//					&& (ptr->getLeftSon()->getFather() == ptr));
//			return;
//		}
//		if (ptr->getLeftSon() != NULL && ptr->getRightSon() != NULL) {
//			return;
//		}
//		this->IsTrue = (this->IsTrue && (ptr->getLeftSon()->getFather() == ptr)
//				&& (ptr->getRightSon()->getFather() == ptr));
//
//	}
//};
//
//class print
//{
//public:
//	void operator()(int x, int value)
//	{
//		cout <<value << ",";
//	}
//};

bool testPokimonMaster() {
	PokimonMaster pokimonMaster = PokimonMaster();
	pokimonMaster.addTrainer(1);
	pokimonMaster.CatchPokemon(1, 1, 2);
	pokimonMaster.CatchPokemon(2, 1, 2);
	pokimonMaster.CatchPokemon(3, 1, 2);
	pokimonMaster.CatchPokemon(4, 1, 2);
	pokimonMaster.CatchPokemon(6, 1, 2);
	pokimonMaster.EvolvePokemon(3, 5);
	pokimonMaster.addTrainer(2);
	pokimonMaster.CatchPokemon(7, 2, 2);
	pokimonMaster.CatchPokemon(8, 2, 3);
	pokimonMaster.CatchPokemon(9, 2, 7);
	pokimonMaster.CatchPokemon(10, 2, 15);
	pokimonMaster.addTrainer(3);
	pokimonMaster.CatchPokemon(11, 3, 8);
	pokimonMaster.EvolvePokemon(11, 12);
	pokimonMaster.EvolvePokemon(12, 13);
	pokimonMaster.printAllTrees();
	try {
		pokimonMaster.addTrainer(-5);
	} catch (InvaildInput& e) {
		cout << "InvaildInput" << endl;
	}
	try {
		pokimonMaster.addTrainer(1);
	} catch (Failure& e) {
		cout << "Failure" << endl;
	}
	try {
		pokimonMaster.CatchPokemon(9, 2, 7);
	} catch (Failure& e) {
		cout << "Failure" << endl;
	}
	try {
		pokimonMaster.CatchPokemon(9,7, 7);
	} catch (Failure& e) {
		cout << "Failure" << endl;
	}
	try {
		pokimonMaster.CatchPokemon(-1,1, 7);
	} catch (InvaildInput& e) {
		cout << "InvaildInput" << endl;
	}
	try {
		pokimonMaster.CatchPokemon(2,-1, 7);
	} catch (InvaildInput& e) {
		cout << "InvaildInput" << endl;
	}
	try {
		pokimonMaster.CatchPokemon(20,1, -1);
	} catch (InvaildInput& e) {
		cout << "InvaildInput" << endl;
	}
	try {
		pokimonMaster.FreePokemon(25);
	} catch (Failure& fail) {
		cout << "Failure" << endl;
	}

	try {
		pokimonMaster.FreePokemon(-1);
	} catch (InvaildInput& e) {
		cout << "InvaildInput" << endl;
	}
	try {
		pokimonMaster.EvolvePokemon(5, 6);
	} catch (Failure& e) {
		cout << "Failure" << endl;
	}
	try {
		pokimonMaster.EvolvePokemon(3, 5);
	} catch (Failure& e) {
		cout << "Failure" << endl;
	}
	try {
		pokimonMaster.EvolvePokemon(-1, 5);
	} catch (InvaildInput& e) {
		cout << "InvaildInput" << endl;
	}
	try {
		pokimonMaster.EvolvePokemon(5, -1);
	} catch (InvaildInput& e) {
		cout << "InvaildInput" << endl;
	}

//	catch(EmptyTree& fail){
//		int a =5;
//		a=a+1;
//	}
	pokimonMaster.FreePokemon(1);
	pokimonMaster.FreePokemon(2);
	pokimonMaster.FreePokemon(4);
	pokimonMaster.FreePokemon(6);

	int b = 5;
	b = b + 1;
	return true;

}

int main() {
	testPokimonMaster();
}
