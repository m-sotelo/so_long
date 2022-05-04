/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:23:13 by msotelo-          #+#    #+#             */
/*   Updated: 2022/05/04 23:05:14 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_map(t_map *map, int i)
{
	int	x;

	x = 0;
	if (i == -1)
	{
		while (map->map[x])
		{
			free(map->map[x]);
			x++;
		}
		free(map->map);
	}
	if (i > 0)
	{
		while (x <= i)
		{
			free(map->map[x]);
			x++;
		}
		free(map->map);
	}
}

/*void	leaks( void )
{
	system( "leaks so_long" );
}*/

int	main(int argc, char **argv)
{
	int		i;
	int		x;
	t_map	map;

	x = 0;
	if (argc != 2)
	{
		printf("Error!\nIncorrect number of arguments\n");
		exit(0);
	}
	i = check_ber(argv, &map);
	if (i <= 0)
	{
		free_map(&map, i);
		printf("Error!\nMap shape or content is not correct\n");
		exit(EXIT_FAILURE);
	}
	init_map(&map);
}
