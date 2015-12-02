#include "PokimonMaster.h"
class IsTrainer {
	int key;
public:
	IsTrainer(int const key) :
			key(key) {

	}

	bool operator()(const Trainer* trainer) const {
		if (trainer->getId() == key) {
			return true;
		}
		return false;
	}
};

Trainer* PokimonMaster::findTrainer(int id) {
	const IsTrainer isTrainer = IsTrainer(id);
	Iterator<Trainer*> found = this->trainerList.find(isTrainer);
	if (found == trainerList.end()) {
		return NULL; //TODO - don't change it to failur!!!!!!!!!
	}
	return (*found);
}

Pokimon& PokimonMaster::findPokimonInIdTree(int id) {
	Pokimon* pokimon = this->idPokimonTree->find(id);
	if (!pokimon) {
		throw Failure();
	}
	return *pokimon;
}

Pokimon& PokimonMaster::findPokimonInLevelTree(int id) {
	Pokimon pokimon1 = findPokimonInIdTree(id);
	int level = pokimon1.getLevel();
	pair<int, int> key = pair<int, int>(level, id);
	Pokimon* pokimon = this->levelPokimonTree->find(key);
	if (!pokimon) {
		throw Failure();
	}
	return *pokimon;

}

void PokimonMaster::addPokimonInIdTree(Pokimon& pokimon) {
	int id = pokimon.getId();
	this->idPokimonTree->addVertices(&pokimon, &id);

}

void PokimonMaster::addPokimonInLevelTree(Pokimon& pokimon) {
	int id = pokimon.getId();
	int level = pokimon.getLevel();
	pair<int, int> key = pair<int, int>(level, id);
	this->levelPokimonTree->addVertices(&pokimon, &key);
	if (levelPokimonTree->getNumOfVertices() == 0) {
		this->bestPokimon = NULL;
		return;
	}
	this->bestPokimon = &(levelPokimonTree->getMax());
}

PokimonMaster::PokimonMaster() :
		trainerList(List<Trainer*>()), idPokimonTree(
				new AVLTree<Pokimon, int, compareByID>()), levelPokimonTree(
				new AVLTree<Pokimon, pair<int, int>, compareByLevel>()), bestPokimon(
		NULL) {

}

PokimonMaster::~PokimonMaster() {
	Iterator<Trainer*> it = trainerList.begin();
	for (; it != trainerList.end(); it++) {
		delete (*it);
	}
	delete idPokimonTree;
	delete levelPokimonTree;
}

void PokimonMaster::addTrainer(int id) {
	if (id < 0) {
		throw InvaildInput();
	}
	if (this->findTrainer(id)) {
		throw Failure();
	}
	Trainer* newTrainer = new Trainer(id);
	trainerList.insert(newTrainer, trainerList.end());
}

//ALLOCATION_ERROR - In case of an allocation error.
//	 *                INVALID_INPUT - If DS==NULL or if trainerID <= 0.
//	 *                FAILURE - If trainerID is already in the DS.
//	 *                SUCCESS - Otherwise.

void PokimonMaster::CatchPokemon(int pokemonID, int trainerID, int level) {
	if (trainerID <= 0 || pokemonID <= 0 || level <= 0) {
		throw InvaildInput();
	}
	if (this->idPokimonTree->find(pokemonID)) { // if pokimon already in the game
		throw Failure();
	}
	Pokimon pokimon = Pokimon(pokemonID, level, trainerID);
	Trainer* trainer = findTrainer(trainerID);
	if (!trainer) {
		throw Failure();
	}
	trainer->addPokimon(pokimon);
	addPokimonInIdTree(pokimon);
	addPokimonInLevelTree(pokimon);
}

void PokimonMaster::FreePokemon(int pokemonID) {
	if (pokemonID <= 0) {
		throw InvaildInput();
	}
	if (!this->idPokimonTree->find(pokemonID)) {
		throw Failure();
	}
	Pokimon* pokimon = this->idPokimonTree->deleteVertice(pokemonID);
	int id = pokimon->getId();
	int level = pokimon->getLevel();
	int trainerId = pokimon->getTrainerId();
	Trainer* trainer = findTrainer(trainerId);
	if (!trainer) {
		throw Failure();
	}
	pair<int, int> key = pair<int, int>(level, id);
	trainer->removePokimon(key);
	Pokimon* pokimon2 = this->levelPokimonTree->deleteVertice(key);
	delete pokimon;
	delete pokimon2;

	if (levelPokimonTree->getNumOfVertices() == 0) {
		this->bestPokimon = NULL;
		return;
	}
	this->bestPokimon = &(this->levelPokimonTree->getMax());

}

