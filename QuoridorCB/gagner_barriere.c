#include "Header_Pierre.h"


///Fonction retournant le gagnant si la victoire est parce qu'un joueur n'a plus de barrieres
int gagner_barriere(t_joueur player[4], int *Pnombre_joueur)
{
    /*
    A 4joueurs, les joueurs ayant le plus d'avance meme avec egalite marque 1 point
    */

    ///0. DDV
    int placement_1 = 0;
    int placement_2 = 0;
    int placement_3 = 0;
    int placement_4 = 0;

    int gagne_1 = 0;
    int gagne_2 = 0;

    ///1. Calcul gagnant a 2joueurs
    if(*Pnombre_joueur == 2)
    {
        ///1.1. Initialisation du placement relatif de chacun
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

        ///1.2. Tests pour savoir qui gagne
        //Personne ne gagne
        if(placement_1 == placement_2)
        {
            return -1;
        }
        //J1 gagne
        else if(placement_1 > placement_2)
        {
            return gagne_1;
        }
        //J2 gagne
        else if(placement_1 < placement_2)
        {
            return gagne_2;
        }
    }
    ///2. Calcul gagnant a 4joueurs
    else
    {
        ///2.1. Initialisation du placement relatif de chacun
        placement_1 = player[0].coordonneY;
        placement_2 = 16 - player[1].coordonneX;
        placement_3 = 16 - player[2].coordonneY;
        placement_4 = player[3].coordonneX;

        ///2.2. Tests pour savoir qui gagne
        //Tous les joueurs sont a egalite
        if((placement_1 == placement_2)&&(placement_1 == placement_3)&&(placement_1 == placement_4)&&(placement_2 == placement_3)&&(placement_2 == placement_4)&&(placement_3 == placement_4))
        {
            return -1;
        }
        //1, 2 et 3 sont a egalité devant
        else if((placement_4 < placement_1)&&(placement_1 == placement_2)&&(placement_1==placement_3)&&(placement_2==placement_3))
        {
            return 123;
        }
        //1, 2 et 4 sont a egalité devant
        else if((placement_3 < placement_1)&&(placement_1 == placement_2)&&(placement_1==placement_4)&&(placement_2==placement_4))
        {
            return 124;
        }
        //1, 3 et 4 sont a egalité devant
        else if((placement_2 < placement_1)&&(placement_1 == placement_3)&&(placement_1==placement_4)&&(placement_3==placement_4))
        {
            return 134;
        }
        //3, 2 et 4 sont a egalité devant
        else if((placement_1 < placement_1)&&(placement_2 == placement_3)&&(placement_2==placement_4)&&(placement_3==placement_4))
        {
            return 234;
        }
        //1, 2 sont a egalite devant
        else if((placement_3<placement_1)&&(placement_4<placement_1)&&(placement_1==placement_2))
        {
            return 12;
        }
        //2, 3 sont a egalite devant
        else if((placement_1<placement_2)&&(placement_4<placement_2)&&(placement_3==placement_2))
        {
            return 23;
        }
        //3, 4 sont a egalite devant
        else if((placement_1<placement_3)&&(placement_2<placement_3)&&(placement_3==placement_4))
        {
            return 34;
        }
        //1, 4 sont a egalite devant
        else if((placement_3<placement_1)&&(placement_2<placement_1)&&(placement_1==placement_4))
        {
            return 14;
        }
        //1 Gagne
        else if((placement_2<placement_1)&&(placement_3<placement_1)&&(placement_4<placement_1))
        {
            return 1;
        }
        //2 Gagne
        else if((placement_1<placement_2)&&(placement_3<placement_2)&&(placement_4<placement_2))
        {
            return 2;
        }
        //3 Gagne
        else if((placement_2<placement_3)&&(placement_1<placement_3)&&(placement_4<placement_3))
        {
            return 3;
        }
        //4 Gagne
        else if((placement_2<placement_4)&&(placement_3<placement_4)&&(placement_1<placement_4))
        {
            return 4;
        }
        //Personne ne gagne
        else
        {
            return 0;
        }
    }

    return 0;

}


