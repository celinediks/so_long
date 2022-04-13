/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:56:11 by cdiks             #+#    #+#             */
/*   Updated: 2022/04/13 11:33:20 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			end_game("\033[0;31mInvalid map\033[0m\n");
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
			end_game("\033[0;31mInvalid map\033[0m\n");
		temp = temp->next;
	}
	return ;
}

void	check_valid_file(char *argv)
{
	char	*file;
	int		len;

	file = ft_strnstr(argv, ".ber", ft_strlen(argv));
	len = ft_strlen(argv);
	if (file)
	{
		if (argv[len - 4] != '.' || argv[len - 3] != 'b'
			|| argv[len - 2] != 'e' || argv[len - 1] != 'r')
			end_game("\033[0;31mInvalid map, must end with .ber\033[0m\n");
	}
	else if (!file)
		end_game("\033[0;31mInvalid map, must end with .ber\033[0m\n");
	return ;
}
