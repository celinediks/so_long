/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:51:08 by cdiks             #+#    #+#             */
/*   Updated: 2022/04/13 10:54:58 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_map **map, char *argv)
{	
	check_letters(map);
	check_wall(map);
	check_rectangle(map);
	check_other_chars(map);
	check_ver_lines(map);
	check_hor_lines(map);
	check_valid_file(argv);
}

void	check_letters(t_map **map)
{
	t_map	*temp;
	int		c;
	int		e;
	int		p;

	temp = *map;
	c = 0;
	e = 0;
	p = 0;
	while (temp)
	{
		if (temp->data == COLLECT)
			c++;
		else if (temp->data == EXIT)
			e++;
		else if (temp->data == PLAYER)
			p++;
		temp = temp->next;
	}
	if (c >= 1 && e == 1 && p == 1)
		return ;
	end_game("\033[0;31mInvalid map\033[0m\n");
}

void	check_wall(t_map **map)
{
	t_map	*temp;

	temp = *map;
	while (temp)
	{
		if ((temp->y == 0 && temp->data != WALL)
			|| (temp->x == 0 && temp->data != WALL))
			end_game("\033[0;31mInvalid map\033[0m\n");
		if (((temp->y == highest_y(*map) && temp->data != WALL))
			|| ((temp->x == highest_x(*map)) && temp->data != WALL))
			end_game("\033[0;31mInvalid map\033[0m\n");
		temp = temp->next;
	}
	return ;
}

void	check_rectangle(t_map **map)
{
	if (highest_y(*map) >= highest_x(*map))
		end_game("\033[0;31mInvalid map\033[0m\n");
	return ;
}

void	check_other_chars(t_map **map)
{
	t_map	*temp;

	temp = *map;
	while (temp)
	{
		if (temp->data == WALL || temp->data == EMPTY
			|| temp->data == COLLECT || temp->data == EXIT
			|| temp->data == PLAYER)
			temp = temp->next;
		else
			end_game("\033[0;31mInvalid map\033[0m\n");
	}
	return ;
}
