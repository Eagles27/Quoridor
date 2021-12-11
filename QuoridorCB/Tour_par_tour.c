#include "Header_Pierre.h"

void tour_par_tour(int* Pnombre_joueur, int mat[17][17], t_joueur player[4],int* Ptour, int mat_avant[17][17])
{

    if(*Pnombre_joueur == 4)
    {

        if(*Ptour%4 == 1)
        {
            *Ptour = 2;

        }

        else if(*Ptour%4 == 2)
        {
            *Ptour = 3;

        }

        else if(*Ptour%4 == 3)
        {
            *Ptour = 4;
        }

        else
        {
            *Ptour = 1;
        }


    }



    else
    {
        if(*Ptour%2 == 0)
        {
            *Ptour = 1;
        }

        else
        {
            *Ptour = 2;
        }

    }


}
