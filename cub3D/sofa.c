#include <mlx.h>
#include "cub3D.h"

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    scale_map(t_data *img, int x, int y)
{
	int scale;

	scale = 10;
	x *= scale;
	y *= scale;
	for (int i = y; i < y + scale; i++)
	{
		for (int j = x; j < x + scale; j++)
		{
			my_mlx_pixel_put(img, j, i, 0x00FF0000);
		}
	}
}

int		exitb(int keycode, t_sofa *sofa)
{
	exit(0);
	return (1);
}

int     draw_1(t_sofa *sofa)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    int     i;
    int     j;

    i = 0;
    j = 0;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    while (sofa->map[i])
    {
        while (sofa->map[i][j])
        {
            if (sofa->map[i][j] == '1')
            	scale_map(&img, j, i);
			j++;
        }
        j = 0;
        i++;
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 17, 0, exitb, sofa);
    mlx_loop(mlx);
    return(0);
}