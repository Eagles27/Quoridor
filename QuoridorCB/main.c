#include "Header_Pierre.h"

int main()
{
    ///0. DDV
    int depla[3] = {5, 4};
    int *plateau;

    ///1. Test
    plateau = genematrice();
    deplacement(depla, plateau);
}
