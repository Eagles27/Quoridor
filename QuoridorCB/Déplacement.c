/*Règles
- Un pion se déplace dans les quatres directions (haut, bas, gauche, droite)
- Un pion ne peut pas passer au dessus d'une barrière
- Si 2 joueurs, alors un pion peut sauter au dessus d'un autre seulement si il
n'y a pas de barriere entre lui et l'autre pion. Le pion saute dans la case qui
est dans la meme ligne. Si il y a une barriere entre l'autre pion et la case
d'atterissage alors il ira à droite ou à gauche.
- Si 4 joueurs, alors pas de sauts autorisés.
*/

#include "Header_Pierre.h"

void deplacement(int *dep, int *matrice)
{
    /// 0. DDV
    char choix;
    int valid_choix = 1;
    int valid_dep = 1;

    ///1. Affichage utilisateur
    while(valid_dep == 1)
    {
        while(valid_choix == 1)
        {
            system("cls");
            printf("Direction de deplacement (h, b, g, d) :\n");
            scanf("%c", &choix);
            if((choix=='h')||(choix=='b')||(choix=='g')||(choix=='d')||(choix=='H')||(choix=='B')||(choix=='G')||(choix=='D'))
            {
                valid_choix = 0;
            }
            else
            {
                system("cls");
                printf("Saisie erronee\n");
                printf("Direction de deplacement (h, b, g, d) :\n");
                scanf("%c", &choix);
            }
        }
        printf("choix termine\n");
        if(((choix=='h')||(choix=='H'))&&(dep[1]!=0)&&((matrice[dep[0]][dep[1]-1]!=2)||(matrice[dep[0]][dep[1]-1]!=3)))
        {
            dep[1] -= 2;
            valid_dep = 0;
        }
        else if(((choix=='b')||(choix=='B'))&&(dep[1]!=16))
        {
            dep[1] +=2;
            valid_dep = 0;
        }
        else if(((choix=='g')||(choix=='G'))&&(dep[0]!=0))
        {
            dep[0]-=2;
            valid_dep = 0;
        }
        else if(((choix=='d')||(choix=='D'))&&(dep[0]!=16))
        {
            dep[0]+=2;
            valid_dep = 0;
        }
        else
        {
            valid_choix = 1;
        }
    }
}
