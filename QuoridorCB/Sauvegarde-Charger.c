#include "Header_Pierre.h"

//////////////////////////////////////////////////////
///////////////////// Sauvegarde /////////////////////
//////////////////////////////////////////////////////

void sauver_plateau(int tab[17][17])
{
    ///0. DDV
    FILE* fp = NULL;
    int i,j;

    ///1. Ouvrir fichier
    fp = fopen("Sauvegarde_plateau.txt", "w");

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

void sauver_joueur(t_joueur joueur[4], int *Pnombre_joueur)
{
    ///0. DDV
    FILE* fp = NULL;

    ///1. Ouvrir fichier
    fp = fopen("Sauvegarde_info.txt", "w");

    if (fp == NULL) printf("\nerreur fichier\n");
    else
    {
        ///1.1. Ecriture du nombre de joueur
        fprintf(fp, "%d\n", *Pnombre_joueur);
        ///1.2. Ecritur des infos de chacun des joueurs
        for(int i = 0; i<*Pnombre_joueur; i++)
        {
            fprintf(fp, "%s\n", joueur[i].nomJ);
            fprintf(fp, "%d\n", joueur[i].scoreP);
            fprintf(fp, "%d\n", joueur[i].barrieresR);
            fprintf(fp, "%d\n", joueur[i].numeroJ);
            fprintf(fp, "%d\n", joueur[i].coordonneX);
            fprintf(fp, "%d\n", joueur[i].coordonneY);
            fprintf(fp, "%d\n", joueur[i].coordonneX_org);
            fprintf(fp, "%d\n", joueur[i].coordonneY_org);
            fprintf(fp, "%d\n", joueur[i].A_annule);
        }
        fclose(fp);
    }
}

//////////////////////////////////////////////////////
///////////////////// Chargement /////////////////////
//////////////////////////////////////////////////////

void charger_plateau(int tab[17][17])
{
    ///0. DDV
    FILE* fic;
    int i=0;
    int j=0;
    char info;
    int chiffre;

    ///1. Ouvrir fichier
    fic = fopen("Sauvegarde_plateau.txt", "r");

    if (fic == NULL) printf("\nerreur fichier\n");
    else
    {
        ///2. R?cup?ration du plateau
        while(!(feof(fic)))
        {
            info = fgetc(fic); //recuperation du caractere
            chiffre = (int)info - 48; //Transformation en chiffre (0 en ascii = 48, 1 = 49,...)
            tab[i][j] = chiffre; //Ajout de la valeur de la case dans le tableau
            j++;
            if(j==17) //Retour la la ligne suivante
            {
                j = 0;
                i++;
            }
        }
        fclose(fic);
    }
}

void charger_joueur(t_joueur joueur[4], int * Pnombre_joueur)
{
    ///0. DDV
    FILE* fp;

    ///1. Ouvrir fichier
    fp = fopen("Sauvegarde_info.txt", "r");

    if (fp == NULL) printf("\nerreur fichier\n");
    else
    {
        ///1.2. Lecture nombre de joueur
        fscanf(fp, "%d", Pnombre_joueur);
        while(!(feof(fp)))
        {
            ///1.3. lecture des infos de chacun des joueurs
            for(int i = 0; i< *Pnombre_joueur; i++)
            {
                fscanf(fp, "%s", joueur[i].nomJ);
                fscanf(fp, "%d", &(joueur[i].scoreP));
                fscanf(fp, "%d", &(joueur[i].barrieresR));
                fscanf(fp, "%d", &(joueur[i].numeroJ));
                fscanf(fp, "%d", &(joueur[i].coordonneX));
                fscanf(fp, "%d", &(joueur[i].coordonneY));
                fscanf(fp, "%d", &(joueur[i].coordonneX_org));
                fscanf(fp, "%d", &(joueur[i].coordonneY_org));
                fscanf(fp, "%d", &(joueur[i].A_annule));
            }
        }
        fclose(fp);
    }
}
