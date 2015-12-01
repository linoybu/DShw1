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

bool testUpdeteLevel(){
	PokimonMaster pokimonMaster = PokimonMaster();
	pokimonMaster.addTrainer(1);
	pokimonMaster.CatchPokemon(1, 1, 1);
	pokimonMaster.CatchPokemon(2, 1, 2);
	pokimonMaster.CatchPokemon(3, 1, 3);
	pokimonMaster.CatchPokemon(4, 1, 4);
	pokimonMaster.CatchPokemon(5, 1, 5);
	pokimonMaster.CatchPokemon(6, 1, 6);
	pokimonMaster.CatchPokemon(7, 1, 7);
	pokimonMaster.CatchPokemon(8, 1, 8);
	pokimonMaster.CatchPokemon(9, 1, 9);
	pokimonMaster.CatchPokemon(10, 1, 10);
	pokimonMaster.UpdateLevels(3,3);
	pokimonMaster.printAllTrees();
	int id;
	pokimonMaster.GetTopPokemon(-1,&id);
	ASSERT_EQUALS(id, 9);
	return true;



}

//bool testGetAllPokemonsByLevel() {
//
//	PokimonMaster pokimonMaster = PokimonMaster();
//	pokimonMaster.addTrainer(1);
//	pokimonMaster.CatchPokemon(1, 1, 2);
//	pokimonMaster.CatchPokemon(2, 1, 2);
//	pokimonMaster.CatchPokemon(3, 1, 2);
//	pokimonMaster.CatchPokemon(4, 1, 2);
//	pokimonMaster.CatchPokemon(6, 1, 2);
//	pokimonMaster.addTrainer(2);
//	pokimonMaster.CatchPokemon(7, 2, 2);
//	pokimonMaster.CatchPokemon(8, 2, 3);
//	pokimonMaster.CatchPokemon(9, 2, 7);
//	pokimonMaster.CatchPokemon(10, 2, 15);
//	pokimonMaster.addTrainer(3);
//	pokimonMaster.CatchPokemon(11, 3, 8);

//	int* arr1;
//	int numberOfPokimons;
//	pokimonMaster.GetAllPokemonsByLevel(1, &(arr1), &numberOfPokimons);
//	for (int i = 0; i < numberOfPokimons; i++) {
//		cout << (arr1[i]);
//	}
//	cout << endl;
//	free(arr1);
//
//	pokimonMaster.GetAllPokemonsByLevel(2, &(arr1), &numberOfPokimons);
//	for (int i = 0; i < numberOfPokimons; i++) {
//		cout << (arr1[i]);
//	}
//	cout << endl;
//	free(arr1);
//	pokimonMaster.GetAllPokemonsByLevel(3, &(arr1), &numberOfPokimons);
//	for (int i = 0; i < numberOfPokimons; i++) {
//		cout << (arr1[i]);
//	}
//	cout << endl;
//	free(arr1);
//	pokimonMaster.GetAllPokemonsByLevel(-1, &(arr1), &numberOfPokimons);
//	for (int i = 0; i < numberOfPokimons; i++) {
//		cout << (arr1[i]);
//	}
//	cout << endl;
//	free(arr1);
//	try {
//		pokimonMaster.GetAllPokemonsByLevel(47, &(arr1), &numberOfPokimons);
//	} catch (Failure& e) {
//		cout << "Failure" << endl;
//	}
//	try {
//		pokimonMaster.GetAllPokemonsByLevel(1, NULL, &numberOfPokimons);
//	} catch (InvaildInput& e) {
//		cout << "InvaildInput" << endl;
//	}
//	try {
//		pokimonMaster.GetAllPokemonsByLevel(1, &(arr1), NULL);
//	} catch (InvaildInput& e) {
//		cout << "InvaildInput" << endl;
//	}
//	try {
//		pokimonMaster.GetAllPokemonsByLevel(0, &(arr1), &numberOfPokimons);
//	} catch (InvaildInput& e) {
//		cout << "InvaildInput" << endl;
//	}
//	try {
//		pokimonMaster.LevelUp(-1,7);
//	} catch (InvaildInput& e) {
//		cout << "InvaildInput" << endl;
//	}
//	try {
//		pokimonMaster.LevelUp(3,-1);
//	} catch (InvaildInput& e) {
//		cout << "InvaildInput" << endl;
//	}
//	try {
//		pokimonMaster.LevelUp(37,7);
//	} catch (Failure& e) {
//		cout << "failure" << endl;
//	}
//	int a =0;
//	pokimonMaster.GetTopPokemon(2,&a);
//	cout<<" "<<(a==10)<<" "<<endl;
//
//	a =0;
//	pokimonMaster.GetTopPokemon(-1,&a);
//	cout<<" "<<(a==10)<<" "<<endl;
//
//	try {
//		pokimonMaster.GetTopPokemon(0,&a);
//	} catch (InvaildInput& e) {
//		cout << "InvaildInput" << endl;
//	}
//
//	try {
//		pokimonMaster.LevelUp(1,NULL);
//	} catch (InvaildInput& e) {
//		cout << "InvaildInput" << endl;
//	}
//	try {
//		pokimonMaster.LevelUp(37,7);
//	} catch (Failure& e) {
//		cout << "failure" << endl;
//	}
//
//	pokimonMaster.printAllTrees();
//
//	pokimonMaster.FreePokemon(1);
//	pokimonMaster.FreePokemon(2);
//	pokimonMaster.FreePokemon(4);
//	pokimonMaster.FreePokemon(6);
//
//	return true;

//}


//bool generelTests(){
//	PokimonMaster pokimonMaster = PokimonMaster();
//	ASSERT_THROW(InvaildInput,	pokimonMaster.UpdateLevels(0,5));
//	ASSERT_THROW(InvaildInput,	pokimonMaster.UpdateLevels(3,-2));
//	cout<<"1- no pokimons "<<endl;
//	pokimonMaster.UpdateLevels(99,5);
//	pokimonMaster.printAllTrees();
//
//	for (int i = 1; i <= 10; ++i) {
//		pokimonMaster.addTrainer(i);
//	}
//
//	int k =1;
//	for(int i =1; i<100;i++){
//		for(int j=1;j<25;j++,i++){
//			pokimonMaster.CatchPokemon(i, k, j);
//			k++;
//			if(k==10){
//				k=1;
//			}
//		}
//	}
//
//	pokimonMaster.addTrainer(20);
//	cout<<"2- no pokimons to trainer 20 "<<endl;
//	pokimonMaster.UpdateLevels(7,2);
//	pokimonMaster.printAllTrees();
//
//	cout<<"3- no change "<<endl;
//	pokimonMaster.UpdateLevels(20,2);
//	pokimonMaster.printAllTrees();
//
//
//	return true;
//
//}


int main() {
	//cout << testGetAllPokemonsByLevel() << endl;
cout<<testUpdeteLevel()<<endl;
//cout<<"final result "<<generelTests()<<endl;
}

