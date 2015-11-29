/*
 * library1.cpp
 *
 *  Created on: Nov 29, 2015
 *      Author: linoy
 */

#include "library1.h"
#include <stdlib.h>
#include "PokimonMaster.h"

void* Init(){
	PokimonMaster* pokimonMaster = new PokimonMaster;
	return (void*)pokimonMaster;

}

/* Description:   Adds a new trainer.
 * Input:         DS - A pointer to the data structure.
 *                trainerID - The ID of the trainer to add.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL or if trainerID <= 0.
 *                FAILURE - If trainerID is already in the DS.
 *                SUCCESS - Otherwise.
 */
StatusType AddTrainer(void *DS, int trainerID){
	if(!DS){
		return INVALID_INPUT;
	}
	try{
		((PokimonMaster*)DS)->addTrainer(trainerID);
	}catch (InvaildInput& e) {
		return INVALID_INPUT;

	}catch (std::bad_alloc& e) {
		return ALLOCATION_ERROR;

	}catch (Failure& e) {
		return FAILURE;
	}
	return SUCCESS;
}

/* Description:   Adds a new pokemon to the system.
 * Input:         DS - A pointer to the data structure.
 *                pokemonID - ID of the pokemon to add.
 *                trainerID - The ID of the pokemon's trainer
 *                level - The pokemon's level
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL, or if pokemonID <=0, or if trainerID <=0, or if level <= 0
 *                FAILURE - If pokemonID is already in the DS, or trainerID isn't in the DS.
 *                SUCCESS - Otherwise.
 */
StatusType CatchPokemon(void *DS, int pokemonID, int trainerID, int level){
	if(!DS){
		return INVALID_INPUT;
	}
	try{
		((PokimonMaster*)DS)->CatchPokemon(pokemonID,trainerID,level);
	}catch (InvaildInput& e) {
		return INVALID_INPUT;

	}catch (std::bad_alloc& e) {
		return ALLOCATION_ERROR;

	}catch (Failure& e) {
		return FAILURE;
	}
	return SUCCESS;
}

/* Description:   Removes an existing pokemon.
 * Input:         DS - A pointer to the data structure.
 *                pokemonID - The ID of the pokemon to remove.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL or if pokemonID <= 0.
 *                FAILURE - If pokemonID isn't in the DS.
 *                SUCCESS - Otherwise.
 */
StatusType FreePokemon(void *DS, int pokemonID){
	if(!DS){
		return INVALID_INPUT;
	}
	try{
		((PokimonMaster*)DS)->FreePokemon(pokemonID);
	}catch (InvaildInput& e) {
		return INVALID_INPUT;

	}catch (std::bad_alloc& e) {
		return ALLOCATION_ERROR;

	}catch (Failure& e) {
		return FAILURE;
	}
	return SUCCESS;
}

/* Description:   Increases the level of a pokemon.
 * Input:         DS - A pointer to the data structure.
 *                pokemonID - The ID of the pokemon.
 *		            levelIncrease - The increase in level.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL, or if pokemonID<=0, or if levelIncrease<=0
 *                FAILURE - If pokemonID isn't in the DS.
 *                SUCCESS - Otherwise.
 */
StatusType LevelUp(void *DS, int pokemonID, int levelIncrease){
	if(!DS){
		return INVALID_INPUT;
	}
	try{
		((PokimonMaster*)DS)->LevelUp(pokemonID,levelIncrease);
	}catch (InvaildInput& e) {
		return INVALID_INPUT;

	}catch (std::bad_alloc& e) {
		return ALLOCATION_ERROR;

	}catch (Failure& e) {
		return FAILURE;
	}
	return SUCCESS;
}

/* Description:   Evolves a pokemon, updating his ID, while maintaining his level.
 * Input:         DS - A pointer to the data structure.
 *                pokemonID - The original ID of the pokemon.
 *                evolvedID - The new ID of the pokemon.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL, or if pokemonID<=0, or if evolvedID<=0.
 *                FAILURE - If pokemonID isn't in the DS, or evolvedID is in the DS.
 *                SUCCESS - Otherwise.
 */
