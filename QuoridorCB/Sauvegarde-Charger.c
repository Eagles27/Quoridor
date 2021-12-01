#include "Header_Pierre.h"

void sauver(int tab[17][17])
{
    ///0. DDV
    FILE* fp = NULL;
    int i,j;

    ///1. Ouvrir fichier
    fp = fopen("Sauvegarde.txt", "w");

    if (fp == NULL) printf("\nerreur fichier\n");
    else
    {
        ///2. Ajout du plateau
        for(i=0; i<17; i++)
        {
            for(j=0; j<17; j++)
            {
                fprintf(fp,"%d",tab[i][j]);
            }
            //fprintf(fp,"\n");
        }
        fclose(fp);
    }
}

void charger(int tab[17][17])
{
    ///0. DDV
    FILE* fic;
    int i,j;
    char info;
    int chiffre;

    ///1. Ouvrir fichier
    fic = fopen("Sauvegarde.txt", "r");

    if (fic == NULL) printf("\nerreur fichier\n");
    else
    {
        ///2. Récupération du plateau
        while(!(feof(fic)))
        {
            for(i=0; i<17; i++)
            {
                for(j=0; j<17; j++)
                {
                    info = fgetc(fic);
                    printf("%c", info);
                    //printf("%d", info-48);
                }
            }
            printf("\n");
        }
        fclose(fic);
    }
}
