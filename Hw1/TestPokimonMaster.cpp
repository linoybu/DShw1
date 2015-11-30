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

//bool testPokimonMaster() {
//	PokimonMaster pokimonMaster = PokimonMaster();
//	pokimonMaster.addTrainer(1);
//	pokimonMaster.CatchPokemon(1, 1, 2);
//	pokimonMaster.CatchPokemon(2, 1, 2);
//	pokimonMaster.CatchPokemon(3, 1, 2);
//	pokimonMaster.CatchPokemon(4, 1, 2);
//	pokimonMaster.CatchPokemon(6, 1, 2);
//	pokimonMaster.EvolvePokemon(3, 5);
//	pokimonMaster.addTrainer(2);
//	pokimonMaster.CatchPokemon(7, 2, 2);
//	pokimonMaster.CatchPokemon(8, 2, 3);
//	pokimonMaster.CatchPokemon(9, 2, 7);
//	pokimonMaster.CatchPokemon(10, 2, 15);
//	pokimonMaster.addTrainer(3);
//	pokimonMaster.CatchPokemon(11, 3, 8);
//	pokimonMaster.EvolvePokemon(11, 12);
//	pokimonMaster.EvolvePokemon(12, 13);
//	pokimonMaster.printAllTrees();
//	try {
//		pokimonMaster.addTrainer(-5);
//	} catch (InvaildInput& e) {
//		cout << "InvaildInput" << endl;
//	}
//	try {
//		pokimonMaster.addTrainer(1);
//	} catch (Failure& e) {
//		cout << "Failure" << endl;
//	}
//	try {
//		pokimonMaster.CatchPokemon(9, 2, 7);
//	} catch (Failure& e) {
//		cout << "Failure" << endl;
//	}
//	try {
//		pokimonMaster.CatchPokemon(9,7, 7);
//	} catch (Failure& e) {
//		cout << "Failure" << endl;
//	}
//	try {
//		pokimonMaster.CatchPokemon(-1,1, 7);
//	} catch (InvaildInput& e) {
//		cout << "InvaildInput" << endl;
//	}
//	try {
//		pokimonMaster.CatchPokemon(2,-1, 7);
//	} catch (InvaildInput& e) {
//		cout << "InvaildInput" << endl;
//	}
//	try {
//		pokimonMaster.CatchPokemon(20,1, -1);
//	} catch (InvaildInput& e) {
//		cout << "InvaildInput" << endl;
//	}
//	try {
//		pokimonMaster.FreePokemon(25);
//	} catch (Failure& fail) {
//		cout << "Failure" << endl;
//	}
//
//	try {
//		pokimonMaster.FreePokemon(-1);
//	} catch (InvaildInput& e) {
//		cout << "InvaildInput" << endl;
//	}
//	try {
//		pokimonMaster.EvolvePokemon(5, 6);
//	} catch (Failure& e) {
//		cout << "Failure" << endl;
//	}
//	try {
//		pokimonMaster.EvolvePokemon(3, 5);
//	} catch (Failure& e) {
//		cout << "Failure" << endl;
//	}
//	try {
//		pokimonMaster.EvolvePokemon(-1, 5);
//	} catch (InvaildInput& e) {
//		cout << "InvaildInput" << endl;
//	}
//	try {
//		pokimonMaster.EvolvePokemon(5, -1);
//	} catch (InvaildInput& e) {
//		cout << "InvaildInput" << endl;
//	}
//
////	catch(EmptyTree& fail){
////		int a =5;
////		a=a+1;
////	}
//	pokimonMaster.FreePokemon(1);
//	pokimonMaster.FreePokemon(2);
//	pokimonMaster.FreePokemon(4);
//	pokimonMaster.FreePokemon(6);
//
//	int b = 5;
//	b = b + 1;
//	return true;
//
//}

//bool testGetTopPokemon() {
//	int pokimonId;
//	PokimonMaster pokimonMaster = PokimonMaster();
//	pokimonMaster.addTrainer(1);
//	pokimonMaster.GetTopPokemon(1, &pokimonId);
//
//	ASSERT_EQUALS(-1, pokimonId);
//	pokimonMaster.GetTopPokemon(-1, &pokimonId);
//	ASSERT_EQUALS(-1, pokimonId);
//
//	pokimonMaster.CatchPokemon(1, 1, 2);
//	pokimonMaster.CatchPokemon(2, 1, 2);
//	pokimonMaster.CatchPokemon(3, 1, 2);
//	pokimonMaster.CatchPokemon(4, 1, 2);
//	pokimonMaster.CatchPokemon(6, 1, 2);
//
//	pokimonMaster.GetTopPokemon(1, &pokimonId);
//	ASSERT_EQUALS(1, pokimonId);
//	ASSERT_THROW(Failure, pokimonMaster.GetTopPokemon(2, &pokimonId));
//	ASSERT_THROW(InvaildInput, pokimonMaster.GetTopPokemon(0, &pokimonId));
//	ASSERT_THROW(InvaildInput, pokimonMaster.GetTopPokemon(1, NULL));
//	ASSERT_THROW(InvaildInput, pokimonMaster.GetTopPokemon(20, NULL));
//
//	pokimonMaster.addTrainer(2);
//	pokimonMaster.CatchPokemon(7, 2, 2);
//	pokimonMaster.CatchPokemon(8, 2, 3);
//	pokimonMaster.CatchPokemon(9, 2, 7);
//	pokimonMaster.CatchPokemon(10, 2, 15);
//	pokimonMaster.addTrainer(3);
//	pokimonMaster.CatchPokemon(11, 3, 8);
//
//	pokimonMaster.GetTopPokemon(-1, &pokimonId);
//	ASSERT_EQUALS(10, pokimonId);
//
//	pokimonMaster.printAllTrees();
//
//	pokimonMaster.FreePokemon(1);
//	pokimonMaster.FreePokemon(2);
//	pokimonMaster.FreePokemon(4);
//	pokimonMaster.FreePokemon(6);
//
//	return true;
//
//}

