#include "Header_Pierre.h"

void main_menu(int* Pnombre_joueur, int mat[17][17], t_joueur player[4])
{
    int Action = -1;
    int choix;
    int sortie = 0;
    int debut;
    char nom[50];
    int mat_avant[17][17];
    int numero;

    char list_joueur[100][50];
    int list_score[100];
    int index_score[4][2];

    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<2; j++)
        {
            index_score[i][j] = -1;
        }
    }

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
    int *PAction = &Action;



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


            //for(int i=0; i<4; i++)
            {
                // player[i].jetonJ = '1';     // Valeur donnee arbitrairement

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


                    player[i].numeroJ = i+1;


                }
                choixPion(player,Pnombre_joueur);
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
                    player[i].numeroJ = i+1;
                }
                choixPion(player,Pnombre_joueur);
            }


            debut = choix_j(*Pnombre_joueur); //SSPG pour déterminer qui commence
            system("cls");
            distribution_barriere(player,Pnombre_joueur);

            extraction_score(player, Pnombre_joueur, list_joueur, list_score, index_score);

            for(int i = 0; i<4; i++)
            {
                if(index_score[i][1] != -1)
                {
                    player[index_score[i][1]].scoreP = list_score[index_score[i][0]];
                }
            }

            setup(Pnombre_joueur,debut,mat,player,Ptour);
            tour_par_tour(Pnombre_joueur,mat,player,Ptour, mat_avant, PAction);


            player[1].barrieresR = 1;

            ///Initialisation bonus
            case_bonus(mat);

            do
            {
                for(int i = 0; i<17; i++)
                {
                    for(int j = 0; j<17; j++)
                    {
                        mat_avant[i][j] = mat[i][j];
                    }
                }

                system("cls");
                matrice_propre(mat,player);
                menu_cote(Ptour,Pnombre_joueur,player);
                player[*Ptour-1].coordonneX_av = player[*Ptour-1].coordonneX;
                player[*Ptour-1].coordonneY_av = player[*Ptour-1].coordonneY;
                menu_game(mat,Pnombre_joueur,player,Ptour, mat_avant, PAction);

                if(*Pnombre_joueur == 2)
                {
                    if(*Ptour == 1)
                    {
                        tour_test = *Ptour-1;
                    }
                    else if(*Ptour == 2)
                    {
                        tour_test = 1;
                    }
                }



                tour_par_tour(Pnombre_joueur,mat,player,Ptour, mat_avant, PAction);
                sauver_plateau(mat_avant);

            }
            while(gagner(player,Pnombre_joueur,tour_test) == -1);


            ///Test fin de partie car joueur qui atteint la fin
            if (gagner(player,Pnombre_joueur,tour_test) == 1)
            {
                system("cls");
                printf("Gagne!!!");
                player[tour_test].scoreP ++;
                sauver_score(player, Pnombre_joueur);
                system("PAUSE");
            }


            ///Test fin de partie car joueur n'a plus de barrieres

            else if(gagner(player,Pnombre_joueur,tour_test) == 2)
            {
                system("cls");
                matrice_propre(mat,player);
                printf("\n\n%s n'a plus de barriere\n\n",player[tour_test].nomJ);

                if(player[tour_test].numeroJ == 1)
                {
                    numero = 0;
                }
                else
                {
                    numero = 1;
                }




                if(gagner_barriere(player, Pnombre_joueur) == -1)
                {
                    printf("Les 2 jouers ont gagnes car ils sont autant avances\n");
                    system("PAUSE");
                    sauver_score(player, Pnombre_joueur);
                }

                else
                {

                    printf("%s a gagne la partie car c'est le plus avance sur le plateau\n",player[gagner_barriere(player, Pnombre_joueur)].nomJ);
                    player[gagner_barriere(player, Pnombre_joueur)].scoreP ++;
                    system("PAUSE");
                    sauver_score(player, Pnombre_joueur);

                }

            }
            if(gagner(player,Pnombre_joueur,tour_test) != -1)
            {
                for(int i = 0; i<4; i++)
                {
                    if(index_score[i][1] != -1)
                    {
                        list_score[index_score[i][0]] = player[index_score[i][1]].scoreP;
                    }
                }
            }



            break;
        }
        case 2:
        {
            printf("Chargement de la partie\n");
            charger_plateau(mat);
            charger_joueur(player, Pnombre_joueur);
            extraction_score(player, Pnombre_joueur, list_joueur, list_score, index_score);
            for(int j = 0; j<*Pnombre_joueur; j++)
            {
                for(int i=0; i<100; i++)
                {
                    if(strcmp(list_joueur[i],player[j].nomJ)==0)
                    {
                        player[0].scoreP = list_score[i];
                    }
                    else
                    {
                        player[j].scoreP = 0;
                    }
                }
            }

            system("cls");
            tour_par_tour(Pnombre_joueur,mat,player,Ptour, mat_avant, PAction);


            while(gagne == 1)
            {
                system("cls");
                matrice_propre(mat,player);
                menu_cote(Ptour,Pnombre_joueur,player);
                menu_game(mat,Pnombre_joueur,player,Ptour, mat_avant, PAction);
                tour_par_tour(Pnombre_joueur,mat,player,Ptour, mat_avant, PAction);
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
            printf("Deconnexion...\n");
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
