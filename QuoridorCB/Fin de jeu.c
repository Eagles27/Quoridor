#include "Header_Pierre.h"

///Verifie si un joueur a gagner ou pas
int gagner(t_joueur player[4], int* Pnombrejoueur, int tour)
{
    ///1. Partie a 2J
    if(*Pnombrejoueur == 2)
    {
        ///1.1. Un joueur n'a plus de barriere
        if(player[tour].barrieresR == 0)
        {
            return 2;
        }
        ///1.2. Un joueur est arrive au bout du plateau
        else if((player[tour].coordonneY_org == 0)&&(player[tour].coordonneY == 16))
        {
            return 1;
        }
        else if((player[tour].coordonneY_org == 16)&&(player[tour].coordonneY == 0))
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    ///2. Partie a 4j
    else
    {
        ///2.1.1. Le joueur 1 est arrive au bout du plateau
        if(player[0].coordonneY == 16)
        {
            return 1;
        }
        ///2.1.2. Le joueur 2 est arrive au bout du plateau
        else if(player[1].coordonneX == 0)
        {
            return 1;
        }
        ///2.1.3. Le joueur 3 est arrive au bout du plateau
        else if(player[2].coordonneY == 0)
        {
            return 1;
        }
        ///2.1.4. Le joueur 4 est arrive au bout du plateau
        else if(player[3].coordonneX == 16)
        {
            return 1;
        }
        ///2.2. Un jour n'a plus de barriere
        else if(player[tour].barrieresR == 0)
        {
            return 2;
        }
        else
        {
            return -1;
        }
    }
    return -1;
}

///Determine si un  joueur lors d'une partie avec une IA
int gagner_ia(t_joueur player[4], t_IA ia, int tour)
{
    ///1. Test si victoire car plus de barriere
    if((player[0].barrieresR == 0)||(ia.barrieresR==0))
    {
        return 2;
    }
    ///2. Test si l'IA est arrivee au bout du plateau
    else if(ia.coordonneY == 0)
    {
        return 1;
    }
    ///3. Test si le joueur est arrive au bout du plateau
    else if(player[0].coordonneY == 16)
    {
        return 1;
    }
    ///4. Personne n'a gagne
    else
    {
        return -1;
    }
    return -1;
}
