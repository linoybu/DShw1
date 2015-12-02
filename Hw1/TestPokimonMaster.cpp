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
#include "library1.h"
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

//bool testUpdeteLevel(){
//	PokimonMaster pokimonMaster = PokimonMaster();
//	pokimonMaster.addTrainer(1);
//	pokimonMaster.CatchPokemon(1, 1, 1);
//	pokimonMaster.CatchPokemon(2, 1, 2);
//	pokimonMaster.CatchPokemon(3, 1, 3);
//	pokimonMaster.CatchPokemon(4, 1, 4);
//	pokimonMaster.CatchPokemon(5, 1, 5);
//	pokimonMaster.CatchPokemon(6, 1, 6);
//	pokimonMaster.CatchPokemon(7, 1, 7);
//	pokimonMaster.CatchPokemon(8, 1, 8);
//	pokimonMaster.CatchPokemon(9, 1, 9);
//	pokimonMaster.CatchPokemon(10, 1, 10);
//	pokimonMaster.UpdateLevels(3,3);
//	pokimonMaster.printAllTrees();
//	int id;
//	pokimonMaster.GetTopPokemon(-1,&id);
//	ASSERT_EQUALS(id, 9);
//	return true;
//
//
//
//}

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


void tryfunc(int** arr){
	*arr = (int*)malloc(sizeof(**arr)*5);
	for(int i =0;i<5;i++){
		int a=1;
		((*arr)[i]) = a;
	}
}

int main() {

void* pokimonMaster=Init();
AddTrainer (pokimonMaster,4);
AddTrainer (pokimonMaster,3);
CatchPokemon (pokimonMaster,101, 4 ,50);
AddTrainer (pokimonMaster,5);
CatchPokemon (pokimonMaster,101, 5 ,25);
CatchPokemon (pokimonMaster,102, 5, 25);
int top;
GetTopPokemon (pokimonMaster,-1,&top);
LevelUp (pokimonMaster,102, 26);
//GetAllPokemonsByLevel(pokimonMaster,-1);
FreePokemon (pokimonMaster,102);
//GetAllPokemonsByLevel(pokimonMaster,-1);
GetTopPokemon (pokimonMaster,5,&top);
EvolvePokemon (pokimonMaster,101, 105);
GetTopPokemon (pokimonMaster,-1,&top);
EvolvePokemon(pokimonMaster, 105, 101);
CatchPokemon(pokimonMaster ,105, 4 ,5);
CatchPokemon(pokimonMaster, 120, 5, 15);
//GetAllPokemonsByLevel(pokimonMaster,-1);
//GetAllPokemonsByLevel (pokimonMaster,4);
//GetAllPokemonsByLevel (pokimonMaster,5);
UpdateLevels (pokimonMaster,5, 4);
int* arr;
GetAllPokemonsByLevel (pokimonMaster,-1,&arr,&top);
Quit(&pokimonMaster);
}

//

