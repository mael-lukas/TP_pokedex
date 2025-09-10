#include "Pokemon_party.hpp"
#include <vector>

Pokemon_party::Pokemon_party() : Pokemon_vector() {}

Pokemon_party::~Pokemon_party(){}

void Pokemon_party::addToParty(Pokemon pokemon){
  getPokemons().push_back(pokemon);
  std::cout << pokemon.getName() << " (ID: " << pokemon.getId() << ") added to party!" << std::endl;
}

void Pokemon_party::removeFromParty(Pokemon pokemon){
  int index = 0;
  for(Pokemon partymon: getPokemons()){
    if(partymon.getName() == pokemon.getName()){
        getPokemons().erase(getPokemons().begin() + index);
        std::cout << pokemon.getName() << " (ID: " << pokemon.getId() << ") removed from party" << std::endl;
    }
    index++;
  }
}