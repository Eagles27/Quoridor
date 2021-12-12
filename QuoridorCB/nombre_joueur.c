#include "Header_Pierre.h"

int nombre_joueur()
{

///0. Declaration variable

    int choix = -1; //Initialisation a -1 car choix impossible en pratique
    Color(15,0);
    //system("cls");  //On efface la console pour seulement afficher le menu

///1. Saisie du nombre de joueur

    do
    {
        system("cls");

        Affichage_Du_Titre(1,35);

        Color(15,2);
            gotoligcol(10,50);
            printf("                    ");
            gotoligcol(11,50);
            printf("  Saisir  1,2 ou 3  ");
            gotoligcol(12,50);
            printf("                    ");
            Color(15,10);
            gotoligcol(13,50);
            printf("                    ");
            gotoligcol(14,50);
            printf("     1. 2 Joueurs   ");
            gotoligcol(15,50);
            printf("     2. 4 Joueurs   ");
            gotoligcol(16,50);
            printf(" 3. 1 Joueur et IA  ");
            gotoligcol(17,50);
            printf("                    ");
            gotoligcol(18,50);

        scanf("%d",&choix);

    }
    while ((choix != 1)&&(choix != 2)&&(choix != 3));   //Blindage de valeurs



    if (choix == 1)
        return 2;   //Return le nombre de joueurs

    else if(choix == 2)
        return 4;   //Return le nombre de joueurs

    else
        return 1;   //Return le nombre de joueurs

}
