#ifndef AVLTREE_H_
#define AVLTREE_H_
#include <stdio.h>
#include "exception.h"
#include "pair.h"
#include <math.h>
#include <cstdlib>
#include <stddef.h>
#include <new>
//using std::cout;
//using std::endl;

//************************************test
//class print1 {
//public:
//	void operator()(int x, int value) {
//		cout << value << ",";
//	}
//};

/**************************************helper classes**************************/

/**********************************node class**********************************/

template<class T, class Key>
class Node {
	Node<T, Key>* father;
	Node<T, Key>* leftSon;
	Node<T, Key>* rightSon;
	T* value;
	Key* key;
	int height;

public:
	Node();
	Node(T* value, Key* key, Node<T, Key>* father = NULL,
			Node<T, Key>* rightSon = NULL, Node<T, Key>* leftSon = NULL,
			int height = 0);
	~Node();
	void setLeftSon(Node<T, Key>* leftSon);
	void setRightSon(Node<T, Key>* rightSon);
	void setFather(Node<T, Key>* father);
	Node<T, Key>* getLeftSon();
	Node<T, Key>* getRightSon();
	Node<T, Key>* getFather();
	void setNode(Node<T, Key>* father, Node<T, Key>*Lson, Node<T, Key>* Rson,
			int h);
	void setheight(int i);
	int getheight();
	void setKey(Key* key);
	Key* getKey();
	void setValue(T* value);
	T* getValue();
	bool amIRightSon();
	bool NeedRoll();
	int getMaxSonHeight();
};

template<class T, class Key>
bool Node<T, Key>::amIRightSon() {
	return ((this->father)->rightSon == this);
}

template<class T, class Key>
Node<T, Key>::Node(T* value, Key* key, Node<T, Key>* father,
		Node<T, Key>* rightSon, Node<T, Key>* leftSon, int height) :
		father(father), leftSon(leftSon), rightSon(rightSon), value(
				new T(*value)), key(new Key(*key)), height(height) {
}
template<class T, class Key>
Node<T, Key>::Node() :
		father(NULL), leftSon(NULL), rightSon(NULL), value(NULL), key(NULL), height(
				0) {

}

template<class T, class Key>
void Node<T, Key>::setLeftSon(Node<T, Key>* leftSon) {
	if (!this) {
		return;
	}
	this->leftSon = leftSon;
}
template<class T, class Key>
void Node<T, Key>::setRightSon(Node<T, Key>* rightSon) {
	if (!this) {
		return;
	}
	this->rightSon = rightSon;
}
template<class T, class Key>
void Node<T, Key>::setFather(Node<T, Key>* father) {
	if (!this) {
		return;
		//** in the rolls if there is no son
		//** we should'nt try put in null father.
	}
	this->father = father;
}
template<class T, class Key>
void Node<T, Key>::setNode(Node<T, Key>* father, Node<T, Key>*Lson,
		Node<T, Key>* Rson, int h) {
	this->father = father;
	this->leftSon = Lson;
	this->rightSon = Rson;
	this->height = h;

}

template<class T, class Key>
int Node<T, Key>::getMaxSonHeight() {
	return ((this->getLeftSon()->getheight() > this->getRightSon()->getheight()) ?
			this->getLeftSon()->getheight() : this->getRightSon()->getheight());
}

template<class T, class Key>
Node<T, Key>* Node<T, Key>::getLeftSon() {
	if (!this) {
		return NULL;
	}
	return this->leftSon;
}
template<class T, class Key>
Node<T, Key>* Node<T, Key>::getRightSon() {
	if (!this) {
		return NULL;
	}
	return this->rightSon;
}
template<class T, class Key>
Node<T, Key>* Node<T, Key>::getFather() {
	if (!this) {
		return NULL;
	}
	return father;
}

//destroying one node will destroy all his sons
template<class T, class Key>
Node<T, Key>::~Node() {
	delete value;
	delete key;
	delete leftSon;
	delete rightSon;
	leftSon = NULL;
	rightSon = NULL;
	value = NULL;
	key = NULL;
}

