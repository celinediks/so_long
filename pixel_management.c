/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:49:19 by cdiks             #+#    #+#             */
/*   Updated: 2022/03/28 10:30:43 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include "mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_length + x \
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel_from_xpm(t_data *xpm, int x, int y)
{
	char	*dst;

	dst = xpm->address + (y * xpm->line_length + x * (xpm->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
