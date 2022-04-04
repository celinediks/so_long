/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:49:55 by cdiks             #+#    #+#             */
/*   Updated: 2022/04/04 11:43:20 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"
#include "./libft/libft.h"
#include "mlx.h"

int	close_window(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->mlx_window);
		exit(0);
	}
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == UP)
	{
		move(UP, &data);
		ft_putstr_fd("Move up\n", 1);
	}
	if (keycode == LEFT)
	{
		move(LEFT, &data);
		ft_putstr_fd("Move to the left\n", 1);
	}
	if (keycode == RIGHT)
	{
		move(RIGHT, &data);
		ft_putstr_fd("Move down\n", 1);
	}
	if (keycode == DOWN)
	{
		move(DOWN, &data);
		ft_putstr_fd("Move to the right\n", 1);
	}
	return (0);
}

void	move(int move, t_data *data)
{
	if (move == UP)
		return ;
	if (move == DOWN)
		return ;
	if (move == RIGHT)
		return ;
	if (move == LEFT)
		return ;
}
