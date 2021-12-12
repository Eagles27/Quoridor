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

    ///1.2. Setup Joueur
    t_joueur player[4];

    ///1.3 Menu de mise full screen et menu accueil
    //1.3.1 Mise full screen

    Color(15,0);
    gotoligcol(13,43);
    Color(15,4);
    printf("Quand full screen OK, press any key ...");
    Color(15,0);
    gotoligcol(14,43);
    system("PAUSE");
    Color(15,0);


    //1.3.2 Menu accueil
    system("cls");
    Affichage_Du_Titre(1,35);
    gotoligcol(13,43);
    system("PAUSE");
    Color(15,0);

    ///1.4. Setup plateau
    genematrice(mat);

    ///2. Debut du jeu

    main_menu(Pnombre_joueur, mat, player, ia);


    return 0;
}
