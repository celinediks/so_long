/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:25:07 by cdiks             #+#    #+#             */
/*   Updated: 2022/03/16 17:25:08 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int argument)
{
	if ((argument >= '0') && (argument <= '9'))
		return (1);
	if ((argument > 64) && (argument < 91))
		return (1);
	if ((argument > 96) && (argument < 123))
		return (1);
	return (0);
}
