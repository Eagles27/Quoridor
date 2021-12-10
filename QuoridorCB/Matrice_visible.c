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

    printf("    ");
    for (i = 0 ; i<17 ; i++) printf(" %c", 'A'+i);
    printf("\n\n");

    for(i=0; i<17; i++)
    {
        printf("%c   ",'a'+i);
        for(j=0; j<17; j++)
        {
            if(i%2==1)
            {
                if(j%2==1)
                {
                    if(tab[i][j]==3){
                        printf("%c", 0xCE);
                    }
                    else{
                        printf("%c", 0xC5);
                    }
                }

                else if(j%2==0)
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
            else
            {
                if(tab[i][j]==0)
                {
                    printf("   ");
                }
                else if(tab[i][j]==5){
                    printf(" %c ", caractereJ[0]);
                }
                else if(tab[i][j]==7){
                    printf(" %c ", caractereJ[1]);
                }
                else if(tab[i][j]==9){
                    printf(" %c ", caractereJ[2]);
                }
                else if(tab[i][j]==11){
                    printf(" %c ", caractereJ[3]);
                }
                else if(tab[i][j]==1){
                    printf("%c", 0xB3);
                }
                else if(tab[i][j]==3){
                    printf("%c", 0xBA);
                }
                else if(tab[i][j]==13){
                    printf(" %c ", 0x01);
                }
                else if(tab[i][j]==14){
                    printf(" %c ", ia.jeton);
                }
            }
        }
        printf("\n");
    }
}
