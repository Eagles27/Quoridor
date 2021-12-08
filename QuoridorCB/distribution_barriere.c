#include "Header_Pierre.h"

void distribution_barriere(t_joueur player[4],int *nombrejoueur)
{
    if (*nombrejoueur == 4)
    {
        for(int i = 0; i<4; i++)
        {
            player[i].barrieresR = 20/4;
        }
    }

    else if(*nombrejoueur == 2)
    {
        for(int i = 0; i<2; i++)
        {
            player[i].barrieresR = 20/2;
        }

    }

    else
        printf("Erreur distribution des barrieres\n");
}

