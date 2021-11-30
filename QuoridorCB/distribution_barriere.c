#include "jeu.h"

void distributio_barriere(int *PbarJ1,int *PbarJ2, int *PbarJ3, int *PbarJ4, int *nombrejoueur)
{
    if (*nombrejoueur == 4)
    {
        *PbarJ1 = 20/4;
        *PbarJ2 = 20/4;
        *PbarJ3 = 20/4;
        *PbarJ4 = 20/4;
    }

    else if(*nombrejoueur == 2)
    {
        *PbarJ1 = 20/2;
        *PbarJ2 = 20/2;
    }

    else
        printf("Erreur distribution des barrieres\n");
}

