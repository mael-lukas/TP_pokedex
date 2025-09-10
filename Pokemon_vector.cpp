#include "Pokemon_vector.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

Pokemon_vector::Pokemon_vector() {
  std::vector<Pokemon> pokemons;
}

Pokemon Pokemon_vector::getByID(int ID){
  for(Pokemon pokemon: pokemons){
    if(pokemon.getId() == ID){
      return pokemon;
    }
  }
};

Pokemon Pokemon_vector::getByName(std::string name){
  for(Pokemon pokemon: pokemons){
    if(pokemon.getName() == name){
      return pokemon;
    }
  }
};

bool Pokemon_vector::compareByID(Pokemon pkmn1, Pokemon pkmn2){
  return pkmn1.getId() < pkmn2.getId();
}

bool Pokemon_vector::compareByName(Pokemon pkmn1, Pokemon pkmn2){
  return pkmn1.getName() < pkmn2.getName();
}

void Pokemon_vector::displayByID(){
  std::vector<Pokemon> sorted_pokemons(pokemons);
  std::sort(sorted_pokemons.begin(), sorted_pokemons.end(), compareByID);
  for (Pokemon pokemon : sorted_pokemons){
    pokemon.displayInfo();
  }
};

void Pokemon_vector::displayByName(){
  std::vector<Pokemon> sorted_pokemons(pokemons);
  std::sort(sorted_pokemons.begin(), sorted_pokemons.end(), compareByName);
  for (Pokemon pokemon : sorted_pokemons){
    pokemon.displayInfo();
  }
}

void Pokemon_vector::addPokemon(Pokemon pokemon){
  pokemons.push_back(pokemon);
}