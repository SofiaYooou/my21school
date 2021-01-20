#include <mlx.h>
#include "cub3D.h"


void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    scale_map(t_data *img, int x, int y, int color)
{
	// int scale;
	int i;
	int j;

	// SCALE = 30;
	x *= SCALE;
	y *= SCALE;
	i = y;
	j = x;
	while (i < (y + SCALE))
	{
		j = x;
		while (j < (x + SCALE))
		{
			my_mlx_pixel_put(img, j, i, color);
			j++;
		}
		i++;
	}
}

void    scale_plr(t_data *img, float x, float y, int color)
{
	// int scale;
	float i;
	float j;

	// scale = 30;
	x *= SCALE;
	y *= SCALE;
	i = y;
	j = x;
	while (i < (y + SCALE))
	{
		j = x;
		while (j < (x + SCALE))
		{
			my_mlx_pixel_put(img, j, i, color);
			j += 1.0;
		}
	i += 1.0;
	}
}

void    scale_ray(t_data *img, float x, float y, int color)
{
	// int scale;
	float i;
	float j;

	// scale = 30;
	x *= SCALE;
	y *= SCALE;
	i = y;
	j = x;
	while (i < (y + SCALE))
	{
		j = x;
		while (j < (x + SCALE))
		{
			my_mlx_pixel_put(img, j, i, color);
			j += 1.0;
		}
	i += 1.0;
	}
}

void	ft_cast_ray(t_sofa *sofa)
{
	t_plr	ray = sofa->plr; // задаем координаты луча равные координатам игрока

	ray.x *= SCALE;
	ray.y *= SCALE;
	while (sofa->map[(int)(ray.y / SCALE)][(int)((ray.x / 2) / SCALE)] != '1')
	{
		ray.x += cos(ray.dir);
		ray.y += sin(ray.dir);
		mlx_pixel_put(sofa->mlx, sofa->win, ray.x, ray.y, 0xCAFF33);
	}
}

int		exitb(int keycode, t_sofa *sofa)
{
	exit(0);
	return (1);
}

void	fn_paint_map(t_sofa *sofa, t_data *img)
{
	int     i;
    int     j;

	i = 8;
    j = 0;
	while (sofa->map[i])
    {
        while (sofa->map[i][j])
        {
            if (sofa->map[i][j] == '1')
			{
            	scale_map(img, j, i, 0x33FFB5);
			}
			if (sofa->map[i][j] == '0')
				scale_map(img, j, i, 0);
			if (sofa->map[i][j] == 'N')
			{
				sofa->plr.x = j;
				sofa->plr.y = i;
				sofa->map[i][j] = '0';
			}
			j++;
        }
        j = 0;
        i++;
    }
	// mlx_clear_window(sofa->mlx, sofa->win);
	
	scale_plr(img, sofa->plr.x + sofa->plr.move_x, sofa->plr.y + sofa->plr.move_y, 0x338AFF);
	mlx_put_image_to_window(sofa->mlx, sofa->win, sofa->data.img, 0, 0);
}

int		key_hook(int keycode, t_sofa *sofa)
{
	// printf("keycode = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 13 || keycode == 126) //up
	{
		sofa->plr.y -= 0.1;
	}
	if (keycode == 1 || keycode == 125) //down
	{
		sofa->plr.y += 0.1;
	}
	if (keycode == 0 || keycode == 123) //left
	{
		sofa->plr.x -= 0.1;
	}
	if (keycode == 2 || keycode == 124) //right
	{
		sofa->plr.x += 0.1;
	}
	mlx_clear_window(sofa->mlx, sofa->win);
	fn_paint_map(sofa,  &sofa->data);
	ft_cast_ray(sofa);
	return (0);
}

int     draw_1(t_sofa *sofa)
{
    // void    *mlx;
    // void    *mlx_win;
    // t_data  img;

    sofa->mlx = mlx_init();
    sofa->win = mlx_new_window(sofa->mlx, sofa->resol.Rone, sofa->resol.Rtwo, "SOFA");
    sofa->data.img = mlx_new_image(sofa->mlx, sofa->resol.Rone, sofa->resol.Rtwo);
    sofa->data.addr = mlx_get_data_addr(sofa->data.img, &sofa->data.bits_per_pixel, &sofa->data.line_length,
                                 &sofa->data.endian);
	sofa->plr.move_y = 0;
	sofa->plr.move_x = 0;
	fn_paint_map(sofa, &sofa->data);
	ft_cast_ray(sofa);
	mlx_hook(sofa->win, 2, 0, key_hook, sofa);
	mlx_hook(sofa->win, 17, 0, exitb, sofa);
    mlx_loop(sofa->mlx);
	printf("%d\n", sofa->resol.Rone);
	printf("%d\n", sofa->resol.Rtwo);
    return(0);
}