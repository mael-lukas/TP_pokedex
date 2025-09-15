#include "Pokemon_team.hpp"

Pokemon_team::Pokemon_team(Pokemon_PC &PC): PC(PC) {}

Pokemon_team::~Pokemon_team(){}

void Pokemon_team::addToTeam(Pokemon& pokemon) {
	int size = getPokemons().size();
	if (size >= 6) {
		std::cout << "Your team is already full!" << std::endl;
	}
	else {
		
	}
}