template<class T, class Key>
void Node<T, Key>::setheight(int i) {
	if (!this) {
		return;
	}
	this->height = i;
}
template<class T, class Key>
int Node<T, Key>::getheight() {
	if (!this) {
		return -1; //if i don't exist my height is (-1) so my father height will be 0
	}
	return this->height;
}
template<class T, class Key>
void Node<T, Key>::setKey(Key* key) {
	if (!this) {
		return;
	}
	this->key = key;
}
template<class T, class Key>
Key* Node<T, Key>::getKey() {
	if (!this) {
		return NULL;
	}
	return key;
}
template<class T, class Key>
void Node<T, Key>::setValue(T* value) {
	if (!this) {
		return;
	}
	this->value = value;
}
template<class T, class Key>
T* Node<T, Key>::getValue() {
	if (!this) {
		return NULL;
	}
	return this->value;
}

///*********************End Node class*****************************************/

/*********************************class AVLTree********************************/
template<class T, class Key, class CompareKey>
class AVLTree {
	Node<T, Key>* root;
	int numOfVertices;

	//*** private helper functions:

	// recursive function for tours at the  tree:
	template<class inScanFunc>
	void inOrderRec(inScanFunc& scanfunc, Node<T, Key>* ptr) {
		if (ptr == NULL) {
			return;
		}
		inOrderRec(scanfunc, ptr->getLeftSon());
		scanfunc(*(ptr->getKey()), *(ptr->getValue()));
		inOrderRec(scanfunc, ptr->getRightSon());
	}

	template<class inScanFunc>
	void NodeinOrderRec(inScanFunc& scanfunc, Node<T, Key>* ptr) {
		if (ptr == NULL) {
			return;
		}
		NodeinOrderRec(scanfunc, ptr->getLeftSon());
		scanfunc(ptr);
		NodeinOrderRec(scanfunc, ptr->getRightSon());

	}

	template<class invScanFunc>
	void invarsinOrderRec(invScanFunc& scanfunc, Node<T, Key>* ptr) {
		if (ptr == NULL) {
			return;
		}
		invarsinOrderRec(scanfunc, ptr->getRightSon());
		invarsinOrderRec(scanfunc, ptr->getLeftSon());
		scanfunc(ptr);
	}

	template<class postScanFunc>
	void postOrderRec(postScanFunc& scanfunc, Node<T, Key>* ptr) {
		if (ptr == NULL) {
			return;
		}
		postOrderRec(scanfunc, ptr->getLeftSon());
		postOrderRec(scanfunc, ptr->getRightSon());
		scanfunc(*(ptr->getKey()), *(ptr->getValue()));
	}

	template<class preScanFunc>
	void preOrderRec(preScanFunc& scanfunc, Node<T, Key>* ptr) {
		if (ptr == NULL) {
			return;
		}
		scanfunc(*(ptr->getKey()), *(ptr->getValue()));
		preOrderRec(scanfunc, ptr->getLeftSon());
		preOrderRec(scanfunc, ptr->getRightSon());
	}

	Node<T, Key>* minimumNode(Node<T, Key>* curNode) {
//		while (curNode->getFather()) {
//			curNode = curNode->getFather();
//		}
		while (curNode->getLeftSon()) {
			curNode = curNode->getLeftSon();
		}
		return curNode;
	}
	///**** Rolls:
	void LLRoll(Node<T, Key>* node) {
		Node<T, Key>* leftNode = node->getLeftSon();
		Node<T, Key>* leftRightNode = leftNode->getRightSon();
		Node<T, Key>* fatherNode = node->getFather();
		node->setLeftSon(leftRightNode);
		leftNode->setRightSon(node);
		if (fatherNode->getRightSon() == node) {
			fatherNode->setRightSon(leftNode);
		} else {
			fatherNode->setLeftSon(leftNode);
		}
		leftRightNode->setFather(node);
		leftNode->setFather(fatherNode);
		node->setFather(leftNode);
		node->setheight(node->getMaxSonHeight() + 1);
		leftNode->setheight(leftNode->getMaxSonHeight() + 1);
		if (node == root) {
			this->root = leftNode;
		}

	}

