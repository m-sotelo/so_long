/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 20:37:19 by msotelo-          #+#    #+#             */
/*   Updated: 2022/05/04 11:25:06 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	draw_hero(t_map *map)
{
	int	y;
	int	x;

	y = map->y;
	x = map->x;
	mlx_put_image_to_window(map->mlx, map->win, map->hero, y * 32, x * 32);
}

int	draw_map1(t_map *map)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	c = 0;
	while (x < map->h)
	{
		y = 0;
		while (y < map->w)
		{
			c = draw_map2(map, x, y, c);
			y++;
		}
		x++;
	}
	return (c);
}

int	draw_map2(t_map *map, int x, int y, int c)
{
	if (map->map[x][y] == '1')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->wall, y * 32, x * 32);
	}
	if (map->map[x][y] == '0')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->floor, y * 32, x * 32);
	}
	if (map->map[x][y] == 'C')
	{
		c++;
		mlx_put_image_to_window(map->mlx, map->win, map->floor, y * 32, x * 32);
		mlx_put_image_to_window(map->mlx, map->win, map->colec, y * 32, x * 32);
	}
	if (map->map[x][y] == 'E')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->floor, y * 32, x * 32);
		mlx_put_image_to_window(map->mlx, map->win, map->exit, y * 32, x * 32);
	}
	return (c);
}
