#include "header_Pierre.h"

void Affichage_Du_Titre(int numero_ligne, int numero_colonne)
{
    Color(10,0);
    gotoligcol(numero_ligne,numero_colonne);
    printf("                                                           \n");
    gotoligcol(numero_ligne+1,numero_colonne);
    printf("                                 %c       %c                 \n",0x6F,0xBA);
    gotoligcol(numero_ligne+2,numero_colonne);
//                Q        |    U    |       O      |      R       | I |      D      |       O      |       R        |           Q                     |         U |            O                     |          R                       |  I |                 D                |                         O        |       R
    printf(" %c%c%c%c%c%c%c %c     %c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c \n",0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xBB,0xBB,0xC9,0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xBB,0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD,0xBA,0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xB9,0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xBB,0xC9,0xCD,0xCD,0xCD,0xCD,0xCD,0xCD);
    gotoligcol(numero_ligne+3,numero_colonne);
    printf(" %c     %c %c     %c %c     %c %c       %c %c     %c %c     %c %c       \n",0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA);
    gotoligcol(numero_ligne+4,numero_colonne);
    printf(" %c     %c %c     %c %c     %c %c       %c %c     %c %c     %c %c       \n",0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA,0xBA);
    gotoligcol(numero_ligne+5,numero_colonne);
    printf(" %c%c%c%c%c%c%c %c%C%C%C%C%c%c %c%c%c%c%c%c%c %c       %c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c       \n",0xC8,0xCD,0xCD,0xCD,0xCD,0xCD,0xB9,0xC8,0xCD,0xCD,0xCD,0xCD,0xCD,0xBC,0xC8,0xCD,0xCD,0xCD,0xCD,0xCD,0xBC,0xBC,0xBA,0xC8,0xCD,0xCD,0xCD,0xCD,0xCD,0xBC,0xC8,0xCD,0xCD,0xCD,0xCD,0xCD,0xBC,0xBC);
//                Q        |    U          |       O     |   R    | I|      D       |       O      | R   |           Q                      |           U                     |            O                     | R  |  I |                 D                |                    O             |  R
    gotoligcol(numero_ligne+6,numero_colonne);
    printf("       %c                                                   \n",0xBA);
    gotoligcol(numero_ligne+7,numero_colonne);
    printf("                                                           \n");
    Color(15,2);


}
