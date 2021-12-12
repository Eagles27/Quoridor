#include "Header_Pierre.h"

///Incremente le nombre de tour
void tour_par_tour(int* Pnombre_joueur, int mat[17][17], t_joueur player[4],int* Ptour, int mat_avant[17][17])
{
    ///1. Partie a 4j
    if(*Pnombre_joueur == 4)
    {
        ///1.1. Si c'etait le tour de J1 alors ca sera a J2
        if(*Ptour%4 == 1)
        {
            *Ptour = 2;

        }
        ///1.2. Si c'etait le tour de J2 alors ca sera a J3
        else if(*Ptour%4 == 2)
        {
            *Ptour = 3;

        }
        ///1.3. Si c'etait le tour de J3 alors ca sera a J4
        else if(*Ptour%4 == 3)
        {
            *Ptour = 4;
        }
        ///1.4. Sinon c'est au tour de J1
        else
        {
            *Ptour = 1;
        }
    }

    ///2. Partie a 2J
    else
    {
        ///2.1. Si le nombre de tour est pair ca sera au tour de J1
        if(*Ptour%2 == 0)
        {
            *Ptour = 1;
        }
        ///2.2 Sinon ca sera au tour de J2
        else
        {
            *Ptour = 2;
        }

    }


}
