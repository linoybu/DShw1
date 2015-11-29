/*
 * list.h
 *
 *  Created on: 9 αιεπ 2015
 *      Author: Lior
 */

#include "exception.h"
#include <stddef.h>

#ifndef LIST_H_
#define LIST_H_

template<class D>
class List;
template<class T>
class Iterator;
/******************************************************************************/
/*ListNode:
 a aid class for class list (all the function and fields are private) */

template<class U>
class ListNode {
	U* data;
	ListNode<U>* next;
	ListNode<U>* previous;
	explicit ListNode(const U data) {
		this->data = new U(data);
		this->next = NULL;
		this->previous = NULL;
	}
	ListNode(const ListNode& node) {
		this->data = new U(*(node.data));
		this->next = NULL;
		this->previous = NULL;
	}
	~ListNode() {
		delete data;
	}

	template<class D> friend class List;
	template<class T> friend class Iterator;
};

/******************************************************************************/

//Iterator:
template<class T>
class Iterator {
	ListNode<T>* element;
	List<T>* myList; // for checking which list this iterator belongs to
	// if the iterator points to NULL, this is the end of the list

public:
	explicit Iterator(List<T>* myList, ListNode<T>* element = NULL);
	Iterator(const Iterator& iterator);
	~Iterator() {
	}
	;

	Iterator<T>& operator++(); // prefix operator (++Iterator)
	Iterator<T> operator++(int); //postfix operator (Iterator++)
	T& operator*() const;
	Iterator& operator=(const Iterator<T>& iterator);

	bool operator==(const Iterator<T>& Iterator) const;
	bool operator!=(const Iterator<T>& Iterator) const;

	//operators we don't use:
	T& operator[](T) = delete;
	const T& operator[](T) const = delete;

	template<class D> friend class List;
};

template<class T>
Iterator<T>::Iterator(List<T>* myList, ListNode<T>* element) {
	this->element = element;
	this->myList = myList;
}

template<class T>
Iterator<T>::Iterator(const Iterator& iterator) {
	this->element = iterator.element;
	this->myList = iterator.myList;
}

template<class T>
Iterator<T>& Iterator<T>::operator++() {
	if (!this->element) {
		// the iterator points to the end
		return (*this);		// return the iterator without a change
	}
	//advance the iterator
	this->element = (this->element)->next;
	return (*this);		// return reference to the iterator after the change
}

template<class T>
Iterator<T> Iterator<T>::operator++(int) {
	Iterator<T> copyIterator(*this); //make a copy for result
	++(*this); // advance the iterator
	return copyIterator; // return the old data
}

template<class T>
T& Iterator<T>::operator*() const {
	if (this->element == NULL) {
		throw Failure();
	}

	return *((this->element)->data);

}

template<class T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& iterator) {
	this->element = iterator.element;
	this->myList = iterator.myList;
	return (*this);
}

template<class T>
bool Iterator<T>::operator==(const Iterator<T>& Iterator) const {
	return (this->element == Iterator.element);
}

template<class T>
bool Iterator<T>::operator!=(const Iterator<T>& Iterator) const {
	return !(Iterator == *this);
}

/******************************************************************************/

//List:
template<class D>
class List {
	ListNode<D>* head; // the first node at the list
	ListNode<D>* tail; // the last node at the list
	int size;

public:
	List();
	List(const List& list);
	~List();

	Iterator<D> begin();
	Iterator<D> end();
	void insert(const D& data, Iterator<D> iteator);
	void remove(Iterator<D> iterator);
	int getSize();

	template<class Predicate>
	Iterator<D> find(const Predicate& predicate);

	template<class Compare>
	void sort(const Compare& compare);

};

template<class D>
List<D>::List() {
	head = NULL;
	tail = NULL;
	size = 0;
}

