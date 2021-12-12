#include "Header_Pierre.h"

void menu_game(int mat[17][17],int* Pnombrejoueur,t_joueur player[4],int* Ptour, int mat_avant[17][17], int *Action, t_IA ia, int tour)
{
    ///0. DDV
    int choix;
    int sortie = 1;
    int dep[3];
    int org[3];
    char temp;
    int saisie1[2];
    char saisie_direction;
    int bool_barriere = -1;


    ///1. Choix de l'action voulue
    do //Blindage
    {

        ///1.1. Affichage des choix

        int numero_ligne_action=20;//locales
        int numero_colonne_action=3;//locales

        gotoligcol(numero_ligne_action,numero_colonne_action);
        Color(15,2);
        printf("                                    ");
        gotoligcol(numero_ligne_action+1,numero_colonne_action);
        printf("         Actions Possibles:         ");
        gotoligcol(numero_ligne_action+2,numero_colonne_action);
        printf("                                    ");
        gotoligcol(numero_ligne_action+3,numero_colonne_action);
        Color(15,10);
        printf("                                    ");
        gotoligcol(numero_ligne_action+4,numero_colonne_action);
        printf("       1. Deplacer son pion         ");
        gotoligcol(numero_ligne_action+5,numero_colonne_action);
        printf("       2. Poser une barriere        ");
        gotoligcol(numero_ligne_action+6,numero_colonne_action);
        printf("         3. Passer son tour         ");
        gotoligcol(numero_ligne_action+7,numero_colonne_action);
        printf("    4. Annuler la derniere action   ");
        gotoligcol(numero_ligne_action+8,numero_colonne_action);
        printf("    5. Revenir au menu precedent    ");
        gotoligcol(numero_ligne_action+9,numero_colonne_action);
        printf("                                    ");
        gotoligcol(numero_ligne_action+10,numero_colonne_action);
        printf("   Saisie de l'action du joueur:    ");
        gotoligcol(numero_ligne_action+11,numero_colonne_action);
        printf("                                    ");
        gotoligcol(numero_ligne_action+12,numero_colonne_action);
        Color(15,0);
        fflush(stdin);
        scanf("%d",&choix);

        switch(choix)
        {
        ///2. Se deplacer
        case 1:
        {
            ///2.1. Partie avec une IA
            if(*Pnombrejoueur == 1)
            {
                ///2.1.1. Sauvegarde des coordonnees du pion
                dep[0] =  player[0].coordonneX;
                dep[1] = player[0].coordonneY;
                org[0] =  player[0].coordonneX;
                org[1] = player[0].coordonneY;

                ///2.1.2. Modification des coordonnees du pion
                deplacement_ia(dep, player, mat,tour, ia);

                player[0].coordonneX = dep[0];
                player[0].coordonneY = dep[1];

                ///2.1.3. Actualisation de la matrice
                mat[org[1]][org[0]]=0;
                mat[dep[1]][dep[0]] = 5;
            }
            ///2.2. Partie classique
            else
            {
                ///2.2.1. Sauvegarde des coordonnees du pion
                dep[0] =  player[*Ptour-1].coordonneX;
                dep[1] = player[*Ptour-1].coordonneY;
                org[0] =  player[*Ptour-1].coordonneX;
                org[1] = player[*Ptour-1].coordonneY;

                ///2.2.2. Modification des coordonnees du pion
                deplacement(dep,mat,Pnombrejoueur,Ptour,player,ia);

                player[*Ptour-1].coordonneX = dep[0];
                player[*Ptour-1].coordonneY = dep[1];

                ///2.2.3. Actualisation de la matrice
                mat[org[1]][org[0]]=0;

                if(*Pnombrejoueur == 2)
                {
                    if(*Ptour == 2)
                    {
                        mat[dep[1]][dep[0]] = 7;
                    }

                    else
                    {
                        mat[dep[1]][dep[0]] = 5;

                    }
                }
                else
                {
                    if(*Ptour == 4)
                    {
                        mat[dep[1]][dep[0]] = 9;
                    }

                    else if(*Ptour == 3)
                    {
                        mat[dep[1]][dep[0]] = 8;

                    }
                    else if(*Ptour == 2)
                    {
                        mat[dep[1]][dep[0]] = 7;

                    }
                    else
                    {
                        mat[dep[1]][dep[0]] = 5;

                    }
                }

                *Action = 1;
            }

            break;
        }
        ///3. Poser une barriere
        case 2:
        {
            ///3.1. Placement de la barriere
            while(bool_barriere==-1)
            {
                if(*Pnombrejoueur == 1)
                {
                    Color(15,0);
                    system("cls");
                    matrice_propre(mat,player,ia);
                    menu_cote_ia(2, player, ia);
                    saisie_coord(saisie1,Ptour,Pnombrejoueur,player,mat,ia);
                    saisie_direction = saisie_dir(Ptour,Pnombrejoueur,player,mat,ia);
                }
                else
                {
                    Color(15,0);
                    system("cls");
                    matrice_propre(mat,player,ia);
                    menu_cote(Ptour,Pnombrejoueur,player);
                    saisie_coord(saisie1,Ptour,Pnombrejoueur,player,mat,ia);
                    saisie_direction = saisie_dir(Ptour,Pnombrejoueur,player,mat,ia);
                }


                bool_barriere = placer_barriere(mat, saisie1, saisie_direction);
            }
            Color(15,0);
            system("cls");

            ///3.2. Decrement du nombre de barriere du joueur
            if(*Pnombrejoueur == 1)
            {
                player[0].barrieresR --;
            }
            else
            {
                player[*Ptour-1].barrieresR --; //On decremente le nombre de barriere une fois posee
            }

            if(*Pnombrejoueur==1)
            {
                matrice_propre(mat,player,ia);
                menu_cote_ia(2, player, ia);
            }
            else
            {
                matrice_propre(mat,player,ia);
                menu_cote(Ptour,Pnombrejoueur,player);
            }



            *Action = 2;

            break;
        }

        ///4. Passer son tour
        case 3 :
        {
            *Ptour ++;
            *Action = 3;

            break;
        }

        ///5. Annuler la derniere action
        case 4 :
        {
            ///5.1. Partie avec une ia
            if(*Pnombrejoueur == 1)
            {
                ///5.1.1. Chargement des coordonnees de l'IA au tour precedent
                if(player[0].A_annule == 0)
                {
                    ia.coordonneX = ia.coordonneX_av;
                    ia.coordonneY = ia.coordonneY_av;

                    ///5.1.2. Booleen passe a true : le joueur ne peut annuler l'action qu'une fois
                    player[0].A_annule = 1;
                }
                else
                {
                    ///5.1.3. Le joueur a deja annule une action, il ne peut plus le refaire

                    Color(15,0);
                    gotoligcol(33,3);
                    Color(15,10);
                    printf("                                                           ");
                    Color(15,0);
                    gotoligcol(34,3);
                    Color(15,10);
                    printf("        Cette action ne peut etre faite qu'une fois        ");

                    Color(15,0);
                    gotoligcol(35,3);
                    Color(15,10);
                    printf("                                                           ");
                    Color(15,0);
                    gotoligcol(36,3);


                    system("PAUSE");
                    system("cls");
                    matrice_propre(mat,player,ia);
                    menu_cote_ia(tour, player, ia);
                    choix = 0;
                }

            }
            ///5.2. Partie classique
            else
            {
                ///5.2.1. Si le joueur n'a pas deja annulé un tour
                if(player[*Ptour-1].A_annule == 0)
                {
                    ///5.2.2. Chargement de l'ancien plateau et des anciennes coordonnees
                    charger_plateau(mat_avant);

                    for(int i = 0; i<17; i++)
                    {
                        for(int j = 0; j<17; j++)
                        {
                            mat[i][j] = mat_avant[i][j];
                        }
                    }
                    if(*Action == 1)
                    {
                        if(*Pnombrejoueur == 2)
                        {
                            if(*Ptour == 2)
                            {
                                player[0].coordonneX = player[0].coordonneX_av;
                                player[0].coordonneY = player[0].coordonneY_av;
                            }
                            else
                            {
                                player[*Ptour].coordonneX = player[*Ptour].coordonneX_av;
                                player[*Ptour].coordonneY = player[*Ptour].coordonneY_av;
                            }
                        }
                        else
                        {
                            if(*Ptour == 1)
                            {
                                player[3].coordonneX = player[3].coordonneX_av;
                                player[3].coordonneY = player[3].coordonneY_av;
                            }
                            else
                            {
                                player[*Ptour-2].coordonneX = player[*Ptour-2].coordonneX_av;
                                player[*Ptour-2].coordonneY = player[*Ptour-2].coordonneY_av;
                            }
                        }

                        ///5.2.3. Passage du booleen a true
                        player[*Ptour-1].A_annule = 1;

                    }


                    *Action = 4;
                    *Ptour ++;
                }
                ///5.2.4. Le joueur a deja annulé un tour
                else
                {
                    Color(15,0);
                    gotoligcol(33,3);
                    Color(15,10);
                    printf("                                                           ");
                    Color(15,0);
                    gotoligcol(34,3);
                    Color(15,10);
                    printf("        Cette action ne peut etre faite qu'une fois        ");
                    Color(15,0);
                    gotoligcol(35,3);
                    Color(15,10);
                    printf("                                                           ");
                    Color(15,0);
                    gotoligcol(36,3);

                    system("PAUSE");
                    system("cls");
                    matrice_propre(mat,player,ia);
                    menu_cote(Ptour,Pnombrejoueur,player);
                    choix = 0;
                }
            }

            break;
        }

        ///6. Revenir au menu precedent
        case 5 :
        {
            ///6.1. Retour au menu precedent et sauvegarde des infos plateau et joueur
            main_menu(Pnombrejoueur,mat,player, ia);
            sauver_plateau(mat);
            sauver_joueur(player, Pnombrejoueur);
            break;
        }

        default :
        {
            choix = 0;
            Color(15,0);
            gotoligcol(33,3);
            Color(15,10);
            printf("                              ");
            Color(15,0);
            gotoligcol(34,3);
            Color(15,10);
            printf("        Saisie erronee        ");
            Color(15,0);
            gotoligcol(35,3);
            Color(15,10);
            printf("                              ");
            system("PAUSE");
            system("cls");
            matrice_propre(mat,player,ia);
            menu_cote(Ptour,Pnombrejoueur,player);
            break;
        }
        }

    }
    while(choix == 0); //Blindage

}
