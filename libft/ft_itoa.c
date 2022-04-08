/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:21:03 by cdiks             #+#    #+#             */
/*   Updated: 2022/03/16 17:21:04 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_n(int n)
{
	int		len;
	int		nb;

	len = 0;
	nb = n;
	if (n == 0)
		len = 1;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static int	is_neg(int n, int neg)
{
	if (n < 0)
		neg = 1;
	return (neg);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	int			neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	neg = is_neg(n, neg);
	if (neg == 1)
		n *= -1;
	len = len_n(n);
	if (neg == 1)
		len++;
	str = ft_calloc((len + 1), sizeof(char));
	if (!(str))
		return (NULL);
	while (len)
	{
		str[len - 1] = ((n % 10) + '0');
		n /= 10;
		len--;
		if (neg == 1)
			str[0] = '-';
	}
	return (str);
}
