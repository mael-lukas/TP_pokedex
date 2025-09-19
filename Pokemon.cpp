#include <iostream>
#include "Pokemon.hpp"

int Pokemon::counter = 0;

Pokemon::Pokemon(int id, std::string name, double maxHP, double attack, double defense):
id(id),name(name),maxHP(maxHP), currentHP(maxHP), attack(attack), defense(defense) {
  /*std::cout << "Pokemon " << name << " constructed!" << std::endl;
  std::cout << std::endl;*/
  counter++;
}

Pokemon::Pokemon(const Pokemon &other):
id(other.id),name(other.name),maxHP(other.maxHP), currentHP(other.maxHP), attack(other.attack), defense(other.defense){
  /*std::cout << "Pokemon " << name << " copied!" << std::endl;
  std::cout << std::endl;*/
  counter++;
}

Pokemon::~Pokemon() {
 /* std::cout << "Pokemon " << name << " destroyed!" << std::endl;
  std::cout << std::endl;*/
  counter--;
}

void Pokemon::displayInfo() const{
  std::cout << name << ":  Current HP: " << currentHP << " HP (max: " << maxHP << ")  ATK: " << attack << "  DEF " << defense << std::endl;
}

void Pokemon::takeDamage(double damage){
  if(currentHP - damage <= 0){
    currentHP = 0;
    std::cout<<name<<" has fainted!"<<std::endl;
    std::cout<<std::endl;
    return;
    }
  else{
    currentHP -= damage;
    return;
    }
}

void Pokemon::attackOther(Pokemon &other){
  int otherDef = other.getDef();
  std::string otherName = other.getName();
  if(otherDef - attack > 0){
    std::cout<<name<<" did 0 damage to "<<otherName<<"!"<<std::endl;
    return;
  }
  else{
    double damage = attack - otherDef;
    std::cout<<name<<" did "<<damage<<" damage to "<<otherName<<"!"<<std::endl;
    other.takeDamage(damage);
  }
  return;

}


// Since there is no real indicator in the pokedex file for evolution, I will take the next pokemon and assume that if it has more hp, it's an evolution, if not the it's the next pokemon.
void Pokemon::evolve(Pokedex * pokedex) {
  int idTemp = id+1;
  Pokemon & nextPokemon = pokedex->findById(idTemp);
  if (maxHP<=nextPokemon.maxHP) {
    double missingHP = maxHP-currentHP;
    maxHP = nextPokemon.getHp();
    currentHP=maxHP-missingHP;    // Not sure how it's done in the real game.
    attack = nextPokemon.getAtk();
    defense = nextPokemon.getDef();
    id = nextPokemon.getId();
    name = nextPokemon.getName();
    //evolution ++;   //To uncomment once evolution is initialized.
  }
  else {
    std::cerr<<name<<" was the last evolution of this pokemon"<<std::endl;
  }
}

void Pokemon::evolve(Pokemon & nextPokemon) {
    double missingHP = maxHP-currentHP;
    maxHP = nextPokemon.getHp();
    currentHP=maxHP-missingHP;    // Not sure how it's done in the real game.
    attack = nextPokemon.getAtk();
    defense = nextPokemon.getDef();
    id = nextPokemon.getId();
    name = nextPokemon.getName();
    //evolution ++;   //To uncomment once evolution is initialized.
}