void PokimonMaster::LevelUp(int pokemonID, int levelIncrease) {
	if (pokemonID <= 0 || levelIncrease <= 0) {
		throw InvaildInput();
	}
	Pokimon& pokimon = findPokimonInIdTree(pokemonID);

	// fix level tree :
	int id = pokimon.getId(), level = pokimon.getLevel(), trainerId =
			pokimon.getTrainerId();
	pokimon.setLevel(pokimon.getLevel() + levelIncrease); //update level in IdTree
	pair<int, int> key = pair<int, int>(level, id);
	Pokimon* delPokimon = this->levelPokimonTree->deleteVertice(key);
	delete delPokimon;
	Pokimon newPokimon = Pokimon(id, level + levelIncrease, trainerId);
	addPokimonInLevelTree(newPokimon);

	//update trainer:
	Trainer* trainer = findTrainer(trainerId);
	if (!trainer) {
		throw Failure();
	}
	trainer->removePokimon(key);
	trainer->addPokimon(newPokimon);

}

void PokimonMaster::EvolvePokemon(int pokemonID, int evolvedID) {
	if (pokemonID <= 0 || evolvedID <= 0) {
		throw InvaildInput();
	}
	if (!this->idPokimonTree->find(pokemonID)) {
		throw Failure();
	}
	Pokimon* pokimon = this->idPokimonTree->deleteVertice(pokemonID);
	int id = pokimon->getId();
	int level = pokimon->getLevel();
	int trainerId = pokimon->getTrainerId();
	Trainer* trainer = findTrainer(trainerId);
	if (!trainer) {
		throw Failure();
	}

	//update trainer:
	pair<int, int> key = pair<int, int>(level, id);
	trainer->removePokimon(key);

	//update level tree
	Pokimon* pokimon2 = this->levelPokimonTree->deleteVertice(key);
	delete pokimon;
	delete pokimon2;
	Pokimon pokimonToAdd = Pokimon(evolvedID, level, trainerId);
	this->addPokimonInIdTree(pokimonToAdd); // update id tree
	this->addPokimonInLevelTree(pokimonToAdd);
	trainer->addPokimon(pokimonToAdd);

}

// class that always return true so we will get all the pokimons in the array
class arrayFunctionGetAll {
public:
	arrayFunctionGetAll() {
	}
	bool operator()(pair<int, int>& key, Pokimon& value) {
		return true;
	}
};

void PokimonMaster::GetAllPokemonsByLevel(int trainerID, int **pokemons,
		int *numOfPokemon) {
	if (trainerID == 0 || !numOfPokemon || !pokemons) {
		throw InvaildInput();
	}
	if (trainerID > 0) {
		Trainer* trainer = findTrainer(trainerID);
		if (!trainer) {
			throw Failure();
		}
		*numOfPokemon = trainer->getNumberOfPokimons();
		if (*numOfPokemon == 0) {
			*pokemons = NULL;
			return;
		}
		int size = *numOfPokemon;
		*pokemons = (int*) malloc(sizeof(**pokemons) * (size));
		if (!pokemons) {
			throw std::bad_alloc();
		}

		pair<Pokimon, pair<int, int> >** arr =
				new pair<Pokimon, pair<int, int> >*[*numOfPokemon];
		arrayFunctionGetAll func = arrayFunctionGetAll();
		trainer->gettree()->toArr(arr, numOfPokemon, func);
		int i = *numOfPokemon - 1;
		int j = 0;
		for (; i >= 0; i--, j++) {
			int id = arr[i]->getValue().getId();
			(*pokemons)[j] = id;
		}
		for (i = 0; i < *numOfPokemon; i++) {
			delete arr[i];
		}

		//delete arr;

	} else {
		*numOfPokemon = this->levelPokimonTree->getNumOfVertices();
		int size = *numOfPokemon;
		if (!size) {
			*pokemons = NULL;
			return;
		}
		*pokemons = (int*) malloc(sizeof(**pokemons) * (size));
		if (!pokemons) {
			throw std::bad_alloc();
		}

		pair<Pokimon, pair<int, int> >** arr =
				new pair<Pokimon, pair<int, int> >*[*numOfPokemon];
		arrayFunctionGetAll func = arrayFunctionGetAll();
		levelPokimonTree->toArr(arr, numOfPokemon, func);

		for (int i = *numOfPokemon - 1, j = 0; i >= 0; i--, j++) {
			int id = arr[i]->getValue().getId();
					(*pokemons)[j] = id;
		}
		for (int i = 0; i < *numOfPokemon; i++) {
			delete arr[i];
		}
		//delete arr;

	}

}

