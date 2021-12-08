#include "Header_Pierre.h"

void main_menu(int* Pnombre_joueur, int mat[17][17], t_joueur player[4])
{
    int choix;
    int sortie = 0;
    int debut;
    char nom[50];
    char liste_nom[100][50];
    int liste_score[100];
    /*
    //Declaration tableau dynamique pour les scores
    int *liste_score;
    liste_score = (int*)malloc(100*sizeof(int));

    //Declaration tableau dynamique pour les noms
    char** liste_nom;
    liste_score = (char**)malloc(100*sizeof(char*));
    if(liste_nom != NULL){
        for(int i = 0; i<100; i++){
            liste_nom[i] = (char*)malloc(50*sizeof(char));
        }
    }*/

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
            *Pnombre_joueur = nombre_joueur();  //Lancement du SSPG pour jouer � 2 ou 4

/// RESET DES TOKENS


            for(int i=0; i<4; i++)
            {
                player[i].jetonJ = '1';     // Valeur donnee arbitrairement

            }





            ///Remplissage des donnees de la strcuture pour 4 J

            if(*Pnombre_joueur == 4)
            {
                for(int i=0; i<4; i++)
                {
                    system("cls");
                    printf("Joueur %d : Saisissez votre nom :\n",i+1);
                    fflush(stdin);
                    scanf("%s",nom);
                    majuscule(nom);
                    strcpy(player[i].nomJ,nom);
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
                    scanf("%s",nom);
                    majuscule(nom);
                    strcpy(player[i].nomJ,nom);
                    choixPion(player,i);
                    player[i].numeroJ = i+1;
                }
            }


            debut = choix_j(*Pnombre_joueur); //SSPG pour d�terminer qui commence
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
                sauver_plateau(mat);


            }
            while(gagner(player,Pnombre_joueur,tour_test) == -1);


            ///Test fin de partie car joueur qui atteint la fin
            if (gagner(player,Pnombre_joueur,tour_test) == 1)
            {
                system("cls");
                printf("Gagne!!!");
                system("PAUSE");
            }


            ///Test fin de partie car joueur n'a plus de barri�res

            else if(gagner(player,Pnombre_joueur,tour_test) == 2)
            {
                system("cls");
                matrice_propre(mat,player);
                printf("\n\n%s n'a plus de barriere\n",player[tour_test].nomJ);

                system("PAUSE");
            }


            break;
        }
        case 2:
        {
            printf("Chargement de la partie\n");
            charger_plateau(mat);
            charger_joueur(player, Pnombre_joueur);
            charger_score(liste_nom, liste_score);
            for(int i=0; i<100; i++)
            {
                if(*Pnombre_joueur == 2)
                {
                    if(strcmp(liste_nom[i],player[0].nomJ)==0)
                    {
                        player[0].scoreP = liste_score[i];
                    }
                    else if(strcmp(liste_nom[i],player[1].nomJ)==0)
                    {
                        player[1].scoreP = liste_score[i];
                    }
                }
                else{
                    if(strcmp(liste_nom[i],player[0].nomJ)==0)
                    {
                        player[0].scoreP = liste_score[i];
                    }
                    else if(strcmp(liste_nom[i],player[1].nomJ)==0)
                    {
                        player[1].scoreP = liste_score[i];
                    }
                    else if(strcmp(liste_nom[i],player[2].nomJ)==0)
                    {
                        player[2].scoreP = liste_score[i];
                    }
                    else if(strcmp(liste_nom[i],player[3].nomJ)==0)
                    {
                        player[3].scoreP = liste_score[i];
                    }
                }
            }

            system("cls");
            tour_par_tour(Pnombre_joueur,mat,player,Ptour);


            while(gagne == 1)
            {
                system("cls");
                matrice_propre(mat,player);
                menu_cote(Ptour,Pnombre_joueur,player);
                menu_game(mat,Pnombre_joueur,player,Ptour);
                tour_par_tour(Pnombre_joueur,mat,player,Ptour);
                sauver_plateau(mat);
            }

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