template<class D>
List<D>::List(const List& list) {
	this->size = 0;

	if (list.size == 0) { //empty list
		this->head = NULL;
		this->tail = NULL;
		return;
	}
	this->head = new ListNode<D>(*list.head);
	this->size++;
	ListNode<D>* nextHead = this->head;
	ListNode<D>* origenList = list.head->next;
	while (this->size < list.size) {
		ListNode<D>* newListNode = new ListNode<D>(*origenList);
		nextHead->next = newListNode;
		newListNode->previous = nextHead;
		this->tail = nextHead;
		this->size++;
		nextHead = nextHead->next;
		origenList = origenList->next;
	}
}

template<class D>
List<D>::~List() {
	while (size > 0) {
		ListNode<D>* nextHead = head->next;
		delete head;
		size--;
		head = nextHead;
	}
}

template<class D>
Iterator<D> List<D>::begin() {
	if (size == 0) {
		// the list is empty
		return Iterator<D>(this); //return NULL iterator (end of list)
	}
	return Iterator<D>(this, this->head); // return iterator to the beginning
}

template<class D>
Iterator<D> List<D>::end() {
	return Iterator<D>(this); //return NULL iterator (end of list)
}

template<class D>
void List<D>::insert(const D& data, Iterator<D> iterator) {
	if (iterator.myList != this) { // iterator to different list
		throw Failure();
	}
	ListNode<D>* newListNode = new ListNode<D>(data); // construct new node

	if (size == 0) { // empty list
		this->head = newListNode;
		this->tail = newListNode;
		size++;
		return;
	}
	// iterator points to end of list
	if (iterator.element == NULL) {
		this->tail->next = newListNode;
		newListNode->previous = this->tail;
		this->tail = newListNode;
		size++;
		return;
	}

	// iterator points to head
	if (iterator.element == head) {
		newListNode->next = head;
		head->previous = newListNode;
		head = newListNode;
		size++;
		return;
	}

	// add before the iterator
	ListNode<D>* curListNode = iterator.element;
	ListNode<D>*prevListNode = curListNode->previous;
	newListNode->next = curListNode;
	newListNode->previous = prevListNode;
	prevListNode->next = newListNode;
	curListNode->previous = newListNode;
	size++;
}

template<class D>
void List<D>::remove(Iterator<D> iterator) {
	if (size == 0) { //if the list is empty
		throw Failure();
	} else if (iterator.element == NULL) { //if the iterator points to the end of the list
		throw Failure();
	} else if (iterator.myList != this) { //the iterator points to an other list
		throw Failure();
	}

	if (iterator.element == head) {	//iterator points to the head of the list
		ListNode<D>* nextListNode = iterator.element->next;
		delete iterator.element;
		this->head = nextListNode;
		if( nextListNode!=NULL){ //remove the last element
		nextListNode->previous = NULL;
		}
		size--;
		return;
	}

	if (iterator.element == tail) {	//iterator points to the last node
		ListNode<D>*prevListNode = iterator.element->previous;
		delete iterator.element;
		tail = prevListNode;
		prevListNode->next = NULL;
		size--;
		return;
	}

	ListNode<D>* nextListNode = iterator.element->next;
	ListNode<D>*prevListNode = iterator.element->previous;
	delete iterator.element;
	prevListNode->next = nextListNode;
	nextListNode->previous = prevListNode;
	size--;
}

template<class D>
int List<D>::getSize() {
	return size;
}

template<class D>
template<class Predicate>
Iterator<D> List<D>::find(const Predicate& predicate) {
	int size = this->size;
	Iterator<D> iterator = (*this).begin(); // set iterator to head of the list
	while (size > 0) {
		if (predicate(*((iterator.element)->data))) {
			return iterator;
		}
		iterator++;
		size--;
	}
	iterator = (*this).end();
	return iterator;
}

template<class D>
template<class Compare>
void List<D>::sort(const Compare& compare) {
	if (size < 2) {
		return;
	}
	for (ListNode<D>* ptr1 = this->head; ptr1; ptr1 = ptr1->next) {
		for (ListNode<D>* ptr2 = ptr1->next; ptr2; ptr2 = ptr2->next) {
			if (!compare(*(ptr1->data), *(ptr2->data))) {
				D* tempData = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = tempData;

			}
		}
	}
}

#endif /* LIST_H_ */
