#include "jeu.h"

void main_menu(int* PbarJ1,int* PbarJ2,int* PbarJ3,int* PbarJ4,int* Pnombre_joueur, int mat[17][17])
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
            *Pnombre_joueur = nombre_joueur();  //Lancement du SSPG pour jouer à 2 ou 4
            affiche(mat);
            debut = choix_j(*Pnombre_joueur);   //SSPG pour déterminer qui commence
            system("cls");
            affiche(mat);
            menu_game();
            distributio_barriere(PbarJ1,PbarJ2,PbarJ3,PbarJ4,Pnombre_joueur);
            printf("\nNombre barriere J1 : %d, Nombre Barriere J3 : %d\n",*PbarJ1,*PbarJ3);
            setup(Pnombre_joueur,debut,mat);
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
            affiregles();
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