//class that will return all the pokimons that need to be updated according to the stoneCode
class GetAllEvolvedPoks {
	int stoneCode;
public:
	GetAllEvolvedPoks(int stoneCode) :
			stoneCode(stoneCode) {

	}
	bool operator()(pair<int, int>& key, Pokimon& value) {
		return ((value.getId() % stoneCode) == 0);
	}
};

//class that will return all the pokimons that not need to be updated according to the stoneCode
class GetAllNotEvolvedPoks {
	int stoneCode;
public:
	GetAllNotEvolvedPoks(int stoneCode) :
			stoneCode(stoneCode) {

	}

	bool operator()(pair<int, int>& key, Pokimon& value) {
		return !((value.getId() % stoneCode) == 0);
	}

};

//marge to arrays in to unionArrs
void marge(pair<Pokimon, pair<int, int> >** arr1,
		pair<Pokimon, pair<int, int> >** arr2,
		pair<Pokimon, pair<int, int> >** unionArrs, int arr1Size, int arr2Size,
		int unionSize) {
	pair<Pokimon, pair<int, int> >** pToArr1 = arr1;
	pair<Pokimon, pair<int, int> >** pToArr2 = arr2;
//	pair<Pokimon, pair<int, int> >** pToUnion = unionArrs;
	compareByLevel compareFunc = compareByLevel();
	int i = 0;
	while (arr1Size && arr2Size) {
		if (compareFunc((*pToArr1)->getKey(), (*pToArr2)->getKey()) < 0) {
			unionArrs[i] = new pair<Pokimon, pair<int, int> >(
					(*pToArr1)->getKey(), (*pToArr1)->getValue());
			pToArr1++;
			arr1Size--;
			i++;
		} else {
			unionArrs[i] = new pair<Pokimon, pair<int, int> >(
					(*pToArr2)->getKey(), (*pToArr2)->getValue());
			pToArr2++;
			arr2Size--;
			i++;

		}
	}
	if (!arr1Size) {
		while (arr2Size) {
			unionArrs[i] = new pair<Pokimon, pair<int, int> >(
					(*pToArr2)->getKey(), (*pToArr2)->getValue());
			pToArr2++;
			arr2Size--;
			i++;

		}
	} else if (!arr2Size) {
		while (arr1Size) {
			unionArrs[i] = new pair<Pokimon, pair<int, int> >(
					(*pToArr1)->getKey(), (*pToArr1)->getValue());
			pToArr1++;
			arr1Size--;
			i++;

		}
	}

}

void PokimonMaster::updateLevelsForTree(int stoneCode, int stoneFactor,
		AVLTree<Pokimon, pair<int, int>, compareByLevel>* tree,
		pair<Pokimon, pair<int, int> >** unionArrs) {
	int numOfPok = tree->getNumOfVertices();
	pair<Pokimon, pair<int, int> >** evolvedArr = new pair<Pokimon,
			pair<int, int> >*[numOfPok];
	pair<Pokimon, pair<int, int> >** notEvolvedArr = new pair<Pokimon,
			pair<int, int> >*[numOfPok];
	GetAllEvolvedPoks getEvolvedFunc = GetAllEvolvedPoks(stoneCode);
	GetAllNotEvolvedPoks getAllNotEvolvedFunc = GetAllNotEvolvedPoks(stoneCode);
	int numEvolvedPoks = 0;
	int numNotEvolvedPoks = 0;
	tree->toArr(evolvedArr, &numEvolvedPoks, getEvolvedFunc);
	tree->toArr(notEvolvedArr, &numNotEvolvedPoks, getAllNotEvolvedFunc);
	for (int i = 0; i < numEvolvedPoks; i++) {
		int newLevel = (evolvedArr[i]->getValue().getLevel()) * stoneFactor;
		evolvedArr[i]->getValue().setLevel(newLevel);
		evolvedArr[i]->getKey().setKey(newLevel);
	}

	marge(evolvedArr, notEvolvedArr, unionArrs, numEvolvedPoks,
			numNotEvolvedPoks, numOfPok);
	//***** free the arrays after we union them
//	for (int i = 0; i < numEvolvedPoks; i++) {
//		delete evolvedArr[i];
//	}
	delete[] evolvedArr;
//	for (int i = 0; i < numNotEvolvedPoks; i++) {
//		delete notEvolvedArr[i];
//	}
	delete[] notEvolvedArr;

}

