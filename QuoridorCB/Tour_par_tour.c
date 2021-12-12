#include "Header_Pierre.h"

///Increment le nombre de tour
void tour_par_tour(int* Pnombre_joueur, int mat[17][17], t_joueur player[4],int* Ptour, int mat_avant[17][17])
{
    ///1. Partie a 4j
    if(*Pnombre_joueur == 4)
    {
        ///1.1. Si c'etait le tour du 1 alors ca sera au joueur 2
        if(*Ptour%4 == 1)
        {
            *Ptour = 2;

        }
        ///1.2. Si c'etait le tour du 2 alors ca sera au joueur 3
        else if(*Ptour%4 == 2)
        {
            *Ptour = 3;

        }
        ///1.3. Si c'etait le tour du 3 alors ca sera au joueur 4
        else if(*Ptour%4 == 3)
        {
            *Ptour = 4;
        }
        ///1.4. Sinon c'est au tour du joueur 1
        else
        {
            *Ptour = 1;
        }
    }

    ///2. Partie a 2J
    else
    {
        ///2.1. Si le nombre de tour est pair ca sera au tour du jour 1
        if(*Ptour%2 == 0)
        {
            *Ptour = 1;
        }
        ///2.2 Sinon ca sera au tour du joueur 2
        else
        {
            *Ptour = 2;
        }

    }


}
