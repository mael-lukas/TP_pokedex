#include <iostream>
#include "Pokemon.hpp"
#include <SFML/Graphics.hpp>
#include "Pokedex.hpp"
#include "Pokemon_party.hpp"

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
    Pokemon mienshao_3 = pokedex->getByName("Mienshao");
    mienshao_3.displayInfo();

    Pokemon_party party;
    party.addToParty(mienshao_3);
    party.addToParty(ludicolo);
    party.removeFromParty(ludicolo);
    party.addToParty(pokedex->getByID(576));

    return 0;
}
