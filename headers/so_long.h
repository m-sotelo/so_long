/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:04:26 by msotelo-          #+#    #+#             */
/*   Updated: 2022/05/04 23:05:07 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	void	*wall;
	void	*floor;
	void	*colec;
	void	*exit;
	void	*hero;
	void	*win;
	void	*mlx;
	int		h;
	int		w;
	int		x;
	int		y;
	int		c;
	int		moves;
}	t_map;

int		check_ber(char **argv, t_map *map);
int		check_map1(char *map_name, t_map *map, int i, int fd);
int		check_map2(char *map_name);
int		check_map3(char **map, int w, int h);
int		check_map4(char **map, int w, int h, int i);
void	init_map(t_map *map);
void	move_w(t_map *map);
void	move_a(t_map *map);
void	move_s(t_map *map);
void	move_d(t_map *map);
void	draw_hero(t_map *map);
void	locate_hero(t_map *map);
void	close_window(t_map *map);
void	free_map(t_map *map, int i);
int		draw_map1(t_map *map);
int		draw_map2(t_map *map, int x, int y, int c);
int		key_hook_movement(int keycode, t_map *map);
int		close_x(t_map *map);
#endif
