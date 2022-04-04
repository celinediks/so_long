/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:05:45 by cdiks             #+#    #+#             */
/*   Updated: 2022/03/16 17:05:46 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	int		*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (size * count));
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			counter;
	unsigned char	*x;

	x = (unsigned char *)s;
	counter = 0;
	while (counter != n)
	{
		x[counter] = '\0';
		counter++;
	}
}

size_t	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return (counter);
	while (str[counter])
		counter++;
	return (counter);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	counter;
	char	*sub;
	size_t	slen;

	counter = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	while (counter < len && start < slen)
	{
		sub[counter] = s[start + counter];
		counter++;
	}
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	counter;
	size_t	counter2;

	s1 = check(s1);
	counter = 0;
	counter2 = 0;
	s3 = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!s3)
	{
		free(s1);
		return (NULL);
	}
	while (s1[counter] != '\0')
	{
		s3[counter] = s1[counter];
		counter++;
	}
	while (s2[counter2] != '\0')
	{
		s3[counter + counter2] = s2[counter2];
		counter2++;
	}
	free(s1);
	return (s3);
}
