#include "Header_Pierre.h"

void placer_barriere_v2(int mat[17][17])
{

    ///0. DDV
    ///0.1. Limites du plateau
    int XG_lim=4;
    int XD_lim=32;
    int YH_lim=3;
    int YB_lim=17;
    ///0.2. Rotation et coordonnées
    int r=0; //0 pour horizontal, 1 vertical
    int x=8;
    int y=7;
    ///0.3. Booleen justifiant la pose de la barriere
    int valid_pose = 0;

    ///1. Deplacement de la barriere
    while(valid_pose == 0)
    {
        if (r==0)
        {
            Color(4,0);
            gotoligcol(y,x);
            printf("%c%c%c%c%c%c%c",0xCD, 0xCD, 0xCD, 0xCE, 0xCD, 0xCD, 0xCD); //ligne horizontale
            int touche = getch();
            if (touche==114)//"r"
            {
                r=1;
                Color(4,0);
                gotoligcol(y-1,x+3);
                printf("%c",0xBA);
                gotoligcol(y,x+3);
                printf("%c",0xCE);
                gotoligcol(y+1,x+3);
                printf("%c",0xBA);

                gotoligcol(y,x);
                Color(10,0);
                printf("%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4);

            }
            else if (touche == 0x48&&y!=YH_lim)//fleche haut
            {
                Color(10,0);
                gotoligcol(y,x);
                printf("%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4);
                y=y-2;
            }
            else if (touche == 0x50 && y!=YB_lim)//fleche bas
            {
                Color(10,0);
                gotoligcol(y,x);
                printf("%c%c%c%c%c%c%c",0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4);
                y=y+2;
            }
            else if (touche == 0x4B && x!=XG_lim)//fleche gauche
            {
                Color(10,0);
                gotoligcol(y,x+3);
                printf("%c%c%c%c",0xC5,0xC4,0xC4,0xC4);
                x=x-4;
            }
            else if (touche == 0x4D && x!=XD_lim) //fleche droite
            {
                Color(10,0);
                gotoligcol(y,x);
                printf("%c%c%c%c",0xC4,0xC4,0xC4,0xC5 );
                x=x+4;
            }
            else if (touche == 0x0D) //return (entree)
            {
                Color(10,0);
                gotoligcol(y,x-1);
                printf("%c%c%c%c%c%c%c",0xC4, 0xC5, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4); //ligne horizontale
                printf("%d, %d", x, y);
                system("PAUSE");
                mat[x-4][y-12] = 3;
                mat[x-4][y-11] = 3;
                mat[x-4][y-10] = 3;
                valid_pose = 1;
            }
        }
        else if (r==1)
        {
            Color(4,0);
            gotoligcol(y-1,x+3);
            printf("%c",0xBA);
            gotoligcol(y,x+3);
            printf("%c",0xCE);
            gotoligcol(y+1,x+3);
            printf("%c",0xBA);
            int touche = getch();
            if (touche==114)//"r"
            {
                r=0;
                Color(10,0);
                gotoligcol(y-1,x+3);
                printf("%c",0xB3);
                gotoligcol(y,x+3);
                printf("%c",0xC5);
                gotoligcol(y+1,x+3);
                printf("%c",0xB3);

                /*gotoligcol(x-1, y-1);
                Color(10,0);
                printf("%c%c%c%c%c%c%c",0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD);*/ //ligne horizontale
            }
            else if (touche == 0x48 && y!=YH_lim)//fleche haut
            {
                Color(10,0);
                gotoligcol(y-1,x+3);
                printf("%c",0xB3);
                gotoligcol(y,x+3);
                printf("%c",0xC5);
                gotoligcol(y+1,x+3);
                printf("%c",0xB3);
                y=y-2;
            }
            else if (touche == 0x50 && y!=YB_lim)//fleche bas
            {
                Color(10,0);
                gotoligcol(y-1,x+3);
                printf("%c",0xB3);
                gotoligcol(y,x+3);
                printf("%c",0xC5);
                gotoligcol(y+1,x+3);
                printf("%c",0xB3);
                y=y+2;
            }
            else if (touche == 0x4B && x!=XG_lim)//fleche gauche
            {
                Color(10,0);
                gotoligcol(y-1,x+3);
                printf("%c",0xB3);
                gotoligcol(y,x+3);
                printf("%c",0xC5);
                gotoligcol(y+1,x+3);
                printf("%c",0xB3);
                x=x-4;
            }
            else if (touche == 0x4D && x!= XD_lim) //fleche droite
            {
                Color(10,0);
                gotoligcol(y-1,x+3);
                printf("%c",0xB3);
                gotoligcol(y,x+3);
                printf("%c",0xC5);
                gotoligcol(y+1,x+3);
                printf("%c",0xB3);
                x=x+4;
            }
            else if (touche == 0x0D) //return (entree)
            {
                Color(10,0);
                gotoligcol(y-1,x+3);
                printf("%c",0xBA);
                gotoligcol(y,x+3);
                printf("%c",0xBA);
                gotoligcol(y+1,x+3);
                printf("%c",0xBA);

                mat[x+3][y-1] = 3;
                mat[x+3][y] = 3;
                mat[x+3][y+1] = 3;
                valid_pose = 1;
            }
        }
    }
}

