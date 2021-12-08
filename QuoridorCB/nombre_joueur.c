#include "Header_Pierre.h"

int nombre_joueur()
{
    int choix = -1;

    Color(15,0);
    system("cls");
    Color(15,0);//OK

    do
    {
        if((choix != 1)&&(choix != 2))
        {
            Color(15,2);
            gotoligcol(10,50);
            printf("                    ");
            gotoligcol(11,50);
            printf("   Saisir  1 ou 2   ");
            gotoligcol(12,50);
            printf("                    ");
        }


            Affichage_Du_Titre(1,35);
            Color(15,10);
            gotoligcol(13,50);
            printf("                    ");
            gotoligcol(14,50);
            printf("     1. 2 Joueurs   ");
            gotoligcol(15,50);
            printf("     2. 4 Joueurs   ");
            gotoligcol(16,50);
            printf("                    ");
            gotoligcol(17,50);
            scanf("%d",&choix);

    }
    while ((choix != 1)&&(choix != 2));


    if (choix == 1)
        return 2;

    else
        return 4;

}
