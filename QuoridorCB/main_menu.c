#include "Header_Pierre.h"

void main_menu(int* Pnombre_joueur, int mat[17][17], t_joueur player[4])
{
    int choix;
    int sortie = 0;
    int debut;

    /// Test
    int tour = 1;

    do
    {
        system("cls");
        printf("1. Nouvelle Partie\n2. Charger Partie\n3. Afficher les regles\n4. Quitter\n");
        fflush(stdin);
        scanf("%d",&choix);

        switch(choix)
        {
        case 1:
        {

            system("cls");
            *Pnombre_joueur = nombre_joueur();  //Lancement du SSPG pour jouer à 2 ou 4

            ///Remplissage des donnees de la strcuture pour 4 J

            if(*Pnombre_joueur == 4)
            {
                for(int i=0; i<4; i++)
                {
                    system("cls");
                    printf("Saisissez votre nom :\n");
                    fflush(stdin);
                    scanf("%s",player[i].nomJ);

                    system("cls");
                    printf("Choisissez votre pion parmis les suivants:\n\n'*','&','@','#'\n");
                    fflush(stdin);
                    scanf("%c",&player[i].jetonJ);

                    player[i].numeroJ = i+1;


                }
            }

            ///Remplissage des donnees de la strcuture pour 2 J

            else
            {
                for(int i=0; i<2; i++)
                {
                    system("cls");
                    printf("Saisissez votre nom :\n");
                    fflush(stdin);
                    scanf("%s",player[i].nomJ);

                    system("cls");
                    printf("Choisissez votre pion parmis les suivants:\n\n'*','&','@','#'\n");
                    fflush(stdin);
                    scanf("%c",&player[i].jetonJ);

                    player[i].numeroJ = i+1;

                }
            }


            debut = choix_j(*Pnombre_joueur);   //SSPG pour déterminer qui commence
            system("cls");
            distribution_barriere(player,Pnombre_joueur);
            matrice_propre(mat);
            menu_cote(tour,Pnombre_joueur,player);
            setup(Pnombre_joueur,debut,mat,player,tour);
            tour_par_tour(Pnombre_joueur,mat,player,tour);
            menu_game(mat,Pnombre_joueur,player,tour);
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
            system("cls");
            printf("Deconexion...\n");
            ExitProcess(0); ///Permet la sortie du process et l'interruption de l'ensemble des SPPG en cours
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
