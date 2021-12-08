#include "Header_Pierre.h"

int gagner_barriere(t_joueur player[4])
{
    int placement_1 = 0;
    int placement_2 = 0;

    int gagne_1 = 0;
    int gagne_2 = 0;

    for(int i = 0; i<4; i++)
    {
        if(player[i].coordonneY_org == 0)
        {
            placement_1 = 16 - player[i].coordonneY;
            gagne_1 = i;
        }

        else
        {
            placement_2 = player[i].coordonneY - 16;
            gagne_2 = i;

        }
    }



    if((placement_1 == placement_2)||(placement_1 == 16 - placement_2)||(16 - placement_1 == placement_2))
    {
        return -1;
    }



    else if(placement_1 > placement_2)
    {
        return gagne_2;
    }


    else if(placement_1 < placement_2)
    {
        return gagne_1;
    }




}


