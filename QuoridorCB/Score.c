#include "Header_Pierre.h"

void extraction_score(t_joueur joueur[4], int *PnbJ, char list_joueur[100][50], int list_score[100], int index_score[4][2])
{
    char list_joueur_en_cours[4][50];
    int list_score_en_cours[4];

    int k = 0;
    int l = 0;

    charger_score(list_joueur, list_score);

    for(int i = 0; i<*PnbJ; i++)
    {
        for(int j = 0; j<100; j++)
        {
            if(strcmp(joueur[i].nomJ, list_joueur[j])==0)
            {
                index_score[i][0] = j;
                index_score[i][1] = joueur[i].numeroJ;

                while(list_joueur[j][l] != '\0')
                {
                    list_joueur_en_cours[k][l] = list_joueur[j][l];
                    k++;
                    l++;
                }
            }
        }
    }
}


