#include <iostream>
#include "Pokemon.hpp"
#include <SFML/Graphics.hpp>

int main() {

    Pokemon mienshao(620, "Mienshao", 334, 349, 219, 5);
    mienshao.displayInfo();

    Pokemon mienshao_copy(mienshao);

    Pokemon ludicolo(272, "Ludicolo", 364, 239, 239, 3);
    Pokemon sunkern(191,"Sunkern",137,82,82,2);

    std::cout<<"There are currently "<<Pokemon::getCounter()<<" pokemon(s)"<<std::endl;
    std::cout<<std::endl;

    ludicolo.attackOther(mienshao);
    mienshao.displayInfo();

    mienshao.attackOther(sunkern);

    return 0;
}
