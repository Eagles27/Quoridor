#include "jeu.h"

void main_menu()
{
    int choix;
    int sortie = 0;
    int debut;

    do
    {
        system("cls");
        printf("1. Nouvelle Partie\n2. Charger Partie\n3. Afficher les regles\n4. Quitter\n");
        scanf("%d",&choix);

        switch(choix)
        {
        case 1:
        {

            system("cls");
            printf("Lancement de la partie\n");
            genematrice();
            debut = choix_j(2);
            printf("%d\n",debut);
            system("PAUSE");
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
