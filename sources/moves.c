/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:14:54 by msotelo-          #+#    #+#             */
/*   Updated: 2022/05/03 16:52:29 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	close_window(t_map *map)
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
	mlx_destroy_window(map->mlx, map->win);
	exit(EXIT_SUCCESS);
}

void	move_w(t_map *map)
{
	int	x;
	int	y;

	x = map->x - 1;
	y = map->y;
	if (map->map[x][y] == 'E' && map->c == 0)
		close_window(map);
	if (map->map[x][y] != '0' && map->map[x][y] != 'C')
		return ;
	else
	{
		map->x--;
		if (map->map[x][y] == 'C')
		{
			map->c--;
			map->map[x][y] = '0';
		}
		map->moves++;
		draw_map1(map);
		draw_hero(map);
		printf("Movimientos: %i\n", map->moves);
	}
}

void	move_a(t_map *map)
{
	int	x;
	int	y;

	x = map->x;
	y = map->y - 1;
	if (map->map[x][y] == 'E' && map->c == 0)
		close_window(map);
	if (map->map[x][y] != '0' && map->map[x][y] != 'C')
		return ;
	else
	{
		map->y--;
		if (map->map[x][y] == 'C')
		{
			map->c--;
			map->map[x][y] = '0';
		}
		map->moves++;
		draw_map1(map);
		draw_hero(map);
		printf("Movimientos: %i\n", map->moves);
	}
}

void	move_s(t_map *map)
{
	int	x;
	int	y;

	x = map->x + 1;
	y = map->y;
	if (map->map[x][y] == 'E' && map->c == 0)
		close_window(map);
	if (map->map[x][y] != '0' && map->map[x][y] != 'C')
		return ;
	else
	{
		map->x++;
		if (map->map[x][y] == 'C')
		{
			map->c--;
			map->map[x][y] = '0';
		}
		map->moves++;
		draw_map1(map);
		draw_hero(map);
		printf("Movimientos: %i\n", map->moves);
	}
}

void	move_d(t_map *map)
{
	int	x;
	int	y;

	x = map->x;
	y = map->y + 1;
	if (map->map[x][y] == 'E' && map->c == 0)
		close_window(map);
	if (map->map[x][y] != '0' && map->map[x][y] != 'C')
		return ;
	else
	{
		map->y++;
		if (map->map[x][y] == 'C')
		{
			map->c--;
			map->map[x][y] = '0';
		}
		map->moves++;
		draw_map1(map);
		draw_hero(map);
		printf("Movimientos: %i\n", map->moves);
	}
}