bool testGetAllPokemonsByLevel() {

	PokimonMaster pokimonMaster = PokimonMaster();
	pokimonMaster.addTrainer(1);
	pokimonMaster.CatchPokemon(1, 1, 2);
	pokimonMaster.CatchPokemon(2, 1, 2);
	pokimonMaster.CatchPokemon(3, 1, 2);
	pokimonMaster.CatchPokemon(4, 1, 2);
	pokimonMaster.CatchPokemon(6, 1, 2);
	pokimonMaster.addTrainer(2);
	pokimonMaster.CatchPokemon(7, 2, 2);
	pokimonMaster.CatchPokemon(8, 2, 3);
	pokimonMaster.CatchPokemon(9, 2, 7);
	pokimonMaster.CatchPokemon(10, 2, 15);
	pokimonMaster.addTrainer(3);
	pokimonMaster.CatchPokemon(11, 3, 8);

	int* arr1;
	int numberOfPokimons;
	pokimonMaster.GetAllPokemonsByLevel(1, &(arr1), &numberOfPokimons);
	for (int i = 0; i < numberOfPokimons; i++) {
		cout << (arr1[i]);
	}
	cout << endl;
	free(arr1);

	pokimonMaster.GetAllPokemonsByLevel(2, &(arr1), &numberOfPokimons);
	for (int i = 0; i < numberOfPokimons; i++) {
		cout << (arr1[i]);
	}
	cout << endl;
	free(arr1);
	pokimonMaster.GetAllPokemonsByLevel(3, &(arr1), &numberOfPokimons);
	for (int i = 0; i < numberOfPokimons; i++) {
		cout << (arr1[i]);
	}
	cout << endl;
	free(arr1);
	pokimonMaster.GetAllPokemonsByLevel(-1, &(arr1), &numberOfPokimons);
	for (int i = 0; i < numberOfPokimons; i++) {
		cout << (arr1[i]);
	}
	cout << endl;
	free(arr1);
	try {
		pokimonMaster.GetAllPokemonsByLevel(47, &(arr1), &numberOfPokimons);
	} catch (Failure& e) {
		cout << "Failure" << endl;
	}
	try {
		pokimonMaster.GetAllPokemonsByLevel(1, NULL, &numberOfPokimons);
	} catch (InvaildInput& e) {
		cout << "InvaildInput" << endl;
	}
	try {
		pokimonMaster.GetAllPokemonsByLevel(1, &(arr1), NULL);
	} catch (InvaildInput& e) {
		cout << "InvaildInput" << endl;
	}
	try {
		pokimonMaster.GetAllPokemonsByLevel(0, &(arr1), &numberOfPokimons);
	} catch (InvaildInput& e) {
		cout << "InvaildInput" << endl;
	}
	try {
		pokimonMaster.LevelUp(-1,7);
	} catch (InvaildInput& e) {
		cout << "InvaildInput" << endl;
	}
	try {
		pokimonMaster.LevelUp(3,-1);
	} catch (InvaildInput& e) {
		cout << "InvaildInput" << endl;
	}
	try {
		pokimonMaster.LevelUp(37,7);
	} catch (Failure& e) {
		cout << "failure" << endl;
	}
	int a =0;
	pokimonMaster.GetTopPokemon(2,&a);
	cout<<" "<<(a==10)<<" "<<endl;

	a =0;
	pokimonMaster.GetTopPokemon(-1,&a);
	cout<<" "<<(a==10)<<" "<<endl;

	try {
		pokimonMaster.GetTopPokemon(0,&a);
	} catch (InvaildInput& e) {
		cout << "InvaildInput" << endl;
	}

	try {
		pokimonMaster.LevelUp(1,NULL);
	} catch (InvaildInput& e) {
		cout << "InvaildInput" << endl;
	}
	try {
		pokimonMaster.LevelUp(37,7);
	} catch (Failure& e) {
		cout << "failure" << endl;
	}

	pokimonMaster.printAllTrees();

	pokimonMaster.FreePokemon(1);
	pokimonMaster.FreePokemon(2);
	pokimonMaster.FreePokemon(4);
	pokimonMaster.FreePokemon(6);

	return true;

}
int main() {
	cout << testGetAllPokemonsByLevel() << endl;
}

