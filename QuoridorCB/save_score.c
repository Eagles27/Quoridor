#include "Header_Pierre.h"

void save_score(t_joueur player[4],int i)
{
    FILE *fic;

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

            if(strcmp(tempN,player[i].nomJ)==0)
            {
                sortie =1;
                player[i].scoreP = tempS;
            }

            else
            {
                fseek(fic,0,SEEK_END);
                fprintf(fic,"%s\n%d\n",player[i].nomJ,player[i].scoreP);
                sortie = 1;
            }


        }
        /*

        printf("%d",player[0].scoreP);
        system("PAUSE");

        */

        fclose(fic);


    }


}
