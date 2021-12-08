#include "Header_Pierre.h"

/*
- mur verticale : 0xB3
- mur horizontal : 0xC4
- mur "+" : 0xC5
- mur verticale double : 0xBA
- mur horizontal double : 0xCD
- mur "+" double : 0xCE
- rond : 0x09
*/

void matrice_propre(int tab[17][17], t_joueur player[4]) //Programme graphique OK
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

    printf("    ");


    for (i = 0 ; i<17 ; i++) {
            if (i%2==0){
                Color(15,0);
                printf(" %c", 'A'+i);
            }
            else
            {
                Color(10,0);
                printf(" %c", 'A'+i);
            }

    }
    printf("\n\n");

    for(i=0; i<17; i++)
    {

        if(i%2==0)
        {
            Color(15,0);
        printf("%c   ",'a'+i);
        }
        else
        {
            Color(10,0);
            printf("%c   ",'a'+i);
        }
        for(j=0; j<17; j++)
        {
            if(i%2==1)
            {
                if(j%2==1)
                {
                    if(tab[i][j]==3){
                        Color(4,0);
                        printf("%c", 0xCE);
                    }
                    else{
                        Color(10,0);
                        printf("%c", 0xC5);
                    }
                }

                else if(j%2==0)
                {
                    if(tab[i][j]==1){
                        //printf("j%2==0");
                        Color(10,0);
                        printf("%c%c%c", 0xC4, 0xC4, 0xC4);
                    }
                    else{
                        Color(4,0);
                        printf("%c%c%c", 0xCD, 0xCD, 0xCD);
                    }
                }
            }
            else
            {
                if(tab[i][j]==0)
                {
                    Color(15,0);
                    printf("   ");
                }
                else if(tab[i][j]==5){
                    Color(1,0);
                    printf(" %c ", caractereJ[0]);
                }
                else if(tab[i][j]==7){
                    Color(6,0);
                    printf(" %c ", caractereJ[1]);
                }
                else if(tab[i][j]==9){
                    Color(5,0);
                    printf(" %c ", caractereJ[2]);
                }
                else if(tab[i][j]==11){
                    Color(15,0);
                    printf(" %c ", caractereJ[3]);
                }
                else if(tab[i][j]==1){
                    Color(10,0);
                    printf("%c", 0xB3);
                }
                else if(tab[i][j]==3){
                    Color(4,0);
                    printf("%c", 0xBA);
                }
            }
        }
        printf("\n");
    }
}
