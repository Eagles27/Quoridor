#include "Header_Pierre.h"

void tour_par_tour(int* Pnombre_joueur, int mat[17][17], int* PbarJ1,int* PbarJ2,int* PbarJ3,int* PbarJ4)
{
    int i=0;

    do
    {
        menu_game(mat,Pnombre_joueur,*PbarJ1,*PbarJ2,*PbarJ3,*PbarJ4);
        i++;
    }while(i<3);
}
