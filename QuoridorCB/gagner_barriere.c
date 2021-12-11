#include "Header_Pierre.h"

int gagner_barriere(t_joueur player[4], int *Pnombre_joueur)
{
    /*
    Les joueurs ayant le plus d'avance meme avec egalite marque 1 point
    */
    int placement_1 = 0;
    int placement_2 = 0;
    int placement_3 = 0;
    int placement_4 = 0;

    int gagne_1 = 0;
    int gagne_2 = 0;

    if(*Pnombre_joueur == 2)
    {
        for(int i = 0; i<*Pnombre_joueur; i++)
        {
            if(player[i].coordonneY_org == 0)
            {
                placement_1 = player[i].coordonneY;
                gagne_1 = i;
            }

            else
            {
                placement_2 = 16 - player[i].coordonneY;
                gagne_2 = i;

            }
        }



        if(placement_1 == placement_2)
        {
            return -1;
        }



        else if(placement_1 > placement_2)
        {
            return gagne_1;
        }


        else if(placement_1 < placement_2)
        {
            return gagne_2;
        }
    }
    else
    {
        placement_1 = player[0].coordonneY;
        placement_2 = 16 - player[1].coordonneX;
        placement_3 = 16 - player[2].coordonneY;
        placement_4 = player[3].coordonneX;

        //Tous les joueurs sont a egalite
        if((placement_1 == placement_2)&&(placement_1 == placement_3)&&(placement_1 == placement_4)&&(placement_2 == placement_3)&&(placement_2 == placement_4)&&(placement_3 == placement_4)){
            return -1;
        }
        //1, 2 et 3 sont a egalité devant
        else if((placement_4 < placement_1)&&(placement_1 == placement_2)&&(placement_1==placement_3)&&(placement_2==placement_3)){
            return 123;
        }
        //1, 2 et 4 sont a egalité devant
        else if((placement_3 < placement_1)&&(placement_1 == placement_2)&&(placement_1==placement_4)&&(placement_2==placement_4)){
            return 124;
        }
        //1, 3 et 4 sont a egalité devant
        else if((placement_2 < placement_1)&&(placement_1 == placement_3)&&(placement_1==placement_4)&&(placement_3==placement_4)){
            return 134;
        }
        //3, 2 et 4 sont a egalité devant
        else if((placement_1 < placement_1)&&(placement_2 == placement_3)&&(placement_2==placement_4)&&(placement_3==placement_4)){
            return 234;
        }
        //1, 2 sont a egalite devant
        else if((placement_3<placement_1)&&(placement_4<placement_1)&&(placement_1==placement_2)){
            return 12;
        }
        //2, 3 sont a egalite devant
        else if((placement_1<placement_2)&&(placement_4<placement_2)&&(placement_3==placement_2)){
            return 23;
        }
        //3, 4 sont a egalite devant
        else if((placement_1<placement_3)&&(placement_2<placement_3)&&(placement_3==placement_4)){
            return 34;
        }
        //1, 4 sont a egalite devant
        else if((placement_3<placement_1)&&(placement_2<placement_1)&&(placement_1==placement_4)){
            return 14;
        }
        //1 Gagne
        else if((placement_2<placement_1)&&(placement_3<placement_1)&&(placement_4<placement_1)){
            return 1;
        }
        //2 Gagne
        else if((placement_1<placement_2)&&(placement_3<placement_2)&&(placement_4<placement_2)){
            return 2;
        }
        //3 Gagne
        else if((placement_2<placement_3)&&(placement_1<placement_3)&&(placement_4<placement_3)){
            return 3;
        }
        //4 Gagne
        else if((placement_2<placement_4)&&(placement_3<placement_4)&&(placement_1<placement_4)){
            return 4;
        }
        else{
            return 0;
        }
    }
    return 0;




}


