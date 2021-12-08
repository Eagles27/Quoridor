#include "header_adrien.h"

int main()

{
    int i=0;
    int nombreJ=2;
    int numeroPlayer=1;

    t_joueur Jugador[4];

    ///1
    strcpy(Jugador[0].nomJ,"Pierre");
    Jugador[0].scoreP=0;
    //Jugador[0].jetonJ='@';
    Jugador[0].barrieresR=0;

    ///2
    strcpy(Jugador[1].nomJ,"Maxime");
    Jugador[1].scoreP=1;
    //Jugador[1].jetonJ='*';
    Jugador[1].barrieresR=1;

    ///3
    strcpy(Jugador[2].nomJ,"Adrien");
    Jugador[2].scoreP=2;
    //Jugador[2].jetonJ='#';
    Jugador[2].barrieresR=2;

    ///4
    strcpy(Jugador[3].nomJ,"Ravaut");
    Jugador[3].scoreP=3;
    //Jugador[3].jetonJ='&';
    Jugador[3].barrieresR=3;

    /*------------------------------------------------*/

    /*------------------------------------------------*/




    //genematrice(); //Affiche la matrice



    /*for(i=0;i<4;i++){

        choixPion(Jugador,i); //Prend la structure et le numero du token du joueur à set

        menucote(3,70,2,Jugador,i); //Affiche le menu dynamique sur le coté
        system("PAUSE");

    }*/

    Color(10,0);
    printf("                                                           \n");
    printf("                                 %c       %c                 \n",0x6F,0xBA);
//                Q        |    U    |       O      |      R       | I |      D      |       O      |       R        |           Q                     |         U |            O                     |          R                       |  I |                 D                |                         O        |       R
    printf(" %c%c%c%c%c%c%c %c     %c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c \n",0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xBB,0xBB,0xC9,0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xBB,0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBA,0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xB9,0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xBB,0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD);
    printf(" %c     %c %c     %c %c     %c %c       %c %c     %c %c     %c %c       \n",0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA);
    printf(" %c     %c %c     %c %c     %c %c       %c %c     %c %c     %c %c       \n",0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA);
    printf(" %c%c%c%c%c%c%c %c%C%C%C%C%c%c %c%c%c%c%c%c%c %c       %c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c       \n",0xC8,0xCD,0xCD,0xCD,0xCD,0xCD,0xB9,0xC8,0xCD,0xCD,0xCD,0xCD,0xCD,0xBC,0xC8,0xCD,0xCD,0xCD,0xCD,0xCD,0xBC,0xBC,0xBA,0xC8,0xCD,0xCD,0xCD,0xCD,0xCD,0xBC,0xC8,0xCD,0xCD,0xCD,0xCD,0xCD,0xBC,0xBC);
//                Q        |    U          |       O     |   R    | I|      D       |       O      | R   |           Q                      |           U                     |            O                     | R  |  I |                 D                |                    O             |  R
    printf("       %c                                                   \n",0xBA);
printf("                                                           \n");
Color(15,0);
}
