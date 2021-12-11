#include "Header_Pierre.h"


void saisietaille(int*Ptaille)
{
    FILE* fic;

    fic = fopen("score.txt","r");

    if(fic == NULL)
    {
        exit(1);
    }

    else
    {
        fscanf(fic,"%d",Ptaille);  ///Lecture du nombre d'éléments

        fclose(fic);
    }
}


void trierB(t_joueur player[150],int*Ptaille)
{
    int temp;
    char nom[30];

    for(int i=0; i<*Ptaille; i++)
    {
        for(int j=0; j<*Ptaille-1; j++)
        {
            if (player[j].scoreP < player[j+1].scoreP)
            {
                temp = player[j].scoreP;
                strcpy(nom,player[j].nomJ);
                player[j].scoreP = player[j+1].scoreP;
                strcpy(player[j].nomJ,player[j+1].nomJ);
                player[j+1].scoreP = temp;
                strcpy(player[j+1].nomJ,nom);

            }
        }
    }
}


void tableau_score(t_joueur player[150])
{
    int taille = 0;
    int *Ptaille = &taille;
    FILE *fp;

    saisietaille(Ptaille);

    fp = fopen("score.txt","r");

    if(fp == NULL)
    {
        exit(1);
    }

    else
    {
        fseek(fp,2,SEEK_SET);
        for(int i = 0; i<taille; i++)
        {
            fscanf(fp, "%s\n%d",player[i].nomJ,&(player[i].scoreP));

        }

        trierB(player,Ptaille);


        for(int i = 0; i<taille; i++)
        {
            printf("%s: %dpts\n", player[i].nomJ,player[i].scoreP);

        }
        system("PAUSE");

        fclose(fp);
    }

}
