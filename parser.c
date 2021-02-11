#include "cub3D.h"

void	parser_resol (t_sofa *sofa, char *map)
{
    int i;

    i = 0;

    // while (map[i])
	// {
		// printf("%s", map[i]);
		if (map[i] == 'R')
    		sofa->resol.r = 1;
    	i++;
    	while (map[i] == ' ')
			i++;
		if (map[i] >= '0' && map[i] <= '9')
    		sofa->resol.r_one = ft_atoi(&map[i]);
		while (map[i] >= '0' && map[i] <= '9')
			i++;
    	while (map[i] == ' ')
    		i++;
    	if (map[i] >= '0' && map[i] <= '9')
    		sofa->resol.r_two = ft_atoi(&map[i]);
    	// i++;
	// }
}
// void	parser_pol(t_sofa *sofa, char **map)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 1;
//     while (map[j][i] == 'F' || map[j][i] == 'C')
//     {
//     i = 0;
//         if (map[j][i] == 'F')
//         {
//             sofa->resol.f = 1;
//             while (map[j][i] == ' ')
//                 i++;
//             if (map[j][i] >= '0' && map[j][i] <= '9')
//                 sofa->resol.fr = ft_atoi(&map[j][i]);
//             while (map[j][i] >= '0' && map[j][i] <= '9')
//                 i++;
//             if (map[j][i] == ',' || map[j][i] ' ')
//                 i++;
//             if (map[j][i] >= '0' && map[j][i] <= '9')
//                 sofa->resol.fg = ft_atoi(&map[j][i]);
//             while (map[j][i] >= '0' && map[j][i] <= '9')
//                 i++;
//             if (map[j][i] == ',')
//                 i++;
//             if (map[j][i] >= '0' && map[j][i] <= '9')
//                 sofa->resol.fb = ft_atoi(&map[j][i]);
//             while (map[j][i] >= '0' && map[j][i] <= '9')
//                 i++;
// 			sofa->resol.f_resol = (sofa->resol.fr << 16 | sofa->resol.fg << 8 | sofa->resol.fb)
//         }
//         else
//         {
//             sofa->resol.c = 1;
//             while (map[j][i] == ' ')
//                 i++;
//             if (map[j][i] >= '0' && map[1][i] <= '9')
//                 sofa->resol.cr = ft_atoi(&map[j][i]);
//             while (map[1][i] >= '0' && map[j][i] <= '9')
//                 i++;
//             if (map[j][i] == ',')
//                 i++;
//             if (map[j][i] >= '0' && map[1][i] <= '9')
//                 sofa->resol.cg = ft_atoi(&map[j][i]);
//             while (map[1][i] >= '0' && map[j][i] <= '9')
//                 i++;
//             if (map[j][i] == ',')
//                 i++;
//             if (map[j][i] >= '0' && map[1][i] <= '9')
//                 sofa->resol.cb = ft_atoi(&map[j][i]);
//             while (map[j][i] >= '0' && map[j][i] <= '9')
//                 i++;
//         }
//         j++;
// 		sofa->resol.c_resol = (sofa->resol.cr << 16 | sofa->resol.cg << 8 | sofa->resol.cb)
//     }

void	parse_direction(t_sofa *sofa, char **map)
{
	int	i;
    int j;

	j = 0;
	while (map[j])
	{
    	i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'N')
			{
				sofa->plr.dir_x = -1;
				sofa->plr.dir_y = 0;
				sofa->plr.plane_x = 0;
				sofa->plr.plane_y = 0.66;
			}
			if (map[j][i] == 'S')
			{
				sofa->plr.dir_x = 1;
				sofa->plr.dir_y = 0;
				sofa->plr.plane_x = 0;
				sofa->plr.plane_y = -0.66;
			}
			if (map[j][i] == 'E')
			{
				sofa->plr.dir_x = 0;
				sofa->plr.dir_y = 1;
				sofa->plr.plane_x = 0.66;
				sofa->plr.plane_y = 0;
			}
			if (map[j][i] == 'W')
			{
				sofa->plr.dir_x = 0;
				sofa->plr.dir_y = -1;
				sofa->plr.plane_x = -0.66;
				sofa->plr.plane_y = 0;
			}
			i++;		
		}
		j++;
	}
}

void		parser_main(t_sofa *sofa, char **map)
{
	int i;
    int j;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'R')
				parser_resol (sofa, map[j]); //sofa->map);
			// if (map[j][i] == 'F' || map[j][i] == 'C')
			// 	parser_pol (sofa, map[j]);
			if (map[j][i] == 'E' || map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'W')
			{
				sofa->plr.pos_x = j + 0.5;
				sofa->plr.pos_y = i + 0.5;
				parse_direction(sofa, sofa->map);
			}
			i++;
		}
		j++;
	}
}

int		main (int argc, char **argv)
{
    // char    *line;
    char    *buf;
    int     fd;
    int     num;
    int     len;
    t_sofa  *sofa;
    (void)argc;

    len = 0;
    if ((fd = open(argv[1], O_RDONLY)) < 0)
        return(0);
    while ((num = read(fd, &buf, 1)) > 0)
        len++;
    close(fd);
    if ((fd = open(argv[1], O_RDONLY)) < 0)
        return(0);
    if (!(buf = (char *)malloc(sizeof(char) * (len + 1))))
        return (0);
    num = read(fd, buf, len);
    buf[len] = '\0';
    if(!(sofa = (t_sofa*)malloc(sizeof(t_sofa))))
        return (0);
    sofa->map = ft_split(buf, '\n');
    free(buf);
    close(fd);
	// while(*sofa->map)
    // {
    //     printf("%s\n", *sofa->map);
    //     sofa->map++;
    // }
	parser_main(sofa, sofa->map);
	// parser_resol(sofa, sofa->map);
	// parse_position(sofa, sofa->map);	
    // printf("%d\n", sofa->resol.Rone);
    // printf("%d\n", sofa->resol.Rtwo);
    // printf("%d\n", sofa->resol.FR);
    // printf("%d\n", sofa->resol.FG);
    // printf("%d\n", sofa->resol.FB);
    // printf("%d\n", sofa->resol.CR);
    // printf("%d\n", sofa->resol.CG);
    // printf("%d\n", sofa->resol.CB);
    draw_1(sofa);
    // return(0);
}