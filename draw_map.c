/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:47:58 by cdiks             #+#    #+#             */
/*   Updated: 2022/03/28 13:39:18 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"

void	draw_map(t_data *data, t_map *map, t_xpm *xpm)
{
	t_map	*temp;

	temp = map;
	while (temp)
	{
		draw_tile(temp->x, temp->y, data, &xpm->floor.mlx);
		if (temp->data == WALL)
			draw_tile(temp->x, temp->y, data, &xpm->wall.mlx);
		if (temp->data == COLLECT)
			draw_tile(temp->x, temp->y, data, &xpm->collectible.mlx);
		else if (temp->data == EXIT)
			draw_tile(temp->x, temp->y, data, &xpm->exit.mlx);
		else if (temp->data == PLAYER)
		{
			draw_tile(temp->x, temp->y, data, &xpm->player.mlx);
			xpm->player.y = temp->y;
			xpm->player.x = temp->x;
		}
		temp = temp->next;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->image, 0, 0);
}

void	draw_tile(int x, int y, t_data *data, t_data *xpm)
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
			color = get_pixel_from_xpm(xpm, col, row);
			my_mlx_pixel_put(data, col + (x * TILE_SIZE),
				row + (y * TILE_SIZE), color);
			col++;
		}
		row++;
	}
}
