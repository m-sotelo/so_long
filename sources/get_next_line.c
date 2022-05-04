/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:28:06 by msotelo-          #+#    #+#             */
/*   Updated: 2022/03/31 21:23:17 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	first_read(char **buf, char *res, int fd)
{
	ssize_t	i;

	res = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = read(fd, res, BUFFER_SIZE);
	if (i <= 0)
	{
		free(res);
		return ;
	}
	res[i] = '\0';
	*buf = ft_strdup(res);
	free(res);
}

char	*trim_line(char *res, char **buf, char	*aux)
{
	int		start;
	int		len;

	start = 0;
	len = 0;
	if (!*aux)
		return (NULL);
	while (*aux != '\n' && *aux)
	{
		aux++;
		start++;
	}
	start++;
	aux++;
	res = ft_substr(*buf, 0, start);
	while (*aux)
	{
		aux++;
		len++;
	}
	aux = ft_substr(*buf, start, len);
	free(*buf);
	*buf = aux;
	return (res);
}

char	*read_line(char **buf, char *res, int fd)
{
	ssize_t	i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ft_strchr(*buf, '\n') == NULL && *buf)
	{
		i = read(fd, res, BUFFER_SIZE);
		if (i == 0)
			break ;
		res[i] = '\0';
		*buf = ft_strjoin(*buf, res);
	}
	free(res);
	return (*buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*res;
	char		*aux;

	res = NULL;
	aux = NULL;
	if (!buf)
	{		
		first_read(&buf, res, fd);
		if (buf == NULL)
			return (NULL);
	}
	buf = read_line(&buf, res, fd);
	aux = buf;
	res = trim_line(res, &buf, aux);
	if (res == NULL)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	return (res);
}

/*void	puta( void ){

	system( "leaks a.out" );
}

int main()
{
	int	i;
	char *x;
	
	atexit( puta );
	x = NULL;
	i = 0;
	i  = open("nl.txt" , O_RDONLY);
	x = get_next_line(i);
	printf("esto es el final:%s", x);
	x = get_next_line(i);
	printf("esto es el fina2:%s", x);
//	x = get_next_line(i, 3);
//	printf("esto es el fina3:%s", x);
}*/
