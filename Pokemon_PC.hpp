#ifndef POKEMON_PARTY_HPP
#define POKEMON_PARTY_HPP

#include "Pokemon_vector.hpp"

class Pokemon_PC: public Pokemon_vector {
  public:
    Pokemon_PC();
    ~Pokemon_PC();

	void addToParty(Pokemon pokemon);
    void removeFromParty(Pokemon pokemon);

	void displayParty();
};

#endif
