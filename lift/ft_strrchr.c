/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:23:47 by cdiks             #+#    #+#             */
/*   Updated: 2022/03/16 17:24:35 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		counter;
	char	*x;

	x = (char *)s;
	counter = ft_strlen(x);
	while (counter > -1)
	{
		if ((char)c == x[counter])
			return (&x[counter]);
		counter--;
	}
	return (NULL);
}