StatusType EvolvePokemon(void *DS, int pokemonID, int evolvedID){
	if(!DS){
		return INVALID_INPUT;
	}
	try{
		((PokimonMaster*)DS)->EvolvePokemon(pokemonID,evolvedID);
	}catch (InvaildInput& e) {
		return INVALID_INPUT;

	}catch (std::bad_alloc& e) {
		return ALLOCATION_ERROR;

	}catch (Failure& e) {
		return FAILURE;
	}
	return SUCCESS;
}

/* Description:   Returns the pokemon with the highest level from trainerID
 * 			If trainerID < 0, returns the top pokemon in the entire DS.
 * Input:         DS - A pointer to the data structure.
 *                trainerID - The trainer that we'd like to get the data for.
 * Output:        pokemonID - A pointer to a variable that should be updated to the ID of the top pokemon.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL, or if pokemonID == NULL, or if trainerID == 0.
 *                SUCCESS - Otherwise.
 */
StatusType GetTopPokemon(void *DS, int trainerID, int *pokemonID){
	if(!DS){
		return INVALID_INPUT;
	}
	try{
		((PokimonMaster*)DS)->GetTopPokemon(trainerID,pokemonID);
	}catch (InvaildInput& e) {
		return INVALID_INPUT;

	}catch (std::bad_alloc& e) {
		return ALLOCATION_ERROR;

	}catch (Failure& e) {
		return FAILURE;
	}
	return SUCCESS;
}

/* Description:   Returns all the pokemons from trainerID sorted by their level.
 *           			If trainerID < 0, returns all the pokemons in the entire DS sorted by their level.
 * Input:         DS - A pointer to the data structure.
 *                trainerID - The trainer that we'd like to get the data for.
 * Output:        pokemons - A pointer to a to an array that you should update with the pokemons' IDs sorted by their level,
 *			          in case two pokemons have same level they should be sorted by their ID.
 *                numOfPokemon - A pointer to a variable that should be updated to the number of pokemons.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If any of the arguments is NULL or if trainerID == 0.
 *                SUCCESS - Otherwise.
 */
StatusType GetAllPokemonsByLevel(void *DS, int trainerID, int **pokemons, int *numOfPokemon){
	if(!DS){
		return INVALID_INPUT;
	}

	try{
		((PokimonMaster*)DS)->GetAllPokemonsByLevel(trainerID,pokemons,numOfPokemon);
	}catch (InvaildInput& e) {
		return INVALID_INPUT;

	}catch (std::bad_alloc& e) {
		return ALLOCATION_ERROR;

	}catch (Failure& e) {
		return FAILURE;
	}
	return SUCCESS;
}

/* Description:   Updates the level of the pokemons where pokemonID % stoneCode == 0.
 * 			          For each matching pokemon, multiplies its level by stoneFactor.
 * Input:         DS - A pointer to the data structure.
 *                stoneCode - The basis that the stone works on
 *          		  stoneFactor - The multiply factor of the level
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - If DS==NULL or if stoneCode < 1 or if stoneFactor <1
 *                SUCCESS - Otherwise.
 */
StatusType UpdateLevels(void *DS, int stoneCode, int stoneFactor){
	if(!DS){
		return INVALID_INPUT;
	}
	try{
		((PokimonMaster*)DS)->UpdateLevels(stoneCode,stoneFactor);
	}catch (InvaildInput& e) {
		return INVALID_INPUT;

	}catch (std::bad_alloc& e) {
		return ALLOCATION_ERROR;

	}catch (Failure& e) {
		return FAILURE;
	}
	return SUCCESS;
}


/* Description:   Quits and deletes the database.
 *                DS should be set to NULL.
 * Input:         DS - A pointer to the data structure.
 * Output:        None.
 * Return Values: None.
 */
void Quit(void** DS){
	delete (PokimonMaster*)DS;
}