	void RRRoll(Node<T, Key>* node) {
		Node<T, Key>* rightNode = node->getRightSon();
		Node<T, Key>* rightLeftNode = rightNode->getLeftSon();
		Node<T, Key>* fatherNode = node->getFather();
		node->setRightSon(rightLeftNode);
		rightNode->setLeftSon(node);
		if (fatherNode->getLeftSon() == node) {
			fatherNode->setLeftSon(rightNode);
		} else {
			fatherNode->setRightSon(rightNode);
		}
		rightLeftNode->setFather(node);
		rightNode->setFather(fatherNode);
		node->setFather(rightNode);
		node->setheight(node->getMaxSonHeight() + 1);
		rightNode->setheight(rightNode->getMaxSonHeight() + 1);
		if (node == root) {
			this->root = rightNode;
		}

	}
	void LRRoll(Node<T, Key>* node) {
		RRRoll(node->getLeftSon());
		LLRoll(node);
	}
	void RLRoll(Node<T, Key>* node) {
		LLRoll(node->getRightSon());
		RRRoll(node);
	}

	Node<T, Key>* findNodeReq(Key& key, Node<T, Key>* ptr,
			CompareKey compFunc) {
		if (!ptr->getLeftSon() && !ptr->getRightSon()) {
			return ptr;
		}
		if (compFunc(*(ptr->getKey()), key) == 0) {
			return ptr;
		}
		if (compFunc(*(ptr->getKey()), key) > 0) {
			return findNodeReq(key, ptr->getLeftSon(), compFunc);
		}
		return findNodeReq(key, ptr->getRightSon(), compFunc);

	}

	void rolls(Node<T, Key>* ptr) {
		int leftHigh = ptr->getLeftSon()->getheight();
		int rightHigh = ptr->getRightSon()->getheight();
		int height = leftHigh - rightHigh;

		switch (height) {
		case 2:
			leftHigh = ptr->getLeftSon()->getLeftSon()->getheight();
			rightHigh = ptr->getLeftSon()->getRightSon()->getheight();
			height = leftHigh - rightHigh;
			if (height >= 0) {
				LLRoll(ptr);
			} else
				LRRoll(ptr);
			break;

		case (-2):
			leftHigh = ptr->getRightSon()->getLeftSon()->getheight();
			rightHigh = ptr->getRightSon()->getRightSon()->getheight();
			height = leftHigh - rightHigh;
			if (height <= 0) {
				RRRoll(ptr);
			} else
				RLRoll(ptr);
			break;
		default:
			return;
		}
	}
	void removeIfNoSons(Node<T, Key>* delNode) {
		Node<T, Key>* father = delNode->getFather();
		//**no father and no son, its root
		if (!father) {
			root = NULL;
			return;
		}
		if (delNode->amIRightSon()) {
			father->setRightSon(NULL);
		} else {
			father->setLeftSon(NULL);
		}
		father->setheight(father->getMaxSonHeight() + 1);

	}

	//remove vartic in case the vartic have only one son
	void removeVarticIfOneSon(Node<T, Key>* delNode) {
		Node<T, Key>* delNodeFather = delNode->getFather();
		bool isLeftExist = delNode->getLeftSon() != NULL;
		bool isRightExist = delNode->getRightSon() != NULL;
		//** do if the right son exist and the left not
		if (!isRightExist && isLeftExist) {
			//** if the dellNode is a right son, we connect the
			//** dellNode son to the right of the dellNode father
			if (delNode == root) {
				root = delNode->getLeftSon();
				delNode->getLeftSon()->setFather(NULL);
			} else if (delNode->amIRightSon()) {
				delNodeFather->setRightSon(delNode->getLeftSon());
				delNode->getLeftSon()->setFather(delNodeFather);
			} else {
				delNodeFather->setLeftSon(delNode->getLeftSon());
				delNode->getLeftSon()->setFather(delNodeFather);
			}

			//*** do if the left son exist
		} else if (!isLeftExist && isRightExist) {
			if (delNode == root) {
				root = delNode->getRightSon();
				delNode->getRightSon()->setFather(NULL);
			} else if (delNode->amIRightSon()) {
				delNodeFather->setRightSon(delNode->getRightSon());
				delNode->getRightSon()->setFather(delNodeFather);
			} else {
				delNodeFather->setLeftSon(delNode->getRightSon());
				delNode->getRightSon()->setFather(delNodeFather);
			}
		}
		delNode->setLeftSon(NULL);
		delNode->setRightSon(NULL);
		delNodeFather->setheight(delNodeFather->getMaxSonHeight());

	}

