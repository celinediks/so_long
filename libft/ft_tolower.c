/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:23:53 by cdiks             #+#    #+#             */
/*   Updated: 2022/03/16 17:23:54 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	int	counter;

	counter = 0;
	if ((c >= 'A') && (c <= 'Z'))
		c += 32;
	else
		return (c);
	return (c);
}
