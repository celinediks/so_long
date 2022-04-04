/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:48:47 by cdiks             #+#    #+#             */
/*   Updated: 2022/03/28 13:23:48 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"
#include "mlx.h"

t_data	initialize_game(t_map *map)
{
	t_data	data;

	data.mlx = mlx_init();
	data.mlx_window = mlx_new_window(data.mlx, length(map) * TILE_SIZE,
			width(map) * TILE_SIZE, "so_long");
	data.image = mlx_new_image(data.mlx, length(map) * TILE_SIZE,
			width(map) * TILE_SIZE);
	data.address = mlx_get_data_addr(data.image, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	mlx_hook(data.mlx_window, 2, 0, close_window, &data);
	mlx_key_hook(data.mlx_window, key_hook, &data);
	return (data);
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

void	get_addresses(t_data *data, t_xpm *xpm)
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
	t_data	data;
	t_map	*map;
	t_xpm	xpm;

	if (argc != 2)
		exit(1);
	map = NULL;
	read_map(&map, argv[1]);
	check_map(&map);
	data = initialize_game(map);
	initialize_images(&data, &xpm);
	get_addresses(&data, &xpm);
	draw_map(&data, map, &xpm);
	mlx_loop(data.mlx);
}