	void swapVartics(Node<T, Key>*& firstNode, Node<T, Key>*& secNode) {
		T* tempValue = (firstNode)->getValue();
		Key* tempKey = (firstNode)->getKey();
		(firstNode)->setValue((secNode)->getValue());
		(firstNode)->setKey((secNode)->getKey());
		(secNode)->setValue(tempValue);
		(secNode)->setKey(tempKey);
		Node<T, Key>* tempNode = firstNode;
		firstNode = secNode;
		secNode = tempNode;
//		Node<T, Key>* tempFather = firstNode->getFather();
//		Node<T, Key>* tempLSon = firstNode->getLeftSon();
//		Node<T, Key>* tempRSon = firstNode->getRightSon();
//		int tempHigh = firstNode->getheight();
//		if (firstNode->getLeftSon() == secNode) {	//**firstnode father of secnode from left
//			firstNode->setNode(secNode, secNode->getLeftSon(),
//					secNode->getRightSon(), secNode->getheight());
//			secNode->setNode(tempFather, firstNode,tempRSon, tempHigh);
//		}
//		else if (firstNode->getRightSon() == secNode) {	//**firstnode father of secnode from right
//			firstNode->setNode(secNode, secNode->getLeftSon(),
//					secNode->getRightSon(), secNode->getheight());
//			secNode->setNode(tempFather, tempLSon,secNode, tempHigh);
//		}
//		else if (secNode->getLeftSon() == firstNode) {	//**secnode father of firstnode
//			secNode->setNode(firstNode, firstNode,tempRSon, tempHigh);
//			firstNode->setNode(secNode->getFather(), secNode,
//					secNode->getRightSon(), secNode->getheight());
//		}
//		else if (secNode->getRightSon() == firstNode) {	//**firstnode father of secnode
//			secNode->setNode(firstNode, firstNode,tempRSon, tempHigh);
//			firstNode->setNode(secNode->getFather(), secNode->getLeftSon(),
//							secNode, secNode->getheight());
//		}
//		else{
//			firstNode->setNode(secNode->getFather(), secNode->getLeftSon(),
//				secNode->getRightSon(), secNode->getheight());
//		secNode->setNode(tempFather, tempLSon,tempRSon, tempHigh);
//		}
	}

	//remove vartic in case the vartic have 2 sons
	void removeVarticIfTwoSons(Node<T, Key>*& delNode) {
		Node<T, Key>* minLergerThenDelNode = this->minimumNode(
				delNode->getRightSon());
		if (root == delNode) {
			this->root = delNode;
		}
		//** the height is swapping as well, and the remove from one son fix the height
		this->swapVartics(delNode, minLergerThenDelNode);

		if (!delNode->getLeftSon() && !delNode->getRightSon()) {
			removeIfNoSons(delNode);
		} else {
			removeVarticIfOneSon(delNode);
		}
	}

