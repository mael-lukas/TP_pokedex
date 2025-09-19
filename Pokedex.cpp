#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Pokedex.hpp"

Pokedex::Pokedex() {
      int cmpt = 0;
      std::ifstream fichier("/home/administrateur/Documents/git/TP_pokedex/pokedex.csv"); // Ouvre le fichier
      if (!fichier.is_open()) { // Vérifie si le fichier est bien ouvert
        std::cerr << "Impossible d'ouvrir le fichier : " << "/home/administrateur/Documents/git/TP_pokedex/pokedex.csv" << std::endl;
        return;
      }
      std::string ligne;
      while (std::getline(fichier, ligne)) { // Lit le fichier ligne par ligne
        std::stringstream ss(ligne); // Utilise un flux pour diviser la ligne
        std::string cellule;
        std::vector<std::string> donneesLigne;
        // Divise la ligne en cellules séparées par des virgules
          while (std::getline(ss, cellule, ',')) {
            donneesLigne.push_back(cellule); // Ajoute chaque cellule au vecteur
          }
          if (cmpt != 0) {
            int id = std::stoi(donneesLigne[0]);
            std::string name = donneesLigne[1];
            double maxHP = std::stod(donneesLigne[5]);
            double attack = std::stod(donneesLigne[6]);
            double defense = std::stod(donneesLigne[7]);
            Pokemon pokemon_temp(id,name,maxHP,attack,defense);
            pokemons.push_back(pokemon_temp);
          }
          cmpt++;
          // Affiche les données de la ligne
          /*for (const auto& valeur : donneesLigne) {
            std::cout << valeur << " "; // Affiche les valeurs séparées par un espace
          }
          std::cout << std::endl;*/
        }
          fichier.close(); // Ferme le fichier
      }



Pokedex::~Pokedex() {}

Pokedex *Pokedex::instance{nullptr};

Pokedex *Pokedex::getInstance() {
  if (instance == nullptr) {
    instance = new Pokedex();
  }
  else {
    std::cout << "Instance already exists" << std::endl;
  }
  return instance;
}