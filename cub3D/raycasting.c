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
	}
}