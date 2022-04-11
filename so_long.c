/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:48:47 by cdiks             #+#    #+#             */
/*   Updated: 2022/04/11 15:32:11 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_hook(xpm->data.mlx_window, 17, (1L << 17), exit_game,
		"\033[0;34mexit game\033[0m\n");
	mlx_loop_hook(xpm->data.mlx, animate, xpm);
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
	xpm->collectible.cur_img = 0;
	xpm->exit.cur_img = 0;
	xpm->collectible.mlx[0].image = mlx_xpm_file_to_image(data->mlx,
			"./xpm/discount.xpm", &width, &height);
	xpm->collectible.mlx[1].image = mlx_xpm_file_to_image(data->mlx,
			"./xpm/discount1.xpm", &width, &height);
	xpm->exit.mlx[0].image = mlx_xpm_file_to_image(data->mlx,
			"./xpm/checkout.xpm", &width, &height);
	xpm->exit.mlx[1].image = mlx_xpm_file_to_image(data->mlx,
			"./xpm/checkout2.xpm", &width, &height);
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
	xpm->exit.mlx[0].address = mlx_get_data_addr(xpm->exit.mlx[0].image,
			&xpm->exit.mlx[0].bits_per_pixel, &xpm->exit.mlx[0].line_length,
			&xpm->exit.mlx[0].endian);
	xpm->exit.mlx[1].address = mlx_get_data_addr(xpm->exit.mlx[1].image,
			&xpm->exit.mlx[1].bits_per_pixel, &xpm->exit.mlx[1].line_length,
			&xpm->exit.mlx[1].endian);
	initialize_collectibles(xpm);
}

int	main(int argc, char **argv)
{
	t_xpm	xpm;

	if (argc != 2)
		exit(1);
	argv++;
	read_map(&xpm.map, *argv);
	check_map(&xpm.map, *argv);
	initialize_game(&xpm);
	initialize_images(&xpm.data, &xpm);
	get_addresses(&xpm);
	draw_map(&xpm);
	mlx_loop(xpm.data.mlx);
}
