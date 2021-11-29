#include "jeu.h"

int choix_j(int nombre)
{
    int joueur = 0;
    srand(time(NULL));

    joueur = rand()%(nombre-1+1)+1;

    return joueur;

}
