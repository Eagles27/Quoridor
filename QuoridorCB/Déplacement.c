/*R�gles
- Un pion se d�place dans les quatres directions (haut, bas, gauche, droite)
- Un pion ne peut pas passer au dessus d'une barri�re
- Si 2 joueurs, alors un pion peut sauter au dessus d'un autre seulement si il
n'y a pas de barriere entre lui et l'autre pion. Le pion saute dans la case qui
est dans la meme ligne. Si il y a une barriere entre l'autre pion et la case
d'atterissage alors il ira � droite ou � gauche.
- Si 4 joueurs, alors pas de sauts autoris�s.
*/

#include "Header_Pierre.h"

int validation_choix(char chx, char choix1, char choix2)
{
    int valid_chx = 1;

    if((chx==choix1)||(chx==choix2))
    {
        valid_chx=0;
    }

    if(valid_chx==1) return 1;
    else return 0;
}

void deplacement(int dep[3], int matrice[17][17], int nombrejoueur)
{
    /// 0. DDV
    char choix;
    char choix_decalage = 'x';
    int valid_choix = 1;
    int valid_dep = 1;

    ///1. Affichage utilisateur
    while(valid_dep == 1)
    {
        while(valid_choix == 1)
        {
            system("cls");
            printf("Direction de deplacement (h, b, g, d) :\n");
            scanf("%c", &choix);
            if((choix=='h')||(choix=='b')||(choix=='g')||(choix=='d')||(choix=='H')||(choix=='B')||(choix=='G')||(choix=='D'))
            {
                //printf("valid choix");
                valid_choix = 0;
            }
            /*else
            {
                system("cls");
                printf("Saisie erronee\n");
                printf("Direction de deplacement (h, b, g, d) :\n");
                scanf("%c", &choix);
            }*/
        }
        //printf("choix termine\n");
        if(nombrejoueur==4)
        {
            if(((choix=='h')||(choix=='H'))&&(dep[1]!=0)&&(((matrice[dep[1]-1][dep[0]])!=2)||((matrice[dep[1]-1][dep[0]])!=3))&&(matrice[dep[1]-2][dep[0]]==0))
            {
                dep[1] -= 2;
                valid_dep = 0;
            }
            else if(((choix=='b')||(choix=='B'))&&(dep[1]!=16)&&(((matrice[dep[1]+1][dep[0]])!=2)||((matrice[dep[1]+1][dep[0]])!=3))&&(matrice[dep[1]+2][dep[0]]==0))
            {
                dep[1] +=2;
                valid_dep = 0;
            }
            else if(((choix=='g')||(choix=='G'))&&(dep[0]!=0)&&(((matrice[dep[1]][dep[0]-1])!=2)||((matrice[dep[1]][dep[0]-1])!=3))&&(matrice[dep[1]][dep[0]-2]==0))
            {
                dep[0]-=2;
                valid_dep = 0;
            }
            else if(((choix=='d')||(choix=='D'))&&(dep[0]!=16)&&(((matrice[dep[1]][dep[0]+1])!=2)||((matrice[dep[1]][dep[0]+1])!=3))&&(matrice[dep[1]][dep[0]+2]==0))
            {
                dep[0]+=2;
                valid_dep = 0;
            }
            else
            {
                valid_choix = 1;
            }
        }
        else
        {
            if(((choix=='h')||(choix=='H'))&&(dep[1]!=0)&&(((matrice[dep[1]-1][dep[0]])!=2)||((matrice[dep[1]-1][dep[0]])!=3)))
            {
                if(matrice[dep[1]-2][dep[0]]==0)
                {
                    dep[1] -= 2;
                    valid_dep = 0;
                }
                else if((valid_dep == 1)&&(matrice[dep[1]-4][dep[0]]==0)){

                }
                else
                {
                    if((matrice[dep[1]-3][dep[0]]==2)||(matrice[dep[1]-3][dep[0]]==3))
                    {
                        while(validation_choix(choix_decalage, 'g', 'd')==1)
                        {
                            system("cls");
                            printf("Vous ne pouvez pas sauter le deuxi�me mur,\nSouhaitez vous aller � gauche (g) ou a droite (d) ?\n");
                            scanf("%c", &choix_decalage);
                        }
                        if(choix_decalage == 'd')
                        {
                            if((matrice[dep[1]-2][dep[0]+1]==2)||(matrice[dep[1]-2][dep[0]+1]==3))
                            {
                                printf("Vous etes face a une barriere\nVotre piont va faire un decalage a gauche\n");
                                dep[0]-=2;
                                valid_dep = 0;
                            }
                            else
                            {
                                dep[0]+=2;
                                valid_dep = 0;
                            }
                        }
                        else
                        {
                            if((matrice[dep[1]-2][dep[0]-1]==2)||(matrice[dep[1]-2][dep[0]-1]==3))
                            {
                                printf("Vous etes face a une barriere\nVotre piont va faire un decalage a droite\n");
                                dep[0]+=2;
                                valid_dep = 0;
                            }
                            else
                            {
                                dep[0]-=2;
                                valid_dep = 0;
                            }
                        }
                    }
                }
            }
            else if(((choix=='b')||(choix=='B'))&&(dep[1]!=16)&&(((matrice[dep[1]+1][dep[0]])!=2)||((matrice[dep[1]+1][dep[0]])!=3)))
            {
                if(matrice[dep[1]+4][dep[0]]==0)
                {
                    dep[1] += 4;
                    valid_dep = 0;
                }
                else
                {
                    if((matrice[dep[1]+3][dep[0]]==2)||(matrice[dep[1]+3][dep[0]]==3))
                    {
                        while(validation_choix(choix_decalage, 'g', 'd')==1)
                        {
                            system("cls");
                            printf("Vous ne pouvez pas sauter le deuxi�me mur,\nSouhaitez vous aller a gauche (g) ou a droite (d) ?\n");
                            scanf("%c", &choix_decalage);
                        }
                        if(choix_decalage == 'd')
                        {
                            if((matrice[dep[1]+2][dep[0]+1]==2)||(matrice[dep[1]+2][dep[0]+1]==3))
                            {
                                printf("Vous etes face a une barriere\nVotre piont va faire un decalage a gauche\n");
                                dep[0]-=2;
                                valid_dep = 0;
                            }
                            else
                            {
                                dep[0]+=2;
                                valid_dep = 0;
                            }
                        }
                        else
                        {
                            if((matrice[dep[1]+2][dep[0]-1]==2)||(matrice[dep[1]+2][dep[0]-1]==3))
                            {
                                printf("Vous etes face a une barriere\nVotre piont va faire un decalage a droite\n");
                                dep[0]+=2;
                                valid_dep = 0;
                            }
                            else
                            {
                                dep[0]-=2;
                                valid_dep = 0;
                            }
                        }
                    }
                }
            }
            else if(((choix=='g')||(choix=='G'))&&(dep[0]!=0)&&(((matrice[dep[1]][dep[0]-1])!=2)||((matrice[dep[1]][dep[0]-1])!=3)))
            {
                if(matrice[dep[1]+4][dep[0]]==0)
                {
                    dep[1] -= 4;
                    valid_dep = 0;
                }
                else
                {
                    if((matrice[dep[1]+3][dep[0]]==2)||(matrice[dep[1]+3][dep[0]]==3))
                    {
                        while(validation_choix(choix_decalage, 'h', 'b')==1)
                        {
                            system("cls");
                            printf("Vous ne pouvez pas sauter le deuxi�me mur,\nSouhaitez vous aller en haut (h) ou en bas (b) ?\n");
                            scanf("%c", &choix_decalage);
                        }
                        if(choix_decalage == 'h')
                        {
                            if((matrice[dep[1]+2][dep[0]+1]==2)||(matrice[dep[1]+2][dep[0]+1]==3))
                            {
                                printf("Vous etes face a une barriere\nVotre piont va faire un decalage en bas\n");
                                dep[0]-=2;
                                valid_dep = 0;
                            }
                            else
                            {
                                dep[0]+=2;
                                valid_dep = 0;
                            }
                        }
                        else
                        {
                            if((matrice[dep[1]+2][dep[0]-1]==2)||(matrice[dep[1]+2][dep[0]-1]==3))
                            {
                                printf("Vous etes face a une barriere\nVotre piont va faire un decalage en haut\n");
                                dep[0]+=2;
                                valid_dep = 0;
                            }
                            else
                            {
                                dep[0]-=2;
                                valid_dep = 0;
                            }
                        }
                    }
                }
            }
            else if(((choix=='d')||(choix=='D'))&&(dep[0]!=16)&&(((matrice[dep[1]][dep[0]+1])!=2)||((matrice[dep[1]][dep[0]+1])!=3)))
            {
                dep[0]+=2;
                valid_dep = 0;
            }
            else
            {
                valid_choix = 1;
            }
        }
    }
}
