#ifndef CUB3D_H
# define CUB3D_H
#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "/Users/laddie/libft/libft.h"
#include "get_next_line/get_next_line.h"

# define SCALE 30
# define p 3.14
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

typedef struct	plr //структура для игрока и луча
{
	float		x;
	float		y;
	// float		ray;
	// float		ray_x;
	// float		ray_y;
	float		dir;
	float		start;
	float		end;
	float		move_x;
	float		move_y;
}				  t_plr;

typedef struct  s_data 
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct sofa
{
	void		*mlx;
    void		*win;
    char        **map;
    t_resol     resol;
	t_data		data;
	t_plr		plr;
}               t_sofa;

void            parser_resol (t_sofa *sofa, char **map);
//void            my_mlx_pixel_put(t_data *data, int x, int y, int color);
int             draw_1(t_sofa *sofa);
void	fn_paint_map(t_sofa *sofa, t_data *img);

#endif