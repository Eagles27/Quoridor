#include "Header_Pierre.h"

void main_menu(int* Pnombre_joueur, int mat[17][17], t_joueur player[4], t_IA ia)
{
///0.0. DDV Joueur
    int choix;
    int sortie = 0;
    int debut;
    char nom[50];
    int mat_avant[17][17];
    int numero;
    int gagne = -1;
    int tour_test;
    int tour = 1;
    int* Ptour = &tour;
    int Action = -1;
    int* PAction = &Action;

///0.1. DDV IA
    char cJ1;
    int cIA;
    int num_tour = 0;
    int org[2];
    int dep_ia[2];
    int action_ia;

    srand(time(NULL));  //Reset de l'horloge interne
    int numero_lig=20;
    int numero_col=3;

    int nl=10;
    int nc=45;

///1 Affichage du menu principal

    do
    {
        system("cls");
        Affichage_Du_Titre(1,35);

        Color(15,2);
        gotoligcol(10,50);
        printf("                            ");
        gotoligcol(11,50);
        printf("            MENU            ");
        gotoligcol(12,50);
        printf("                            ");
        Color(15,10);
        gotoligcol(13,50);
        printf("                            ");
        gotoligcol(14,50);
        printf("   1. Nouvelle Partie       ");
        gotoligcol(15,50);
        printf("   2. Charger Partie        ");
        gotoligcol(16,50);
        printf("   3. Afficher les regles   ");
        gotoligcol(17,50);
        printf("   4. Affichage des scores  ");
        gotoligcol(18,50);
        printf("   5. Quitter               ");
        gotoligcol(19,50);
        printf("                            ");

        fflush(stdin);
        gotoligcol(20,50);
        scanf("%d",&choix);
        Color(15,0);

        switch(choix)
        {

///1.1 Nouvelle Partie

        case 1:
        {
            genematrice(mat);   //Reset de la matrice ordinateur

            system("cls");
            *Pnombre_joueur = nombre_joueur();  //Lancement du SSPG pour jouer a 1,2 ou 4J

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////PARTIE AVEC IA ////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            if(*Pnombre_joueur == 1)
            {
                //On fixe *Ptour a 0 car le menu ne sera que pour J1
                *Ptour = 0;

                ///Initialisation joueur
                Color(15,0);
                system("cls");
                Affichage_Du_Titre(1,35);
                Color(15,2);
                gotoligcol(10,47);
                printf("                             ");
                gotoligcol(11,47);
                printf("         Saisie nom          ");
                gotoligcol(12,47);
                printf("                             ");
                Color(15,10);
                gotoligcol(13,47);
                printf("                             ");
                gotoligcol(14,47);
                printf("          Joueur %d           ",1);
                gotoligcol(15,47);
                printf("    Saisissez votre nom :    ");
                gotoligcol(16,47);
                printf("                             ");
                fflush(stdin);
                gotoligcol(17,47);
                scanf("%s",nom);
                Color(15,0);
                majuscule(nom);
                strcpy(player[0].nomJ,nom);

                ///Initialisation jetons
                choix_pion_ia(player, ia);


                ///Initialisation barrieres
                ia.barrieresR = 10;
                player[0].barrieresR = 10;

                ///Initialisation score
                ia.score = 0;
                save_score(player,0);

                ///Initialisation booleen annulation
                player[0].A_annule = 0;

                ///Placement joueur
                do
                {
                    system("cls");
                    matrice_propre(mat,player,ia);
                    menu_cote_ia(num_tour,player,ia);
                    //printf("%s:\n\n",player[0].nomJ);

                    Color(15,0);
                    gotoligcol(numero_lig+8,3);
                    Color(15,2);
                    printf("                                      ");
                    Color(15,0);
                    gotoligcol(numero_lig+8,3);
                    Color(15,2);
                    printf("                %s                     ",player[0].nomJ);
                    Color(15,0);
                    ///Effacage de ce qui dépasse
                    gotoligcol(numero_lig+9,38+3);
                    printf("             ");
                    gotoligcol(numero_lig+10,3);
                    Color(15,10);
                    printf("                                      ");
                    Color(15,0);
                    gotoligcol(numero_lig+11,3);
                    Color(15,10);
                    printf("     Choisissez une ligne A --> Q     ");
                    Color(15,0);
                    gotoligcol(numero_lig+12,3);
                    Color(15,10);
                    printf("                                      ");
                    Color(15,0);
                    gotoligcol(numero_lig+13,3);


                    fflush(stdin);
                    scanf("%c",&cJ1);
                    player[0].coordonneX = traduction(cJ1);
                    player[0].coordonneY = 0;

                    player[0].coordonneX_org = traduction(cJ1);
                    player[0].coordonneY_org = 0;
                }
                while ((cJ1!='A')&&(cJ1!='C')&&(cJ1!='E')&&(cJ1!='G')&&(cJ1!='I')&&(cJ1!='K')&&(cJ1!='M')&&(cJ1!='O')&&(cJ1!='Q'));

                mat[player[0].coordonneY][player[0].coordonneX] = 5;

                ///Placement IA
                ia.coordonneY = 16;
                do
                {
                    cIA = rand()%16;
                    ia.coordonneX = cIA;
                }
                while((cIA != 0)&&(cIA != 2)&&(cIA != 4)&&(cIA != 6)&&(cIA != 8)&&(cIA != 10)&&(cIA != 12)&&(cIA != 14)&&(cIA != 16));


                mat[ia.coordonneY][ia.coordonneX] = 6;  //6 est attribue comme la position de IA dans la matrice ordi

                ///Initialisation bonus
                case_bonus(mat);

                ///Choix premier joueur
                debut = rand()%1;
                num_tour = debut;

                ///Debut du jeu
                do
                {
                    for(int i = 0; i<17; i++)
                    {
                        for(int j = 0; j<17; j++)
                        {
                            mat_avant[i][j] = mat[i][j];    //Permet de stocker la matrice du tour precedant en cas: "annuler l'action"
                        }
                    }

                    ///Tour du joueur
                    if(num_tour%2 == 0)
                    {
                        system("cls");
                        matrice_propre(mat,player,ia);
                        menu_cote_ia(num_tour,player,ia);



                        //Affichage_Du_Titre(18,43);

                        menu_game(mat,Pnombre_joueur,player,Ptour, mat_avant, PAction, ia, num_tour);
                        player[0].coordonneX_av = player[0].coordonneX;
                        player[0].coordonneY_av = player[0].coordonneY;

                        num_tour++;
                    }

                    ///Tour de l'IA
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

                ///Victoire car joueur qui traverse le plateau
                if(gagner_ia(player, ia, num_tour) == 1)
                {
                    if(num_tour%2 == 1)
                    {
                        ///Joueur gagne
                        Color(15,0);
                        system("cls");
                        Affichage_Du_Titre(1,35);
                        Color(15,2);
                        gotoligcol(10,50);
                        printf("                                     ");
                        Color(15,0);
                        gotoligcol(nl+1,nc);
                        Color(15,2);
                        printf("           PARTIE TERMINEE           ");
                        Color(15,0);
                        gotoligcol(nl+2,nc);
                        Color(15,2);
                        printf("                                     ");
                        Color(15,0);
                        gotoligcol(nl+3,nc);
                        Color(15,10);
                        printf("                                     ");
                        Color(15,0);
                        gotoligcol(nl+4,nc);
                        Color(15,10);
                        printf("           Victoire de VOUS          ");
                        Color(15,0);
                        gotoligcol(nl+5,nc);
                        Color(15,10);
                        printf("                                     ");

                        Color(15,0);
                        gotoligcol(nl+6,nc);
                        player[0].scoreP += 5;
                        actualisation_score(player,0);
                        system("PAUSE");
                    }
                    else
                    {
                        Color(15,0);
                        system("cls");
                        Affichage_Du_Titre(1,35);
                        Color(15,2);
                        gotoligcol(nl,nc);
                        printf("                                     ");
                        Color(15,0);
                        gotoligcol(nl+1,nc);
                        Color(15,2);
                        printf("           PARTIE TERMINEE           ");
                        Color(15,0);
                        gotoligcol(nl+2,nc);
                        Color(15,2);
                        printf("                                     ");
                        Color(15,0);
                        gotoligcol(nl+3,nc);
                        Color(15,10);
                        printf("                                     ");
                        Color(15,0);
                        gotoligcol(nl+4,nc);
                        Color(15,10);
                        printf("          Victoire de l'IA           ");
                        Color(15,0);
                        gotoligcol(nl+5,nc);
                        Color(15,10);
                        printf("                                     ");

                        Color(15,0);
                        gotoligcol(nl+6,nc);
                        system("PAUSE");

                    }
                }

                ///Un joueur n'a plus de barrieres
                else if(gagner_ia(player, ia, num_tour) == 2)
                {
                    if(player[0].coordonneY == (16 - ia.coordonneY))
                    {
                        Color(15,0);
                        system("cls");
                        Affichage_Du_Titre(1,35);
                        Color(15,2);
                        gotoligcol(nl,nc);
                        printf("                                     ");
                        Color(15,0);
                        gotoligcol(nl+1,nc);
                        Color(15,2);
                        printf("           PARTIE TERMINEE           ");
                        Color(15,0);
                        gotoligcol(nl+2,nc);
                        Color(15,2);
                        printf("                                     ");
                        Color(15,0);
                        gotoligcol(nl+3,nc);
                        Color(15,10);
                        printf("                                     ");
                        Color(15,0);
                        gotoligcol(nl+4,nc);
                        Color(15,10);
                        printf("          Plus de barrieres          ");
                        Color(15,0);
                        gotoligcol(nl+5,nc);
                        Color(15,10);
                        printf("                                     ");

                        Color(15,0);
                        gotoligcol(nl+6,nc);
                        system("PAUSE");
                    }
                    else if(player[0].coordonneY > (16 - ia.coordonneY))
                    {
                        Color(15,0);
                        system("cls");
                        Affichage_Du_Titre(1,35);
                        Color(15,2);
                        gotoligcol(nl+0,nc);
                        printf("                                     ");
                        Color(15,0);
                        gotoligcol(nl+1,nc);
                        Color(15,2);
                        printf("           PARTIE TERMINEE           ");
                        Color(15,0);
                        gotoligcol(nl+2,nc);
                        Color(15,2);
                        printf("                                     ");
                        Color(15,0);
                        gotoligcol(nl+3,nc);
                        Color(15,10);
                        printf("                                     ");
                        Color(15,0);
                        gotoligcol(nl+4,nc);
                        Color(15,10);
                        printf("          Victoire de VOUS           ");
                        Color(15,0);
                        gotoligcol(nl+5,nc);
                        Color(15,10);
                        printf("                                     ");

                        Color(15,0);
                        gotoligcol(nl+6,nc);
                        player[0].scoreP += 5;
                        actualisation_score(player,0);
                        system("PAUSE");
                    }
                    else if(player[0].coordonneY < (16 - ia.coordonneY))
                    {
                        Color(15,0);
                        system("cls");
                        Affichage_Du_Titre(1,35);
                        Color(15,2);
                        gotoligcol(nl,nc);
                        printf("                                     ");
                        Color(15,0);
                        gotoligcol(nl+1,nc);
                        Color(15,2);
                        printf("           PARTIE TERMINEE           ");
                        Color(15,0);
                        gotoligcol(nl+2,nc);
                        Color(15,2);
                        printf("                                     ");
                        Color(15,0);
                        gotoligcol(nl+3,nc);
                        Color(15,10);
                        printf("                                     ");
                        Color(15,0);
                        gotoligcol(nl+4,nc);
                        Color(15,10);
                        printf("          Victoire de l'IA           ");
                        Color(15,0);
                        gotoligcol(nl+5,nc);
                        Color(15,10);
                        printf("                                     ");

                        Color(15,0);
                        gotoligcol(nl+6,nc);
                        system("PAUSE");
                    }
                }



            }

            else
            {

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////PARTIE CLASSIQUE ///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                ///Reset Point de la partie + booléen annulation

                for(int i=0; i<4; i++)
                {
                    player[i].scoreP = 0;
                    player[i].A_annule = 0;
                }


                ///Remplissage des donnees de la strcuture pour 4 J

                if(*Pnombre_joueur == 4)
                {
                    for(int i=0; i<4; i++)
                    {
                        Color(15,0);
                        system("cls");
                        Affichage_Du_Titre(1,35);
                        Color(15,2);
                        gotoligcol(10,47);
                        printf("                             ");
                        gotoligcol(11,47);
                        printf("         Saisie nom          ");
                        gotoligcol(12,47);
                        printf("                             ");
                        Color(15,10);
                        gotoligcol(13,47);
                        printf("                             ");
                        gotoligcol(14,47);
                        printf("          Joueur %d           ",i+1);
                        gotoligcol(15,47);
                        printf("    Saisissez votre nom :    ");
                        gotoligcol(16,47);
                        printf("                             ");
                        fflush(stdin);
                        gotoligcol(17,47);
                        scanf("%s",nom);
                        Color(15,0);
                        majuscule(nom);
                        strcpy(player[i].nomJ,nom);
                        player[i].numeroJ = i+1;

                        save_score(player,i);


                    }
                    choixPion(player,Pnombre_joueur);
                }



                ///Remplissage des donnees de la strcuture pour 2 J

                else
                {
                    for(int i=0; i<2; i++)
                    {
                        Color(15,0);//OK
                        system("cls");
                        Affichage_Du_Titre(1,35);
                        Color(15,2);
                        gotoligcol(10,47);
                        printf("                             ");
                        gotoligcol(11,47);
                        printf("         Saisie nom          ");
                        gotoligcol(12,47);
                        printf("                             ");
                        Color(15,10);
                        gotoligcol(13,47);
                        printf("                             ");
                        gotoligcol(14,47);
                        printf("          Joueur %d           ",i+1);
                        gotoligcol(15,47);
                        printf("    Saisissez votre nom :    ");
                        gotoligcol(16,47);
                        printf("                             ");
                        fflush(stdin);
                        gotoligcol(17,47);
                        scanf("%s",nom);
                        Color(15,0);
                        majuscule(nom);
                        strcpy(player[i].nomJ,nom);
                        player[i].numeroJ = i+1;

                        save_score(player,i);
                    }
                    choixPion(player,Pnombre_joueur);
                }


                debut = choix_j(*Pnombre_joueur); //SSPG pour déterminer qui commence
                system("cls");
                distribution_barriere(player,Pnombre_joueur);



                ///TRICHE(easter_eggs)
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
                        player[i].barrieresR = 1;
                    }
                    else if(strcmp(player[i].nomJ, "PIERRE")==0)
                    {
                        player[i].barrieresR += 5;
                    }
                }

                setup(Pnombre_joueur,debut,mat,player,Ptour,ia);

                tour_par_tour(Pnombre_joueur,mat,player,Ptour, mat_avant);


                ///Initialisation bonus
                case_bonus(mat);


                ///Debut Partie
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
                    menu_cote(Ptour,Pnombre_joueur,player);
                    player[*Ptour-1].coordonneX_av = player[*Ptour-1].coordonneX;
                    player[*Ptour-1].coordonneY_av = player[*Ptour-1].coordonneY;
                    menu_game(mat,Pnombre_joueur,player,Ptour, mat_avant,PAction, ia, num_tour);

                    ///Cas pour 2J
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

                    ///Cas pour 4J
                    else
                    {
                        if(*Ptour == 1)
                        {
                            tour_test = *Ptour-1;
                        }
                        else if(*Ptour == 2)
                        {
                            tour_test = *Ptour-1;
                        }

                        else if(*Ptour == 3)
                        {
                            tour_test = *Ptour-1;
                        }

                        else
                        {
                            tour_test = 3;
                        }
                    }



                    tour_par_tour(Pnombre_joueur,mat,player,Ptour, mat_avant);
                    sauver_plateau(mat_avant);

                }
                while(gagner(player,Pnombre_joueur,tour_test) == -1);


                ///Test fin de partie car joueur traversant le plateau
                if (gagner(player,Pnombre_joueur,tour_test) == 1)
                {
                    Color(15,0);
                    system("cls");
                    Affichage_Du_Titre(1,35);
                    Color(15,2);
                    gotoligcol(nl,nc);
                    printf("                                     ");
                    Color(15,0);
                    gotoligcol(nl+1,nc);
                    Color(15,2);
                    printf("           PARTIE TERMINEE           ");
                    Color(15,0);
                    gotoligcol(nl+2,nc);
                    Color(15,2);
                    printf("                                     ");
                    Color(15,0);
                    gotoligcol(nl+3,nc);
                    Color(15,10);
                    printf("                                     ");
                    Color(15,0);
                    gotoligcol(nl+4,nc);
                    Color(15,10);
                    printf("            Victoire de :            ");
                    Color(15,0);
                    gotoligcol(nl+5,nc);
                    Color(15,10);
                    printf("                                     ");
                    Color(15,0);
                    gotoligcol(nl+6,nc);
                    Color(15,10);
                    printf("                                     ");


                    Color(15,0);
                    gotoligcol(nl+6,nc);//+4
                    Color(15,10);
                    printf("            %s",player[tour_test].nomJ);
                    Color(15,0);
                    gotoligcol(nl+7,nc);
                    Color(15,10);
                    printf("                                     ");
                    Color(15,0);
                    gotoligcol(nl+8,nc);

                    player[tour_test].scoreP += 5;

                    for(int i=0; i<*Pnombre_joueur; i++)
                    {
                        actualisation_score(player,i);

                    }
                    system("PAUSE");
                }


                ///Test fin de partie car joueur n'a plus de barrieres

                else if(gagner(player,Pnombre_joueur,tour_test) == 2)
                {
                    system("cls");
                    matrice_propre(mat,player,ia);

                    Color(15,0);
                    gotoligcol(20,3);

                    Color(15,0);

                    //menu_cote(Ptour,Pnombre_joueur,player);



                    gotoligcol(nl,nc);
                    Color(15,2);
                    printf("                                           ");
                    Color(15,0);
                    gotoligcol(nl+1,nc);
                    Color(15,2);
                    printf("              PARTIE TERMINEE              ");
                    Color(15,0);
                    gotoligcol(nl+2,nc);
                    Color(15,2);
                    printf("                                           ");
                    Color(15,0);
                    gotoligcol(nl+3,nc);
                    Color(15,10);
                    printf("                                           ");
                    Color(15,0);
                    gotoligcol(nl+4,nc);//+4
                    Color(15,10);

                    printf("                                           ");

                    Color(15,0);
                    gotoligcol(nl+4,nc);//+4
                    Color(15,10);
                    printf("                  %s",player[tour_test].nomJ);

                    Color(15,0);
                    gotoligcol(nl+5,nc);//+5
                    Color(15,10);
                    printf("           n'a plus de barrieres           ");

                    Color(15,0);
                    gotoligcol(nl+6,nc);
                    Color(15,10);
                    printf("                                           ");
                    Color(15,0);
                    gotoligcol(nl+7,nc);
                    system("PAUSE");


                    ///Cas pour 2J
                    if(*Pnombre_joueur == 2)
                    {
                        ///Personne ne gagne
                        if(gagner_barriere(player, Pnombre_joueur) == -1)
                        {
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("         Les %d joueurs ont gagnes          ",*Pnombre_joueur);
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("        car ils sont autant avances        ");
                            Color(15,0);
                            gotoligcol(nl+9,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+10,nc);
                            system("PAUSE");

                            for(int i=0; i<*Pnombre_joueur; i++)
                            {
                                actualisation_score(player,i);  //Actualisation des scores
                            }
                        }

                        ///Le joueur le plus avance gagne
                        else
                        {
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);

                            printf("                  %s",player[gagner_barriere(player, Pnombre_joueur)].nomJ);
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("       gagne car ils est plus avance       ");
                            Color(15,0);
                            gotoligcol(nl+9,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+10,nc);

                            //printf("%s a gagne la partie car c'est le plus avance sur le plateau\n",player[gagner_barriere(player, Pnombre_joueur)].nomJ);
                            player[gagner_barriere(player, Pnombre_joueur)].scoreP ++;

                            player[tour_test].scoreP += 5;

                            for(int i=0; i<*Pnombre_joueur; i++)        //Actualisation des scores
                            {
                                actualisation_score(player,i);

                            }

                            system("PAUSE");

                        }

                    }
                    ///Cas pour 4J
                    else
                    {
                        ///Personne ne gagne
                        if(gagner_barriere(player, Pnombre_joueur) == -1)
                        {
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("         Les %d joueurs ont gagnes         ",*Pnombre_joueur);
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("        car ils sont autant avances        ");
                            Color(15,0);
                            gotoligcol(nl+9,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+10,nc);

                            for(int i=0; i<*Pnombre_joueur; i++)        //Actualisation des scores
                            {
                                actualisation_score(player,i);

                            }

                            system("PAUSE");
                        }

                        ///Les 3 joueurs les plus avances gagnent
                        else if(gagner_barriere(player, Pnombre_joueur) == 123)
                        {

                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("         3 joueurs ont gagnes              ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("            %s,%s et %s",player[0].nomJ,player[1].nomJ,player[2].nomJ);
                            Color(15,0);
                            gotoligcol(nl+9,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+10,nc);


                            player[0].scoreP += 5;
                            player[1].scoreP += 5;
                            player[2].scoreP += 5;

                            for(int i=0; i<*Pnombre_joueur; i++)    //Actualisation des scores
                            {
                                actualisation_score(player,i);
                            }

                            system("PAUSE");

                        }


                        else if(gagner_barriere(player, Pnombre_joueur) == 124)
                        {


                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("         3 joueurs ont gagnes              ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("            %s,%s et %s",player[0].nomJ,player[1].nomJ,player[3].nomJ);
                            Color(15,0);
                            gotoligcol(nl+9,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+10,nc);


                            player[0].scoreP += 5;
                            player[1].scoreP += 5;
                            player[3].scoreP += 5;

                            for(int i=0; i<*Pnombre_joueur; i++)    //Actualisation des scores
                            {
                                actualisation_score(player,i);
                            }

                            system("PAUSE");


                        }

                        else if(gagner_barriere(player, Pnombre_joueur) == 134)
                        {
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("         3 joueurs ont gagnes              ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("            %s,%s et %s",player[0].nomJ,player[1].nomJ,player[3].nomJ);
                            Color(15,0);
                            gotoligcol(nl+9,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+10,nc);

                            player[0].scoreP += 5;
                            player[2].scoreP += 5;
                            player[3].scoreP += 5;

                            for(int i=0; i<*Pnombre_joueur; i++)    //Actualisation des scores
                            {
                                actualisation_score(player,i);
                            }

                            system("PAUSE");

                        }

                        else if(gagner_barriere(player, Pnombre_joueur) == 234)
                        {
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("         3 joueurs ont gagnes              ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("            %s,%s et %s",player[1].nomJ,player[2].nomJ,player[3].nomJ);
                            Color(15,0);
                            gotoligcol(nl+9,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+10,nc);

                            player[1].scoreP += 5;
                            player[2].scoreP += 5;
                            player[3].scoreP += 5;

                            for(int i=0; i<*Pnombre_joueur; i++)    //Actualisation des scores
                            {
                                actualisation_score(player,i);
                            }

                            system("PAUSE");

                        }

                        ///Les 2 joueurs les plus avances gagnent
                        else if(gagner_barriere(player, Pnombre_joueur) == 12)
                        {
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("         2 joueurs ont gagnes              ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("             %s et %s",player[0].nomJ,player[1].nomJ);
                            Color(15,0);
                            gotoligcol(nl+9,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+10,nc);

                            player[0].scoreP += 5;
                            player[1].scoreP += 5;

                            for(int i=0; i<*Pnombre_joueur; i++)    //Actualisation des scores
                            {
                                actualisation_score(player,i);
                            }
                            system("PAUSE");

                        }

                        else if(gagner_barriere(player, Pnombre_joueur) == 23)
                        {
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("         2 joueurs ont gagnes              ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("             %s et %s",player[1].nomJ,player[2].nomJ);
                            Color(15,0);
                            gotoligcol(nl+9,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+10,nc);

                            player[1].scoreP += 5;
                            player[2].scoreP += 5;

                            for(int i=0; i<*Pnombre_joueur; i++)    //Actualisation des scores
                            {
                                actualisation_score(player,i);
                            }

                            system("PAUSE");

                        }

                        else if(gagner_barriere(player, Pnombre_joueur) == 34)
                        {
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("         2 joueurs ont gagnes              ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("             %s et %s",player[2].nomJ,player[3].nomJ);
                            Color(15,0);
                            gotoligcol(nl+9,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+10,nc);

                            player[2].scoreP += 5;
                            player[3].scoreP += 5;

                            for(int i=0; i<*Pnombre_joueur; i++)    //Actualisation des scores
                            {
                                actualisation_score(player,i);
                            }

                            system("PAUSE");

                        }

                        else if(gagner_barriere(player, Pnombre_joueur) == 14)
                        {
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("         2 joueurs ont gagnes              ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("             %s et %s",player[0].nomJ,player[3].nomJ);
                            Color(15,0);
                            gotoligcol(nl+9,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+9,nc);

                            player[0].scoreP += 5;
                            player[3].scoreP += 5;

                            for(int i=0; i<*Pnombre_joueur; i++)    //Actualisation des scores
                            {
                                actualisation_score(player,i);
                            }

                            system("PAUSE");

                        }

                        ///Le joueur le plus avance gagne
                        else if(gagner_barriere(player, Pnombre_joueur) == 1)
                        {
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("                  %s",player[0].nomJ);

                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("              a gagne !                    ");

                            Color(15,0);
                            gotoligcol(nl+9,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+10,nc);

                            player[0].scoreP += 5;

                            for(int i=0; i<*Pnombre_joueur; i++)    //Actualisation des scores
                            {
                                actualisation_score(player,i);
                            }

                            system("PAUSE");

                        }

                        else if(gagner_barriere(player, Pnombre_joueur) == 2)
                        {
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("                  %s",player[1].nomJ);

                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("              a gagne !                    ");

                            Color(15,0);
                            gotoligcol(nl+9,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+10,nc);

                            player[1].scoreP += 5;

                            for(int i=0; i<*Pnombre_joueur; i++)    //Actualisation des scores
                            {
                                actualisation_score(player,i);
                            }

                            system("PAUSE");

                        }

                        else if(gagner_barriere(player, Pnombre_joueur) == 3)
                        {
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("                  %s",player[2].nomJ);

                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("              a gagne !                    ");

                            Color(15,0);
                            gotoligcol(nl+9,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+10,nc);

                            player[2].scoreP += 5;

                            for(int i=0; i<*Pnombre_joueur; i++)    //Actualisation des scores
                            {
                                actualisation_score(player,i);
                            }

                            system("PAUSE");

                        }

                        else if(gagner_barriere(player, Pnombre_joueur) == 4)
                        {
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+7,nc);
                            Color(15,10);
                            printf("                  %s",player[3].nomJ);

                            Color(15,0);
                            gotoligcol(nl+8,nc);
                            Color(15,10);
                            printf("              a gagne !                    ");

                            Color(15,0);
                            gotoligcol(nl+9,nc);
                            Color(15,10);
                            printf("                                           ");
                            Color(15,0);
                            gotoligcol(nl+10,nc);

                            player[3].scoreP += 5;

                            for(int i=0; i<*Pnombre_joueur; i++)    //Actualisation des scores
                            {
                                actualisation_score(player,i);
                            }

                            system("PAUSE");

                        }
                    }

                }

            }

            break;
        }

///1.2 Charger Partie

        case 2:
        {
            ///Chargement des ressources dans les fichiers txt
            //printf("Chargement de la partie\n");
            charger_plateau(mat);
            charger_joueur(player, Pnombre_joueur);
            choixPion(player, Pnombre_joueur);

            ///Debut partie
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
                menu_cote(Ptour,Pnombre_joueur,player);
                player[*Ptour-1].coordonneX_av = player[*Ptour-1].coordonneX;
                player[*Ptour-1].coordonneY_av = player[*Ptour-1].coordonneY;
                menu_game(mat,Pnombre_joueur,player,Ptour, mat_avant, PAction, ia, num_tour);

                ///Cas pour 2Joueurs
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

                ///Cas pour 4Joueurs
                else
                {
                    if(*Ptour == 1)
                    {
                        tour_test = *Ptour-1;
                    }
                    else if(*Ptour == 2)
                    {
                        tour_test = *Ptour-1;
                    }

                    else if(*Ptour == 3)
                    {
                        tour_test = *Ptour-1;
                    }

                    else
                    {
                        tour_test = 3;
                    }
                }


                tour_par_tour(Pnombre_joueur,mat,player,Ptour, mat_avant);
                sauver_plateau(mat_avant);

            }
            while(gagner(player,Pnombre_joueur,tour_test) == -1);


            ///Test fin de partie car joueur traversant le plateau
            if (gagner(player,Pnombre_joueur,tour_test) == 1)
            {
                Color(15,0);
                system("cls");
                Affichage_Du_Titre(1,35);
                Color(15,2);
                gotoligcol(nl,nc);
                printf("                                     ");
                Color(15,0);
                gotoligcol(nl+1,nc);
                Color(15,2);
                printf("           PARTIE TERMINEE           ");
                Color(15,0);
                gotoligcol(nl+2,nc);
                Color(15,2);
                printf("                                     ");
                Color(15,0);
                gotoligcol(nl+3,nc);
                Color(15,10);
                printf("                                     ");
                Color(15,0);
                gotoligcol(nl+4,nc);
                Color(15,10);
                printf("            Victoire de :            ");
                Color(15,0);
                gotoligcol(nl+5,nc);
                Color(15,10);
                printf("                                     ");

                gotoligcol(nl+6,nc);//13
                Color(15,10);
                printf("                                     ");

                Color(15,0);
                Color(15,0);
                gotoligcol(nl+7,nc);//13
                Color(15,10);
                printf("            %s",player[tour_test].nomJ);
                Color(15,0);
                gotoligcol(nl+8,nc);
                Color(15,10);
                printf("                                     ");
                Color(15,0);
                gotoligcol(nl+9,nc);

                player[tour_test].scoreP += 5;

                for(int i=0; i<*Pnombre_joueur; i++)
                {
                    actualisation_score(player,i);

                }
                system("PAUSE");
            }



            else if(gagner(player,Pnombre_joueur,tour_test) == 2)
            {
                system("cls");
                matrice_propre(mat,player,ia);
                Color(15,0);
                gotoligcol(20,3);

                Color(15,0);

                menu_cote(Ptour,Pnombre_joueur,player);



                gotoligcol(nl,nc);
                Color(15,2);
                printf("                                           ");
                Color(15,0);
                gotoligcol(nl+1,nc);
                Color(15,2);
                printf("              PARTIE TERMINEE              ");
                Color(15,0);
                gotoligcol(nl+2,nc);
                Color(15,2);
                printf("                                           ");
                Color(15,0);
                gotoligcol(nl+3,nc);
                Color(15,10);
                printf("                                           ");
                Color(15,0);
                gotoligcol(nl+4,nc);//24
                Color(15,10);

                printf("                                           ");

                Color(15,0);
                gotoligcol(nl+4,nc);//24
                Color(15,10);
                printf("                  %s",player[tour_test].nomJ);

                Color(15,0);
                gotoligcol(nl+5,nc);
                Color(15,10);
                printf("           n'a plus de barrieres           ");


                Color(15,0);
                gotoligcol(nl+6,nc);
                Color(15,10);
                printf("                                           ");
                Color(15,0);

                ///Cas pour 2J
                if(*Pnombre_joueur == 2)
                {
                    ///Personne ne gagne
                    if(gagner_barriere(player, Pnombre_joueur) == -1)
                    {
                        Color(15,0);
                        gotoligcol(nl+7,nc);//A la suite
                        Color(15,10);
                        printf("         Les %d joueurs ont gagnes          ",*Pnombre_joueur);
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("        car ils sont autant avances        ");
                        Color(15,0);
                        gotoligcol(nl+9,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+10,nc);

                        for(int i=0; i<*Pnombre_joueur; i++)
                        {
                            actualisation_score(player,i);
                        }

                        system("PAUSE");
                    }

                    ///Le joueur le plus avance gagne
                    else
                    {
                        Color(15,0);
                        gotoligcol(nl+7,nc);//A la suite du dessus 27
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+7,nc);//27
                        Color(15,10);

                        printf("                  %s",player[gagner_barriere(player, Pnombre_joueur)].nomJ);
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("       gagne car ils est plus avance       ");
                        Color(15,0);
                        gotoligcol(nl+9,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+10,nc);
                        //printf("%s a gagne la partie car c'est le plus avance sur le plateau\n",player[gagner_barriere(player, Pnombre_joueur)].nomJ);
                        player[gagner_barriere(player, Pnombre_joueur)].scoreP ++;

                        player[tour_test].scoreP += 5;

                        for(int i=0; i<*Ptour; i++)
                        {
                            actualisation_score(player,i);
                        }
                        system("PAUSE");

                    }

                }

                ///Cas pour 4J
                else
                {
                    ///Personne ne gagne
                    if(gagner_barriere(player, Pnombre_joueur) == -1)
                    {
                        Color(15,0);
                        gotoligcol(nl+7,nc);//A la suite
                        Color(15,10);
                        printf("         Les %d joueurs ont gagnes         ",*Pnombre_joueur);
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("        car ils sont autant avances        ");
                        Color(15,0);
                        gotoligcol(nl+9,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+10,nc);

                        for(int i=0; i<*Ptour; i++)
                        {
                            actualisation_score(player,i);
                        }
                        system("PAUSE");
                    }

                    ///Les 3 joueurs les plus avances gagne
                    else if(gagner_barriere(player, Pnombre_joueur) == 123)
                    {
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("         3 joueurs ont gagnes              ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("            %s,%s et %s",player[0].nomJ,player[1].nomJ,player[2].nomJ);
                        Color(15,0);
                        gotoligcol(nl+9,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+10,nc);

                        player[0].scoreP += 5;
                        player[1].scoreP += 5;
                        player[2].scoreP += 5;

                        for(int i=0; i<*Ptour; i++)
                        {
                            actualisation_score(player,i);
                        }

                        system("PAUSE");
                    }


                    else if(gagner_barriere(player, Pnombre_joueur) == 124)
                    {
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("         3 joueurs ont gagnes              ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);//Meme qu'o desu
                        Color(15,10);
                        printf("            %s,%s et %s",player[0].nomJ,player[1].nomJ,player[3].nomJ);
                        Color(15,0);
                        gotoligcol(nl+9,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+10,nc);

                        player[0].scoreP += 5;
                        player[1].scoreP += 5;
                        player[3].scoreP += 5;

                        for(int i=0; i<*Ptour; i++)
                        {
                            actualisation_score(player,i);
                        }

                        system("PAUSE");

                    }

                    else if(gagner_barriere(player, Pnombre_joueur) == 134)
                    {
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("         3 joueurs ont gagnes              ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("            %s,%s et %s",player[0].nomJ,player[1].nomJ,player[3].nomJ);
                        Color(15,0);
                        gotoligcol(nl+9,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+10,nc);

                        player[0].scoreP += 5;
                        player[2].scoreP += 5;
                        player[3].scoreP += 5;

                        for(int i=0; i<*Ptour; i++)
                        {
                            actualisation_score(player,i);
                        }

                        system("PAUSE");

                    }

                    else if(gagner_barriere(player, Pnombre_joueur) == 234)
                    {
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("         3 joueurs ont gagnes              ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("            %s,%s et %s",player[1].nomJ,player[2].nomJ,player[3].nomJ);
                        Color(15,0);
                        gotoligcol(nl+9,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+10,nc);

                        player[1].scoreP += 5;
                        player[2].scoreP += 5;
                        player[3].scoreP += 5;

                        for(int i=0; i<*Ptour; i++)
                        {
                            actualisation_score(player,i);
                        }
                        system("PAUSE");

                    }

                    ///Les 2 joueurs les plus avances gagne
                    else if(gagner_barriere(player, Pnombre_joueur) == 12)
                    {
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("         2 joueurs ont gagnes              ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("             %s et %s",player[0].nomJ,player[1].nomJ);
                        Color(15,0);
                        gotoligcol(nl+9,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+10,nc);

                        player[0].scoreP += 5;
                        player[1].scoreP += 5;

                        for(int i=0; i<*Ptour; i++)
                        {
                            actualisation_score(player,i);
                        }
                        system("PAUSE");

                    }

                    else if(gagner_barriere(player, Pnombre_joueur) == 23)
                    {
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("         2 joueurs ont gagnes              ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("             %s et %s",player[1].nomJ,player[2].nomJ);
                        Color(15,0);
                        gotoligcol(nl+9,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+10,nc);

                        player[1].scoreP += 5;
                        player[2].scoreP += 5;

                        for(int i=0; i<*Ptour; i++)
                        {
                            actualisation_score(player,i);
                        }
                        system("PAUSE");


                    }

                    else if(gagner_barriere(player, Pnombre_joueur) == 34)
                    {
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("         2 joueurs ont gagnes              ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("             %s et %s",player[2].nomJ,player[3].nomJ);
                        Color(15,0);
                        gotoligcol(nl+9,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+10,nc);

                        player[2].scoreP += 5;
                        player[3].scoreP += 5;

                        for(int i=0; i<*Ptour; i++)
                        {
                            actualisation_score(player,i);
                        }
                        system("PAUSE");

                    }

                    else if(gagner_barriere(player, Pnombre_joueur) == 14)
                    {
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("         2 joueurs ont gagnes              ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("             %s et %s",player[0].nomJ,player[3].nomJ);
                        Color(15,0);
                        gotoligcol(nl+9,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+10,nc);

                        player[0].scoreP += 5;
                        player[3].scoreP += 5;

                        for(int i=0; i<*Ptour; i++)
                        {
                            actualisation_score(player,i);
                        }
                        system("PAUSE");

                    }

                    ///Le joueur le plus avance gagne
                    else if(gagner_barriere(player, Pnombre_joueur) == 1)
                    {
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("                  %s",player[0].nomJ);

                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("              a gagne !                    ");

                        Color(15,0);
                        gotoligcol(nl+9,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+10,nc);

                        player[0].scoreP += 5;

                        for(int i=0; i<*Ptour; i++)
                        {
                            actualisation_score(player,i);
                        }
                        system("PAUSE");

                    }

                    else if(gagner_barriere(player, Pnombre_joueur) == 2)
                    {
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("                  %s",player[1].nomJ);

                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("              a gagne !                    ");

                        Color(15,0);
                        gotoligcol(nl+9,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+10,nc);

                        player[1].scoreP += 5;

                        for(int i=0; i<*Ptour; i++)
                        {
                            actualisation_score(player,i);
                        }
                        system("PAUSE");

                    }

                    else if(gagner_barriere(player, Pnombre_joueur) == 3)
                    {
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("                  %s",player[2].nomJ);

                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("              a gagne !                    ");

                        Color(15,0);
                        gotoligcol(nl+9,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+10,nc);

                        player[2].scoreP += 5;

                        for(int i=0; i<*Ptour; i++)
                        {
                            actualisation_score(player,i);
                        }
                        system("PAUSE");

                    }

                    else if(gagner_barriere(player, Pnombre_joueur) == 4)
                    {
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+7,nc);
                        Color(15,10);
                        printf("                  %s",player[3].nomJ);

                        Color(15,0);
                        gotoligcol(nl+8,nc);
                        Color(15,10);
                        printf("              a gagne !                    ");

                        Color(15,0);
                        gotoligcol(nl+9,nc);
                        Color(15,10);
                        printf("                                           ");
                        Color(15,0);
                        gotoligcol(nl+10,nc);

                        player[3].scoreP += 5;

                        for(int i=0; i<*Ptour; i++)
                        {
                            actualisation_score(player,i);
                        }
                        system("PAUSE");

                    }

                }

            }

            break;
        }

///1.3 Affichage des regles

        case 3:
        {
            system("cls");
            affiregles();
            break;
        }

///1.4 Affichage du tableau des scores

        case 4:
        {
            t_joueur playeraffichage[150];  //Definition localement d'un tableau de structure permettant l'affichage

            system("cls");

            tableau_score(playeraffichage);
            break;
        }

///1.5 Quitter Partie

        case 5:
        {
            ///Sauvegarde de la partie
            sauver_plateau(mat);
            sauver_joueur(player, Pnombre_joueur);

            ///Sortie du jeu
            sortie = -1;
            Color(15,0);
            system("cls");
            gotoligcol(10,50);
            Color(15,2);
            printf("                                 ");
            Color(15,0);
            gotoligcol(11,50);
            Color(15,2);
            printf("           DECONNEXION           ");
            Color(15,0);
            gotoligcol(12,50);
            Color(15,2);
            printf("                                 ");
            Color(15,0);
            gotoligcol(13,50);
            Color(15,10);
            printf("                                 ");
            Color(15,0);
            gotoligcol(14,50);
            Color(15,10);
            printf("            AUREVOIR             ");
            Color(15,0);
            gotoligcol(15,50);
            Color(15,10);
            printf("                                 ");
            Color(15,0);
            gotoligcol(30,50);

            ExitProcess(0); //Permet la sortie du process et l'interruption de l'ensemble des SPPG en cours
            break;
        }

        default:    //Cas de mauvaise saisie
        {
            Color(15,0);
            system("cls");
            gotoligcol(10,50);
            Color(15,2);
            printf("                                 ");
            Color(15,0);
            gotoligcol(11,50);
            Color(15,2);
            printf("             ERREUR              ");
            Color(15,0);
            gotoligcol(12,50);
            Color(15,2);
            printf("                                 ");
            Color(15,0);
            gotoligcol(13,50);
            Color(15,10);
            printf("                                 ");
            Color(15,0);
            gotoligcol(14,50);
            Color(15,10);
            printf("             SAISIE              ");
            Color(15,0);
            gotoligcol(15,50);
            Color(15,10);
            printf("                                 ");
            Color(15,0);
            gotoligcol(30,50);
            system("PAUSE");
            break;
        }
        }

    }
    while(sortie!=-1);

}





