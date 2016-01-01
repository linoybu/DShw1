///***************************************************************************/
///*                                                                         */
///* 234218 Data DSs 1, Winter 2015-2016                                     */
///*                                                                         */
///* Homework : Wet 1                                                        */
///*                                                                         */
///***************************************************************************/
//
///***************************************************************************/
///*                                                                         */
///* File Name : main1.cpp                                                   */
///*                                                                         */
///* Holds the "int main()" function and the parser of the shell's           */
///* command line.                                                           */
///***************************************************************************/
//
//#include <assert.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "library1.h"
//#include <iostream>
//using namespace std;
//
//#ifdef __cplusplus
//extern "C" {
//#endif
//
///* The command's strings */
//
//
//static const int numActions = 10;
//static const char *commandStr[] = { "Init", "AddTrainer", "CatchPokemon",
//		"FreePokemon", "LevelUp", "EvolvePokemon",
//		"GetTopPokemon", "GetAllPokemonsByLevel", "UpdateLevels", "Quit" };
//
//static const char* ReturnValToStr(int val) {
//	switch (val) {
//	case SUCCESS:
//		return "SUCCESS";
//	case ALLOCATION_ERROR:
//		return "ALLOCATION_ERROR";
//	case FAILURE:
//		return "FAILURE";
//	case INVALID_INPUT:
//		return "INVALID_INPUT";
//	default:
//		return "";
//	}
//}
//
///* we assume maximum string size is not longer than 256  */
//#define MAX_STRING_INPUT_SIZE (255)
//#define MAX_BUFFER_SIZE       (255)
//
//#define StrCmp(Src1,Src2) ( strncmp((Src1),(Src2),strlen(Src1)) == 0 )
//
//typedef enum {
//	error_free, error
//} errorType;
//static errorType parser(const char* const command);
//
//#define ValidateRead(read_parameters,required_parameters,ErrorString) \
//if ( (read_parameters)!=(required_parameters) ) { printf(ErrorString); return error; }
//
//static bool isInit = false;
//
///***************************************************************************/
///* main                                                                    */
///***************************************************************************/
//
//
//
///***************************************************************************/
///* Command Checker                                                         */
///***************************************************************************/
//
//
//
///***************************************************************************/
///* Commands Functions                                                      */
///***************************************************************************/
//
//static errorType OnInit(void** DS);
//static errorType OnAddTrainer(void* DS);
//static errorType OnCatchPokemon(void* DS);
//static errorType OnFreePokemon(void* DS);
//static errorType OnLevelUp(void* DS);
//static errorType OnEvolvePokemon(void* DS);
//static errorType OnGetTopPokemon(void* DS);
//static errorType OnGetAllPokemonsByLevel(void* DS);
//static errorType OnUpdateLevels(void* DS);
//static errorType OnQuit(void** DS);
//
///***************************************************************************/
///* Parser                                                                  */
///***************************************************************************/
//
//int main(int argc, const char**argv) {
//	char buffer[MAX_STRING_INPUT_SIZE];
//	void** DS;
//	char a;
//	OnInit(ds);
//	OnCatchPokemon (ds,288, -3, 174);;
//	 GetTopPokemon (ds,1,&a);
//
//	 CatchPokemon (ds,255, 7, 26);
//
//	 GetAllPokemonsByLevel(ds, 101,&b,&a);
//
//	 GetTopPokemon (ds,6,&a);
//
//	 CatchPokemon (ds,163 ,9 ,332);
//
//	 LevelUp (ds,260, 2);
//
//	 AddTrainer (ds,3);
//
//	 GetAllPokemonsByLevel (ds,273,&b,&a);
//
//	 EvolvePokemon (ds,378 ,366);
//
//	 LevelUp (ds,289 ,21);
//
//	 UpdateLevels (ds,1 ,-2);
//
//	 AddTrainer (ds,0);
//
//	 CatchPokemon (ds,193, 12, 158);
//
//	 FreePokemon (ds,18);
//
//	 GetAllPokemonsByLevel (ds,282,&b,&a);
//
//	 LevelUp (ds,196 ,8);
//
//	 GetTopPokemon (ds,-1,&a);
//
//	 GetAllPokemonsByLevel (ds,298,&b,&a);
//
//	 FreePokemon (ds,0);
//
//	 GetAllPokemonsByLevel(ds, 41,&b,&a);
//
//	 CatchPokemon (ds,371 ,-3 ,132);
//
//	 GetAllPokemonsByLevel (ds,377,&b,&a);
//
//	 EvolvePokemon (ds,247, 92);
//
//	 LevelUp (ds,343 ,-5);
//
//	 LevelUp (ds,381, 14);
//
//	 FreePokemon (ds,-3);
//
//	 UpdateLevels (ds,1 ,0);
//
//	 CatchPokemon (ds,-20 ,9 ,75);
//
//	 GetAllPokemonsByLevel (ds,-2,&b,&a);
//
//	 EvolvePokemon (ds,399 ,289);
//
//	 CatchPokemon (ds,199, 12, 305);
//
//	 GetTopPokemon (ds,17,&a);
//
//	 EvolvePokemon (ds,364 ,306);
//
//	 FreePokemon (ds,11);
//	 UpdateLevels (ds,2 ,-3);
//	 CatchPokemon (ds,377, 7, 136);
//	 AddTrainer (ds,-2);
//	 LevelUp (ds,188 ,-3);
//	 CatchPokemon (ds,393, -5, 441);
//	 GetTopPokemon (ds,6,&a);
//	return 0;
//}
//
///***************************************************************************/
///* OnInit                                                                  */
///***************************************************************************/
//static errorType OnInit(void** DS) {
//	if (isInit) {
//		printf("Init was already called.\n");
//		return (error_free);
//	};
//	isInit = true;
//
//	*DS = Init();
//	if (*DS == NULL) {
//		printf("Init failed.\n");
//		return error;
//	};
//	printf("Init done.\n");
//
//	return error_free;
//}
//
///***************************************************************************/
///* OnAddTrainer                                                             */
///***************************************************************************/
//static errorType OnAddTrainer(void* DS) {
//	int trainerID;
//	StatusType res = AddTrainer(DS, trainerID);
//
//	if (res != SUCCESS) {
//		printf("AddTrainer: %s\n", ReturnValToStr(res));
//		return error_free;
//	} else {
//		printf("AddTrainer: %s\n", ReturnValToStr(res));
//	}
//
//	return error_free;
//}
//
///***************************************************************************/
///* OnCatchPokemon                                                          */
///***************************************************************************/
//static errorType OnCatchPokemon(void* DS) {
//	int pokemonID;
//	int trainerID;
//	int level;
//	StatusType res = CatchPokemon(DS, pokemonID, trainerID, level);
//
//	if (res != SUCCESS) {
//		printf("CatchPokemon: %s\n", ReturnValToStr(res));
//		return error_free;
//	}
//
//	printf("CatchPokemon: %s\n", ReturnValToStr(res));
//	return error_free;
//}
//
///***************************************************************************/
///* OnFreePokemon                                                            */
///***************************************************************************/
//static errorType OnFreePokemon(void* DS) {
//	int pokemonID;
//
//	StatusType res = FreePokemon(DS, pokemonID);
//
//	if (res != SUCCESS) {
//		printf("FreePokemon: %s\n", ReturnValToStr(res));
//		return error_free;
//	}
//
//	printf("FreePokemon: %s\n", ReturnValToStr(res));
//	return error_free;
//}
//
///***************************************************************************/
///* OnLevelUp                                                         */
///***************************************************************************/
//static errorType OnLevelUp(void* DS) {
//	int pokemonID;
//	int levelIncrease;
//	StatusType res = LevelUp(DS, pokemonID, levelIncrease);
//
//	if (res != SUCCESS) {
//		printf("LevelUp: %s\n", ReturnValToStr(res));
//		return error_free;
//	}
//
//	printf("LevelUp: %s\n", ReturnValToStr(res));
//	return error_free;
//}
//
///***************************************************************************/
///* OnEvolvePokemon                                                            */
///***************************************************************************/
//static errorType OnEvolvePokemon(void* DS) {
//	int pokemonID;
//	int evolvedID;
//
//	StatusType res = EvolvePokemon(DS, pokemonID, evolvedID);
//
//	if (res != SUCCESS) {
//		printf("EvolvePokemon: %s\n", ReturnValToStr(res));
//		return error_free;
//	}
//
//	printf("EvolvePokemon: %s\n", ReturnValToStr(res));
//	return error_free;
//}
//
///***************************************************************************/
///* OnGetTopPokemon                                                         */
///***************************************************************************/
//static errorType OnGetTopPokemon(void* DS) {
//	int trainerID;
//	int pokemonID;
//	StatusType res = GetTopPokemon(DS, trainerID, &pokemonID);
//
//	if (res != SUCCESS) {
//		printf("GetTopPokemon: %s\n", ReturnValToStr(res));
//		return error_free;
//	}
//
//	cout << "Pokemon with highest level is: " << pokemonID << endl;
//	return error_free;
//}
//
///***************************************************************************/
///* OnGetAllGames                                                        */
///***************************************************************************/
//
//void PrintAll(int *pokemons, int numOfPokemons) {
//	if (numOfPokemons > 0) {
//		cout << "Level	||	Pokemon" << endl;
//	}
//
//	for (int i = 0; i < numOfPokemons; i++) {
//		cout << i + 1 << "\t||\t" << pokemons[i] << endl;
//	}
//	cout << "and there are no more pokemons!" << endl;
//
//	free (pokemons);
//}
//
//static errorType OnGetAllPokemonsByLevel(void* DS) {
//	int trainerID;
//
//	int* pokemons;
//	int numOfPokemons;
//	StatusType res = GetAllPokemonsByLevel(DS, trainerID, &pokemons, &numOfPokemons);
//
//	if (res != SUCCESS) {
//		printf("GetAllPokemonsByLevel: %s\n", ReturnValToStr(res));
//		return error_free;
//	}
//
//	PrintAll(pokemons, numOfPokemons);
//	return error_free;
//}
//
///***************************************************************************/
///* OnUpdateLevels                                                           */
///***************************************************************************/
//static errorType OnUpdateLevels(void* DS) {
//	int stoneCode;
//	int stoneFactor;
//
//	StatusType res = UpdateLevels(DS, stoneCode, stoneFactor);
//
//	if (res != SUCCESS) {
//		printf("UpdateLevels: %s\n", ReturnValToStr(res));
//		return error_free;
//	}
//
//	printf("UpdateLevels: %s\n", ReturnValToStr(res));
//	return error_free;
//}
//
///***************************************************************************/
///* OnQuit                                                                  */
///***************************************************************************/
//static errorType OnQuit(void** DS) {
//	Quit(DS);
//	if (*DS != NULL) {
//		printf("Quit failed.\n");
//		return error;
//	};
//
//	isInit = false;
//	printf("Quit done.\n");
//
//	return error_free;
//}
//
//#ifdef __cplusplus
//}
//#endif