	Node<T, Key>* deleteVerticeReq(Node<T, Key>* ptr, Key& key,
			CompareKey& compareFunc) {
		//*** if no sons, we got a leaf and we did'nt found the right key
		if (!ptr) {
			return ptr;
		}
		//** if we found the vertices
		if (compareFunc(*ptr->getKey(), key) == 0) {
			bool isLeftExist = ptr->getLeftSon() != NULL;
			bool isRightExist = ptr->getRightSon() != NULL;
			//** if no sons we can just delete it
			if (!isLeftExist && !isRightExist) {
				removeIfNoSons(ptr);
				//**  if only one son exist
			} else if (!isRightExist || !isLeftExist) {
				removeVarticIfOneSon(ptr);
			} else {
				removeVarticIfTwoSons(ptr);
			}
			return ptr;
		}
		if (compareFunc(*ptr->getKey(), key) > 0) {
			Node<T, Key>* node = deleteVerticeReq(ptr->getLeftSon(), key,
					compareFunc);
			ptr->setheight(ptr->getMaxSonHeight() + 1);
			rolls(ptr);
			return node;
		} else {
			Node<T, Key>* node = deleteVerticeReq(ptr->getRightSon(), key,
					compareFunc);
			ptr->setheight(ptr->getMaxSonHeight() + 1);
			rolls(ptr);
			return node;
		}
	}
	bool addVerticeRec(Node<T, Key>* ptr, Key& key,
			Node<T, Key>* nodeToInsert) {
		CompareKey comparefunc = CompareKey();
		//**if the key already exist
		if (comparefunc(*ptr->getKey(), key) == 0) {
			return false;
		}
		//** if no sons at all - we got a leaf
		if (!ptr->getLeftSon() && !ptr->getRightSon()) {
			//** no sons, check if to put the newNode in left or right
			if (comparefunc(*(ptr->getKey()), key) < 0) {
				ptr->setRightSon(nodeToInsert);
				nodeToInsert->setFather(ptr);
				//** we got new node, we need to check if height need to be
				//**updated
				ptr->setheight(ptr->getMaxSonHeight() + 1);
//				if (!ptr->getLeftSon()) {
//					ptr->setheight((ptr->getheight()) + 1);
//				}
			} else {
				ptr->setLeftSon(nodeToInsert);
				nodeToInsert->setFather(ptr);
				//** we got new node, we need to check if height need to be
				//**updated
				ptr->setheight(ptr->getMaxSonHeight() + 1);
//				if (!ptr->getRightSon()) {
//					ptr->setheight((ptr->getheight()) + 1);
//				}
			}
			//** we add the node and updated, return.
			return true;

			//** if no left son but right son exist, add to the left
			//ptr.key>key
		} else if (!ptr->getLeftSon() && comparefunc(*ptr->getKey(), key) > 0) {
			ptr->setLeftSon(nodeToInsert);
			nodeToInsert->setFather(ptr);
			//** Because we have right son no need to fix height
			return true;
		} else if (!ptr->getRightSon()
				&& comparefunc(*ptr->getKey(), key) < 0) {
			ptr->setRightSon(nodeToInsert);
			nodeToInsert->setFather(ptr);
			return true;
			//** Because we have right son no need to fix height
		}
		//** if we are still not in the end of the tree
		//** if we found the same key, do'nt add it
		if (comparefunc(*ptr->getKey(), key) == 0) {
			return true;
			//** if we need to put it in the left
		} else if (comparefunc(*ptr->getKey(), key) > 0) {
			bool vertAdd = addVerticeRec(ptr->getLeftSon(), key, nodeToInsert);
			ptr->setheight(ptr->getMaxSonHeight() + 1);
//			if (ptr->getLeftSon()->getheight()
//					> ptr->getRightSon()->getheight()) {
//				ptr->setheight(ptr->getheight() + 1);
//			}
			rolls(ptr);
			return vertAdd;
			//**if we need to put it in the right
		} else {
			bool vertAdd = addVerticeRec(ptr->getRightSon(), key, nodeToInsert);
			//** before we add the new vertice the rightson.height = leftson.highet
			//** or > in 1, or < in 1. if == after the change, it will be bigger
			//** and we need to update, if > need to be update, and if <
			//** no need to update
			ptr->setheight(ptr->getMaxSonHeight() + 1);
			rolls(ptr);
			return vertAdd;
		}
	}

	Node<T, Key>* fillTreeWithBlankNodes(int height, Node<T, Key>* father) {
		if (!height) {
			return NULL;
		}

		Node<T, Key>* node = new Node<T, Key>();
		node->setFather(father);
		node->setheight(height - 1);
		node->setRightSon(fillTreeWithBlankNodes(height - 1, node));
		node->setLeftSon(fillTreeWithBlankNodes(height - 1, node));
		return node;
	}

public:
	AVLTree();
	AVLTree(const AVLTree<T, Key, CompareKey>&);
	~AVLTree();
	void cleanTree();
	T* find(Key& key);
	T* deleteVertice(Key& key);
	template<class inScanFunc>
	void inOrder(inScanFunc& scanfunc);
	template<class preScanFunc>
	void preOrder(preScanFunc& scanfunc);
	template<class postScanFunc>
	void postOrder(postScanFunc& scanfunc);
	template<class FilterFunc>
	void toArr(pair<T, Key>** arr, int* size, FilterFunc& filter);
	T& getMax();
	int getNumOfVertices();
	void addVertices(T* value, Key* key);
	void arrToAvlTree(int arrSize, pair<T, Key>** arr);


