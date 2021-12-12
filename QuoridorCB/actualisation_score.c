#include "Header_Pierre.h"

void actualisation_score(t_joueur player[4],int tour_test)
{
///0 Declaration des variables

    FILE * fic;
    char tempN[50];
    int tempS;
    int sortie = 0;

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
        while((!feof(fic))&&(sortie == 0))  //
        {
            ///Lecture des elements du fichier
            fscanf(fic,"%s\n%d",tempN,&tempS);

            ///Si le joueur est deja present dans la base
            if(strcmp(tempN,player[tour_test].nomJ)==0)
            {
                ///Score <10
                if(player[tour_test].scoreP<10)
                {
                    fseek(fic,-1,SEEK_CUR);
                    fprintf(fic,"%d\n",player[tour_test].scoreP);//On modifie le score du joueur
                }

                ///Score <100
                else if((player[tour_test].scoreP>10)&&(player[tour_test].scoreP<100))
                {
                    fseek(fic,-2,SEEK_CUR);
                    fprintf(fic,"%d\n",player[tour_test].scoreP);
                }

                ///Score <1000
                else if((player[tour_test].scoreP>100)&&(player[tour_test].scoreP<1000))
                {
                    fseek(fic,-3,SEEK_CUR);
                    fprintf(fic,"%d\n",player[tour_test].scoreP);
                }

                ///Score <10000
                else if((player[tour_test].scoreP>1000)&&(player[tour_test].scoreP<10000))
                {
                    fseek(fic,-4,SEEK_CUR);
                    fprintf(fic,"%d\n",player[tour_test].scoreP);
                }

                sortie =1;  //On sort de la boucle une fois l'element enregistre

            }

        }

        fclose(fic);
    }
}
