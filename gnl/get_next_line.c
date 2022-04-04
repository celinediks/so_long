/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:05:39 by cdiks             #+#    #+#             */
/*   Updated: 2022/03/16 17:05:41 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*check(char *s)
{
	if (!s)
		s = ft_calloc(1, sizeof(char));
	return (s);
}

int	newl(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (!str)
		return (i);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (i == len)
		return (-1);
	return (i + 1);
}

char	*read_file(int fd, char *n)
{
	int		i;
	char	buf[BUFFER_SIZE + 1];

	i = 1;
	buf[0] = '\0';
	while (i != 0 && newl(buf) == -1)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		buf[i] = '\0';
		n = ft_strjoin(n, buf);
	}
	if (!n[0])
	{
		free(n);
		return (NULL);
	}
	return (n);
}

char	*make_line(int fd)
{
	static char	*n;
	char		*temp;
	char		*line;

	n = read_file(fd, n);
	line = ft_substr(n, 0, newl(n));
	temp = ft_substr(n, newl(n), ft_strlen(n) - newl(n));
	free(n);
	n = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = make_line(fd);
	return (line);
}
