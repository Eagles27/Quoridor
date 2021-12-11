#include "Header_Pierre.h"

/*

- mur verticale : 0xB3
- mur horizontal : 0xC4
- mur "+" : 0xC5
- mur verticale double : 0xBA
- mur horizontal double : 0xCD
- mur "+" double : 0xCE
- rond : 0x0F
*/

void matrice_propre(int tab[17][17], t_joueur player[4], t_IA ia)
{
    ///0.0. DDV temporaire
    char caractereJ[4];

    /// Attribution des tokens pour chaques joueurs

    for(int i=0;i<4;i++)
    {
        caractereJ[i] = player[i].jetonJ;
    }

    ///0. DDV
    int i,j;

    ///1. Affichage des lettres
    printf("    "); //Coin superieur gauche

    ///1.1. Affichage ligne coordonnees abscisses
    for (i = 0 ; i<17 ; i++) printf(" %c", 'A'+i);
    printf("\n\n");

    for(i=0; i<17; i++)
    {
        ///1.2. Affichage colonne coordonnees ordonnees
        printf("%c   ",'a'+i);

        ///2. Affichage plateau
        for(j=0; j<17; j++)
        {
            ///2.1. Lecture des lignes impaires donc que des barrieres verticales et des croix
            if(i%2==1)
            {
                if(j%2==1) //Si impair alors croix simple ou double
                {
                    if(tab[i][j]==3){
                        printf("%c", 0xCE);
                    }
                    else{
                        printf("%c", 0xC5);
                    }
                }

                else if(j%2==0) //Si pair alors barriere horizontale simple ou double
                {
                    if(tab[i][j]==1){
                        //printf("j%2==0");
                        printf("%c%c%c", 0xC4, 0xC4, 0xC4);
                    }
                    else{
                        printf("%c%c%c", 0xCD, 0xCD, 0xCD);
                    }
                }
            }
            ///2.1. Lecture des lignes paires donc des barrieres horizontales ou le contenu d'une case
            else
            {
                if(tab[i][j]==0) //0 = case vide
                {
                    printf("   ");
                }
                else if(tab[i][j]==5){ //1 = Pion joueur 1
                    printf(" %c ", caractereJ[0]);
                }
                else if(tab[i][j]==7){ //7 = Pion joueur 2
                    printf(" %c ", caractereJ[1]);
                }
                else if(tab[i][j]==8){ //8 = Pion joueur 3
                    printf(" %c ", caractereJ[2]);
                }
                else if(tab[i][j]==9){ //9 = Pion joueur 4
                    printf(" %c ", caractereJ[3]);
                }
                else if(tab[i][j]==1){
                    printf("%c", 0xB3);
                }
                else if(tab[i][j]==3){ //3 = barriere simple
                    printf("%c", 0xBA);
                }
                else if(tab[i][j]==4){ //4 = barriere double
                    printf(" %c ", 0x01);
                }
                else if(tab[i][j]==6){ //6 = Pion IA
                    printf(" %c ", ia.jeton);
                }
            }
        }
        printf("\n");
    }
}
