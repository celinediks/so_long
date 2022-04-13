/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:47:58 by cdiks             #+#    #+#             */
/*   Updated: 2022/04/13 11:02:40 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_xpm *xpm)
{
	t_map	*temp;

	temp = xpm->map;
	while (temp)
	{
		draw_tile(temp->x, temp->y, &xpm->data, &xpm->floor.mlx);
		if (temp->data == WALL)
			draw_tile(temp->x, temp->y, &xpm->data, &xpm->wall.mlx);
		if (temp->data == COLLECT)
			draw_tile(temp->x, temp->y, &xpm->data,
				&xpm->collectible.mlx[xpm->collectible.cur_img]);
		if (temp->data == EXIT)
			draw_tile(temp->x, temp->y, &xpm->data,
				&xpm->exit.mlx[xpm->exit.cur_img]);
		draw_tile(xpm->player.x, xpm->player.y, &xpm->data, &xpm->player.mlx);
		temp = temp->next;
	}
	mlx_put_image_to_window(xpm->data.mlx, xpm->data.mlx_window,
		xpm->data.image, 0, 0);
}

void	draw_tile(int x, int y, t_data *data, t_data *item)
{
	int				row;
	int				col;
	unsigned int	color;

	row = 0;
	while (row < TILE_SIZE)
	{
		col = 0;
		while (col < TILE_SIZE)
		{
			color = get_pixel_from_xpm(item, col, row);
			my_mlx_pixel_put(data, col + (x * TILE_SIZE),
				row + (y * TILE_SIZE), color);
			col++;
		}
		row++;
	}
}

void	init_player(t_xpm *xpm)
{
	t_map	*temp;

	temp = xpm->map;
	while (temp)
	{
		if (temp->data == PLAYER)
		{
			xpm->player.y = temp->y;
			xpm->player.x = temp->x;
		}
		temp = temp->next;
	}
}

void	init_collectibles(t_xpm *xpm)
{
	int		c;
	t_map	*temp;

	c = 0;
	temp = xpm->map;
	while (temp)
	{
		if (temp->data == COLLECT)
			c++;
		temp = temp->next;
	}
	xpm->collectible.amount = c;
}
