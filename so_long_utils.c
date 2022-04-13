/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:01:33 by cdiks             #+#    #+#             */
/*   Updated: 2022/04/13 11:03:13 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_and_close(int fd, char *line)
{
	free(line);
	close(fd);
}

void	check_fd(int fd)
{
	if (fd < 0)
		end_game("\033[0;31mFile does not exist\033[0m\n");
}

void	end_game(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

void	free_map(t_map *map)
{
	t_map	*temp;

	if (!map)
	{
		while (map)
		{
			temp = map->next;
			free(map);
			map = temp;
		}
		map = NULL;
	}
}

int	exit_game(char *ptr)
{
	if (ptr)
	{
		ft_putstr_fd(ptr, 1);
		exit(0);
	}
	exit(0);
}
