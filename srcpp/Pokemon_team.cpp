#include "../incpp/Pokemon_team.hpp"

Pokemon_team::Pokemon_team(Pokemon_PC &PC): PC(PC) {}

Pokemon_team::~Pokemon_team(){}

void Pokemon_team::addToTeam(std::string name) {
	if (pokemons.size() >= 6) {
		std::cout << "Your team is already full!" << std::endl;
	}
	else {
		if (not PC.isInPC(name)) {
			std::cout << "The Pokemon " << name << " is not in your PC !" << std::endl;
		}
		else {
			Pokemon pokemon = PC.findByName(name);
			PC.removeFromPC(pokemon);
			pokemons.push_back(pokemon);
			std::cout << name << " (ID: " << pokemon.getId() << ") added to team" << std::endl;
		}
	}
}

void Pokemon_team::addToTeam(int id) {
	if (pokemons.size() >= 6) {
		std::cout << "Your team is already full!" << std::endl;
	}
	else {
		if (not PC.isInPC(id)) {
			std::cout << "The Pokemon with ID " << id << " is not in your PC !" << std::endl;
		}
		else {
			Pokemon &pokemon = PC.findById(id);
			pokemons.push_back(pokemon);
			PC.removeFromPC(pokemon);
			std::cout << pokemon.getName() << " (ID: " << id << ") added to team" << std::endl;
		}
	}
}

void Pokemon_team::displayTeam() {
	int size = pokemons.size();
	if (size <= 0) {
		std::cout << "Your team is empty, add Pokemons from your PC to your team" << std::endl;
	}
	else {
		std::cout << "You have " << size << "/6 Pokemons in your team:" << std::endl;
		for (Pokemon &pokemon: pokemons) {
			pokemon.displayInfo();
		}
	}
}

void Pokemon_team::removeFromTeam(std::string name) {
	int index = 0;
	for(Pokemon partymon: pokemons) {
		if(partymon.getName() == name){
			pokemons.erase(pokemons.begin() + index);
			PC.addToPC(partymon);
			std::cout << name << " (ID: " << partymon.getId() << ") removed from team" << std::endl;
		}
		index++;
	}
}

void Pokemon_team::removeFromTeam(int id) {
	int index = 0;
	for(Pokemon partymon: pokemons){
		if(partymon.getId() == id){
			pokemons.erase(pokemons.begin() + index);
			PC.addToPC(partymon);
			std::cout << partymon.getName() << " (ID: " << id << ") removed from team" << std::endl;
		}
		index++;
	}
}