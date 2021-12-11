#include "Header_Pierre.h"

/*

- mur verticale : 0xB3
- mur horizontal : 0xC4
- mur "+" : 0xC5
- mur verticale double : 0xBA
- mur horizontal double : 0xCD
- mur "+" double : 0xCE
- rond : 0x0F
*/

void matrice_propre(int tab[17][17], t_joueur player[4], t_IA ia)//Comm OK
{
    ///0.0.pré-DDV
    char caractereJ[4];

    /// Attribution des tokens pour chaques joueurs

    for(int i=0;i<4;i++)
    {
        caractereJ[i] = player[i].jetonJ;
    }

    ///0. DDV
    int i,j;


    ///1. Affichage des lettres autour du graphique (horizontal)
    printf("    ");
    for (i = 0 ; i<17 ; i++) printf(" %c", 'A'+i);
    printf("\n\n");


    ///2. Affichage des lettres verticales
    for(i=0; i<17; i++)
    {
        printf("%c   ",'a'+i);
        for(j=0; j<17; j++)
        {
            if(i%2==1)
            {
                if(j%2==1)//Les doubles if permet de se placer exactement sur les croisements
                {
                    if(tab[i][j]==3){
                        printf("%c", 0xCE);//Mur croisement double
                    }
                    else{
                        printf("%c", 0xC5);//Mur croisement simple
                    }
                }

                else if(j%2==0)
                {
                    if(tab[i][j]==1){
                        //printf("j%2==0");
                        printf("%c%c%c", 0xC4, 0xC4, 0xC4);//Mur horizontal
                    }
                    else{
                        printf("%c%c%c", 0xCD, 0xCD, 0xCD);//Mur horizontal double
                    }
                }
            }
            else
            {
                ///Etapes de traduction
                if(tab[i][j]==0)
                {
                    printf("   ");//Rien dans la case
                }
                //Affichage du jeton du joueur à la bonne place
                else if(tab[i][j]==5){
                    printf(" %c ", caractereJ[0]);//J1
                }
                else if(tab[i][j]==7){
                    printf(" %c ", caractereJ[1]);//J2
                }
                else if(tab[i][j]==8){
                    printf(" %c ", caractereJ[2]);//J3
                }
                else if(tab[i][j]==9){
                    printf(" %c ", caractereJ[3]);//J4
                }
                else if(tab[i][j]==1){
                    printf("%c", 0xB3);//Mur vertical
                }
                else if(tab[i][j]==3){
                    printf("%c", 0xBA);//Mur vertical double
                }
                else if(tab[i][j]==4){
                    printf(" %c ", 0x01);//Case bonus
                }
                else if(tab[i][j]==6){
                    printf(" %c ", ia.jeton);//Jeton du joueur IA
                }
            }
        }
        printf("\n");//Va disparaitre soooooon <3
    }
}
