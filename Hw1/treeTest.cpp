///*
// * treeTest.cpp
// *
// *  Created on: 21 бреб 2015
// *      Author: Lior
// */
//
//#include <stdio.h>
//#include "exception.h"
//#include "mtmtest.h"
//#include "AVLTree.h"
//#include "pair.h"
//
////using std::cout;
////using std::endl;
////
////class fatherMatchSon {
////public:
////	bool IsTrue;
////	fatherMatchSon() {
////		this->IsTrue = true;
////	}
////	;
////	void operator()(Node<int, int>* ptr) {
////		if (ptr->getLeftSon() == NULL && ptr->getRightSon() != NULL) {
////			this->IsTrue = (this->IsTrue
////					&& (ptr->getRightSon()->getFather() == ptr));
////			return;
////		}
////
////		if (ptr->getLeftSon() != NULL && ptr->getRightSon() == NULL) {
////			this->IsTrue = (this->IsTrue
////					&& (ptr->getLeftSon()->getFather() == ptr));
////			return;
////		}
////		if (ptr->getLeftSon() != NULL && ptr->getRightSon() != NULL) {
////			return;
////		}
////		this->IsTrue = (this->IsTrue && (ptr->getLeftSon()->getFather() == ptr)
////				&& (ptr->getRightSon()->getFather() == ptr));
////
////	}
////};
////
////
////bool IsAllTheSonsBelongToThierFater(AVLTree<int, int> T) {
////	fatherMatchSon f = fatherMatchSon();
////	T.inOrder(f);
////	ASSERT_EQUALS(true, f.IsTrue);
////	return true;
////}
//
////bool pairTest() {
////
////
//////	pair<int,int> p2=new pair(1,3);
//////	ASSERT_EQUALS(1, p1.getKey());
//////	ASSERT_EQUALS(p1.getKey(), p2.getKey());
//////	ASSERT_EQUALS(p1.getValue(), 2);
//////	ASSERT_EQUALS(p2.getValue(), 3);
//////	int key1=5,key2=8;
//////	p1.setKey(*key1);
////
////return true;
////}
////
////int main() {
////	AVLTree<int, int> T;
////	cout << "IsAllTheSonsBelongToThierFater:"
////			<< IsAllTheSonsBelongToThierFater(T) << endl;
////
////}
////
