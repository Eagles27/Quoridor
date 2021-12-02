#include "Header_Pierre.h"

void tour_par_tour(int* Pnombre_joueur, int mat[17][17], t_joueur player[4],int tour)
{
    int i=0;

    if(*Pnombre_joueur == 4)
    {
        do
        {
            menu_game(mat,Pnombre_joueur,player,tour);
            i++;
        }
        while(i<3);
    }

    else
    {
        do
        {
            menu_game(mat,Pnombre_joueur,player,tour);
            i++;
        }
        while(i<2);
    }


}
