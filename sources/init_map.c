/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:00:40 by msotelo-          #+#    #+#             */
/*   Updated: 2022/05/05 17:09:11 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_pointer(t_map *map)
{
	int x;
	
	x = 0;
	if (map->hero == 0x0 || map->floor == 0x0 || map->wall == 0x0 || 
		map->exit == 0x0 || map->colec == 0x0)
	{
		while (map->map[x])
		{
			free(map->map[x]);
			x++;
		}
		free(map->map);
		printf("Error!\n Access denied\n");
		exit(EXIT_FAILURE);
	}
	else
		return ;
}

void	locate_hero(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->h)
	{
		y = 0;
		while (y < map->w)
		{
			if (map->map[x][y] == 'P')
			{
				map->x = x;
				map->y = y;
				map->map[x][y] = '0';
			}
			y++;
		}
		x++;
	}
	return ;
}

int	close_x(t_map *map)
{
	int	x;

	x = 0;
	while (map->map[x])
	{
		free(map->map[x]);
		x++;
	}
	free(map->map);
	mlx_destroy_image(map->mlx, map->exit);
	mlx_destroy_image(map->mlx, map->floor);
	mlx_destroy_image(map->mlx, map->wall);
	mlx_destroy_image(map->mlx, map->hero);
	mlx_destroy_image(map->mlx, map->colec);
	exit(EXIT_SUCCESS);
}

int	key_hook_movement(int keycode, t_map *map)
{
	if (keycode == 0)
	{
		move_a(map);
	}
	else if (keycode == 13)
	{
		move_w(map);
	}
	else if (keycode == 1)
	{
		move_s(map);
	}
	else if (keycode == 2)
	{
		move_d(map);
	}
	else if (keycode == 53)
	{
		close_window(map);
	}
	return (0);
}

void	init_map(t_map *map)
{
	char	*path[5];
	int		width;
	int		height;

	path[0] = "sprites/hero.xpm";
	path[1] = "sprites/floor_clown8.xpm";
	path[2] = "sprites/wall_clown1.xpm";
	path[3] = "sprites/colect_clown.xpm";
	path[4] = "sprites/puerta1.xpm";
	map->moves = 0;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->w * 32, map->h * 32, "so_long");
	map->hero = mlx_xpm_file_to_image(map->mlx, path[0], &width, &height);
	map->floor = mlx_xpm_file_to_image(map->mlx, path[1], &width, &height);
	map->wall = mlx_xpm_file_to_image(map->mlx, path[2], &width, &height);
	map->colec = mlx_xpm_file_to_image(map->mlx, path[3], &width, &height);
	map->exit = mlx_xpm_file_to_image(map->mlx, path[4], &width, &height);
	check_pointer(map);
	locate_hero(map);
	map->c = draw_map1(map);
	draw_hero(map);
	mlx_hook(map->win, 2, 1L << 0, key_hook_movement, map);
	mlx_hook(map->win, 17, 0L, close_x, map);
	mlx_loop(map->mlx);
}
