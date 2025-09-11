#include "Pokemon_PC.hpp"
#include <vector>

Pokemon_PC::Pokemon_PC() : Pokemon_vector() {}

Pokemon_PC::~Pokemon_PC(){}

void Pokemon_PC::addToParty(Pokemon pokemon){
  getPokemons().push_back(pokemon);
  std::cout << pokemon.getName() << " (ID: " << pokemon.getId() << ") added to party!" << std::endl;
}

void Pokemon_PC::removeFromParty(Pokemon pokemon){
  int index = 0;
  for(Pokemon partymon: getPokemons()){
    if(partymon.getName() == pokemon.getName()){
        getPokemons().erase(getPokemons().begin() + index);
        std::cout << pokemon.getName() << " (ID: " << pokemon.getId() << ") removed from party" << std::endl;
    }
    index++;
  }
}

void Pokemon_PC::displayParty() {
  std::cout<<"Here are all the Pokemons in your PC:"<<std::endl;
  for(Pokemon pokemon: getPokemons()) {
    pokemon.displayInfo();
  }
}
