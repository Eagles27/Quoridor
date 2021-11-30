#include "jeu.h"

void affiregles()
{
    system("cls");
    printf("//////////\n");
    printf("BUT DU JEU\n");
    printf("Il s'agit d'atteindre le premier la ligne opposee a sa ligne de depart.\n");
    printf("\n");
    printf("En debut de partie, les barrieres sont remisees dans leur zone de stockage.\n");
    printf("Chaque joueur pose son pion au centre de sa ligne de depart (la premiere ligne face a lui).\n");
    printf("Un tirage au sort determine qui commence.\n");
    system("PAUSE");
    printf("////////////\n");
    printf("DEPLACEMENTS\n");
    printf("A tour de role, chaque joueur choisit :\n");
    printf("\n");
    printf("-de deplacer son pion d'une case verticalement ou horizontalement, en avant ou en arriere ;\n");
    printf("-de poser une de ses barrieres. Une barriere doit etre posee exactement entre deux blocs de 2 cases.\n");
    printf("Lorsqu'il n'a plus de barrieres, un joueur est oblige de deplacer son pion.\n");
    printf("\n");
    printf("La pose des barrieres a pour but de creer son propre chemin ou de ralentir l'adversaire.\n");
    printf("Il est interdit de lui fermer totalement l'acces a sa ligne de but.\n");
    printf("\n");
    printf("Quand 2 pions se retrouvent en vis-a-vis sur 2 cases voisines non separees par une barriere,\n");
    printf("le joueur dont c'est le tour peut sauter par-dessus son adversaire et se retrouver derriere lui.\n");
    printf("\n");
    printf("Si une barriere se trouve derrière le pion saute, le joueur peut choisir de bifurquer a droite ou a gauche du pion saute.\n");
    system("PAUSE");
    printf("////////////////////\n");
    printf("REGLE POUR 4 JOUEURS\n");
    printf("En debut de partie, les 4 pions sont disposes au centre de chacun des 4 cotes du plateau et chaque joueur dispose de 5 barrieres.\n");
    printf("Les regles sont strictement identiques, mais on ne peut sauter plus d'un pion à la fois.\n");
    system("PAUSE");
    system("cls");
}
