/*
 * Pokimon.h
 *
 *  Created on: Nov 16, 2015
 *      Author: linoy
 */

#ifndef POKIMON_H_
#define POKIMON_H_
#include "exception.h"

class Pokimon {
	int id;
	int level;
public:
	Pokimon(int id,int level);
	Pokimon(const Pokimon& pokimon);
	void operator=(const Pokimon& pokimon);
	virtual ~Pokimon();
	void setId(int id);
	int getId();
	int const getId() const;
	void setLevel(int level);
	int getLevel();
	int const getLevel() const;
};

class compareByLevel{
	bool operator()(const Pokimon &firstPok,const Pokimon &secPok)
	{
		if(firstPok.getLevel()!=secPok.getLevel()){
			return(firstPok.getLevel()>secPok.getLevel());
		}
		return (firstPok.getId()<secPok.getId());
	}
};

//** they say that the better id is the smallest one,but im not sure
//** check later
class compareByID{
	bool operator()( Pokimon &firstPok, Pokimon &secPok)
		{
			return (firstPok.getId()<secPok.getId());
		}

};




#endif /* POKIMON_H_ */
