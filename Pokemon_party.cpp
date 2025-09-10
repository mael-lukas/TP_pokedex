#include "Pokemon_party.hpp"
#include <vector>

Pokemon_party::addToParty(Pokemon pokemon){
  pokemons.push_back(pokemon);
}

Pokemon_party::removeFromParty(Pokemon pokemon){
  int index = 0;
  for(Pokemon partymon: pokemons){
    if partymon.getName() == pokemon.getName(){
        pokemons.erase(index)
    }
    index++;
  }
}