#include "../incpp/Pokemon_vector.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

Pokemon_vector::Pokemon_vector() {
}

Pokemon& Pokemon_vector::findById(int ID){
  for(Pokemon &pokemon: pokemons){
    if(pokemon.getId() == ID){
      return pokemon;
    }
  }
  std::cerr << "Found no Pokemon with ID: " << ID << std::endl;
};

Pokemon& Pokemon_vector::findByName(std::string name){
  for(Pokemon &pokemon: pokemons){
    if(pokemon.getName() == name){
      return pokemon;
    }
  }
  std::cerr << "Found no Pokemon with name: " << name << std::endl;
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
