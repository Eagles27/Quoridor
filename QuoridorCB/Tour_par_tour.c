#include "Header_Pierre.h"

void tour_par_tour(int* Pnombre_joueur, int mat[17][17], t_joueur player[4],int* Ptour)
{

    if(*Pnombre_joueur == 4)
    {

            menu_game(mat,Pnombre_joueur,player,Ptour);


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