//class that update the level of the pokimons with the suitable id
class UpdateLevelForIdTree {
	int stoneCode;
	int stoneFactor;
public:
	UpdateLevelForIdTree(int stoneCode, int stoneFactor) :
			stoneCode(stoneCode), stoneFactor(stoneFactor) {
	}
	void operator()(int& key, Pokimon& value) {
		if (value.getLevel() % stoneCode == 0) {
			int newLevel = value.getLevel() * stoneFactor;
			value.setLevel(newLevel);
			key = newLevel;
		}
	}

};

void PokimonMaster::UpdateLevels(int stoneCode, int stoneFactor) {
	if (stoneCode < 1 || stoneFactor < 1) {
		throw InvaildInput();
	}
	//** update levels tree
	int numOfPok=0;
	numOfPok= this->levelPokimonTree->getNumOfVertices();
	if (!numOfPok) {
		return;
	}
	pair<Pokimon, pair<int, int> >** unionArrs = new pair<Pokimon,
			pair<int, int> >*[numOfPok];
	this->updateLevelsForTree(stoneCode, stoneFactor, this->levelPokimonTree,
			unionArrs);
	this->levelPokimonTree->cleanTree();
	this->levelPokimonTree->arrToAvlTree(numOfPok, unionArrs);
	this->bestPokimon = &this->levelPokimonTree->getMax();
//	for (int i = 0; i < numOfPok; i++) {
//		delete unionArrs[i];
//	}
	delete[] unionArrs;
	Iterator<Trainer*> it = trainerList.begin();
	///**** update trainers
	for (; it != trainerList.end(); it++) {
		int numOfPok = ((*it)->gettree())->getNumOfVertices();
		if (!numOfPok) {
			continue;
		}
		unionArrs = new pair<Pokimon, pair<int, int> >*[numOfPok];
		this->updateLevelsForTree(stoneCode, stoneFactor, ((*it)->gettree()),
				unionArrs);
		((*it)->gettree())->cleanTree();
		((*it)->gettree())->arrToAvlTree(numOfPok, unionArrs);
		((*it)->setBestPokimon(&((*it)->gettree())->getMax()));
//		for (int i = 0; i < numOfPok; i++) {
//			delete unionArrs[i];
//		}
		delete[] unionArrs;

	}
	//*** update id tree
	UpdateLevelForIdTree updateFunc = UpdateLevelForIdTree(stoneCode,
			stoneFactor);
	this->idPokimonTree->inOrder(updateFunc);

}

//void PokimonMaster::printAllTrees() {
//	fatherMatchSon1 fatherSon = fatherMatchSon1();
//	fatherMatchSon2 fatherSon2 = fatherMatchSon2();
//	print p1 = print();
//	print2 p2 = print2();
//	cout << "idTree:" << endl;
//	this->idPokimonTree->inOrder(p1);
//	cout << endl;
//	this->idPokimonTree->NodeInOrder(fatherSon);
//	cout << " fatherSonCheck: " << fatherSon.IsTrue << endl;
//	cout << "levelTree:" << endl;
//	this->levelPokimonTree->inOrder(p2);
//	cout << endl;
//	this->levelPokimonTree->NodeInOrder(fatherSon2);
//	cout << " fatherSonCheck: " << fatherSon2.IsTrue << endl;
//	Iterator<Trainer*> it = trainerList.begin();
//	for (; it != trainerList.end(); ++it) {
//		cout << " trainer: " << (*it)->getId() << " " << endl;
//		((*it)->gettree())->inOrder(p2);
//		cout << endl;
//		(*it)->gettree()->NodeInOrder(fatherSon2);
//		cout << " fatherSonCheck: " << fatherSon2.IsTrue << endl;
//
//	}
//
//}

void PokimonMaster::GetTopPokemon(int trainerID, int *pokemonID) {
	if (trainerID == 0 || pokemonID == NULL) {
		throw InvaildInput();
	}
	Pokimon* TopPokimon;
	if (trainerID > 0) { // in case we got valid trainer id
		Trainer* trainer = findTrainer(trainerID);
		if (!trainer) {
			throw Failure();
		}
		TopPokimon = trainer->getBestPokimon();
	} else {
		TopPokimon = this->bestPokimon;
	}
	if (!TopPokimon) {
		*pokemonID = (-1);
		// the trainer doesn't have pokimons or there are no pokimons at the game
		return;
	} else
		*pokemonID = TopPokimon->getId();
}

