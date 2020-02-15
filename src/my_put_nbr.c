/*
** EPITECH PROJECT, 2018
** task07 Day03
** File description:
** my_put_nbr
*/

#include "node.h"


lu_t divisor(lu_t nb)
{
    lu_t i = 1;
    lu_t r = 10;

    if (nb < 0) {
        nb = nb * (-1);
    }
    while (!(r >= 0 && r <= 9)) {
        r = nb / i;
        i = i * 10;
    }
    i = i / 10;
    return (i);
}

int my_put_nbr(void *ptr)
{
    lu_t nb = (lu_t) ptr;
    lu_t i = divisor(nb);
    lu_t r = 1;
    char c;

    if (nb < 0){
        write(1, "-",1);
        nb = nb * (-1);
    }
    for (; i >= 1 ; i = i / 10) {
        r = nb / i;
        c = r + '0';
        write(1, &c, 1);
        nb = nb - (r * i);
    }
    write(1,"\n", 1);
    return (0);
}
