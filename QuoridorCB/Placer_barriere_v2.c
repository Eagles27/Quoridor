#include "Header_Pierre.h"

/*

- mur verticale : 0xB3
- mur horizontal : 0xC4
- mur "+" : 0xC5
- mur verticale double : 0xBA
- mur horizontal double : 0xCD
- mur "+" double : 0xCE
*/

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
    ///0.4. Coordonnees de placement
    int matx_hor;
    int maty_hor;
    int matx_ver;
    int maty_ver;

    ///1. Deplacement de la barriere
    while(valid_pose == 0)
    {
        if (r==0)
        {
            //Coordonnees dans la matrive
            maty_hor = y-2;
            matx_hor = (x/2)-2;

            Color(4,0);
            gotoligcol(y,x);
            printf("%c%c%c%c%c%c%c",0xCD, 0xCD, 0xCD, 0xCE, 0xCD, 0xCD, 0xCD); //ligne horizontale
            int touche = getch();
            if (touche==114)//"r"
            {
                r=1;
                Color(4,0);
                if(mat[maty_hor][matx_hor]==1)
                {
                    Color(10,0);
                    gotoligcol(y,x);
                    printf("%c%c%c",0xC4,0xC4,0xC4);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y,x);
                    printf("%c%c%c",0xCD,0xCD,0xCD);
                }
                if(mat[maty_hor][matx_hor+1]==1){
                    Color(10,0);
                    gotoligcol(y,x+3);
                    printf("%c%c%c",0xC5);
                }
                else{
                    Color(4,0);
                    gotoligcol(y,x+3);
                    printf("%c%c%c",0xCE);
                }
                if(mat[maty_hor][matx_hor+2]==1){
                    Color(10,0);
                    gotoligcol(y,x+4);
                    printf("%c%c%c",0xC4,0xC4,0xC4);
                }
                else{
                    Color(4,0);
                    gotoligcol(y,x+4);
                    printf("%c%c%c",0xCD,0xCD,0xCD);
                }

            }
            else if (touche == 0x48&&y!=YH_lim)//fleche haut
            {
                if(mat[maty_hor][matx_hor]==1)
                {
                    Color(10,0);
                    gotoligcol(y,x);
                    printf("%c%c%c",0xC4,0xC4,0xC4);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y,x);
                    printf("%c%c%c",0xCD,0xCD,0xCD);
                }
                if(mat[maty_hor][matx_hor+1]==1){
                    Color(10,0);
                    gotoligcol(y,x+3);
                    printf("%c%c%c",0xC5);
                }
                else{
                    Color(4,0);
                    gotoligcol(y,x+3);
                    printf("%c%c%c",0xCE);
                }
                if(mat[maty_hor][matx_hor+2]==1){
                    Color(10,0);
                    gotoligcol(y,x+4);
                    printf("%c%c%c",0xC4,0xC4,0xC4);
                }
                else{
                    Color(4,0);
                    gotoligcol(y,x+4);
                    printf("%c%c%c",0xCD,0xCD,0xCD);
                }

                y=y-2;
            }
            else if (touche == 0x50 && y!=YB_lim)//fleche bas
            {
                if(mat[maty_hor][matx_hor]==1)
                {
                    Color(10,0);
                    gotoligcol(y,x);
                    printf("%c%c%c",0xC4,0xC4,0xC4);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y,x);
                    printf("%c%c%c",0xCD,0xCD,0xCD);
                }
                if(mat[maty_hor][matx_hor+1]==1){
                    Color(10,0);
                    gotoligcol(y,x+3);
                    printf("%c%c%c",0xC5);
                }
                else{
                    Color(4,0);
                    gotoligcol(y,x+3);
                    printf("%c%c%c",0xCE);
                }
                if(mat[maty_hor][matx_hor+2]==1){
                    Color(10,0);
                    gotoligcol(y,x+4);
                    printf("%c%c%c",0xC4,0xC4,0xC4);
                }
                else{
                    Color(4,0);
                    gotoligcol(y,x+4);
                    printf("%c%c%c",0xCD,0xCD,0xCD);
                }

                y=y+2;
            }
            else if (touche == 0x4B && x!=XG_lim)//fleche gauche
            {
                if(mat[maty_hor][matx_hor]==1)
                {
                    Color(10,0);
                    gotoligcol(y,x);
                    printf("%c%c%c",0xC4,0xC4,0xC4);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y,x);
                    printf("%c%c%c",0xCD,0xCD,0xCD);
                }
                if(mat[maty_hor][matx_hor+1]==1){
                    Color(10,0);
                    gotoligcol(y,x+3);
                    printf("%c%c%c",0xC5);
                }
                else{
                    Color(4,0);
                    gotoligcol(y,x+3);
                    printf("%c%c%c",0xCE);
                }
                if(mat[maty_hor][matx_hor+2]==1){
                    Color(10,0);
                    gotoligcol(y,x+4);
                    printf("%c%c%c",0xC4,0xC4,0xC4);
                }
                else{
                    Color(4,0);
                    gotoligcol(y,x+4);
                    printf("%c%c%c",0xCD,0xCD,0xCD);
                }

                x=x-4;
            }
            else if (touche == 0x4D && x!=XD_lim) //fleche droite
            {
                if(mat[maty_hor][matx_hor]==1)
                {
                    Color(10,0);
                    gotoligcol(y,x);
                    printf("%c%c%c",0xC4,0xC4,0xC4);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y,x);
                    printf("%c%c%c",0xCD,0xCD,0xCD);
                }
                if(mat[maty_hor][matx_hor+1]==1){
                    Color(10,0);
                    gotoligcol(y,x+3);
                    printf("%c%c%c",0xC5);
                }
                else{
                    Color(4,0);
                    gotoligcol(y,x+3);
                    printf("%c%c%c",0xCE);
                }
                if(mat[maty_hor][matx_hor+2]==1){
                    Color(10,0);
                    gotoligcol(y,x+4);
                    printf("%c%c%c",0xC4,0xC4,0xC4);
                }
                else{
                    Color(4,0);
                    gotoligcol(y,x+4);
                    printf("%c%c%c",0xCD,0xCD,0xCD);
                }

                x=x+4;
            }
            else if (touche == 0x0D) //return (entree)
            {
                Color(10,0);
                gotoligcol(y,x);
                printf("%c%c%c%c%c%c%c",0xC4, 0xC4, 0xC4, 0xC5, 0xC4, 0xC4, 0xC4); //ligne horizontale
                if((mat[maty_hor][matx_hor] != 3)&&(mat[maty_hor][matx_hor+1] != 3)&&(mat[maty_hor][matx_hor+2] != 3))
                {
                    mat[maty_hor][matx_hor] = 3;
                    mat[maty_hor][matx_hor+1] = 3;
                    mat[maty_hor][matx_hor+2] = 3;
                    valid_pose = 1;
                }
                else
                {
                    valid_pose = 0;
                }
            }
        }
        else if (r==1)
        {
            //Coordonnees dans la matrice
            matx_ver = (x/2)-1;
            maty_ver = y-1;

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
                if(mat[maty_ver-2][matx_ver]==1)
                {
                    Color(10,0);
                    gotoligcol(y-1,x+3);
                    printf("%c",0xB3);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y-1,x+3);
                    printf("%c",0xBA);
                }

                if(mat[maty_ver-1][matx_ver]==1)
                {
                    Color(10,0);
                    gotoligcol(y,x+3);
                    printf("%c",0xC5);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y,x+3);
                    printf("%c",0xCE);
                }

                if(mat[maty_ver][matx_ver]==1)
                {
                    Color(10,0);
                    gotoligcol(y+1,x+3);
                    printf("%c",0xB3);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y+1,x+3);
                    printf("%c",0xBA);
                }

                /*gotoligcol(x-1, y-1);
                Color(10,0);
                printf("%c%c%c%c%c%c%c",0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD);*/ //ligne horizontale
            }
            else if (touche == 0x48 && y!=YH_lim)//fleche haut
            {
                if(mat[maty_ver-2][matx_ver]==1)
                {
                    Color(10,0);
                    gotoligcol(y-1,x+3);
                    printf("%c",0xB3);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y-1,x+3);
                    printf("%c",0xBA);
                }

                if(mat[maty_ver-1][matx_ver]==1)
                {
                    Color(10,0);
                    gotoligcol(y,x+3);
                    printf("%c",0xC5);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y,x+3);
                    printf("%c",0xCE);
                }

                if(mat[maty_ver][matx_ver]==1)
                {
                    Color(10,0);
                    gotoligcol(y+1,x+3);
                    printf("%c",0xB3);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y+1,x+3);
                    printf("%c",0xBA);
                }

                y=y-2;
            }
            else if (touche == 0x50 && y!=YB_lim)//fleche bas
            {
                if(mat[maty_ver-2][matx_ver]==1)
                {
                    Color(10,0);
                    gotoligcol(y-1,x+3);
                    printf("%c",0xB3);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y-1,x+3);
                    printf("%c",0xBA);
                }

                if(mat[maty_ver-1][matx_ver]==1)
                {
                    Color(10,0);
                    gotoligcol(y,x+3);
                    printf("%c",0xC5);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y,x+3);
                    printf("%c",0xCE);
                }

                if(mat[maty_ver][matx_ver]==1)
                {
                    Color(10,0);
                    gotoligcol(y+1,x+3);
                    printf("%c",0xB3);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y+1,x+3);
                    printf("%c",0xBA);
                }

                y=y+2;
            }
            else if (touche == 0x4B && x!=XG_lim)//fleche gauche
            {
                if(mat[maty_ver-2][matx_ver]==1)
                {
                    Color(10,0);
                    gotoligcol(y-1,x+3);
                    printf("%c",0xB3);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y-1,x+3);
                    printf("%c",0xBA);
                }

                if(mat[maty_ver-1][matx_ver]==1)
                {
                    Color(10,0);
                    gotoligcol(y,x+3);
                    printf("%c",0xC5);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y,x+3);
                    printf("%c",0xCE);
                }

                if(mat[maty_ver][matx_ver]==1)
                {
                    Color(10,0);
                    gotoligcol(y+1,x+3);
                    printf("%c",0xB3);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y+1,x+3);
                    printf("%c",0xBA);
                }

                x=x-4;
            }
            else if (touche == 0x4D && x!= XD_lim) //fleche droite
            {
                if(mat[maty_ver-2][matx_ver]==1)
                {
                    Color(10,0);
                    gotoligcol(y-1,x+3);
                    printf("%c",0xB3);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y-1,x+3);
                    printf("%c",0xBA);
                }

                if(mat[maty_ver-1][matx_ver]==1)
                {
                    Color(10,0);
                    gotoligcol(y,x+3);
                    printf("%c",0xC5);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y,x+3);
                    printf("%c",0xCE);
                }

                if(mat[maty_ver][matx_ver]==1)
                {
                    Color(10,0);
                    gotoligcol(y+1,x+3);
                    printf("%c",0xB3);
                }
                else
                {
                    Color(4,0);
                    gotoligcol(y+1,x+3);
                    printf("%c",0xBA);
                }

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
                if((mat[maty_ver][matx_ver] != 3)&&(mat[maty_ver-1][matx_ver] != 3)&&(mat[maty_ver-2][matx_ver] != 3))
                {

                    mat[maty_ver][matx_ver] = 3;
                    mat[maty_ver-1][matx_ver] = 3;
                    mat[maty_ver-2][matx_ver] = 3;
                    valid_pose = 1;
                }
                else
                {
                    valid_pose = 0;
                }

            }
        }
    }
}

