#ifndef POKEMON_PARTY_HPP
#define POKEMON_PARTY_HPP

#include "Pokemon_vector.hpp"

class Pokemon_PC: public Pokemon_vector {
  public:
    Pokemon_PC();
    ~Pokemon_PC();

	void addToPC(Pokemon pokemon);
  void removeFromPC(Pokemon pokemon);

	void displayPC();
	bool isInPC(std::string name);
	bool isInPC(int id);
};

#endif
