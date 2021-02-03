#include "cub3D.h"

void	raicacting(t_sofa *sofa)
{
	int x; //координата в пространстве камеры
	int i;
	int j;
	int y;

	x = 0;
	i = 0;
	j = 0;

	while (x < sofa->resol.r_one)
	{
		//вычисляем положение и направление
		sofa->plr.camera_x = 2 * x / (sofa->resol.r_one) - 1;
		sofa->plr.raydir_x = sofa->plr.dir_x + sofa->plr.plane_x * sofa->plr.camera_x;
		sofa->plr.raydir_y = sofa->plr.dir_y + sofa->plr.plane_y * sofa->plr.camera_x;
		sofa->maps.maps_x = sofa->plr.pos_x;
		sofa->maps.maps_y = sofa->plr.pos_y;
		sofa->maps.delta_dist_x = fabs(1 / sofa->plr.raydir_x);
		sofa->maps.delta_dist_y = fabs(1 / sofa->plr.raydir_y);
		sofa->maps.hit = 0;
		if (sofa->plr.raydir_x < 0) //вычисляем шаг и начальный side_dist
		{
			sofa->maps.step_x = -1;
			sofa->maps.side_dist_x = (sofa->plr.pos_x - sofa->maps.maps_x) * sofa->maps.delta_dist_x;
		}
		else
		{
			sofa->maps.step_x = 1;
			sofa->maps.side_dist_x = (sofa->maps.maps_x + 1.0 - sofa->plr.pos_x) * sofa->maps.delta_dist_x;
		}
		if (sofa->plr.raydir_y < 0)
		{
			sofa->maps.step_y = -1;
			sofa->maps.side_dist_y = (sofa->plr.pos_y - sofa->maps.maps_y) * sofa->maps.delta_dist_y;
		}
		else
		{
			sofa->maps.step_y = 1;
			sofa->maps.side_dist_y = (sofa->maps.maps_y + 1.0 - sofa->plr.pos_y) * sofa->maps.delta_dist_y;
		}
		// sofa->maps.hit = 0;
		while (sofa->maps.hit == 0)
		{
			if (sofa->maps.side_dist_x < sofa->maps.side_dist_y)
			{
				sofa->maps.side_dist_x += sofa->maps.delta_dist_x;
				sofa->maps.maps_x += sofa->maps.step_x;
				sofa->maps.side = 0;
			}
			else
			{
				sofa->maps.side_dist_y += sofa->maps.delta_dist_y;
				sofa->maps.maps_y += sofa->maps.step_y;
				sofa->maps.side = 1;
			}
			if (sofa->map[sofa->maps.maps_y][sofa->maps.maps_x] > '0')//== '1'
				sofa->maps.hit = 1;
		}
		if (sofa->maps.side == 0) //узнаем длинну от игрока до стены под прямым углом (перпендикулярно)
			sofa->maps.perp_wall_dist = (sofa->maps.maps_x - sofa->plr.pos_x + (1 - sofa->maps.step_x) / 2) / sofa->plr.raydir_x;
		else
			sofa->maps.perp_wall_dist = (sofa->maps.maps_y - sofa->plr.pos_y + (1 - sofa->maps.step_y) / 2) / sofa->plr.raydir_y;
		sofa->maps.line_heigh = sofa->resol.r_two / sofa->maps.perp_wall_dist;
		sofa->maps.draw_start = -sofa->maps.line_heigh / 2 + sofa->resol.r_two / 2;
		if (sofa->maps.draw_start < 0 )
			sofa->maps.draw_start = 0;
		sofa->maps.draw_end = sofa->maps.line_heigh / 2 + sofa->resol.r_two / 2;
		if (sofa->maps.draw_end >= sofa->resol.r_two)
			sofa->maps.draw_end = sofa->resol.r_two - 1;
		y = sofa->maps.draw_start;
		// = sofa->maps.draw_end;
		while (y < sofa->maps.draw_end)
		{
			my_mlx_pixel_put(&sofa->data, x, y, 0xFFAA11);
			y++;
		}
		x++;
	}
}