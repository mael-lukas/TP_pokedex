#ifndef POKEMON_ATTACK_HPP
#define POKEMON_ATTACK_HPP

#include "Pokemon_vector.hpp"
#include "Pokemon_PC.hpp"

class Pokemon_team: public Pokemon_vector {
  	Pokemon_PC &PC; //Usage of & to ensure that if the PC is modified (pokemons added/removed), it is also modified in its reference in the team
	public:
      Pokemon_team() = delete;
      Pokemon_team(Pokemon_PC &PC);
      ~Pokemon_team();

	  void addToTeam(Pokemon& pokemon);
};

#endif
