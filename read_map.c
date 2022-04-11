/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:12:39 by cdiks             #+#    #+#             */
/*   Updated: 2022/04/11 11:03:14 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>	

void	print_list(t_map *list)
{
	t_map	*temp;

	temp = list;
	while (temp)
	{
		ft_putstr_fd(&temp->data, 1);
		temp = temp->next;
	}
}

void	add_to_list(t_map **head, char line, int x, int y)
{
	t_map	*new;
	t_map	*last;

	new = malloc(sizeof(t_map));
	if (!new)
		return ;
	new->data = line;
	new->y = y;
	new->x = x;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

void	read_map(t_map **map, char *file)
{
	char	*line;
	int		fd;
	int		x;
	int		y;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("\033[0;31mFile does not excist\033[0m\n", 1);
		exit(1);
	}
	line = get_next_line(fd);
	y = 0;
	while (fd && line != '\0')
	{
		x = 0;
		while (*line && *line != '\n')
		{
			add_to_list(map, *line, x, y);
			line++;
			x++;
		}
		y++;
		line = get_next_line(fd);
	}
}

int	length(t_map *map)
{
	int		i;
	t_map	*temp;

	i = 0;
	temp = map;
	while (temp)
	{
		if (temp->y == 1 && temp->x == 0)
			return (i);
		i++;
		temp = temp->next;
	}
	return (0);
}

int	width(t_map *map)
{
	int		i;
	t_map	*temp;

	temp = map;
	i = 0;
	while (temp)
	{
		if (temp->x == 0)
			i++;
		temp = temp->next;
	}
	return (i);
}
