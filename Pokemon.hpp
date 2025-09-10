//
// Created by administrateur on 08/09/25.
//

#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>

class Pokemon {

  private:
    int id;
    std::string name;
    double hitPoints;
    double attack;
    double defense;
    int generation;
    static int counter;


  public:
    Pokemon() = delete;
    Pokemon(int id, std::string name, double hitPoints, double attack, double defense, int generation);
    Pokemon(const Pokemon &other);
    ~Pokemon();

    void displayInfo() const;

    int getId() const {return id;}
    std::string getName() const {return name;}
    double getHp() const {return hitPoints;}
    double getAtk() const {return attack;}
    double getDef() const {return defense;}
    int getGen() const {return generation;}
    static int getCounter() {return counter;}

    void attackOther(Pokemon &other);
    void takeDamage(double damage);

};

#endif //POKEMON_HPP
