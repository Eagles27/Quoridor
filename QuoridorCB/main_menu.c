#include "jeu.h"

void main_menu()
{
    int choix;
    int sortie = 0;

    do
    {
        system("cls");
        printf("1. Nouvelle Partie\n2. Charger Partie\n3. Afficher les règles\n4. Quitter\n");
        scanf("%d",&choix);

        switch(choix)
        {
        case 1:
        {

            system("cls");
            printf("Lancement de la partie\n");
            break;
        }
        case 2:
        {
            printf("Chargement de la partie\n");
            break;
        }

        case 3:
        {
            system("cls");
            printf("Affichage des regles\n");
            break;
        }

        case 4:
        {
            sortie = -1;
            break;
        }



        default:
        {
            printf("Mauvaise saisie\n");
            system("PAUSE");
            break;
        }


        }

    }
    while(sortie!=-1);
}
