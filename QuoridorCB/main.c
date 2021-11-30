#include "jeu.h"


int main()
{
    int mat[17][17];
    int nombre_joueur = 0;

    int *Pnombre_joueur = &nombre_joueur;


    ///Barrieres

    int barJ1 = 0;
    int barJ2 = 0;
    int barJ3 = 0;
    int barJ4 = 0;

    int *PbarJ1 = &barJ1;
    int *PbarJ2 = &barJ2;
    int *PbarJ3 = &barJ3;
    int *PbarJ4 = &barJ4;


    genematrice(mat);
    main_menu(PbarJ1,PbarJ2,PbarJ3,PbarJ4,Pnombre_joueur,mat);

    return 0;
}
