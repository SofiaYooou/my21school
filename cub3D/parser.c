#include "cub3D.h"

void parser_resol (t_sofa *sofa, char **map)
{
    int i;
    int j;

    i = 0;
	j = 1;

    if (map[j][i] == 'R')
        sofa->resol.R = 1;
    i++;
    while (map[j][i] == ' ')
        i++;
    if (map[j][i] >= '0' && map[j][i] <= '9')
        sofa->resol.Rone = ft_atoi(&map[0][i]);
        i++;
    if (map[j][i] == ' ')
        i++;
    if (map[0][i] >= '0' && map[0][i] <= '9')
        sofa->resol.Rtwo = ft_atoi(&map[0][i]);
        i++;
    //i = 0;
    // j = 1;
    // while (map[j][i] == 'F' || map[j][i] == 'C')
    // {
    // i = 0;
    //     if (map[j][i] == 'F')
    //     {
    //         sofa->resol.F = 1;
    //         while (map[j][i] == ' ')
    //             i++;
    //         if (map[j][i] >= '0' && map[j][i] <= '9')
    //             sofa->resol.FR = ft_atoi(&map[j][i]);
    //         while (map[j][i] >= '0' && map[j][i] <= '9')
    //             i++;
    //         if (map[j][i] == ',')
    //             i++;
    //         if (map[j][i] >= '0' && map[j][i] <= '9')
    //             sofa->resol.FG = ft_atoi(&map[j][i]);
    //         while (map[j][i] >= '0' && map[j][i] <= '9')
    //             i++;
    //         if (map[j][i] == ',')
    //             i++;
    //         if (map[j][i] >= '0' && map[j][i] <= '9')
    //             sofa->resol.FB = ft_atoi(&map[j][i]);
    //         while (map[j][i] >= '0' && map[j][i] <= '9')
    //             i++;
    //     }
    //     else
    //     {
    //         sofa->resol.C = 1;
    //         while (map[j][i] == ' ')
    //             i++;
    //         if (map[j][i] >= '0' && map[1][i] <= '9')
    //             sofa->resol.CR = ft_atoi(&map[j][i]);
    //         while (map[1][i] >= '0' && map[j][i] <= '9')
    //             i++;
    //         if (map[j][i] == ',')
    //             i++;
    //         if (map[j][i] >= '0' && map[1][i] <= '9')
    //             sofa->resol.CG = ft_atoi(&map[j][i]);
    //         while (map[1][i] >= '0' && map[j][i] <= '9')
    //             i++;
    //         if (map[j][i] == ',')
    //             i++;
    //         if (map[j][i] >= '0' && map[1][i] <= '9')
    //             sofa->resol.CB = ft_atoi(&map[j][i]);
    //         while (map[j][i] >= '0' && map[j][i] <= '9')
    //             i++;
    //     }
    //     j++;
    // }
}

void parse_direction(t_sofa *sofa, char **map)
{
	int i;
    int j;

	j = 0;
	while (map[j])
	{
    	i = 0;
		while (map[j][i])
		{
			if (map[j][i] >= 'N')
			{
				sofa->plr.posX = j;
				sofa->plr.posY = i;
				sofa->plr.dirX = -1;
				sofa->plr.dirY = 0;
				sofa->plr.planeX = -0.66;
				sofa->plr.planeY = 0;
			}
			if (map[j][i] >= 'S')
			{
				j += 0.5;
				i += 0.5;
				j = sofa->plr.posX;
				i = sofa->plr.posY;
				sofa->plr.dirX = 1;
				sofa->plr.dirY = 0;
				sofa->plr.planeX = 0.66;
				sofa->plr.planeY = 0;
			}
			if (map[j][i] >= 'E')
			{
				j += 0.5;
				i += 0.5;
				j = sofa->plr.posX;
				i = sofa->plr.posY;
				sofa->plr.dirX = 0;
				sofa->plr.dirY = 1;
				sofa->plr.planeX = 0;
				sofa->plr.planeY = 0.66;
			}
			if (map[j][i] >= 'W')
			{
				j += 0.5;
				i += 0.5;
				j = sofa->plr.posX;
				i = sofa->plr.posY;	
				sofa->plr.dirX = 0;
				sofa->plr.dirY = -1;
				sofa->plr.planeX = 0;
				sofa->plr.planeY = -0.66;
			}
			i++;		
		}
	j++;
	}
}

int parser_main(t_sofa *sofa, char **map)
{
	while(map[i][j] != '\0')
	{
		if (map[0][i] == 'R')
			parser_resol (sofa, sofa->map);
		if (map[j][i] >= 'E' || map[j][i] >= 'N' || map[j][i] >= 'S' || map[j][i] >= 'W')
			sofa->plr.pos_x = j;
			sofa->plr.pos_y = i;
			parse_direction(sofa, sofa->map);
	}
}

int main (int argc, char **argv)
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