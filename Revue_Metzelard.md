# Revue par Metzeard Julien

## Problème
En arrivant sur le projet, le projet ne peut pas se lancer correctement car dans pokedex.cpp, le chemin du fichier est absolue et non relatif.  
Pour autant, lorsque je modifie pour y mettre mon chemin (absolue ou relatif), le fichier ne s'ouvre pas et bloque donc à peu près toute l'execution.
Je n'ai donc pas pu tester, ni voir l'exécution du main après la 1ère instanciation du pokedex.

## Remarques

1) Includes  
Il n'y a pas de main.h. Les includes du main sont donc faient dans le main.cpp.  
Certains includes sont faient directement dans les .cpp et non dans les .h associés. (typiquement, `#include <vector>, <iostream>,...`)  
Pour pokedex, tous les includes dont en doubles.

2) Variable non initialisé  
Dans pokemeon.cpp (ou pokemon.h), la valeur de "evolution" n'est jamais initialisé (même à 0).


3) Optimisation  
Dans Pokemon_team.cpp, ligne 12 : Pourquoi chercher le pokemon avant de vérifier la taille de la team ? si le PC devient grand, cela peut rajouter un "long" temps mếme si l'équipe est complète.  
Je suppose que tu l'as fait ainsi pour avoir un if ... else ... et donc pas d'instruction entre les deux, mais tu peux tout aussi bien mettre un return dans ton if et continuer après comme si tu avais un else.  
Même chose dans le addToTeam(id). (ligne 29)


4) Déviation de l'énoncé  
Dans la classe pokemon_vector, les méthodes findByName et findById sont définis explicitement.  
Est-ce un choix ? Cela est contraire à l'énoncé qui les veut virtuelles, mais c'est cohérent de réutiliser ces fonctions dans les sous-classes plutôt que de les redéfinir à l'identique.


5) Pokemon_PC  
Par rapport au PC, tu risques d'avoir (tu peux avoir en tout cas) des pokemon en double, car tu ne vérifie pas sa présence lors de l'ajout.  
Aussi, tu rajoutes à la team seulement par id ou nom, donc tu ne conserves pas l'état du pokemon en passant du PC à la team et vice-versa.