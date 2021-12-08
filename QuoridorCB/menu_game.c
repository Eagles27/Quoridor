#include "Header_Pierre.h"

void menu_game(int mat[17][17],int* Pnombrejoueur,t_joueur player[4],int* Ptour, int mat_avant[17][17], int *Action)
{
    int choix;
    int sortie = 1;
    int dep[3];
    int org[3];
    char temp;
    int saisie1[2];
    int bool_barriere = -1;


    do
    {
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
        fflush(stdin);
        scanf("%d",&choix);

        switch(choix)
        {
        case 1:
        {
            ///Mettre programme de pierre

            dep[0] =  player[*Ptour-1].coordonneX;
            dep[1] = player[*Ptour-1].coordonneY;
            org[0] =  player[*Ptour-1].coordonneX;
            org[1] = player[*Ptour-1].coordonneY;

            deplacement(dep,mat,Pnombrejoueur,Ptour,player);

            player[*Ptour-1].coordonneX = dep[0];
            player[*Ptour-1].coordonneY = dep[1];
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
            system("cls");
            matrice_propre(mat,player);
            menu_cote(Ptour,Pnombrejoueur,player);
            //system("PAUSE");

            *Action = 1;

            break;
        }
        case 2:
        {
            ///PPG Barriere

            while(bool_barriere==-1)
            {

                system("cls");
                matrice_propre(mat,player);
                menu_cote(Ptour,Pnombrejoueur,player);
                saisie_coord(saisie1);

                bool_barriere = placer_barriere(mat, saisie1, saisie_dir());
            }

            system("cls");
            player[*Ptour-1].barrieresR --; ///On d�cremente le nombre de barriere une fois pos�e
            matrice_propre(mat,player);
            menu_cote(Ptour,Pnombrejoueur,player);
            //system("PAUSE");
            *Action = 2;

            break;
        }
        case 3 :
        {
            ///PPG passer son tour
            *Ptour ++;
            *Action = 3;

            break;
        }
        case 4 :
        {
            if(player[*Ptour-1].A_annule == 0)
            {
                ///PPG annuler l'action
                charger_plateau(mat_avant);
                /*system("cls");
                for(int i = 0; i<17; i++)
                {
                    for(int j = 0; j<17; j++)
                    {
                        printf("%d", mat_avant[i][j]);
                    }
                    printf("\n");
                }
                system("PAUSE");*/
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
                        if(*Ptour == 4)
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



                    player[*Ptour-1].A_annule = 1;

                    //mat[player[*Ptour].coordonneY][player[*Ptour].coordonneX] = player[*Ptour].numeroJ;
                }
                //printf("(%d, %d)\n", player[*Ptour-1].coordonneX, player[*Ptour-1].coordonneY);
                //system("PAUSE");

                *Action = 4;
                *Ptour ++;
            }
            else
            {
                printf("Cette action ne peut etre fait qu'une fois\n");
                system("PAUSE");
                choix = 0;
            }

            break;
        }
        case 5 :
        {
            main_menu(Pnombrejoueur,mat,player);
            break;
        }

        default :
        {
            choix = 0;
            printf("Saisie Erronee\n\n");
            system("PAUSE");
            system("cls");
            matrice_propre(mat,player);
            menu_cote(Ptour,Pnombrejoueur,player);
            break;
        }
        }

    }
    while(choix == 0);


}
