#ifndef CUB3D_H
# define CUB3D_H
#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "/Users/laddie/libft/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct resol
{
    int         R;
    int         Rone;
    int         Rtwo;
    int         F;
    int         C;
    int         FR;
    int         FG;
    int         FB;
    int         CR;
    int         CG;
    int         CB;
}               t_resol;

typedef struct sofa
{
    char        **map;
    t_resol     resol;
}               t_sofa;

void            parser_resol (t_sofa *sofa, char **map);
//void            my_mlx_pixel_put(t_data *data, int x, int y, int color);
int             draw_1(t_sofa *sofa);

#endif