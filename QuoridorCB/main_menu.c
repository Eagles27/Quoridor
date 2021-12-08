#include "Header_Pierre.h"

void main_menu(int* Pnombre_joueur, int mat[17][17], t_joueur player[4])
{
    int choix;
    int sortie = 0;
    int debut;


    /// Test

    int gagne = -1;

    int tour_test;

    int tour = 1;
    int* Ptour = &tour;



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
            genematrice(mat);

            system("cls");
            *Pnombre_joueur = nombre_joueur();  //Lancement du SSPG pour jouer à 2 ou 4

/// RESET DES TOKENS


            for(int i=0; i<4; i++)
            {
                player[i].jetonJ = '1';     // Valeur donnée arbitrairement

            }





            ///Remplissage des donnees de la strcuture pour 4 J

            if(*Pnombre_joueur == 4)
            {
                for(int i=0; i<4; i++)
                {
                    system("cls");
                    printf("Joueur %d : Saisissez votre nom :\n",i+1);
                    fflush(stdin);
                    scanf("%s",player[i].nomJ);

                    choixPion(player,i);


                    player[i].numeroJ = i+1;


                }
            }

            ///Remplissage des donnees de la strcuture pour 2 J

            else
            {
                for(int i=0; i<2; i++)
                {
                    system("cls");
                    printf("Joueur %d : Saisissez votre nom :\n",i+1);
                    fflush(stdin);
                    scanf("%s",player[i].nomJ);


                    choixPion(player,i);
                    player[i].numeroJ = i+1;

                }
            }


            debut = choix_j(*Pnombre_joueur); //SSPG pour déterminer qui commence
            system("cls");
            distribution_barriere(player,Pnombre_joueur);



            setup(Pnombre_joueur,debut,mat,player,Ptour);
            tour_par_tour(Pnombre_joueur,mat,player,Ptour);




            do
            {

                system("cls");
                matrice_propre(mat,player);
                menu_cote(Ptour,Pnombre_joueur,player);
                menu_game(mat,Pnombre_joueur,player,Ptour);

                if(*Ptour == 1){
                    tour_test = *Ptour-1;
                }
                else if(*Ptour == 2){
                    tour_test = 1;
                }
                tour_par_tour(Pnombre_joueur,mat,player,Ptour);


            }
            while(gagner(player,Pnombre_joueur,tour_test) == -1);


            ///Test fin de partie car joueur qui atteint la fin
            if (gagner(player,Pnombre_joueur,tour_test) == 1)
            {
                system("cls");
                printf("Gagne!!!");
                system("PAUSE");
            }


            ///Test fin de partie car joueur n'a plus de barrières

            else if(gagner(player,Pnombre_joueur,tour_test) == 2)
            {
                system("cls");
                matrice_propre(mat,player);
                printf("\n\n%s n'a plus de barriere\n\n",player[tour_test].nomJ);



                if(gagner_barriere(player) == -1)
                {
                    printf("Les 2 jouers ont gagnes car ils sont autant avances\n");
                    system("PAUSE");
                }

                else
                {

                printf("%s a gagne la partie car c'est le plus avance sur le plateau\n",player[gagner_barriere(player)].nomJ);

                system("PAUSE");

                }

            }


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