//	PokimonMaster pokimonMaster = PokimonMaster();
//	pokimonMaster.addTrainer (4);
//	pokimonMaster.addTrainer (3);
//	pokimonMaster.CatchPokemon(101,4, 50);
//	pokimonMaster.addTrainer(5);
////	pokimonMaster.CatchPokemon (101, 5, 25);
//	pokimonMaster.CatchPokemon (102, 5 ,25);
//	int top;
//	pokimonMaster.GetTopPokemon(-1,&top);
//	pokimonMaster.LevelUp (102, 26);
//	int* arr;
//	int a;
//	pokimonMaster.GetAllPokemonsByLevel(-1,&arr,&a);
//	pokimonMaster.FreePokemon (102);
//	pokimonMaster.GetAllPokemonsByLevel(-1,&arr,&a);
//	pokimonMaster.GetTopPokemon(5,&top);
//int a;
//int *b;
//StatusType stat;
//stat=CatchPokemon (pokimonMaster,288, -3, 174);;
//cout<<stat<<endl;
//stat=GetTopPokemon (pokimonMaster,1,&a);
//cout<<stat<<endl;
//stat=CatchPokemon (pokimonMaster,255, 7, 26);
//cout<<stat<<endl;
//stat=GetAllPokemonsByLevel(pokimonMaster, 101,&b,&a);
//cout<<stat<<endl;
//stat=GetTopPokemon (pokimonMaster,6,&a);
//cout<<stat<<endl;
//stat=CatchPokemon (pokimonMaster,163 ,9 ,332);
//cout<<stat<<endl;
//stat=LevelUp (pokimonMaster,260, 2);
//cout<<stat<<endl;
//stat=AddTrainer (pokimonMaster,3);
//cout<<stat<<endl;
//stat=GetAllPokemonsByLevel (pokimonMaster,273,&b,&a);
//cout<<stat<<endl;
//stat=EvolvePokemon (pokimonMaster,378 ,366);
//cout<<stat<<endl;
//stat=LevelUp (pokimonMaster,289 ,21);
//cout<<stat<<endl;
//stat=UpdateLevels (pokimonMaster,1 ,-2);
//cout<<stat<<endl;
//stat=AddTrainer (pokimonMaster,0);
//cout<<stat<<endl;
//stat=CatchPokemon (pokimonMaster,193, 12, 158);
//cout<<stat<<endl;
//stat=FreePokemon (pokimonMaster,18);
//cout<<stat<<endl;
//stat=GetAllPokemonsByLevel (pokimonMaster,282,&b,&a);
//cout<<stat<<endl;
//stat=LevelUp (pokimonMaster,196 ,8);
//cout<<stat<<endl;
//stat=GetTopPokemon (pokimonMaster,-1,&a);
//cout<<stat<<endl;
//stat=GetAllPokemonsByLevel (pokimonMaster,298,&b,&a);
//cout<<stat<<endl;
//stat=FreePokemon (pokimonMaster,0);
//cout<<stat<<endl;
//stat=GetAllPokemonsByLevel(pokimonMaster, 41,&b,&a);
//cout<<stat<<endl;
//stat=CatchPokemon (pokimonMaster,371 ,-3 ,132);
//cout<<stat<<endl;
//stat=GetAllPokemonsByLevel (pokimonMaster,377,&b,&a);
//cout<<stat<<endl;
//stat=EvolvePokemon (pokimonMaster,247, 92);
//cout<<stat<<endl;
//stat=LevelUp (pokimonMaster,343 ,-5);
//cout<<stat<<endl;
//stat=LevelUp (pokimonMaster,381, 14);
//cout<<stat<<endl;
//stat=FreePokemon (pokimonMaster,-3);
//cout<<stat<<endl;
//stat=UpdateLevels (pokimonMaster,1 ,0);
//cout<<stat<<endl;
//stat=CatchPokemon (pokimonMaster,-20 ,9 ,75);
//cout<<stat<<endl;
//stat=GetAllPokemonsByLevel (pokimonMaster,-2,&b,&a);
//cout<<stat<<endl;
//stat=EvolvePokemon (pokimonMaster,399 ,289);
//cout<<stat<<endl;
//stat=CatchPokemon (pokimonMaster,199, 12, 305);
//cout<<stat<<endl;
//stat=GetTopPokemon (pokimonMaster,17,&a);
//cout<<stat<<endl;
//stat=EvolvePokemon (pokimonMaster,364 ,306);
//cout<<stat<<endl;
//stat=FreePokemon (pokimonMaster,11);
//stat=UpdateLevels (pokimonMaster,2 ,-3);
//stat=CatchPokemon (pokimonMaster,377, 7, 136);
//stat=AddTrainer (pokimonMaster,-2);
//stat=LevelUp (pokimonMaster,188 ,-3);
//stat=CatchPokemon (pokimonMaster,393, -5, 441);
//stat=GetTopPokemon (pokimonMaster,6,&a);
//Quit(&pokimonMaster);
//int l=5;
//}

