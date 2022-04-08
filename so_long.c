/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:48:47 by cdiks             #+#    #+#             */
/*   Updated: 2022/04/08 14:00:28 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"
#include "mlx.h"

void	initialize_game(t_xpm *xpm)
{
	xpm->data.mlx = mlx_init();
	xpm->data.mlx_window = mlx_new_window(xpm->data.mlx, length(xpm->map)
			* TILE_SIZE,
			width(xpm->map) * TILE_SIZE, "so_long");
	xpm->data.image = mlx_new_image(xpm->data.mlx, length(xpm->map) * TILE_SIZE,
			width(xpm->map) * TILE_SIZE);
	xpm->data.address = mlx_get_data_addr(xpm->data.image,
			&xpm->data.bits_per_pixel,
			&xpm->data.line_length, &xpm->data.endian);
	init_player(xpm);
	mlx_hook(xpm->data.mlx_window, 2, 0, close_window, &xpm->data);
	mlx_key_hook(xpm->data.mlx_window, key_hook, xpm);
	mlx_hook(xpm->data.mlx_window, 17, (1L << 17), close_window, &xpm->data);
}

void	initialize_images(t_data *data, t_xpm *xpm)
{
	int		width;
	int		height;

	xpm->floor.mlx.image = mlx_xpm_file_to_image(data->mlx, "./xpm/floor.xpm",
			&width, &height);
	xpm->wall.mlx.image = mlx_xpm_file_to_image(data->mlx, "./xpm/wall.xpm",
			&width, &height);
	xpm->player.mlx.image = mlx_xpm_file_to_image(data->mlx, "./xpm/basket.xpm",
			&width, &height);
	xpm->collectible.mlx.image = mlx_xpm_file_to_image(data->mlx,
			"./xpm/discount.xpm", &width, &height);
	xpm->exit.mlx.image = mlx_xpm_file_to_image(data->mlx, "./xpm/checkout.xpm",
			&width, &height);
}

void	get_addresses(t_xpm *xpm)
{
	xpm->floor.mlx.address = mlx_get_data_addr(xpm->floor.mlx.image,
			&xpm->floor.mlx.bits_per_pixel, &xpm->floor.mlx.line_length,
			&xpm->floor.mlx.endian);
	xpm->wall.mlx.address = mlx_get_data_addr(xpm->wall.mlx.image,
			&xpm->wall.mlx.bits_per_pixel, &xpm->wall.mlx.line_length,
			&xpm->wall.mlx.endian);
	xpm->player.mlx.address = mlx_get_data_addr(xpm->player.mlx.image,
			&xpm->player.mlx.bits_per_pixel, &xpm->player.mlx.line_length,
			&xpm->player.mlx.endian);
	xpm->collectible.mlx.address = mlx_get_data_addr(xpm->collectible.mlx.image,
			&xpm->collectible.mlx.bits_per_pixel,
			&xpm->collectible.mlx.line_length,
			&xpm->collectible.mlx.endian);
	xpm->exit.mlx.address = mlx_get_data_addr(xpm->exit.mlx.image,
			&xpm->exit.mlx.bits_per_pixel, &xpm->exit.mlx.line_length,
			&xpm->exit.mlx.endian);
}

int	main(int argc, char **argv)
{
	t_xpm	xpm;

	if (argc != 2)
		exit(1);
	read_map(&xpm.map, argv[1]);
	check_map(&xpm.map, argv[1]);
	initialize_game(&xpm);
	initialize_images(&xpm.data, &xpm);
	get_addresses(&xpm);
	draw_map(&xpm);
	mlx_loop(xpm.data.mlx);
}
