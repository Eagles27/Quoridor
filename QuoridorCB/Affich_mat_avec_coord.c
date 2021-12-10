#include "Header_Pierre.h"

void affiche(int tab[17][17])
{
    // 0. DDV
    int i,j;

    //Affichage

    // premiere ligne de lettres MAJUSCULES indices des cases
    printf("    ");
    for (i = 0 ; i<17 ; i++) printf("%c  ", 'A'+i);
    printf("\n\n");

    // affichage du tableau
    for(i=0; i<17; i++)
    {
        printf("%c   ",'a'+i);
        for(j=0; j<17; j++)
        {
            printf("%d  ", tab[i][j]);
        }
        printf("\n");
    }
}
