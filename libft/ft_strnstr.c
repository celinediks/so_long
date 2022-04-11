/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:23:44 by cdiks             #+#    #+#             */
/*   Updated: 2022/04/11 10:47:54 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (NULL);
	while ((haystack[i] != '\0') && (i < len))
	{
		while (((i + j) != (len) && (haystack[j + i] == needle[j])))
		{
			j++;
			if (j == (ft_strlen((needle))))
				return ((char *)(haystack + (i)));
		}
		j = 0;
		i++;
	}
	return (NULL);
}
