#include <iostream>
#include "Pokemon.hpp"

int Pokemon::counter = 0;

Pokemon::Pokemon(int id, std::string name, double hitPoints, double attack, double defense, int generation):
id(id),name(name),hitPoints(hitPoints), attack(attack), defense(defense),generation(generation) {
  std::cout << "Pokemon " << name << " constructed!" << std::endl;
  counter++;
  std::cout << std::endl;
}

Pokemon::Pokemon(const Pokemon &other):
id(other.id),name(other.name),hitPoints(other.hitPoints), attack(other.attack), defense(other.defense),generation(other.generation){
  std::cout << "Pokemon " << name << " copied!" << std::endl;
  counter++;
  std::cout << std::endl;
}

Pokemon::~Pokemon() {
  std::cout << "Pokemon " << name << " destroyed!" << std::endl;
  counter--;
  std::cout << std::endl;
}

void Pokemon::displayInfo() const{
  std::cout << name << " has " << hitPoints << " HP, " << attack << " attack, " << defense << " defense and is from generation " << generation << "." << std::endl;
  std::cout << std::endl;
}

void Pokemon::takeDamage(double damage){
  if(hitPoints - damage <= 0){
    hitPoints = 0;
    std::cout<<name<<" has fainted!"<<std::endl;
    std::cout<<std::endl;
    return;
    }
  else{
    hitPoints -= damage;
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

