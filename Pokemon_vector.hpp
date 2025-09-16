#ifndef POKEMON_VECTOR_HPP
#define POKEMON_VECTOR_HPP

#include "Pokemon.hpp"
#include <iostream>
#include <vector>

class Pokemon_vector{

	std::vector<Pokemon> pokemons;

	protected:
		std::vector<Pokemon>& getPokemons();

    public:
      Pokemon_vector();

      Pokemon& findById(int ID);
      Pokemon& findByName(std::string name);
      void displayByID();
      void displayByName();

      static bool compareByID(Pokemon pkmn1, Pokemon pkmn2);
      static bool compareByName(Pokemon pkmn1, Pokemon pkmn2);
  };

#endif
