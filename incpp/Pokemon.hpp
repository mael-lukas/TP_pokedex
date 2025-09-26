//
// Created by administrateur on 08/09/25.
//

#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>

class Pokemon {

    int id;
    std::string name;
    int evolution;
    double maxHP;
    double currentHP;
    double attack;
    double defense;
    static int counter;
	std::string spritePath;


  public:
    Pokemon() = delete;
    Pokemon(int id, std::string name, double maxHP, double attack, double defense);
    Pokemon(const Pokemon &other);
    ~Pokemon();

    void displayInfo() const;

    int getId() const {return id;}
    std::string getName() const {return name;}
    double getHp() const {return currentHP;}
    double getAtk() const {return attack;}
    double getDef() const {return defense;}
	std::string getSpritePath() {return spritePath;}
    static int getCounter() {return counter;}

    void attackOther(Pokemon &other);
    void takeDamage(double damage);

};

#endif //POKEMON_HPP