	//****TODO deltet it
	template<class inScanFunc>
	void NodeInOrder(inScanFunc scan);
};

///*****TODO for test delete it!!
template<class T, class Key, class CompareKey>
template<class inScanFunc>
void AVLTree<T, Key, CompareKey>::NodeInOrder(inScanFunc scan) {
	this->NodeinOrderRec(scan, this->root);

}

///****

///***** functions Realizations
//* constructor and destructor
template<class T, class Key, class CompareKey>
AVLTree<T, Key, CompareKey>::AVLTree() :
		root(NULL), numOfVertices(0) {
}

template<class T, class Key, class CompareKey>
AVLTree<T, Key, CompareKey>::AVLTree(const AVLTree<T, Key, CompareKey>& tree) :
		root(tree.root), numOfVertices(tree.numOfVertices) {
}

template<class T, class Key, class CompareKey>
AVLTree<T, Key, CompareKey>::~AVLTree() {
	delete (root);
}
//*
template<class T, class Key, class CompareKey>
void AVLTree<T, Key, CompareKey>::cleanTree(){
	delete (root);
	root = NULL;
	this->numOfVertices=0;
}

template<class T, class Key, class CompareKey>
void AVLTree<T, Key, CompareKey>::addVertices(T* value, Key* key) {
	Node<T, Key>* newNode = new Node<T, Key>(value, key);
	if (!root) {
		root = newNode;
		this->numOfVertices++;
		return;
	}
	bool verticesAdd = this->addVerticeRec(this->root, *key, newNode);
	if (!verticesAdd) {
		delete newNode;
		throw Failure();
	}
	this->numOfVertices++;

}

/*class for return array of elements from the tree that comply with the terms of
 *  Filterfunc*/
template<class T, class Key, class CompareKey, class FilterFunc>
class funcFillArray {
	int i; //index
	int size;
	FilterFunc f;
	pair<T, Key>** pairArr;

public:

	funcFillArray(int size, FilterFunc& f, pair<T, Key>** arr) :
			i(0), size(size), f(f), pairArr(arr) {

	}

	void operator()(Key& key, T& value) {

		if (f(key, value)) {
			pairArr[this->i] = new pair<T, Key>(key, value);
			this->i++;
		}
	}
	pair<T, Key>** getArr() {
		return this->pairArr;
	}

	int getNumOfElements() {
		return this->i;
	}
};
template<class T, class Key, class CompareKey>
template<class FilterFunc>
void AVLTree<T, Key, CompareKey>::toArr(pair<T, Key>** arr, int* size,
		FilterFunc& filter) {
	*size = this->getNumOfVertices();
	funcFillArray<T, Key, CompareKey, FilterFunc> func = funcFillArray<T, Key,
			CompareKey, FilterFunc>(*size, filter, arr);
	this->inOrder(func);
	arr = func.getArr();
	*size = func.getNumOfElements();
}

template<class T, class Key, class CompareKey>
int AVLTree<T, Key, CompareKey>::getNumOfVertices() {
	return this->numOfVertices;
}

template<class T, class Key, class CompareKey>
T* AVLTree<T, Key, CompareKey>::find(Key& key) {
	Node<T, Key>* ptr = this->root;
	CompareKey compFunc = CompareKey();
	ptr = findNodeReq(key, ptr, compFunc);
	if ((!ptr)||compFunc(*(ptr->getKey()), key) != 0) {
		return NULL;
	}
	return (ptr->getValue());
}

