#include "jeu.h"

void genematrice(int tab[17][17])
{
    int i;
    int j;


    //Remplissage de 0
    for(i=0; i<17; i++)
    {
        for(j=0; j<17; j++)
        {
            tab[i][j]=0;
        }
    }

    //Remplissage de 1 sur les lignes et les colonnes impaires
    for(i=0;i<17;i++)
    {
        if((i%2)!=0)
        {
            for(j=0;j<17;j++)
            {
                tab[i][j]=1;
            }
        }
        else
        {
            for(j=0;j<17;j++)
            {
                if((j%2)!=0)
                {
                    tab[i][j]=1;
                }
            }
        }
    }
//affichage du tableau
//affiche(tab);
}
