/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:56:11 by cdiks             #+#    #+#             */
/*   Updated: 2022/04/11 10:59:57 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	highest_y(t_map *map)
{
	t_map	*temp;
	int		highest;

	temp = map;
	highest = temp->y;
	while (temp)
	{
		if (temp->y > highest)
			highest = temp->y;
		temp = temp->next;
	}
	return (highest);
}

int	highest_x(t_map *map)
{
	t_map	*temp;
	int		highest;

	temp = map;
	highest = temp->x;
	while (temp)
	{
		if (temp->x > highest)
			highest = temp->x;
		temp = temp->next;
	}
	return (highest);
}

void	check_ver_lines(t_map **map)
{
	t_map	*temp;

	temp = *map;
	while (temp->next != NULL)
	{
		if ((temp->next->x == 0 && temp->x != highest_x(*map)))
		{
			ft_putstr_fd("\033[0;31mInvalid map\033[0m\n", 1);
			exit(1);
		}
		temp = temp->next;
	}
	return ;
}

void	check_hor_lines(t_map **map)
{
	t_map	*temp;

	temp = *map;
	while (temp)
	{
		if (temp->next == NULL && temp->x != highest_x(*map))
		{
			ft_putstr_fd("\033[0;31mInvalid map\033[0m\n", 1);
			exit(1);
		}
		temp = temp->next;
	}
	return ;
}

void	check_valid_file(char *argv)
{
	char	*file;

	file = ft_strnstr(argv, ".ber", ft_strlen(argv));
	if (file)
	{
		if (ft_strlen(file) != 4)
		{
			ft_putstr_fd("\033[0;31mInvalid map, must end with .ber\033[0m\n", 1);
			exit(1);
		}
	}
	else if (!file)
	{
		ft_putstr_fd("\033[0;31mInvalid map, must end with .ber\033[0m\n", 1);
		exit(1);
	}
	return ;
}
