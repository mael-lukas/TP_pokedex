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
    Pokemon throh = pokedex->findByName("Throh");
    throh.displayInfo();

    std::cout<<std::endl;

    Pokemon_PC PC;
    PC.addToPC(throh);
    PC.addToPC(ludicolo);
    PC.removeFromPC(ludicolo);
    PC.addToPC(pokedex->findById(576));
    std::cout<<std::endl;

    PC.addToPC(pokedex->findByName("Chandelure"));
    std::cout<<std::endl;
    PC.displayPC();
    std::cout << std::endl;

    Pokemon_team team(PC);
    team.addToTeam("Throh");
    team.addToTeam(576);
    team.addToTeam("Mienshao");
    std::cout << std::endl;

    team.displayTeam();
    team.removeFromTeam(538);
    std::cout << std::endl;
    team.displayTeam();

    PC.addToPC(pokedex->findByName("Haxorus"));
    PC.addToPC(pokedex->findByName("Serperior"));
    PC.addToPC(pokedex->findByName("Cryogonal"));
    PC.addToPC(pokedex->findByName("Cofagrigus"));
    PC.addToPC(pokedex->findByName("Scolipede"));
    team.addToTeam("Haxorus");
    team.addToTeam("Serperior");
    team.addToTeam("Cryogonal");
    team.addToTeam("Cofagrigus");
    team.addToTeam("Scolipede");
    team.addToTeam("Throh");
    team.removeFromTeam(497);
    team.removeFromTeam(612);

    team.findByName("Gothitelle").attackOther(team.findByName("Cryogonal"));
    std::cout << std::endl;

    team.displayTeam();

    return 0;
}
