#include <mlx.h>
#include "cub3D.h"

void	clean_window(t_sofa *sofa)
{
	int	h;
	int	w;
	
	w = 0;
	while (w < sofa->resol.r_one)
	{
		h = 0;
		while (h < sofa->resol.r_two)
		{
			my_mlx_pixel_put(&sofa->data, w, h, 0x000000);
			h++;
		}
		w++;
	}
}

int	key_hook(int keycode, t_sofa *sofa)
{
// 	(void)keycode;
	clean_window(sofa);

// 	// printf("keycode = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 13) //up
	{
		// printf("%c\n",sofa->map[(int)(sofa->plr.pos_y + sofa->plr.dir_y * 0.1)][(int)sofa->plr.x]);
		// printf("%c\n", sofa->map[(int)sofa->plr.pos_y][(int)(sofa->plr.x + sofa->plr.dir_x * 0.1)]);
		if (sofa->map[(int)(sofa->plr.pos_x + sofa->plr.dir_x * 0.1)][(int)sofa->plr.pos_y] != '1')
			sofa->plr.pos_x += sofa->plr.dir_x * 0.1;
		if (sofa->map[(int)sofa->plr.pos_x][(int)(sofa->plr.pos_y + sofa->plr.dir_y * 0.1)] != '1')
			sofa->plr.pos_y += sofa->plr.dir_y * 0.1;
	}
	if (keycode == 1) //down
	{
			printf("keycode = %d\n", keycode);
		if (sofa->map[(int)(sofa->plr.pos_x - sofa->plr.dir_x * 0.1)][(int)sofa->plr.pos_y] != '1')
			sofa->plr.pos_x -= sofa->plr.dir_x * 0.1;
		if (sofa->map[(int)sofa->plr.pos_x][(int)(sofa->plr.pos_y - sofa->plr.dir_y * 0.1)] != '1')
			sofa->plr.pos_y -= sofa->plr.dir_y * 0.1;
	}
	printf("keycode = %d\n", keycode);
	if (keycode == 2) //right
	{
			printf("keycode = %d\n", keycode);
		if (sofa->map[(int)sofa->plr.pos_x][(int)(sofa->plr.pos_y - sofa->plr.dir_x * 0.1)] != '1')
			sofa->plr.pos_y -= sofa->plr.dir_x * 0.1;
		if (sofa->map[(int)(sofa->plr.pos_x + sofa->plr.dir_y * 0.1)][(int)sofa->plr.pos_y] != '1')
			sofa->plr.pos_x += sofa->plr.dir_y * 0.1;
	}
	if (keycode == 0) //left
	{
			printf("keycode = %d\n", keycode);
		if (sofa->map[(int)sofa->plr.pos_x][(int)(sofa->plr.pos_y + sofa->plr.dir_x * 0.1)] != '1')
			sofa->plr.pos_y += sofa->plr.dir_x * 0.1;
		if (sofa->map[(int)(sofa->plr.pos_x - sofa->plr.dir_y * 0.1)][(int)sofa->plr.pos_y] != '1')
			sofa->plr.pos_x -= sofa->plr.dir_y * 0.1;
	}
	if (keycode == 124) //rotation right
	{
		sofa->plr.old_dir_x = sofa->plr.dir_x;
		sofa->plr.dir_x = sofa->plr.dir_x * cos(-0.1) - sofa->plr.dir_y * sin(-0.1);
		sofa->plr.dir_y = sofa->plr.old_dir_x * sin(-0.1) + sofa->plr.dir_y * cos(-0.1);
		sofa->plr.old_plane_x = sofa->plr.plane_x;
		sofa->plr.plane_x = sofa->plr.plane_x * cos(-0.1) - sofa->plr.plane_y * sin(-0.1);
		sofa->plr.plane_y = sofa->plr.old_plane_x * sin(-0.1) + sofa->plr.plane_y * cos(-0.1);
	}
	if (keycode == 123) //rotation left
	{
		sofa->plr.old_dir_x = sofa->plr.dir_x;
		sofa->plr.dir_x = sofa->plr.dir_x * cos(0.1) - sofa->plr.dir_y * sin(0.1);
		sofa->plr.dir_y = sofa->plr.old_dir_x * sin(0.1) + sofa->plr.dir_y * cos(0.1);
		sofa->plr.old_plane_x = sofa->plr.plane_x;
		sofa->plr.plane_x = sofa->plr.plane_x * cos(0.1) - sofa->plr.plane_y * sin(0.1);
		sofa->plr.plane_y = sofa->plr.old_plane_x * sin(0.1) + sofa->plr.plane_y * cos(0.1);
	}

	raycasting(sofa);
	mlx_put_image_to_window(sofa->mlx, sofa->win, sofa->data.img, 0, 0);
	// 
	// if (keycode == 2) //right
	// {
	// 	sofa->plr.x += 0.1;
	// }
	// if (keycode == 126)
	// {
	// 	sofa->plr.dir -= 0.5;
	// }
	// if (keycode == 125)
	// {
	// 	sofa->plr.dir += 0.5;
	// }
	return(0);
}

int     draw_1(t_sofa *sofa)
{
    // void    *mlx;
    // void    *mlx_win;
    // t_data  img;

    sofa->mlx = mlx_init();
    sofa->win = mlx_new_window(sofa->mlx, sofa->resol.r_one, sofa->resol.r_two, "SOFA");
    sofa->data.img = mlx_new_image(sofa->mlx, sofa->resol.r_one, sofa->resol.r_two);
	mlx_put_image_to_window(sofa->mlx, sofa->win, sofa->data.img, 0, 0);
    sofa->data.addr = mlx_get_data_addr(sofa->data.img, &sofa->data.bits_per_pixel, &sofa->data.line_length,
                                 &sofa->data.endian);
	// sofa->plr.move_y = 0;
	// sofa->plr.move_x = 0;
	raycasting(sofa);
	// ft_cast_ray(sofa);
	// ft_cast_rays(sofa);
	mlx_put_image_to_window(sofa->mlx, sofa->win, sofa->data.img, 0, 0);
	mlx_hook(sofa->win, 2, 0, key_hook, sofa);
	// mlx_hook(sofa->win, 17, 0, exitb, sofa);
    mlx_loop(sofa->mlx);
	// printf("%d\n", sofa->resol.r_one);
	// printf("%d\n", sofa->resol.r_two);
    return(0);
}