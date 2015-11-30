#include "PokimonMaster.h"
class IsTrainer {
	int key;
public:
	IsTrainer(int const key) :
			key(key) {

	}

	bool operator()(const Trainer& trainer) const {
		if (trainer.getId() == key) {
			return true;
		}
		return false;
	}
};

Trainer* PokimonMaster::findTrainer(int id) {
	const IsTrainer isTrainer = IsTrainer(id);
	Iterator<Trainer> found = this->trainerList.find(isTrainer);
	if (found == trainerList.end()) {
		return NULL; //TODO - don't change it to failur!!!!!!!!!
	}
	return &(*found);
}
Pokimon& PokimonMaster::findPokimonInIdTree(int id) {
	Pokimon& pokimon = this->idPokimonTree->find(id);
	return pokimon;
}
Pokimon& PokimonMaster::findPokimonInLevelTree(int id) {
	Pokimon pokimon1 = findPokimonInIdTree(id);
	int level = pokimon1.getLevel();
	pair<int, int> key = pair<int, int>(level, id);
	Pokimon& pokimon = this->levelPokimonTree->find(key);
	return pokimon;

}

void PokimonMaster::addPokimonInIdTree(Pokimon& pokimon) {
	int id = pokimon.getId();
	this->idPokimonTree->addVertices(&pokimon, &id);
	//	this->bestPokimon = &(idPokimonTree->getMax());
}
void PokimonMaster::addPokimonInLevelTree(Pokimon& pokimon) {
	int id = pokimon.getId();
	int level = pokimon.getLevel();
	pair<int, int> key = pair<int, int>(level, id);
	this->levelPokimonTree->addVertices(&pokimon, &key);
	this->bestPokimon = &(levelPokimonTree->getMax());
}

PokimonMaster::PokimonMaster() :
		trainerList(List<Trainer>()), idPokimonTree(
				new AVLTree<Pokimon, int, compareByID>()), levelPokimonTree(
				new AVLTree<Pokimon, pair<int, int>, compareByLevel>()), bestPokimon(
		NULL) {

}
//
//PokimonMaster::PokimonMaster(PokimonMaster& pmaster):
//		trainerList(pmaster.trainerList),
//		idPokimonTree(pmaster.idPokimonTree),
//		levelPokimonTree(pmaster.levelPokimonTree)
//		,bestPokimon(pmaster.bestPokimon)
//{
//
//}

PokimonMaster::~PokimonMaster() {
//	delete trainerList;
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
	Trainer newTrainer = Trainer(id);
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

}
void PokimonMaster::LevelUp(int pokemonID, int levelIncrease) {
	if (pokemonID <= 0 || levelIncrease <= 0) {
		throw InvaildInput();
	}
	Pokimon& pokimon = findPokimonInIdTree(pokemonID);
	pokimon.setLevel(pokimon.getLevel() + levelIncrease); //update level in IdTree

	// fix level tree :
	int id = pokimon.getId(), level = pokimon.getLevel(), trainerId =
			pokimon.getTrainerId();
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
	Pokimon pokimonToAdd = Pokimon(evolvedID, level, trainerId);
	this->addPokimonInIdTree(pokimonToAdd);
	this->addPokimonInLevelTree(pokimonToAdd);
	trainer->addPokimon(pokimonToAdd);

}
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
	if (trainerID == 0 || !numOfPokemon) {
		throw InvaildInput();
	}
	if (trainerID > 0) {
		Trainer* trainer = findTrainer(trainerID);
		if (!trainer) {
			throw Failure();
		}
		*numOfPokemon = trainer->getNumberOfPokimons();
		if (*numOfPokemon == 0) {
			pokemons = NULL;
			return;
		}
		pokemons = (int**) malloc(sizeof(int) * (*numOfPokemon));
		if (!pokemons) {
			throw std::bad_alloc();
		}

		pair<Pokimon, pair<int, int> >** arr =
				new pair<Pokimon, pair<int, int> >*[*numOfPokemon];
		arrayFunctionGetAll func = arrayFunctionGetAll();
		trainer->gettree()->toArr(arr, numOfPokemon, func);

		for (int i = *numOfPokemon - 1, j = 0; i > 0; i--, j++) {
			pokemons[j] = new int(arr[i]->getValue().getId());
		}

		delete arr;

	} else {
		*numOfPokemon = this->levelPokimonTree->getNumOfVertices();
		if (*numOfPokemon == 0) {
			pokemons = NULL;
			return;
		}
		pokemons = (int**) malloc(sizeof(int) * (*numOfPokemon));
		if (!pokemons) {
			throw std::bad_alloc();
		}

		pair<Pokimon, pair<int, int> >** arr =
				new pair<Pokimon, pair<int, int> >*[*numOfPokemon];
		arrayFunctionGetAll func = arrayFunctionGetAll();
		levelPokimonTree->toArr(arr, numOfPokemon, func);

		for (int i = *numOfPokemon - 1, j = 0; i > 0; i--, j++) {
			pokemons[j] = new int(arr[i]->getValue().getId());
		}
		delete arr;

	}

}
void PokimonMaster::UpdateLevels(int stoneCode, int stoneFactor) {

}

void PokimonMaster::printAllTrees() {
	fatherMatchSon1 fatherSon = fatherMatchSon1();
	fatherMatchSon2 fatherSon2 = fatherMatchSon2();
	print p1 = print();
	print2 p2 = print2();
	cout << "idTree:" << endl;
	this->idPokimonTree->inOrder(p1);
	cout << endl;
	this->idPokimonTree->NodeInOrder(fatherSon);
	cout << " fatherSonCheck: " << fatherSon.IsTrue << endl;
	cout << "levelTree:" << endl;
	this->levelPokimonTree->inOrder(p2);
	cout << endl;
	this->levelPokimonTree->NodeInOrder(fatherSon2);
	cout << " fatherSonCheck: " << fatherSon2.IsTrue << endl;
	Iterator<Trainer> it = trainerList.begin();
	for (it; it != trainerList.end(); ++it) {
		cout << " trainer: " << (*it).getId() << " " << endl;
		((*it).gettree())->inOrder(p2);
		cout << endl;
		(*it).gettree()->NodeInOrder(fatherSon2);
		cout << " fatherSonCheck: " << fatherSon2.IsTrue << endl;

	}

}

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
		*pokemonID = bestPokimon->getId();
}

//
//void PokimonMaster::updateLevelHelper(AVLTree<Pokimon,pair<int,int>,compareByLevel >* tree){
//	tree->toArr()
//
//
//}
//
//class conditionForArr{
//
//
//
//};
//
//void merge(int a[], int m, int b[], int n, int sorted[]) {
//  int i, j, k;
//
//  j = k = 0;
//
//  for (i = 0; i < m + n;) {
//    if (j < m && k < n) {
//      if (a[j] < b[k]) {
//        sorted[i] = a[j];
//        j++;
//      }
//      else {
//        sorted[i] = b[k];
//        k++;
//      }
//      i++;
//    }
//    else if (j == m) {
//      for (; i < m + n;) {
//        sorted[i] = b[k];
//        k++;
//        i++;
//      }
//    }
//    else {
//      for (; i < m + n;) {
//        sorted[i] = a[j];
//        j++;
//        i++;
//      }
//    }
//  }
//}
//
