/*R�gles
- Un pion se deplace dans les quatres directions (haut, bas, gauche, droite)
- Un pion ne peut pas passer au dessus d'une barri�re
- Si 2 joueurs, alors un pion peut sauter au dessus d'un autre seulement si il
n'y a pas de barriere entre lui et l'autre pion. Le pion saute dans la case qui
est dans la meme ligne. Si il y a une barriere entre l'autre pion et la case
d'atterissage alors il ira a droite ou a gauche.
- Si 4 joueurs, alors pas de sauts autorises.
*/

#include "Header_Pierre.h"

///Sous programme qui verifie si la saisie est conforme à l'entree saisie en parametre
int validation_choix(char chx, char choix1, char choix2)
{
    ///0. DDV
    int valid_chx = 1; //Booleen

    if((chx==choix1)||(chx==choix2))
    {
        valid_chx=0;
    }

    if(valid_chx==1) return 1;
    else
        return 0;
}


void deplacement(int dep[3], int matrice[17][17], int* Pnombre_joueur,int*Ptour,t_joueur player[4], t_IA ia)
{
    /// 0. DDV
    char choix;
    char choix_decalage = 'x';
    int choix_int;
    int valid_choix = 1;
    int valid_dep = 1;
    int numero_ligne=20;
    int numero_colonne=3;

    ///1. Affichage utilisateur
    while(valid_dep == 1)
    {
        ///1.1. Saisie direction deplacement
        while(valid_choix == 1)
        {
            system("cls");
            matrice_propre(matrice,player, ia);
            menu_cote(Ptour,Pnombre_joueur,player);

            gotoligcol(numero_ligne,numero_colonne);
            Color(15,2);
            printf("                                           ");
            Color(15,0);
            gotoligcol(numero_ligne+1,numero_colonne);
            Color(15,2);
            printf("                DEPLACEMENT                ");
            Color(15,0);
            gotoligcol(numero_ligne+2,numero_colonne);
            Color(15,2);
            printf("                                           ");
            Color(15,0);
            gotoligcol(numero_ligne+3,numero_colonne);
            Color(15,10);
            printf("                                           ");
            Color(15,0);
            gotoligcol(numero_ligne+4,numero_colonne);
            Color(15,10);
            printf("   Deplacez votre pion avec les fleches    ");
            Color(15,0);
            gotoligcol(numero_ligne+5,numero_colonne);
            Color(15,10);
            printf("                                           ");
            Color(15,0);
            gotoligcol(numero_ligne+6,numero_colonne);

            choix_int = getch();
            if(choix_int == 0x48){
                choix = 'h';
            }
            else if(choix_int == 0x50){
                choix = 'b';
            }
            else if(choix_int == 0x4B){
                choix = 'g';
            }
            else if(choix_int == 0x4D){
                choix = 'd';
            }

            if((choix=='h')||(choix=='b')||(choix=='g')||(choix=='d')||(choix=='H')||(choix=='B')||(choix=='G')||(choix=='D'))
            {
                valid_choix = 0;
            }
        }

        ///2.1. Debut Deplacement a 4 joueurs
        if(*Pnombre_joueur==4)
        {
            ///2.1.1. En haut
            //On verifie que la case est libre (ou bonus) et qu'il n'y a pas de barriere sur le chemin
            if(((choix=='h')||(choix=='H'))&&(dep[1]!=0)&&(matrice[dep[1]-1][dep[0]]==1)&&((matrice[dep[1]-2][dep[0]]==0)||(matrice[dep[1]-2][dep[0]]==4)))
            {
                if(matrice[dep[1]-1][dep[0]]==4)
                {
                    player[*Ptour-1].scoreP ++;
                }
                dep[1] -= 2;
                valid_dep = 0;
            }

            ///2.1.2. En bas
            //On verifie que la case est libre (ou bonus) et qu'il n'y a pas de barriere sur le chemin
            else if(((choix=='b')||(choix=='B'))&&(dep[1]!=16)&&(matrice[dep[1]+1][dep[0]]==1)&&((matrice[dep[1]+2][dep[0]]==0)||(matrice[dep[1]+2][dep[0]]==4)))
            {
                if(matrice[dep[1]+2][dep[0]]==4)
                {
                    player[*Ptour-1].scoreP ++;
                }
                dep[1] +=2;
                valid_dep = 0;
            }

            ///2.1.3. A gauche
            //On verifie que la case est libre (ou bonus) et qu'il n'y a pas de barriere sur le chemin
            else if(((choix=='g')||(choix=='G'))&&(dep[0]!=0)&&(matrice[dep[1]][dep[0]-1]==1)&&((matrice[dep[1]][dep[0]-2]==0)||(matrice[dep[1]][dep[0]-2]==4)))
            {
                if(matrice[dep[1]][dep[0]-2]==4)
                {
                    player[*Ptour-1].scoreP ++;
                }
                dep[0]-=2;
                valid_dep = 0;
            }

            ///2.1.4. A droite
            //On verifie que la case est libre (ou bonus) et qu'il n'y a pas de barriere sur le chemin
            else if(((choix=='d')||(choix=='D'))&&(dep[0]!=16)&&(matrice[dep[1]][dep[0]+1]==1)&&((matrice[dep[1]][dep[0]+2]==0)||(matrice[dep[1]][dep[0]+2]==4)))
            {

                if(matrice[dep[1]][dep[0]+2]==4)
                {
                    player[*Ptour-1].scoreP ++;
                }
                dep[0]+=2;
                valid_dep = 0;
            }

            ///2.1.5. Deplacement non valide (on demande un autre choix)
            else
            {

                Color(15,0);
                gotoligcol(numero_ligne+7,numero_colonne);
                Color(15,10);
                printf("  Deplacement impossible  ");
                Color(15,0);
                gotoligcol(numero_ligne+8,numero_colonne);
                system("PAUSE");
                valid_choix = 1;
            }
        }

        ///3. Deplacement a 2 joueurs
        else
        {
            ///3.1. Deplacment en haut
            //On verfifie qu'il n'y a pas de barriere sur le chemin
            if(((choix=='h')||(choix=='H'))&&(dep[1]!=0)&&((matrice[dep[1]-1][dep[0]])!=2)&&((matrice[dep[1]-1][dep[0]])!=3))
            {
                //On verifie que la case est libre (ou bonus)
                if((matrice[dep[1]-2][dep[0]]==0)||(matrice[dep[1]-2][dep[0]]==4))
                {
                    if(matrice[dep[1]-2][dep[0]]==4)
                    {
                        player[*Ptour-1].scoreP ++;
                    }
                    dep[1] -= 2;
                    valid_dep = 0;
                }
                //Si notre deplacement nous fait sortir du plateau alors le booleen passe a false et on affcihera deplacement impossible
                else if(dep[1]==2)
                {
                    valid_dep = 1;
                    valid_choix = 1;
                    Color(15,0);
                    gotoligcol(numero_ligne+7,numero_colonne);
                    Color(15,10);
                    printf("  Impossible de sortir du plateau  ");
                    Color(15,0);
                    gotoligcol(numero_ligne+8,numero_colonne);
                    system("PAUSE");
                }
                //Si un joueur se trouve sur la case d'arrivee, on verfie que la suivante et libre et qu'il n'y a pas de barriere pour sauter
                else if((valid_dep == 1)&&((matrice[dep[1]-4][dep[0]]==0)||(matrice[dep[1]-4][dep[0]]==4))&&((matrice[dep[1]-3][dep[0]])!=2)&&((matrice[dep[1]-3][dep[0]])!=3))
                {
                    if(matrice[dep[1]-4][dep[0]]==4)
                    {
                        player[*Ptour-1].scoreP ++;
                    }
                    dep[1] -= 4;
                    valid_dep = 0;
                }
                //Sinon on est dans le cas ou on va saute par dessus un joueur puis faire un decalage
                else
                {
                    if((matrice[dep[1]-3][dep[0]]==2)||(matrice[dep[1]-3][dep[0]]==3))
                    {
                        //On demande a l'utilisateur le decalage qu'il veux faire
                        while(validation_choix(choix_decalage, 'g', 'd')==1)
                        {
                            system("cls");
                            matrice_propre(matrice,player, ia);
                            menu_cote(Ptour,Pnombre_joueur,player);

                            Color(15,0);
                            gotoligcol(numero_ligne+7,numero_colonne);
                            Color(15,10);
                            printf("       Vous ne pouvez pas sauter le deuxieme mur       ");
                            Color(15,0);
                            gotoligcol(numero_ligne+8,numero_colonne);
                            Color(15,10);
                            printf("  Souhaitez vous aller a gauche (g) ou a droite (d) ?  ");
                            Color(15,0);
                            gotoligcol(numero_ligne+9,numero_colonne);

                            //printf("Vous ne pouvez pas sauter le deuxieme mur,\nSouhaitez vous aller a gauche (g) ou a droite (d) ?\n");
                            scanf("%c", &choix_decalage);
                        }
                        if((choix_decalage == 'd')&&(dep[0]!=16))
                        {
                            //Si le decalage est impossible alors on fait celui de l'autre cote
                            if((matrice[dep[1]-2][dep[0]+1]==2)||(matrice[dep[1]-2][dep[0]+1]==3))
                            {
                                if(matrice[dep[1]-2][dep[0]-2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }

                                Color(15,0);
                                gotoligcol(numero_ligne+7,numero_colonne);
                                Color(15,10);
                                printf("       Vous etes face à une barriere       ");
                                Color(15,0);
                                gotoligcol(numero_ligne+8,numero_colonne);
                                Color(15,10);
                                printf("       Votre pion se decale a gauche       ");
                                Color(15,0);
                                gotoligcol(numero_ligne+9,numero_colonne);

                                //printf("Vous etes face a une barriere\nVotre pion va faire un decalage a gauche\n");
                                dep[0]-=2;
                                dep[1]-=2;
                                valid_dep = 0;

                            }
                            //Sinon on applique le decalage voulu
                            else
                            {
                                if(matrice[dep[1]-2][dep[0]+2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }
                                dep[0]+=2;
                                dep[1]-=2;
                                valid_dep = 0;
                            }
                        }
                        else if(dep[0]!=0)
                        {
                            //Si le decalage est impossible alors on fait celui de l'autre cote
                            if((matrice[dep[1]-2][dep[0]-1]==2)||(matrice[dep[1]-2][dep[0]-1]==3))
                            {
                                if(matrice[dep[1]-2][dep[0]+2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }

                                Color(15,0);
                                gotoligcol(numero_ligne+7,numero_colonne);
                                Color(15,10);
                                printf("       Vous etes face à une barriere       ");
                                Color(15,0);
                                gotoligcol(numero_ligne+8,numero_colonne);
                                Color(15,10);
                                printf("       Votre pion se decale a droite       ");
                                Color(15,0);
                                gotoligcol(numero_ligne+9,numero_colonne);
                                dep[0]+=2;
                                dep[1]-=2;
                                valid_dep = 0;
                            }
                            //Sinon on applique le decalage voulu
                            else
                            {
                                if(matrice[dep[1]-2][dep[0]-2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }
                                dep[0]-=2;
                                dep[1]-=2;
                                valid_dep = 0;
                            }
                        }
                        else{
                            valid_dep = 1;
                        }
                    }
                }
            }

            ///3.2. Deplacment en bas
            //On verfifie qu'il n'y a pas de barriere sur le chemin
            else if(((choix=='b')||(choix=='B'))&&(dep[1]!=16)&&((matrice[dep[1]+1][dep[0]])!=2)&&((matrice[dep[1]+1][dep[0]])!=3))
            {
                //On verifie que la case est libre (ou bonus)
                if((matrice[dep[1]+2][dep[0]]==0)||(matrice[dep[1]+2][dep[0]]==4))
                {
                    if(matrice[dep[1]+2][dep[0]]==4)
                    {
                        player[*Ptour-1].scoreP ++;
                    }
                    dep[1] += 2;
                    valid_dep = 0;
                }
                //Si notre deplacement nous fait sortir du plateau alors le booleen passe a false et on affcihera deplacement impossible
                else if(dep[1]==14)
                {
                    valid_dep = 1;
                    valid_choix = 1;

                    Color(15,0);
                    gotoligcol(numero_ligne+7,numero_colonne);
                    Color(15,10);
                    printf("       Impossible de sortir du plateau       ");
                    Color(15,0);
                    gotoligcol(numero_ligne+8,numero_colonne);
                    system("PAUSE");
                }
                //Si un joueur se trouve sur la case d'arrivee, on verfie que la suivante et libre et qu'il n'y a pas de barriere pour sauter
                else if((valid_dep == 1)&&((matrice[dep[1]+4][dep[0]]==0)||(matrice[dep[1]+4][dep[0]]==4))&&((matrice[dep[1]+3][dep[0]])!=2)&&((matrice[dep[1]+3][dep[0]])!=3))
                {
                    if(matrice[dep[1]+4][dep[0]]==4)
                    {
                        player[*Ptour-1].scoreP ++;
                    }
                    dep[1] += 4;
                    valid_dep = 0;
                }
                //Sinon on est dans le cas ou on va saute par dessus un joueur puis faire un decalage
                else
                {
                    if((matrice[dep[1]+3][dep[0]]==2)||(matrice[dep[1]+3][dep[0]]==3))
                    {
                        //On demande a l'utilisateur le decalage qu'il veux faire
                        while(validation_choix(choix_decalage, 'g', 'd')==1)
                        {
                            system("cls");
                            matrice_propre(matrice,player, ia);
                            menu_cote(Ptour,Pnombre_joueur,player);


                            Color(15,0);
                            gotoligcol(numero_ligne+7,numero_colonne);
                            Color(15,10);
                            printf("       Vous ne pouvez pas sauter le deuxieme mur       ");
                            Color(15,0);
                            gotoligcol(numero_ligne+8,numero_colonne);
                            Color(15,10);
                            printf("  Souhaitez vous aller a gauche (g) ou a droite (d) ?  ");
                            Color(15,0);
                            gotoligcol(numero_ligne+9,numero_colonne);


                            scanf("%c", &choix_decalage);
                        }
                        if((choix_decalage == 'd')&&(dep[0]!=16))
                        {
                            //Si le decalage est impossible alors on fait celui de l'autre cote
                            if(((matrice[dep[1]+2][dep[0]+1]==2)||(matrice[dep[1]+2][dep[0]+1]==3))&&(dep[0]!=0))
                            {
                                if(matrice[dep[1]+2][dep[0]-2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }

                                Color(15,0);
                                gotoligcol(numero_ligne+7,numero_colonne);
                                Color(15,10);
                                printf("       Vous etes face à une barriere       ");
                                Color(15,0);
                                gotoligcol(numero_ligne+8,numero_colonne);
                                Color(15,10);
                                printf("       Votre pion se decale a gauche       ");
                                Color(15,0);
                                gotoligcol(numero_ligne+9,numero_colonne);

                                dep[0]-=2;
                                dep[1]+=2;
                                valid_dep = 0;
                            }
                            //Sinon on applique le decalage voulu
                            else
                            {
                                if(matrice[dep[1]+2][dep[0]+2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }
                                dep[0]+=2;
                                dep[1]+=2;
                                valid_dep = 0;
                            }
                        }
                        else if(dep[0]!=0)
                        {
                            //Si le decalage est impossible alors on fait celui de l'autre cote
                            if(((matrice[dep[1]+2][dep[0]-1]==2)||(matrice[dep[1]+2][dep[0]-1]==3))&&(dep[0]!=16))
                            {
                                if(matrice[dep[1]+2][dep[0]+2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }
                                Color(15,0);
                                gotoligcol(numero_ligne+7,numero_colonne);
                                Color(15,10);
                                printf("       Vous etes face à une barriere       ");
                                Color(15,0);
                                gotoligcol(numero_ligne+8,numero_colonne);
                                Color(15,10);
                                printf("       Votre pion se decale a droite       ");
                                Color(15,0);
                                gotoligcol(numero_ligne+9,numero_colonne);
                                dep[0]+=2;
                                dep[1]+=2;
                                valid_dep = 0;
                            }
                            //Sinon on applique le decalage voulu
                            else
                            {
                                if(matrice[dep[1]+2][dep[0]-2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }
                                dep[0]-=2;
                                dep[1]+=2;
                                valid_dep = 0;
                            }
                        }
                        else{
                            valid_dep = 1;
                        }
                    }
                }
            }

            ///3.3. Deplacment a gauche
            //On verfifie qu'il n'y a pas de barriere sur le chemin
            else if(((choix=='g')||(choix=='G'))&&(dep[0]!=0)&&((matrice[dep[1]][dep[0]-1])!=2)&&((matrice[dep[1]][dep[0]-1])!=3))
            {
                //On verifie que la case est libre (ou bonus)
                if((matrice[dep[1]][dep[0]-2]==0)||(matrice[dep[1]][dep[0]-2]==4))
                {
                    if(matrice[dep[1]][dep[0]-2]==4)
                    {
                        player[*Ptour-1].scoreP ++;
                    }
                    dep[0] -= 2;
                    valid_dep = 0;
                }
                //Si notre deplacement nous fait sortir du plateau alors le booleen passe a false et on affcihera deplacement impossible
                else if(dep[0]==2)
                {
                    valid_dep = 1;
                    valid_choix = 1;
                    Color(15,0);
                    gotoligcol(numero_ligne+7,numero_colonne);
                    Color(15,10);
                    printf("       Impossible de sortir du plateau       ");
                    Color(15,0);
                    gotoligcol(numero_ligne+8,numero_colonne);
                    system("PAUSE");
                }
                //Si un joueur se trouve sur la case d'arrivee, on verfie que la suivante et libre et qu'il n'y a pas de barriere pour sauter
                else if((valid_dep == 1)&&((matrice[dep[1]][dep[0]-4]==0)||(matrice[dep[1]][dep[0]-4]==4))&&((matrice[dep[1]][dep[0]-3])!=2)&&((matrice[dep[1]][dep[0]-3])!=3))
                {
                    if(matrice[dep[1]][dep[0]-4]==4)
                    {
                        player[*Ptour-1].scoreP ++;
                    }
                    dep[0] -= 4;
                    valid_dep = 0;
                }
                //Sinon on est dans le cas ou on va saute par dessus un joueur puis faire un decalage
                else
                {
                    if((matrice[dep[1]][dep[0]-3]==2)||(matrice[dep[1]][dep[0]-3]==3))
                    {
                        //On demande a l'utilisateur le decalage qu'il veux faire
                        while(validation_choix(choix_decalage, 'h', 'b')==1)
                        {
                            system("cls");
                            matrice_propre(matrice,player,ia);
                            menu_cote(Ptour,Pnombre_joueur,player);

                            Color(15,0);
                            gotoligcol(numero_ligne+7,numero_colonne);
                            Color(15,10);
                            printf("       Vous ne pouvez pas sauter le deuxieme mur       ");
                            Color(15,0);
                            gotoligcol(numero_ligne+8,numero_colonne);
                            Color(15,10);
                            printf("  Souhaitez vous aller en haut (h) ou en bas (b) ?  ");
                            Color(15,0);
                            gotoligcol(numero_ligne+9,numero_colonne);

                            //printf("Vous ne pouvez pas sauter le deuxieme mur,\nSouhaitez vous aller en haut (h) ou en bas (b) ?\n");
                            scanf("%c", &choix_decalage);
                        }
                        if((choix_decalage == 'b')&&(dep[1]!=16))
                        {
                            //Si le decalage est impossible alors on fait celui de l'autre cote
                            if((matrice[dep[1]+1][dep[0]-2]==2)||(matrice[dep[1]+1][dep[0]-2]==3))
                            {
                                if(matrice[dep[1]-2][dep[0]-2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }

                                Color(15,0);
                                gotoligcol(numero_ligne+7,numero_colonne);
                                Color(15,10);
                                printf("       Vous etes face à une barriere       ");
                                Color(15,0);
                                gotoligcol(numero_ligne+8,numero_colonne);
                                Color(15,10);
                                printf("        Votre pion se decale en haut        ");
                                Color(15,0);
                                gotoligcol(numero_ligne+9,numero_colonne);

                                //printf("Vous etes face a une barriere\nVotre piont va faire un decalage en haut\n");
                                dep[0]-=2;
                                dep[1]-=2;
                                valid_dep = 0;
                            }
                            //Sinon on applique le decalage voulu
                            else
                            {
                                if(matrice[dep[1]+2][dep[0]-2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }
                                dep[0]-=2;
                                dep[1]+=2;
                                valid_dep = 0;
                            }
                        }
                        else if(dep[1]!=0)
                        {
                            //Si le decalage est impossible alors on fait celui de l'autre cote
                            if((matrice[dep[1]-1][dep[0]-2]==2)||(matrice[dep[1]-1][dep[0]-2]==3))
                            {
                                if(matrice[dep[1]+2][dep[0]-2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }

                                Color(15,0);
                                gotoligcol(numero_ligne+7,numero_colonne);
                                Color(15,10);
                                printf("       Vous etes face à une barriere       ");
                                Color(15,0);
                                gotoligcol(numero_ligne+8,numero_colonne);
                                Color(15,10);
                                printf("       Votre pion se decale en bas       ");
                                Color(15,0);
                                gotoligcol(numero_ligne+9,numero_colonne);

                                //printf("Vous etes face a une barriere\nVotre piont va faire un decalage en bas\n");
                                dep[0]-=2;
                                dep[1]+=2;
                                valid_dep = 0;
                            }
                            //Sinon on applique le decalage voulu
                            else
                            {
                                if(matrice[dep[1]-2][dep[0]-2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }
                                dep[0]-=2;
                                dep[1]-=2;
                                valid_dep = 0;
                            }
                        }
                        else{
                            valid_dep = 1;
                        }
                    }
                }
            }

            ///3.4. Deplacment a droite
            //On verfifie qu'il n'y a pas de barriere sur le chemin
            else if(((choix=='d')||(choix=='D'))&&(dep[0]!=16)&&((matrice[dep[1]][dep[0]+1])!=2)&&((matrice[dep[1]][dep[0]+1])!=3))
            {
                //On verifie que la case est libre (ou bonus)
                if((matrice[dep[1]][dep[0]+2]==0)||(matrice[dep[1]][dep[0]+2]==4))
                {
                    if(matrice[dep[1]][dep[0]+2]==4)
                    {
                        player[*Ptour-1].scoreP ++;
                    }
                    dep[0] += 2;
                    valid_dep = 0;
                }
                //Si notre deplacement nous fait sortir du plateau alors le booleen passe a false et on affcihera deplacement impossible
                else if(dep[0]==14)
                {
                    valid_dep = 1;
                    valid_choix = 1;
                    Color(15,0);
                    gotoligcol(numero_ligne+7,numero_colonne);
                    Color(15,10);
                    printf("       Impossible de sortir du plateau       ");
                    Color(15,0);
                    gotoligcol(numero_ligne+8,numero_colonne);
                    system("PAUSE");
                }
                //Si un joueur se trouve sur la case d'arrivee, on verfie que la suivante et libre et qu'il n'y a pas de barriere pour sauter
                else if((valid_dep == 1)&&((matrice[dep[1]][dep[0]+4]==0)||(matrice[dep[1]][dep[0]+4]==4))&&(matrice[dep[1]][dep[0]+4]==4)&&((matrice[dep[1]][dep[0]+3])!=2)&&((matrice[dep[1]][dep[0]+3])!=3))
                {
                    if(matrice[dep[1]][dep[0]+4]==4)
                    {
                        player[*Ptour-1].scoreP ++;
                    }
                    dep[0] += 4;
                    valid_dep = 0;
                }
                //Sinon on est dans le cas ou on va saute par dessus un joueur puis faire un decalage
                else
                {
                    if((matrice[dep[1]][dep[0]+3]==2)||(matrice[dep[1]][dep[0]+3]==3))
                    {
                        //On demande a l'utilisateur le decalage qu'il veux faire
                        while(validation_choix(choix_decalage, 'h', 'b')==1)
                        {
                            Color(15,0);
                            system("cls");
                            matrice_propre(matrice,player,ia);
                            menu_cote(Ptour,Pnombre_joueur,player);

                            Color(15,0);
                            gotoligcol(numero_ligne+7,numero_colonne);
                            Color(15,10);
                            printf("       Vous ne pouvez pas sauter le deuxieme mur       ");
                            Color(15,0);
                            gotoligcol(numero_ligne+8,numero_colonne);
                            Color(15,10);
                            printf("  Souhaitez vous aller en haut (h) ou en bas (b) ?  ");
                            Color(15,0);
                            gotoligcol(numero_ligne+9,numero_colonne);

                            //printf("Vous ne pouvez pas sauter le deuxieme mur,\nSouhaitez vous aller en haut (h) ou en bas (b) ?\n");

                            scanf("%c", &choix_decalage);
                        }
                        if((choix_decalage == 'b')&&(dep[1]!=16))
                        {
                            //Si le decalage est impossible alors on fait celui de l'autre cote
                            if(((matrice[dep[1]+1][dep[0]+2]==2)||(matrice[dep[1]+1][dep[0]+2]==3))&&(dep[1]!=0))
                            {
                                if(matrice[dep[1]-2][dep[0]+2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }

                                Color(15,0);
                                gotoligcol(numero_ligne+7,numero_colonne);
                                Color(15,10);
                                printf("       Vous etes face à une barriere       ");
                                Color(15,0);
                                gotoligcol(numero_ligne+8,numero_colonne);
                                Color(15,10);
                                printf("        Votre pion se decale en haut        ");
                                Color(15,0);
                                gotoligcol(numero_ligne+9,numero_colonne);

                                dep[0]+=2;
                                dep[1]-=2;
                                valid_dep = 0;
                            }
                            //Sinon on applique le decalage voulu
                            else
                            {
                                if(matrice[dep[1]+2][dep[0]+2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }
                                dep[0]+=2;
                                dep[1]+=2;
                                valid_dep = 0;
                            }
                        }
                        else if(dep[1]!=0)
                        {
                            //Si le decalage est impossible alors on fait celui de l'autre cote
                            if((matrice[dep[1]-1][dep[0]+2]==2)||(matrice[dep[1]-1][dep[0]+2]==3))
                            {
                                if(matrice[dep[1]+2][dep[0]+2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }

                                Color(15,0);
                                gotoligcol(numero_ligne+7,numero_colonne);
                                Color(15,10);
                                printf("       Vous etes face à une barriere       ");
                                Color(15,0);
                                gotoligcol(numero_ligne+8,numero_colonne);
                                Color(15,10);
                                printf("        Votre pion se decale en bas        ");
                                Color(15,0);
                                gotoligcol(numero_ligne+9,numero_colonne);

                                //printf("Vous etes face a une barriere\nVotre piont va faire un decalage en bas\n");
                                dep[0]+=2;
                                dep[1]+=2;
                                valid_dep = 0;
                            }
                            //Sinon on applique le decalage voulu
                            else
                            {
                                if(matrice[dep[1]-2][dep[0]+2]==4)
                                {
                                    player[*Ptour-1].scoreP ++;
                                }
                                dep[0]+=2;
                                dep[1]-=2;
                                valid_dep = 0;
                            }
                        }
                        else{
                            valid_dep = 1;
                        }
                    }
                }
            }

            ///3.5. Deplacment impossible
            else
            {
                Color(15,0);
                gotoligcol(numero_ligne+7,numero_colonne);
                Color(15,10);
                printf("       Deplacement impossible       ");
                Color(15,0);
                gotoligcol(numero_ligne+8,numero_colonne);

                //printf("Deplacement impossible\n");
                system("PAUSE");
                valid_choix = 1;
            }
        }
    }
}


///Fonction de deplacement specifique pour la partie avec l'IA
///Car on ne passe plus par le meme compteur pour les tours
void deplacement_ia(int dep[3], t_joueur player[4], int matrice[17][17], int tour, t_IA ia)
{
    /// 0. DDV
    char choix;
    char choix_decalage = 'x';
    int valid_choix = 1;
    int valid_dep = 1;
    int numero_ligne=20;
    int numero_colonne=3;


    ///1. Affichage utilisateur
    while(valid_dep == 1)
    {
        while(valid_choix == 1)
        {
            system("cls");
            matrice_propre(matrice,player, ia);
            menu_cote_ia(tour, player, ia);

            gotoligcol(numero_ligne,numero_colonne);
            Color(15,2);
            printf("                                           ");
            Color(15,0);
            gotoligcol(numero_ligne+1,numero_colonne);
            Color(15,2);
            printf("                DEPLACEMENT                ");
            Color(15,0);
            gotoligcol(numero_ligne+2,numero_colonne);
            Color(15,2);
            printf("                                           ");
            Color(15,0);
            gotoligcol(numero_ligne+3,numero_colonne);
            Color(15,10);
            printf("                                           ");
            Color(15,0);
            gotoligcol(numero_ligne+4,numero_colonne);
            Color(15,10);
            printf("  Direction de deplacement (h, b, g, d) ?  ");
            Color(15,0);
            gotoligcol(numero_ligne+5,numero_colonne);
            Color(15,10);
            printf("                                           ");
            Color(15,0);
            gotoligcol(numero_ligne+6,numero_colonne);


            //printf("Direction de deplacement (h, b, g, d) :\n");
            scanf("%c", &choix);
            if((choix=='h')||(choix=='b')||(choix=='g')||(choix=='d')||(choix=='H')||(choix=='B')||(choix=='G')||(choix=='D'))
            {
                valid_choix = 0;
            }
        }
        ///3.1. Deplacment en haut
        //On verfifie qu'il n'y a pas de barriere sur le chemin
        if(((choix=='h')||(choix=='H'))&&(dep[1]!=0)&&((matrice[dep[1]-1][dep[0]])!=2)&&((matrice[dep[1]-1][dep[0]])!=3))
        {
            //On verifie que la case est libre (ou bonus)
            if((matrice[dep[1]-2][dep[0]]==0)||(matrice[dep[1]-2][dep[0]]==4))
            {
                if(matrice[dep[1]-2][dep[0]]==4)
                {
                    player[0].scoreP ++;
                }
                dep[1] -= 2;
                valid_dep = 0;
            }
            //Si notre deplacement nous fait sortir du plateau alors le booleen passe a false et on affcihera deplacement impossible
            else if(dep[1]==2)
            {
                valid_dep = 1;
                valid_choix = 1;

                Color(15,0);
                gotoligcol(numero_ligne+7,numero_colonne);
                Color(15,10);
                printf("       Deplacement impossible       ");
                Color(15,0);
                gotoligcol(numero_ligne+8,numero_colonne);

                //printf("Impossible de sortir du plateau\n");
                system("PAUSE");
            }
            //Si un joueur se trouve sur la case d'arrivee, on verfie que la suivante et libre et qu'il n'y a pas de barriere pour sauter
            else if((valid_dep == 1)&&((matrice[dep[1]-4][dep[0]]==0)||(matrice[dep[1]-4][dep[0]]==4))&&((matrice[dep[1]-3][dep[0]])!=2)&&((matrice[dep[1]-3][dep[0]])!=3))
            {
                if(matrice[dep[1]-4][dep[0]]==4)
                {
                    player[0].scoreP ++;
                }
                dep[1] -= 4;
                valid_dep = 0;
            }
            //Sinon on est dans le cas ou on va saute par dessus un joueur puis faire un decalage
            else
            {
                if((matrice[dep[1]-3][dep[0]]==2)||(matrice[dep[1]-3][dep[0]]==3))
                {
                    //On demande a l'utilisateur le decalage qu'il veux faire
                    while(validation_choix(choix_decalage, 'g', 'd')==1)
                    {
                        system("cls");
                        matrice_propre(matrice,player, ia);
                        menu_cote_ia(tour, player, ia);

                        Color(15,0);
                        gotoligcol(numero_ligne+7,numero_colonne);
                        Color(15,10);
                        printf("       Vous ne pouvez pas sauter le deuxieme mur       ");
                        Color(15,0);
                        gotoligcol(numero_ligne+8,numero_colonne);
                        Color(15,10);
                        printf("  Souhaitez vous aller en haut (h) ou en bas (b) ?  ");
                        Color(15,0);
                        gotoligcol(numero_ligne+9,numero_colonne);

                        //printf("Vous ne pouvez pas sauter le deuxieme mur,\nSouhaitez vous aller a gauche (g) ou a droite (d) ?\n");
                        scanf("%c", &choix_decalage);
                    }
                    if(choix_decalage == 'd')
                    {
                        //Si le decalage est impossible alors on fait celui de l'autre cote
                        if((matrice[dep[1]-2][dep[0]+1]==2)||(matrice[dep[1]-2][dep[0]+1]==3))
                        {
                            if(matrice[dep[1]-2][dep[0]-2]==4)
                            {
                                player[0].scoreP ++;
                            }

                            Color(15,0);
                            gotoligcol(numero_ligne+7,numero_colonne);
                            Color(15,10);
                            printf("       Vous etes face à une barriere       ");
                            Color(15,0);
                            gotoligcol(numero_ligne+8,numero_colonne);
                            Color(15,10);
                            printf("        Votre pion se decale a gauche        ");
                            Color(15,0);
                            gotoligcol(numero_ligne+9,numero_colonne);


                            //printf("Vous etes face a une barriere\nVotre piont va faire un decalage a gauche\n");
                            dep[0]-=2;
                            dep[1]-=2;
                            valid_dep = 0;

                        }
                        //Sinon on applique le decalage voulu
                        else
                        {
                            if(matrice[dep[1]-2][dep[0]+2]==4)
                            {
                                player[0].scoreP ++;
                            }
                            dep[0]+=2;
                            dep[1]-=2;
                            valid_dep = 0;
                        }
                    }
                    else
                    {
                        //Si le decalage est impossible alors on fait celui de l'autre cote
                        if((matrice[dep[1]-2][dep[0]-1]==2)||(matrice[dep[1]-2][dep[0]-1]==3))
                        {
                            if(matrice[dep[1]-2][dep[0]+2]==4)
                            {
                                player[0].scoreP ++;
                            }

                            Color(15,0);
                            gotoligcol(numero_ligne+7,numero_colonne);
                            Color(15,10);
                            printf("       Vous etes face à une barriere       ");
                            Color(15,0);
                            gotoligcol(numero_ligne+8,numero_colonne);
                            Color(15,10);
                            printf("        Votre pion se decale a droite       ");
                            Color(15,0);
                            gotoligcol(numero_ligne+9,numero_colonne);


                            //printf("Vous etes face a une barriere\nVotre piont va faire un decalage a droite\n");
                            dep[0]+=2;
                            dep[1]-=2;
                            valid_dep = 0;
                        }
                        //Sinon on applique le decalage voulu
                        else
                        {
                            if(matrice[dep[1]-2][dep[0]-2]==4)
                            {
                                player[0].scoreP ++;
                            }
                            dep[0]-=2;
                            dep[1]-=2;
                            valid_dep = 0;
                        }
                    }
                }
            }
        }

        ///3.2. Deplacment en bas
        //On verfifie qu'il n'y a pas de barriere sur le chemin
        else if(((choix=='b')||(choix=='B'))&&(dep[1]!=16)&&((matrice[dep[1]+1][dep[0]])!=2)&&((matrice[dep[1]+1][dep[0]])!=3))
        {
            //On verifie que la case est libre (ou bonus)
            if((matrice[dep[1]+2][dep[0]]==0)||(matrice[dep[1]+2][dep[0]]==4))
            {
                if(matrice[dep[1]+2][dep[0]]==4)
                {
                    player[0].scoreP ++;
                }
                dep[1] += 2;
                valid_dep = 0;
            }
            //Si notre deplacement nous fait sortir du plateau alors le booleen passe a false et on affcihera deplacement impossible
            else if(dep[1]==14)
            {
                valid_dep = 1;
                valid_choix = 1;

                Color(15,0);
                gotoligcol(numero_ligne+7,numero_colonne);
                Color(15,10);
                printf("       Impossible de sortir du plateau       ");
                Color(15,0);
                gotoligcol(numero_ligne+8,numero_colonne);
                //printf("Impossible de sortir du plateau\n");
                system("PAUSE");
            }
            //Si un joueur se trouve sur la case d'arrivee, on verfie que la suivante et libre et qu'il n'y a pas de barriere pour sauter
            else if((valid_dep == 1)&&((matrice[dep[1]+4][dep[0]]==0)||(matrice[dep[1]+4][dep[0]]==4))&&((matrice[dep[1]+3][dep[0]])!=2)&&((matrice[dep[1]+3][dep[0]])!=3))
            {
                if(matrice[dep[1]+4][dep[0]]==4)
                {
                    player[0].scoreP ++;
                }
                dep[1] += 4;
                valid_dep = 0;
            }
            //Sinon on est dans le cas ou on va saute par dessus un joueur puis faire un decalage
            else
            {
                if((matrice[dep[1]+3][dep[0]]==2)||(matrice[dep[1]+3][dep[0]]==3))
                {
                    //On demande a l'utilisateur le decalage qu'il veux faire
                    while(validation_choix(choix_decalage, 'g', 'd')==1)
                    {
                        system("cls");
                        matrice_propre(matrice,player, ia);
                        menu_cote_ia(tour, player, ia);

                        Color(15,0);
                        gotoligcol(numero_ligne+7,numero_colonne);
                        Color(15,10);
                        printf("       Vous ne pouvez pas sauter le deuxieme mur       ");
                        Color(15,0);
                        gotoligcol(numero_ligne+8,numero_colonne);
                        Color(15,10);
                        printf("  Souhaitez vous aller a gauche (g) ou a droite (d) ?  ");
                        Color(15,0);
                        gotoligcol(numero_ligne+9,numero_colonne);

                        //printf("Vous ne pouvez pas sauter le deuxieme mur,\nSouhaitez vous aller a gauche (g) ou a droite (d) ?\n");
                        scanf("%c", &choix_decalage);
                    }
                    if(choix_decalage == 'd')
                    {
                        //Si le decalage est impossible alors on fait celui de l'autre cote
                        if((matrice[dep[1]+2][dep[0]+1]==2)||(matrice[dep[1]+2][dep[0]+1]==3))
                        {
                            //Si le decalage est impossible alors on fait celui de l'autre cote
                            if(matrice[dep[1]+2][dep[0]-2]==4)
                            {
                                player[0].scoreP ++;
                            }

                            Color(15,0);
                            gotoligcol(numero_ligne+7,numero_colonne);
                            Color(15,10);
                            printf("       Vous etes face à une barriere       ");
                            Color(15,0);
                            gotoligcol(numero_ligne+8,numero_colonne);
                            Color(15,10);
                            printf("        Votre pion se decale a gauche       ");
                            Color(15,0);
                            gotoligcol(numero_ligne+9,numero_colonne);

                            //printf("Vous etes face a une barriere\nVotre piont va faire un decalage a gauche\n");
                            dep[0]-=2;
                            dep[1]+=2;
                            valid_dep = 0;
                        }
                        //Sinon on applique le decalage voulu
                        else
                        {
                            if(matrice[dep[1]+2][dep[0]+2]==4)
                            {
                                player[0].scoreP ++;
                            }
                            dep[0]+=2;
                            dep[1]+=2;
                            valid_dep = 0;
                        }
                    }
                    else
                    {
                        //Si le decalage est impossible alors on fait celui de l'autre cote
                        if((matrice[dep[1]+2][dep[0]-1]==2)||(matrice[dep[1]+2][dep[0]-1]==3))
                        {
                            if(matrice[dep[1]+2][dep[0]+2]==4)
                            {
                                player[0].scoreP ++;
                            }

                            Color(15,0);
                            gotoligcol(numero_ligne+7,numero_colonne);
                            Color(15,10);
                            printf("       Vous etes face à une barriere       ");
                            Color(15,0);
                            gotoligcol(numero_ligne+8,numero_colonne);
                            Color(15,10);
                            printf("        Votre pion se decale a droite        ");
                            Color(15,0);
                            gotoligcol(numero_ligne+9,numero_colonne);

                            //printf("Vous etes face a une barriere\nVotre piont va faire un decalage a droite\n");
                            dep[0]+=2;
                            dep[1]+=2;
                            valid_dep = 0;
                        }
                        //Sinon on applique le decalage voulu
                        else
                        {
                            if(matrice[dep[1]+2][dep[0]-2]==4)
                            {
                                player[0].scoreP ++;
                            }
                            dep[0]-=2;
                            dep[1]+=2;
                            valid_dep = 0;
                        }
                    }
                }
            }
        }

        ///3.3. Deplacment a gauche
        //On verfifie qu'il n'y a pas de barriere sur le chemin
        else if(((choix=='g')||(choix=='G'))&&(dep[0]!=0)&&((matrice[dep[1]][dep[0]-1])!=2)&&((matrice[dep[1]][dep[0]-1])!=3))
        {
            //On verifie que la case est libre (ou bonus)
            if((matrice[dep[1]][dep[0]-2]==0)||(matrice[dep[1]][dep[0]-2]==4))
            {
                if(matrice[dep[1]][dep[0]-2]==4)
                {
                    player[0].scoreP ++;
                }
                dep[0] -= 2;
                valid_dep = 0;
            }
            //Si notre deplacement nous fait sortir du plateau alors le booleen passe a false et on affcihera deplacement impossible
            else if(dep[0]==2)
            {
                valid_dep = 1;
                valid_choix = 1;
                Color(15,0);
                gotoligcol(numero_ligne+7,numero_colonne);
                Color(15,10);
                printf("       Impossible de sortir du plateau       ");
                Color(15,0);
                gotoligcol(numero_ligne+8,numero_colonne);
                //printf("Impossible de sortir du plateau\n");
                system("PAUSE");
            }
            //Si un joueur se trouve sur la case d'arrivee, on verfie que la suivante et libre et qu'il n'y a pas de barriere pour sauter
            else if((valid_dep == 1)&&((matrice[dep[1]][dep[0]-4]==0)||(matrice[dep[1]][dep[0]-4]==4))&&((matrice[dep[1]][dep[0]-3])!=2)&&((matrice[dep[1]][dep[0]-3])!=3))
            {
                if(matrice[dep[1]][dep[0]-4]==4)
                {
                    player[0].scoreP ++;
                }
                dep[0] -= 4;
                valid_dep = 0;
            }
            //Sinon on est dans le cas ou on va saute par dessus un joueur puis faire un decalage
            else
            {
                if((matrice[dep[1]][dep[0]-3]==2)||(matrice[dep[1]][dep[0]-3]==3))
                {
                    //On demande a l'utilisateur le decalage qu'il veux faire
                    while(validation_choix(choix_decalage, 'h', 'b')==1)
                    {
                        system("cls");
                        matrice_propre(matrice,player,ia);
                        menu_cote_ia(tour, player, ia);

                        Color(15,0);
                        gotoligcol(numero_ligne+7,numero_colonne);
                        Color(15,10);
                        printf("       Vous ne pouvez pas sauter le deuxieme mur       ");
                        Color(15,0);
                        gotoligcol(numero_ligne+8,numero_colonne);
                        Color(15,10);
                        printf("  Souhaitez vous aller en haut (h) ou en bas (b) ?  ");
                        Color(15,0);
                        gotoligcol(numero_ligne+9,numero_colonne);

                        //printf("Vous ne pouvez pas sauter le deuxieme mur,\nSouhaitez vous aller en haut (h) ou en bas (b) ?\n");
                        scanf("%c", &choix_decalage);
                    }
                    if(choix_decalage == 'b')
                    {
                        //Si le decalage est impossible alors on fait celui de l'autre cote
                        if((matrice[dep[1]+1][dep[0]-2]==2)||(matrice[dep[1]+1][dep[0]-2]==3))
                        {
                            if(matrice[dep[1]-2][dep[0]-2]==4)
                            {
                                player[0].scoreP ++;
                            }

                            Color(15,0);
                            gotoligcol(numero_ligne+7,numero_colonne);
                            Color(15,10);
                            printf("       Vous etes face à une barriere       ");
                            Color(15,0);
                            gotoligcol(numero_ligne+8,numero_colonne);
                            Color(15,10);
                            printf("        Votre pion se decale en haut        ");
                            Color(15,0);
                            gotoligcol(numero_ligne+9,numero_colonne);

                            //printf("Vous etes face a une barriere\nVotre piont va faire un decalage en haut\n");
                            dep[0]-=2;
                            dep[1]-=2;
                            valid_dep = 0;
                        }
                        //Sinon on applique le decalage voulu
                        else
                        {
                            if(matrice[dep[1]+2][dep[0]-2]==4)
                            {
                                player[0].scoreP ++;
                            }
                            dep[0]-=2;
                            dep[1]+=2;
                            valid_dep = 0;
                        }
                    }
                    else
                    {
                        //Si le decalage est impossible alors on fait celui de l'autre cote
                        if((matrice[dep[1]-1][dep[0]-2]==2)||(matrice[dep[1]-1][dep[0]-2]==3))
                        {
                            if(matrice[dep[1]+2][dep[0]-2]==4)
                            {
                                player[0].scoreP ++;
                            }

                            Color(15,0);
                            gotoligcol(numero_ligne+7,numero_colonne);
                            Color(15,10);
                            printf("       Vous etes face à une barriere       ");
                            Color(15,0);
                            gotoligcol(numero_ligne+8,numero_colonne);
                            Color(15,10);
                            printf("        Votre pion se decale en bas        ");
                            Color(15,0);
                            gotoligcol(numero_ligne+9,numero_colonne);

                            //printf("Vous etes face a une barriere\nVotre piont va faire un decalage en bas\n");
                            dep[0]-=2;
                            dep[1]+=2;
                            valid_dep = 0;
                        }
                        //Sinon on applique le decalage voulu
                        else
                        {
                            if(matrice[dep[1]-2][dep[0]-2]==4)
                            {
                                player[0].scoreP ++;
                            }
                            dep[0]-=2;
                            dep[1]-=2;
                            valid_dep = 0;
                        }
                    }
                }
            }
        }

        ///3.4. Deplacment a droite
        //On verfifie qu'il n'y a pas de barriere sur le chemin
        else if(((choix=='d')||(choix=='D'))&&(dep[0]!=16)&&((matrice[dep[1]][dep[0]+1])!=2)&&((matrice[dep[1]][dep[0]+1])!=3))
        {
            //On verifie que la case est libre (ou bonus)
            if((matrice[dep[1]][dep[0]+2]==0)||(matrice[dep[1]][dep[0]+2]==4))
            {
                if(matrice[dep[1]][dep[0]+2]==4)
                {
                    player[0].scoreP ++;
                }
                dep[0] += 2;
                valid_dep = 0;
            }
            //Si notre deplacement nous fait sortir du plateau alors le booleen passe a false et on affcihera deplacement impossible
            else if(dep[0]==14)
            {
                valid_dep = 1;
                valid_choix = 1;

                Color(15,0);
                gotoligcol(numero_ligne+7,numero_colonne);
                Color(15,10);
                printf("       Impossible de sortir du plateau       ");
                Color(15,0);
                gotoligcol(numero_ligne+8,numero_colonne);

                //printf("Impossible de sortir du plateau\n");
                system("PAUSE");
            }
            //Si un joueur se trouve sur la case d'arrivee, on verfie que la suivante et libre et qu'il n'y a pas de barriere pour sauter
            else if((valid_dep == 1)&&((matrice[dep[1]][dep[0]+4]==0)||(matrice[dep[1]][dep[0]+4]==4))&&(matrice[dep[1]][dep[0]+4]==4)&&((matrice[dep[1]][dep[0]+3])!=2)&&((matrice[dep[1]][dep[0]+3])!=3))
            {
                if(matrice[dep[1]][dep[0]+4]==4)
                {
                    player[0].scoreP ++;
                }
                dep[0] += 4;
                valid_dep = 0;
            }
            //Sinon on est dans le cas ou on va saute par dessus un joueur puis faire un decalage
            else
            {
                if((matrice[dep[1]][dep[0]+3]==2)||(matrice[dep[1]][dep[0]+3]==3))
                {
                    //On demande a l'utilisateur le decalage qu'il veux faire
                    while(validation_choix(choix_decalage, 'h', 'b')==1)
                    {
                        system("cls");
                        matrice_propre(matrice,player,ia);
                        menu_cote_ia(tour, player, ia);
                        printf("Vous ne pouvez pas sauter le deuxieme mur,\nSouhaitez vous aller en haut (h) ou en bas (b) ?\n");
                        scanf("%c", &choix_decalage);
                    }
                    if(choix_decalage == 'b')
                    {
                        //Si le decalage est impossible alors on fait celui de l'autre cote
                        if(((matrice[dep[1]+1][dep[0]+2]==2)||(matrice[dep[1]+1][dep[0]+2]==3)))
                        {
                            if(matrice[dep[1]-2][dep[0]+2]==4)
                            {
                                player[0].scoreP ++;
                            }

                            Color(15,0);
                            gotoligcol(numero_ligne+7,numero_colonne);
                            Color(15,10);
                            printf("       Vous etes face à une barriere       ");
                            Color(15,0);
                            gotoligcol(numero_ligne+8,numero_colonne);
                            Color(15,10);
                            printf("        Votre pion se decale en haut        ");
                            Color(15,0);
                            gotoligcol(numero_ligne+9,numero_colonne);

                            //printf("Vous etes face a une barriere\nVotre piont va faire un decalage en haut\n");
                            dep[0]+=2;
                            dep[1]-=2;
                            valid_dep = 0;
                        }
                        //Sinon on applique le decalage voulu
                        else
                        {
                            if(matrice[dep[1]+2][dep[0]+2]==4)
                            {
                                player[0].scoreP ++;
                            }
                            dep[0]+=2;
                            dep[1]+=2;
                            valid_dep = 0;
                        }
                    }
                    else
                    {
                        //Si le decalage est impossible alors on fait celui de l'autre cote
                        if((matrice[dep[1]-1][dep[0]+2]==2)||(matrice[dep[1]-1][dep[0]+2]==3))
                        {
                            if(matrice[dep[1]+2][dep[0]+2]==4)
                            {
                                player[0].scoreP ++;
                            }

                            Color(15,0);
                            gotoligcol(numero_ligne+7,numero_colonne);
                            Color(15,10);
                            printf("       Vous etes face à une barriere       ");
                            Color(15,0);
                            gotoligcol(numero_ligne+8,numero_colonne);
                            Color(15,10);
                            printf("        Votre pion se decale en bas        ");
                            Color(15,0);
                            gotoligcol(numero_ligne+9,numero_colonne);

                            //printf("Vous etes face a une barriere\nVotre piont va faire un decalage en bas\n");
                            dep[0]+=2;
                            dep[1]+=2;
                            valid_dep = 0;
                        }
                        //Sinon on applique le decalage voulu
                        else
                        {
                            if(matrice[dep[1]-2][dep[0]+2]==4)
                            {
                                player[0].scoreP ++;
                            }
                            dep[0]+=2;
                            dep[1]-=2;
                            valid_dep = 0;
                        }
                    }
                }
            }
        }

        ///3.5. Deplacment impossible
        else
        {
            Color(15,0);
            gotoligcol(numero_ligne+7,numero_colonne);
            Color(15,10);
            printf("       Deplacement impossible       ");
            Color(15,0);
            gotoligcol(numero_ligne+8,numero_colonne);
            //printf("Deplacement impossible\n");
            system("PAUSE");
            valid_choix = 1;
        }

    }
}
