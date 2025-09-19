#include "Pokemon_PC.hpp"
#include <vector>

Pokemon_PC::Pokemon_PC() : Pokemon_vector() {}

Pokemon_PC::~Pokemon_PC(){}

void Pokemon_PC::addToPC(Pokemon pokemon){
  pokemons.push_back(pokemon);
  std::cout << pokemon.getName() << " (ID: " << pokemon.getId() << ") added to PC !" << std::endl;
}

void Pokemon_PC::removeFromPC(Pokemon pokemon){
  int index = 0;
  for(Pokemon partymon: pokemons){
    if(partymon.getName() == pokemon.getName()){
        pokemons.erase(pokemons.begin() + index);
        std::cout << pokemon.getName() << " (ID: " << pokemon.getId() << ") removed from PC" << std::endl;
    }
    index++;
  }
}

void Pokemon_PC::displayPC() {
  std::cout<<"Here are all the Pokemons in your PC:"<<std::endl;
  for(Pokemon &pokemon: pokemons) {
    pokemon.displayInfo();
  }
}

bool Pokemon_PC::isInPC(std::string name) {
  for (Pokemon pkmn : pokemons) {
    if (pkmn.getName() == name) {
      return true;
    }
  }
  return false;
}

bool Pokemon_PC::isInPC(int id) {
  for (Pokemon pkmn : pokemons) {
    if (pkmn.getId() == id) {
      return true;
    }
  }
  return false;
}