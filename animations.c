/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:47:25 by cdiks             #+#    #+#             */
/*   Updated: 2022/04/11 15:35:20 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animate(t_xpm *xpm)
{
	animate_items(xpm);
	return (0);
}

void	animate_items(t_xpm *xpm)
{
	static int	i;

	if ((i % 30) == 3)
	{
		xpm->collectible.cur_img++;
		xpm->exit.cur_img++;
		i++;
	}
	if (xpm->collectible.cur_img == 2)
		xpm->collectible.cur_img = 0;
	if (xpm->exit.cur_img == 2)
		xpm->exit.cur_img = 0;
	i++;
	draw_map(xpm);
}

void	initialize_collectibles(t_xpm *xpm)
{
	xpm->collectible.mlx[0].address = \
		mlx_get_data_addr(xpm->collectible.mlx[0].image,
			&xpm->collectible.mlx[0].bits_per_pixel,
			&xpm->collectible.mlx[0].line_length,
			&xpm->collectible.mlx[0].endian);
	xpm->collectible.mlx[1].address = \
		mlx_get_data_addr(xpm->collectible.mlx[1].image,
			&xpm->collectible.mlx[1].bits_per_pixel,
			&xpm->collectible.mlx[1].line_length,
			&xpm->collectible.mlx[1].endian);
}
