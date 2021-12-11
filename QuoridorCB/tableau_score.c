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


        for(int i = 0; i<taille; i++)
        {
            printf("%s: %dpts\n", player[i].nomJ,player[i].scoreP);

        }
        system("PAUSE");

        fclose(fp);
    }

}
