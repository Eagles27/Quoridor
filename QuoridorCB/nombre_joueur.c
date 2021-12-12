#include "Header_Pierre.h"

int nombre_joueur()
{

///0. Declaration variable

    int choix = -1; //Initialisation a -1 car choix impossible en pratique

    system("cls");  //On efface la console pour seulement afficher le menu

///1. Saisie du nombre de joueur

    do
    {
        system("cls");
        printf("1. 2 Joueurs\n2. 4 Joueurs\n3. 1 joueurs avec IA\n");
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
