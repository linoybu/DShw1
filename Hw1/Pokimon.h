/*
 * Pokimon.h
 *
 *  Created on: Nov 16, 2015
 *      Author: linoy
 */

#ifndef POKIMON_H_
#define POKIMON_H_
#include "exception.h"
#include "pair.h"
#include <iostream>

class Pokimon {
	int id;
	int level;
	int trainerId;
public:
	Pokimon(int id, int level,int trainerId);
	Pokimon(const Pokimon& pokimon);
	void operator=(const Pokimon& pokimon);
	virtual ~Pokimon();
	void setId(int id);
	int getId();
	int const getId() const;
	void setLevel(int level);
	int getLevel();
	int const getLevel() const;
	void setTrainerId(int id);
	int getTrainerId();
	friend std::ostream& operator<<(std::ostream& os, const Pokimon& pokimon);
};



// key = level value = id
class compareByLevel {
public:
	int operator()(pair<int, int> firstPok, pair<int, int> secPok) {
		if (firstPok.getKey() != secPok.getKey()) {
			return (firstPok.getKey() - secPok.getKey());
		}
		return (secPok.getValue() - firstPok.getValue());
	}

};

//** they say that the better id is the smallest one,but im not sure
//** check later
class compareByID {
public:
	int operator()(int firstPok, int secPok) {
		return (secPok - firstPok);
	}

};

#endif /* POKIMON_H_ */
