/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:29:08 by msotelo-          #+#    #+#             */
/*   Updated: 2022/05/05 15:17:42 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_map4(char **map, int w, int h, int i)
{
	int	j;
	int	count[3];

	i = 0;
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (i <= h)
	{
		j = 0;
		while (j <= w)
		{
			if (map[i][j] == 'P')
				count[0]++;
			if (map[i][j] == 'C')
				count[1]++;
			if (map[i][j] == 'E')
				count[2]++;
			j++;
		}
		i++;
	}
	if (count[0] != 1 || count[1] <= 0 || count[2] != 1)
		return (-1);
	return (1);
}

int	check_map3(char **map, int w, int h)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	while (i <= h)
	{
		j = 0;
		while (j <= w)
		{	
			if (i == 0 || i == h)
				if (map[i][j] != '1')
					return (-1);
			if (j == 0 || j == w)
				if (map[i][j] != '1')
					return (-1);
			if (ft_strchr("PEC01", map[i][j]) == NULL)
				return (-1);
			j++;
		}
		i++;
	}
	check = check_map4(map, w, h, i);
	return (check);
}

int	check_map2(char	*map_name)
{
	int		i;
	int		fd;
	char	*buf;

	i = 0;
	fd = open(map_name, O_RDONLY);
	buf = get_next_line(fd);
	if (buf)
		i = 1;
	else if (!buf)
		return (0);
	while (buf != NULL)
	{
		free(buf);
		i++;
		buf = get_next_line(fd);
	}
	free(buf);
	close(fd);
	return (i);
}

int	check_map1(char *map_name, t_map *map, int i, int fd)
{
	int		check;
	size_t	s;

	i = check_map2(map_name);
	if (i == 0 || i > 44)
		return (0);
	fd = open(map_name, O_RDONLY);
	map->map = (char **)malloc(sizeof(char *) * i);
	map->map[0] = get_next_line(fd);
	s = ft_strlen(map->map[0]);
	i = 0;
	while (map->map[i++] != NULL)
	{
		map->map[i] = get_next_line(fd);
		if ((s != ft_strlen(map->map[i]) && map->map[i] != NULL) || s > 81)
		{
			free_map(map, i);
			return (0);
		}
	}
	close(fd);
	check = check_map3(map->map, (int)(s - 2), (i - 2));
	map->w = s - 1;
	map->h = i - 1;
	return (check);
}

int	check_ber(char **argv, t_map *map)
{
	int		i;
	int		j;
	int		check;
	char	*s;

	j = 3;
	s = ".ber";
	i = ft_strlen(argv[1]);
	while (j >= 0)
	{
		if (argv[1][i - 1] != s[j])
			return (0);
		j--;
		i--;
	}
	check = check_map1(argv[1], map, i, j);
	return (check);
}
