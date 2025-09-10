#ifndef POKEMON_PARTY_HPP
#define POKEMON_PARTY_HPP

#include "Pokemon_vector.hpp"

class Pokemon_party: public Pokemon_vector {
  public:
    Pokemon_party();
    ~Pokemon_party();

	void addToParty(Pokemon pokemon);
    void removeFromParty(Pokemon pokemon);
};

#endif
