#include "Header_Pierre.h"

int main()
{
    ///0. DDV
    int nombre_joueur = 0;
    int *Pnombre_joueur = &nombre_joueur;
    int mat[17][17];

    ///1. Setup des entités
    ///1.1. Setup IA
    t_IA ia;
    strcpy(ia.nom, "IA");
    ia.numero = 1;

    ///1.2. Setup IA
    t_joueur player[4];

    ///1.3. Setup plateau
    genematrice(mat);

    ///2. Debut du jeu

    main_menu(Pnombre_joueur, mat, player, ia);


    return 0;
}
