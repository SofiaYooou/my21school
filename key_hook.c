#include "cub3D.h"

int	key_hook(int keycode, t_sofa *sofa)
{
	(void)keycode;
	(void)sofa;
	if (keycode == 53)
		exit(0);
	if (keycode == 13) //up
	{
		if (sofa->map[(int)(sofa->plr.pos_x + sofa->plr.dir_x * 0.1)][(int)sofa->plr.y])
			sofa->plr.pos_x += sofa->plr.dir_x * 0.1;
		if (sofa->map[(int)sofa->plr.pos_x][(int)(sofa->plr.y + sofa->plr.dir_y * 0.1)])
			sofa->plr.pos_y += sofa->plr.dir_y * 0.1;
	}
	// if (keycode == 1) //down
	// {
	// 	if (sofa->map[sofa->maps.maps_y][sofa->maps.maps_x])
	// 		sofa->plr.pos_x += sofa->plr.dir_x * 0.1
	// }
	// if (keycode == 0 || keycode == 123) //left
	// {
	// 	sofa->plr.x -= 0.1;
	// }
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