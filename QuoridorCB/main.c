#include <stdio.h>
#include <stdlib.h>



/////////////////////////////////////////////////::
void affiche(int tab[17][17]  )
{
    // 0. DDV
    int i,j;

    //Affichage

    // premiere ligne de lettres MAJUSCULES indices des cases
    printf("    ");
    for (i = 0 ; i<17 ; i++) printf("%c  ", 'A'+i);
    printf("\n\n");

    // affichage des lignes
    for(int i=0; i<17; i++)
    {
        printf("%c   ",'a'+i);
        for(int j=0; j<17; j++)
        {
            printf("%d  ", tab[i][j]);
        }
        printf("\n");
    }
}



/* ANCIEN SOUS PROG DE GENE DE MATRICE INTIALE
void presmatrice()
{

    int i;
    int j;

    int tab[17][17];

    //Remplissage de 0
    for(int i=0; i<17; i++)
    {
        for(int j=0; j<17; j++)
        {
            tab[i][j]=0;
        }
    }

    //Reste à mettre les 1 sur impairs

    //Setup de 1ere ligne et 1ere colonne //Et espacage de 1 de plus pour i>9
    for(i=0;i<19;i++)
    {

        tab[i][0]=i;
        tab[0][i]=i;

    }


affiche(tab);





}*/


int main()
{
    genematrice();
}
