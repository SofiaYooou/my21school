int raicacting (int num, char **raycast)
{
	int x; //координата в пространстве камеры

	x = 0;

	while (x < sofa->Rone)
	{
		//вычисляем положение и направление
		sofa->plr.cameraX = 2 * x /double (sofa->Rone) - 1;
		sofa->plr.raydir_x = sofa->plr.dir_x + sofa->plr.plane_x * sofa->plr.camera_x
		sofa->plr.raydir_y = sofa->plr.dir_y + sofa->plr.plane_y * sofa->plr.camera_x
		sofa->map.map_x = sofa->plr.pos_x;
		sofa->map.map_y = sofa->plr.pos_y;
		sofa->map.delta_dist_x = fabs(1 / sofa->plr.raydir_x);
		sofa->map.delta_dist_y = fabs(1 / sofa->plr.raydir_y);
		if (sofa->plr.raydir_x < 0) //вычисляем шаг и начальный side_dist
		{
			sofa->map.step_x = -1;
			sofa->map.side_dist_x = (sofa->plr.pos_x - sofa->plr.map_x) * sofa->plr.delta_dist_x;
		}
		else
		{
			sofa->map.step_x = 1;
			sofa->map.side_dist_x = (sofa->plr.map_x + 1.0 - sofa->plr.pos_x) * sofa->plr.delta_dist_x;
		}
		if (sofa->plr.raydir_y < 0)
		{
			sofa->map.step_y = -1;
			sofa->map.side_dist_y = (sofa->plr.pos_y - sofa->plr.map_y) * sofa->plr.delta_dist_y;
		}
		else
		{
			sofa->map.step_y = 1;
			sofa->map.side_dist_y = (sofa->plr.map_y + 1.0 - sofa->plr.pos_y) * sofa->plr.delta_dist_y;
		}
		while (sofa->map.hit == 0)
		{
			if (sofa->map.side_dist_x < sofa->map.side_dist_y)
			{
				sofa->map.side_dist_x += sofa->map.delta_dist_x;
				sofa->map.map_x += sofa->map.step_x;
				sofa->map.side = 0;
			}
			else
			{
				sofa->map.side_dist_y += sofa->map.delta_dist_y;
				sofa->map.map_y += sofa->map.step_y;
				sofa->map.side = 1;
			}
			if (sofa->map[i][j] > '0')
				sofa->map.hit = 1;
		}

	}
}