#include "jeu.h"

int nombre_joueur()
{
    int choix = -1;

    system("cls");

    do
    {
        if((choix != 1)&&(choix != 2))
        {
            printf("Saisir 1 ou 2\n");
        }

            system("cls");
            printf("1. 2 Joueurs\n2. 4 Joueurs\n");
            scanf("%d",&choix);

    }
    while ((choix != 1)&&(choix != 2));


    if (choix == 1)
        return 2;

    else
        return 4;

}
