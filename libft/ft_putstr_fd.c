/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:23:14 by cdiks             #+#    #+#             */
/*   Updated: 2022/03/16 17:23:15 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		counter;

	if (!s)
		return ;
	counter = 0;
	while ((s[counter] != '\0') && (s))
	{
		write(fd, &s[counter], 1);
		counter++;
	}
}
