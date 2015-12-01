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

//** key = level value =ID
class compareByLevel {
public:
	int operator()(pair<int,int>& key1, pair<int,int>& key2) {
		//first we compare by level
		if(key1.getKey()!=key2.getKey()){
			return (key1.getKey()-key2.getKey());
		}// if the levels are equals we compare by id
	return (key2.getValue()-key1.getValue());
	// smallest id is bigger key therefore we return key2-key1
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
