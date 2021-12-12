#include "Header_Pierre.h"

///Determine le premier joueur
int choix_j(int nombre)
{
    ///0. DDV
    int joueur = 0;

    ///0.1. Initialisation clock
    srand(time(NULL));

    ///1. Generation aleatoire du premier joueur
    joueur = rand()%(nombre-1+1)+1;

    return joueur;

}
