///*
// * main.cpp
// *
// *  Created on: Nov 16, 2015
// *      Author: linoy
// */
//#include "Pokimon.h"
//#include "Trainer.h"
//#include "mtmtest.h"
//#include "AVLTree.h"
//#include "pair.h"
//using std::cout;
//using std::endl;
//
//class Sum {
//	int s;
//public:
//	Sum() :
//			s(0) {
//	}
//	;
//	void operator()(int x, int value) {
//		s += value;
//	}
//
//	int getSum() {
//		return this->s;
//	}
//};
//
//class print {
//public:
//	void operator()(int x, int value) {
//		cout << value << ",";
//	}
//};
//
//class CompareInt {
//public:
//	int operator()(int& x, int& y) {
//		return (x - y);
//	}
//};
//
//class BiggerFromInt {
//	int i;
//public:
//	BiggerFromInt(int i = 0) :
//			i(i) {
//	}
//	;
//	bool operator()(int& key, int& value) {
//		return (key > i);
//	}
//};
//
///*****************************************************************************/
////trainer test:
//bool trainerTest() {
//	Trainer trainer1 = Trainer(12);
//	Trainer trainer2 = Trainer(13);
//	Trainer trainer3 = Trainer(13);
//	ASSERT_EQUALS(false, trainer1 == trainer2);
//	ASSERT_EQUALS(true, trainer3 == trainer2);
//	ASSERT_THROW(InvaildInput, Trainer(0));
//	ASSERT_THROW(InvaildInput, Trainer(-5));
//	ASSERT_EQUALS(trainer3.getId(), trainer2.getId());
//	Pokimon pokimon1 = Pokimon(1, 1);
//	Pokimon pokimon2 = Pokimon(2, 2);
//	Pokimon pokimon3 = Pokimon(3, 3);
//	trainer1.setBestPokimon(&pokimon1);
//	trainer2.setBestPokimon(&pokimon1);
//	ASSERT_EQUALS(trainer1.getBestPokimon()->getId(),trainer2.getBestPokimon()->getId());
//	trainer1.addPokimon(pokimon1);
//	trainer1.addPokimon(pokimon2);
//	trainer1.addPokimon(pokimon3);
//	ASSERT_EQUALS(3, trainer1.getNumberOfPokimons());
//	ASSERT_EQUALS(trainer1.getBestPokimon()->getId(),pokimon3.getId());
//
//	//remove pokimpns:
//
//	int c=3;
//	pair<int,int> key3= pair<int,int>(c,c);
//	trainer1.removePokimon(key3);
//	ASSERT_EQUALS(trainer1.getBestPokimon()->getId(),pokimon2.getId());
//	ASSERT_EQUALS(2, trainer1.getNumberOfPokimons());
//	int a=1,b=2;
//	pair<int,int> key2= pair<int,int>(b,b);
//	pair<int,int> key1= pair<int,int>(a,a);
//	trainer1.removePokimon(key2);
//	ASSERT_EQUALS(trainer1.getBestPokimon()->getId(),pokimon1.getId());
//		ASSERT_EQUALS(1, trainer1.getNumberOfPokimons());
//	trainer1.removePokimon(key1);
//	ASSERT_EQUALS(0, trainer1.getNumberOfPokimons());
//	ASSERT_EQUALS(trainer1.getBestPokimon(),NULL);
//
//	return true;
//}
///******************************************************************************/
////void fromArr(){
////	int a=1,b=2,c=3,d=4,e=5,f=6,h=7,i=8,j=9,l=10;
////	pair<int,int> a1 = pair<int,int>(a,a);
////	pair<int,int> b1 = pair<int,int>(b,b);
////	pair<int,int> c1 = pair<int,int>(c,c);
////	pair<int,int> d1 = pair<int,int>(d,d);
////	pair<int,int> e1 = pair<int,int>(e,e);
////	pair<int,int> f1 = pair<int,int>(f,f);
////	pair<int,int> h1 = pair<int,int>(h,h);
////	pair<int,int> i1 = pair<int,int>(i,i);
////	pair<int,int> j1 = pair<int,int>(j,j);
////	pair<int,int> l1 = pair<int,int>(l,l);
////	pair<int,int> arr[] = {a1,b1,c1,d1,e1,f1,h1,i1,j1,l1};
////	AVLTree<int,int,CompareInt> tree =  AVLTree<int,int,CompareInt>();
////	tree.arrToAvlTree(10,arr);
////	print p1 =print();
////	cout <<"inOrder:"<<endl;
////	tree.inOrder(p1);
////	cout <<endl;
////
////}
////bool toArr() {
////AVLTree<int,int,CompareInt> T= AVLTree<int,int,CompareInt>();
////int a=1,b=2,c=3,d=4,e=5,f=6,h=7,i=8,j=9,l=10;
////T.addVertices(&a,&a);
////T.addVertices(&b,&b);
////T.addVertices(&c,&c);
////T.addVertices(&d,&d);
////T.addVertices(&d,&d); //** check double
////T.addVertices(&e,&e);
////T.addVertices(&f,&f);
////T.addVertices(&h,&h);
////T.addVertices(&i,&i);
////T.addVertices(&j,&j);
////T.addVertices(&l,&l);
////
////BiggerFromInt function =BiggerFromInt(3);
////cout <<"bigger then 3:"<<endl;
////pair<int, int>** arr=new pair<int, int>*[T.getNumOfVertices()];
////
////int size=0;
////T.toArr(arr,&size,function);
////for(int k=0; k<size;k++){
////	cout <<arr[k]->getKey()<<",";
////}
////cout <<endl;
////
//////for (int k=0;k<*size;k++){
//////			delete arr[k];
//////		}
//////		delete arr;
////
////	return true;
////}
////bool tours() {
////AVLTree<int,int,CompareInt> T= AVLTree<int,int,CompareInt>();
////int a=1,b=2,c=3,d=4,e=5,f=6,h=7,i=8,j=9,l=10;
////T.addVertices(&a,&a);
////T.addVertices(&b,&b);
////T.addVertices(&c,&c);
////T.addVertices(&d,&d);
////T.addVertices(&e,&e);
////T.addVertices(&f,&f);
////T.addVertices(&h,&h);
////T.addVertices(&i,&i);
////T.addVertices(&j,&j);
////T.addVertices(&l,&l);
////Sum s1 =Sum();
////Sum s2 =Sum();
////T.inOrder(s1);
////T.postOrder(s2);
////ASSERT_EQUALS(s1.getSum(), s2.getSum());
////print p1 =print();
////cout <<"inOrder:"<<endl;
////T.inOrder(p1);
////cout <<endl;
//////** will print: 1 2 3 4 5 6 7 8 9 10
////cout <<"postOrder:"<<endl;
////T.postOrder(p1);
////cout <<endl;
//////** will print: 1 3 2 5 7 6 10 9 8 4
////cout <<"preOrder:"<<endl;
////T.preOrder(p1);
////cout <<endl;
//////** will print: 4 2 1 3 8 6 5 7 9 10
////ASSERT_EQUALS(10, T.getMax());
////ASSERT_EQUALS(10, T.getNumOfVertices());
////
////cout <<endl;
////
////
////
////	return true;
////}
////bool findTest() {
////AVLTree<int,int,CompareInt> T= AVLTree<int,int,CompareInt>();
////int a=1,b=2,c=3,d=4,e=5,f=6;
////T.addVertices(&a,&a);
////T.addVertices(&b,&b);
////T.addVertices(&c,&c);
////T.addVertices(&d,&d);
////T.addVertices(&e,&e);
////ASSERT_EQUALS(a, T.find(a));
////ASSERT_EQUALS(b, T.find(b));
////ASSERT_EQUALS(c, T.find(c));
////ASSERT_THROW(NotINTheTree,T.find(f));
////	return true;
////}
////bool pairTest() {
////	int a = 1,c=1, b = 2,d=3;
////	pair<int, int> p1 = pair<int, int>(a, b);
////	pair<int, int> p2 = pair<int,int>(c, d);
////	pair<int, int>* p3 = new pair<int,int>(c, d);
////	ASSERT_EQUALS(1, p1.getKey());
////	ASSERT_EQUALS(p1.getKey(), p2.getKey());
////	ASSERT_EQUALS(p2.getKey(), p3->getKey());
////	ASSERT_EQUALS(p1.getValue(), 2);
////	ASSERT_EQUALS(p2.getValue(), 3);
////	int key1 = 5;
////	p1.setKey(key1);
////	p1.setValue(key1);
////	ASSERT_EQUALS(p1.getValue(), p1.getKey());
////	return true;
////}
////bool pokimonTest() {
////	Pokimon pokimon = Pokimon(1, 1);
////	ASSERT_EQUALS(1, pokimon.getId());
////	ASSERT_EQUALS(1, pokimon.getLevel());
////	ASSERT_THROW(InvaildInput, pokimon.setLevel(-1));
////	pokimon.setId(5);
////	ASSERT_EQUALS(5, pokimon.getId());
////	pokimon.setLevel(4);
////	ASSERT_EQUALS(4, pokimon.getLevel());
////	ASSERT_THROW(InvaildInput, Pokimon(-1, 1));
////	return true;
////
////}
////bool nodeTest(){
////	int a=5,b=6,c=4;
////	int key = 5;
////
////	Node<int,int> node=  Node<int,int>(&a,&a);
////	Node<int,int>* leftnode = new Node<int,int>(&b,&b);
////	Node<int,int>* rightnode = new Node<int,int>(&c,&c);
////	node.setLeftSon(leftnode);
////	node.setRightSon(rightnode);
////	leftnode->setFather(&node);
////	rightnode->setFather(&node);
////	rightnode->amIRightSon();
////}
////bool AvlTest(){
////	int a=5,b=6,c=4,d=10,e=20,f=25,g=7,h=9;
////	AVLTree<int,int> tree= AVLTree<int,int>();
////	tree.addVertices(&a,&a);
////	tree.addVertices(&b,&b);
////	tree.addVertices(&c,&c);
////	tree.addVertices(&d,&d);
////	tree.addVertices(&e,&e);
////	tree.addVertices(&f,&f);
////	tree.addVertices(&g,&g);
////	tree.addVertices(&h,&h);
////	tree.deleteVertice(f);
////	int k = 5;
////}
//int main() {
//	cout << "test" << trainerTest() << endl;
////cout <<"toArr" << toArr() << endl;
////cout <<"tours" << tours() << endl;
////cout <<"findTest" << findTest() << endl;
////cout <<"pairTest" << pairTest() << endl;
////cout <<"pokimonTest " << pokimonTest() << endl;
////	nodeTest();
////	AvlTest();
////fromArr();
//
//}
//
