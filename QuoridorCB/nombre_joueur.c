#include "Header_Pierre.h"

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
            printf("1. 2 Joueurs\n2. 4 Joueurs\n3. 1 joueurs avec IA\n");
            scanf("%d",&choix);

    }
    while ((choix != 1)&&(choix != 2)&&(choix != 3));


    if (choix == 1)
        return 2;

    else if(choix == 2)
        return 4;

    else
        return 1;

}
