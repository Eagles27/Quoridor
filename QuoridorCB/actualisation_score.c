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
            fscanf(fic,"%s\n%d",tempN,&tempS);

            if(strcmp(tempN,player[tour_test].nomJ)==0)
            {
                player[tour_test].scoreP ++;

                if(player[tour_test].scoreP<10)
                {
                    fseek(fic,-1,SEEK_CUR);
                    fprintf(fic,"%d\n",player[tour_test].scoreP);
                }

                else if((player[tour_test].scoreP>10)&&(player[tour_test].scoreP<100))
                {
                    fseek(fic,-2,SEEK_CUR);
                    fprintf(fic,"%d\n",player[tour_test].scoreP);
                }

                else if((player[tour_test].scoreP>100)&&(player[tour_test].scoreP<1000))
                {
                    fseek(fic,-3,SEEK_CUR);
                    fprintf(fic,"%d\n",player[tour_test].scoreP);
                }

                  else if((player[tour_test].scoreP>1000)&&(player[tour_test].scoreP<10000))
                {
                    fseek(fic,-4,SEEK_CUR);
                    fprintf(fic,"%d\n",player[tour_test].scoreP);
                }



                sortie =1;


            }

        }

        fclose(fic);
    }
}
