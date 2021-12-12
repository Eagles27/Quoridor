#include "Header_Pierre.h"

///Recupere le nombre de joueur enregistré avec leur score
void saisietaille(int*Ptaille)
{
    ///0. DDV
    FILE* fic;

    ///1. Ouverture fichier
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

///Tri dans l'ordre decroissant chaque joueur en fonction de son score
void trierB(t_joueur player[150],int*Ptaille)
{
    ///0. DDV
    int temp;
    char nom[30];

    ///1. Tri a bulle sur les scores des joueurs
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

///Affiche le tableau des scores
void tableau_score(t_joueur player[150])
{
    ///0. DDV
    int taille = 0;
    int *Ptaille = &taille;
    int no_l = 4;
    int no_c = 20;
    FILE *fp;

    ///1. Determine le nombre de joueur dont nous avons sauvegardé le score
    saisietaille(Ptaille);

    ///2. Ouverture fichier
    fp = fopen("score.txt","r");

    if(fp == NULL)
    {
        exit(1);
    }

    else
    {
        ///2.1. Lecture de tous les joueurs
        fseek(fp,2,SEEK_SET);
        for(int i = 0; i<taille; i++)
        {
            fscanf(fp, "%s\n%d",player[i].nomJ,&(player[i].scoreP));

        }

        ///2.2. Tri des joueurs selon leur score
        trierB(player,Ptaille);


        ///3. Affichage des scores
        Color(15,0);

        gotoligcol(no_l,no_c);
        Color(15,10);
        printf("                        ");
        Color(15,0);
        gotoligcol(no_l+1,no_c);
        Color(15,10);


        Color(15,10);
        gotoligcol(no_l,no_c+10);
        printf("LEADERBOARD");
        gotoligcol(no_l+2,no_c);
        for(int i = 0; i<taille; i++)
        {

            printf("%s: %dpts\n", player[i].nomJ,player[i].scoreP);

        }
        system("PAUSE");

        fclose(fp);
    }

}
