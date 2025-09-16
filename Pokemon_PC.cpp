#include "Pokemon_PC.hpp"
#include <vector>

Pokemon_PC::Pokemon_PC() : Pokemon_vector() {}

Pokemon_PC::~Pokemon_PC(){}

void Pokemon_PC::addToPC(Pokemon pokemon){
  getPokemons().push_back(pokemon);
  std::cout << pokemon.getName() << " (ID: " << pokemon.getId() << ") added to PC !" << std::endl;
}

void Pokemon_PC::removeFromPC(Pokemon pokemon){
  int index = 0;
  for(Pokemon partymon: getPokemons()){
    if(partymon.getName() == pokemon.getName()){
        getPokemons().erase(getPokemons().begin() + index);
        std::cout << pokemon.getName() << " (ID: " << pokemon.getId() << ") removed from PC" << std::endl;
    }
    index++;
  }
}

void Pokemon_PC::displayPC() {
  std::cout<<"Here are all the Pokemons in your PC:"<<std::endl;
  for(Pokemon &pokemon: getPokemons()) {
    pokemon.displayInfo();
  }
}

bool Pokemon_PC::isInPC(std::string name) {
  for (Pokemon pkmn : getPokemons()) {
    if (pkmn.getName() == name) {
      return true;
    }
  }
  return false;
}

bool Pokemon_PC::isInPC(int id) {
  for (Pokemon pkmn : getPokemons()) {
    if (pkmn.getId() == id) {
      return true;
    }
  }
  return false;
}