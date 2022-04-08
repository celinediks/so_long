/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:22:41 by cdiks             #+#    #+#             */
/*   Updated: 2022/03/16 17:22:42 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			counter;
	unsigned char	*x;
	unsigned char	*y;

	counter = 0;
	x = (unsigned char *)s1;
	y = (unsigned char *)s2;
	while (counter != n)
	{
		if (*x != *y)
			return (*x - *y);
		x++;
		y++;
		counter++;
	}
	return (0);
}
