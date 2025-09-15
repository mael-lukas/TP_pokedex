#include <iostream>
#include "Pokemon.hpp"
#include <SFML/Graphics.hpp>
#include "Pokedex.hpp"
#include "Pokemon_PC.hpp"
#include "Pokemon_team.hpp"

int main() {

    Pokemon mienshao(620, "Mienshao", 334, 349, 219);
    mienshao.displayInfo();

    Pokemon mienshao_copy(mienshao);

    Pokemon ludicolo(272, "Ludicolo", 364, 239, 239);
    Pokemon sunkern(191,"Sunkern",137,82,82);

    std::cout<<"There are currently "<<Pokemon::getCounter()<<" pokemon(s)"<<std::endl;
    std::cout<<std::endl;

    ludicolo.attackOther(mienshao);
    mienshao.displayInfo();

    mienshao.attackOther(sunkern);

    Pokedex* pokedex = Pokedex::getInstance();
    Pokedex* pokedex2 = Pokedex::getInstance();

    pokedex->displayByName();
    Pokemon throh = pokedex->getByName("Throh");
    throh.displayInfo();

    std::cout<<std::endl;

    Pokemon_PC PC;
    PC.addToPC(throh);
    PC.addToPC(ludicolo);
    PC.removeFromPC(ludicolo);
    PC.addToPC(pokedex->getByID(576));
    std::cout<<std::endl;

    PC.addToPC(pokedex->getByName("Chandelure"));
    std::cout<<std::endl;
    PC.displayPC();
    std::cout << std::endl;

    Pokemon_team team(PC);

    return 0;
}
