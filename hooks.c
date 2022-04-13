/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:49:55 by cdiks             #+#    #+#             */
/*   Updated: 2022/04/13 11:03:08 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->mlx_window);
		end_game("\033[0;34mGame has ended \033[0m\n");
	}
	return (0);
}

int	check_action(t_xpm *xpm, int i, int j)
{
	t_map	*temp;

	temp = xpm->map;
	print_moves(xpm);
	init_collectibles(xpm);
	while (temp)
	{
		if (temp->x == i && temp->y == j && temp->data != WALL)
		{
			if (temp->data == COLLECT)
			{
				ft_putstr_fd("\033[0;35m35% discount, yay!\033[0m\n", 1);
				xpm->collectible.amount -= 1;
				temp->data = EMPTY;
			}
			if (temp->data == EXIT && xpm->collectible.amount == 0)
			{
				ft_putstr_fd("\033[0;34mThanks for shopping at Albert Heijn! \
					\033[0m\n", 1);
				exit(1);
			}
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int	key_hook(int keycode, t_xpm *xpm)
{
	if (keycode == UP)
	{
		if (!check_action(xpm, xpm->player.x, xpm->player.y - 1))
			xpm->player.y -= 1;
	}
	if (keycode == LEFT)
	{
		if (!check_action(xpm, xpm->player.x - 1, xpm->player.y))
			xpm->player.x -= 1;
	}
	if (keycode == RIGHT)
	{
		if (!check_action(xpm, xpm->player.x, xpm->player.y + 1))
			xpm->player.y += 1;
	}
	if (keycode == DOWN)
	{
		if (!check_action(xpm, xpm->player.x + 1, xpm->player.y))
			xpm->player.x += 1;
	}
	draw_map(xpm);
	return (0);
}

void	print_moves(t_xpm *xpm)
{
	xpm->moves++;
	ft_putstr_fd("Move number: ", 1);
	ft_putnbr_fd(xpm->moves, 1);
	ft_putstr_fd("\n", 1);
}
