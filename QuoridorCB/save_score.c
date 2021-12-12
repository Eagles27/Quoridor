#include "Header_Pierre.h"

void save_score(t_joueur player[4],int i)
{
///0. Declaration des variables
    FILE *fic;
    char tempN[50];
    int tempS;
    int sortie = 0;
    int nombre;


///1.0 Ouverture du fichier
    fic = fopen("score.txt","r+");

///1.1 Probleme Ouverture
  if(fic == NULL)
    {
        printf("Erreur ouverture fichier\n");
        system("PAUSE");
        exit(1);

    }

///1.2 Ouverture reussie
    else
    {
        while((!feof(fic)&&(sortie == 0)))
        {
            ///Lecture des elements du fichier
            fscanf(fic,"%s\n%d\n",tempN,&tempS);


            ///Detection du joueur dans le fichier
            if(strcmp(tempN,player[i].nomJ)==0)
            {
                player[i].scoreP = tempS;   //attribution du score lu à la structure correspondant
                sortie = 1;     //booléen permettant de sortir une fois l'element trouve
            }

        }

        ///Le joueur n'est pas présent dans la base de donnée
        if(sortie == 0)
        {
            fseek(fic,0,SEEK_SET);  //On place le curseur au debut du fichier
            fscanf(fic,"%d\n",&nombre); //on lit la premiere ligne du fichier qui correspond au nombre de joueur enregistres
            nombre ++;  //On incremente ce nombre de 1

            fseek(fic,0,SEEK_SET);  //On reecrit le nombre precedent en debut du fichier
            fprintf(fic,"%d",nombre);

            fseek(fic,0,SEEK_END);  //On se place a la fin du fichier
            fprintf(fic,"%s\n%d\n",player[i].nomJ,player[i].scoreP); //On ecrit le nom et le score du nouveau joueur

        }

        fclose(fic);

    }

}
