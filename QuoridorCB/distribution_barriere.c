#include "Header_Pierre.h"

///Suivant le nombre de joueur, donne le nombre adequat de barriere a chacun
void distribution_barriere(t_joueur player[4],int *nombrejoueur)
{
    ///1. Si on joue a 4j
    if (*nombrejoueur == 4)
    {
        ///Chacun aura 5 barrieres
        for(int i = 0; i<4; i++)
        {
            player[i].barrieresR = 20/4;
        }
    }
    ///2. Si on joue a 2j
    else if(*nombrejoueur == 2)
    {
        ///Chacun aura 10 barrieres
        for(int i = 0; i<2; i++)
        {
            player[i].barrieresR = 20/2;
        }

    }

    else
        printf("Erreur distribution des barrieres\n");
}

