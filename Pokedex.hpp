#ifndef POKEDEX_HPP
#define POKEDEX_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Pokemon_vector.hpp"

class Pokedex : public Pokemon_vector {
  Pokedex();
  static Pokedex* instance;

  public:
    Pokedex(const Pokedex& other) = delete;
	~Pokedex();
    static Pokedex *getInstance();
};

#endif
