#include "Header_Pierre.h"

void main_menu(int* Pnombre_joueur, int mat[17][17], t_joueur player[4], t_IA ia)
{
    ///0.0. DDV Joueur
    int Action = -1;
    int choix;
    int sortie = 0;
    int debut;
    char nom[50];
    int mat_avant[17][17];
    int numero;

    ///0.1. DDV IA
    char cJ1;
    int cIA;
    int num_tour = 0;
    int org[2];
    int dep_ia[2];
    int action_ia;

    srand(time(NULL));

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
            *Pnombre_joueur = nombre_joueur();  //Lancement du SSPG pour jouer a 2 ou 4

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////PARTIE AVEC IA ////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            if(*Pnombre_joueur == 1)
            {
                //On fixe *Ptour a 0 car le menu ne sera que pour J1
                *Ptour = 0;

                //Initialisation joueur
                system("cls");
                printf("Joueur %d : Saisissez votre nom :\n",1);
                fflush(stdin);
                scanf("%s",nom);
                majuscule(nom);
                strcpy(player[0].nomJ,nom);

                //Initialisation jetons
                choix_pion_ia(player, ia);
                /*printf("%c", ia.jeton);
                system("PAUSE");*/

                //Initialisation barrieres
                ia.barrieresR = 10;
                player[0].barrieresR = 10;

                //Initialisation score
                ia.score = 0;
                player[0].scoreP = 0;

                //Initialisation booleen annulation
                player[0].A_annule = 0;

                //Placement joueur
                do
                {
                    system("cls");
                    matrice_propre(mat,player,ia);
                    menu_cote(Ptour,Pnombre_joueur,player,ia);
                    printf("%s:\n\n",player[0].nomJ);
                    printf("Choisissez une ligne A --> Q\n");
                    fflush(stdin);
                    scanf("%c",&cJ1);
                    player[0].coordonneX = traduction(cJ1);
                    player[0].coordonneY = 0;

                    player[0].coordonneX_org = traduction(cJ1);
                    player[0].coordonneY_org = 0;
                }
                while ((cJ1!='A')&&(cJ1!='C')&&(cJ1!='E')&&(cJ1!='G')&&(cJ1!='I')&&(cJ1!='K')&&(cJ1!='M')&&(cJ1!='O')&&(cJ1!='Q'));

                mat[player[0].coordonneY][player[0].coordonneX] = 5;

                //Placement IA
                ia.coordonneY = 16;
                do
                {
                    cIA = rand()%16;
                    ia.coordonneX = cIA;
                }
                while((cIA != 0)&&(cIA != 2)&&(cIA != 4)&&(cIA != 6)&&(cIA != 8)&&(cIA != 10)&&(cIA != 12)&&(cIA != 14)&&(cIA != 16));

                /*printf("%s, %c", ia.nom, ia.jeton);
                system("PAUSE");*/
                mat[ia.coordonneY][ia.coordonneX] = 6;

                //Initialisation bonus
                case_bonus(mat);

                //Choix premier joueur
                debut = rand()%1;
                num_tour = debut;

                //Debut du jeu
                do
                {
                    for(int i = 0; i<17; i++)
                    {
                        for(int j = 0; j<17; j++)
                        {
                            mat_avant[i][j] = mat[i][j];
                        }
                    }

                    if(num_tour%2 == 0)
                    {
                        system("cls");
                        matrice_propre(mat,player,ia);
                        menu_cote_ia(num_tour,player,ia);
                        menu_game(mat,Pnombre_joueur,player,Ptour, mat_avant, PAction, ia, num_tour);
                        player[0].coordonneX_av = player[0].coordonneX;
                        player[0].coordonneY_av = player[0].coordonneY;

                        num_tour++;
                    }
                    else
                    {
                        ia.coordonneX_av = ia.coordonneX;
                        ia.coordonneY_av = ia.coordonneY;
                        org[0] =  ia.coordonneX;
                        org[1] = ia.coordonneY;
                        dep_ia[0] = ia.coordonneX;
                        dep_ia[1] = ia.coordonneY;
                        action_ia = ia_v0(dep_ia, mat, player, ia);
                        if(action_ia == 2)
                        {
                            ia.barrieresR --;
                        }

                        ia.coordonneX = dep_ia[0];
                        ia.coordonneY = dep_ia[1];
                        mat[org[1]][org[0]]=0;
                        mat[ia.coordonneY][ia.coordonneX]=6;

                        num_tour++;
                    }
                    sauver_plateau(mat_avant);
                }
                while(gagner_ia(player, ia, num_tour) == -1);

                //Victoire
                if(gagner_ia(player, ia, num_tour) == 1)
                {
                    if(num_tour%2 == 0)
                    {
                        //Joueur gagne
                    }
                    else
                    {
                        //IA gagne
                    }
                }
                else if(gagner_ia(player, ia, num_tour) == 2)
                {
                    printf("A faire");
                    system("PAUSE");
                }



            }
            else
            {

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////PARTIE CLASSIQUE ///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

                setup(Pnombre_joueur,debut,mat,player,Ptour,ia);

                for(int i=0; i<4; i++)
                {
                    player[i].scoreP = 0;
                    player[i].A_annule = 0;
                }


                ///TRICHE
                for(int i = 0; i<*Pnombre_joueur; i++)
                {
                    if(strcmp(player[i].nomJ, "RAVAUT")==0)
                    {
                        player[i].scoreP = 10;
                    }
                    else if(strcmp(player[i].nomJ, "MAXIME")==0)
                    {
                        player[i].barrieresR += 5;
                    }
                    else if(strcmp(player[i].nomJ, "ADRIEN")==0)
                    {
                        player[i].barrieresR += 5;
                    }
                    else if(strcmp(player[i].nomJ, "PIERRE")==0)
                    {
                        player[i].barrieresR += 5;
                    }
                }

                setup(Pnombre_joueur,debut,mat,player,Ptour,ia);

                tour_par_tour(Pnombre_joueur,mat,player,Ptour, mat_avant, PAction, ia);



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
                    matrice_propre(mat,player,ia);
                    menu_cote(Ptour,Pnombre_joueur,player,ia);
                    player[*Ptour-1].coordonneX_av = player[*Ptour-1].coordonneX;
                    player[*Ptour-1].coordonneY_av = player[*Ptour-1].coordonneY;
                    menu_game(mat,Pnombre_joueur,player,Ptour, mat_avant, PAction, ia, num_tour);

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



                    tour_par_tour(Pnombre_joueur,mat,player,Ptour, mat_avant, PAction, ia);
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
                    matrice_propre(mat,player,ia);
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
            }

            break;
        }
        case 2:
        {
            printf("Chargement de la partie\n");
            charger_plateau(mat);
            charger_joueur(player, Pnombre_joueur);
            choixPion(player, Pnombre_joueur);

            for(int i = 0; i<*Pnombre_joueur; i++)
            {
                printf("%s\n", player[i].nomJ);
                printf("%d\n", player[i].scoreP);
                printf("%c\n", player[i].jetonJ);
                printf("%d\n", player[i].numeroJ);
                printf("%d\n", player[i].coordonneX);
                printf("%d\n", player[i].coordonneY);
                printf("%d\n", player[i].coordonneX_org);
                printf("%d\n", player[i].coordonneY_org);
            }

            system("PAUSE");
            system("cls");

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
                matrice_propre(mat,player,ia);
                menu_cote(Ptour,Pnombre_joueur,player,ia);
                player[*Ptour-1].coordonneX_av = player[*Ptour-1].coordonneX;
                player[*Ptour-1].coordonneY_av = player[*Ptour-1].coordonneY;
                menu_game(mat,Pnombre_joueur,player,Ptour, mat_avant, PAction, ia, num_tour);

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



                tour_par_tour(Pnombre_joueur,mat,player,Ptour, mat_avant, PAction, ia);
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
                matrice_propre(mat,player,ia);
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

        case 3:
        {
            system("cls");
            affiregles();
            break;
        }

        case 4:
        {
            sauver_plateau(mat);
            sauver_joueur(player, Pnombre_joueur);
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
