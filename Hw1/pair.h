

#ifndef PAIR_H_
#define PAIR_H_

#include <stdio.h>
#include "exception.h"
#include <math.h>

template<class T,class Key>
class pair {
	Key key;
	T value;

public:
	pair(Key& key,T& value );
	~pair();
	void setKey(Key& key);
	void setValue(T& value);
	Key& getKey();
	T& getValue();
};

template<class T, class Key>
pair<T, Key>::pair(Key& key,T& value) :
	key(Key(key)),value(T(value)) {
}

template<class T, class Key>
pair<T, Key>::~pair() {
	// Default detractor


}

template<class T, class Key>
void pair<T, Key>::setKey(Key& key) {
	this->key = key;
}

template<class T, class Key>
void pair<T, Key>::setValue(T& value) {
	this->value = value;
}

template<class T, class Key>
Key& pair<T, Key>::getKey() {
	return this->key;
}

template<class T, class Key>
T& pair<T, Key>::getValue() {
	return this->value;
}



#endif /* PAIR_H_ */