template<class T, class Key, class CompareKey>
T* AVLTree<T, Key, CompareKey>::deleteVertice(Key& key) {
	if (!root) {
		throw Failure();
	}
	CompareKey compareFunc = CompareKey();
	Node<T, Key>* delNode = this->deleteVerticeReq(this->root, key,
			compareFunc);
	if (!delNode || compareFunc(*(delNode->getKey()), key) != 0) {
		throw Failure();
	}
	this->numOfVertices--;
	T* val = new T(*(delNode->getValue()));
	delete delNode;
	return val;
}

template<class T, class Key, class CompareKey>
template<class inScanFunc>
void AVLTree<T, Key, CompareKey>::inOrder(inScanFunc& scanfunc) {
	Node<T, Key>* ptr = this->root;
	this->inOrderRec(scanfunc, ptr);
}

template<class T, class Key, class CompareKey>
template<class preScanFunc>
void AVLTree<T, Key, CompareKey>::preOrder(preScanFunc& scanfunc) {
	Node<T, Key>* ptr = this->root;
	this->preOrderRec(scanfunc, ptr);

}

template<class T, class Key, class CompareKey>
template<class postScanFunc>
void AVLTree<T, Key, CompareKey>::postOrder(postScanFunc& scanfunc) {
	Node<T, Key>* ptr = this->root;
	this->postOrderRec(scanfunc, ptr);
}

template<class T, class Key, class CompareKey>
T& AVLTree<T, Key, CompareKey>::getMax() {
	if (!root) {
		throw EmptyTree();
	}
	Node<T, Key>* curNode = this->root;
	while (curNode->getRightSon()) {
		curNode = curNode->getRightSon();
	}
	return *(curNode->getValue());
}

template<class T, class Key, class CompareKey>
class RemoveNullVertices {
public:
	RemoveNullVertices() {

	}
	void operator()(Node<T, Key>* node) {
		if (!node || !node->getValue()) {
			if (node->amIRightSon()) {
				node->getFather()->setRightSon(NULL);
			} else {
				node->getFather()->setLeftSon(NULL);
			}
			delete node;
		}
	}

};
//*** function for the inorder func that will fill the tree with the arr
template<class T, class Key, class CompareKey>
class fillTreeInlineFunc {
	pair<T, Key>** arr;
	int arrSize;
	int numOfLeaveLowLevel;
public:
	fillTreeInlineFunc(pair<T, Key>** arr, int arrSize, int numOfLeaveLowLevel) :
			arr(arr), arrSize(arrSize), numOfLeaveLowLevel(numOfLeaveLowLevel) {
	}
	void operator()(Node<T, Key>* node) {
		if (!arrSize) {
			return;
		}
		if (!node->getLeftSon() && !node->getRightSon()) {
			if (!numOfLeaveLowLevel) {
				return;
			}
			numOfLeaveLowLevel--;
		}
		node->setValue(new T((*arr)->getValue()));
		node->setKey(new Key((*arr)->getKey()));
		arr++;
		arrSize--;
	}
};

template<class T, class Key, class CompareKey>
void AVLTree<T, Key, CompareKey>::arrToAvlTree(int arrSize, pair<T, Key>** arr) {
	if(arrSize==1){
		this->numOfVertices=1;
		Node<T, Key>* node = new Node<T, Key>();
		node->setValue(new T((*arr)->getValue()));
		node->setKey(new Key((*arr)->getKey()));
		this->root=node;
		return;
	}
	int height = ceil(log2(arrSize));
	int numberOfLeaves = arrSize - (pow(2, height - 1) - 1);
	this->root = this->fillTreeWithBlankNodes(height, root);
	this->numOfVertices = arrSize;
	fillTreeInlineFunc<T, Key, CompareKey> func = fillTreeInlineFunc<T, Key,
			CompareKey>(arr, arrSize, numberOfLeaves);
	this->NodeinOrderRec(func, root);
	RemoveNullVertices<T, Key, CompareKey> clearFunc = RemoveNullVertices<T,
			Key, CompareKey>();
//	RemoveNullVertices<T,Key,CompareKey> clearFunc = RemoveNullVertices<T,Key,CompareKey>();
	this->invarsinOrderRec(clearFunc, root);
}

#endif /* AVLTREE_H_ */
