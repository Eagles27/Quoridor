#include "Header_Pierre.h"

void actualisation_score(t_joueur player[4],int tour_test)
{
    FILE * fic;

    char tempN[50];
    int tempS;
    int sortie = 0;


    fic = fopen("score.txt","r+");

    if(fic == NULL)
    {
        printf("Erreur ouverture fichier\n");
        system("PAUSE");

    }

    else
    {
        while((!feof(fic))&&(sortie == 0))
        {
            fscanf(fic,"%s\n%d\n",tempN,&tempS);

            if(strcmp(tempN,player[tour_test].nomJ)==0)
            {
                player[tour_test].scoreP ++;
                fseek(fic,(-strlen(tempN))+1,SEEK_CUR);

                fprintf(fic,"\n%d",player[tour_test].scoreP);
                fseek(fic,0,SEEK_END);
                sortie =1;


            }

        }

        fclose(fic);
    }
}
