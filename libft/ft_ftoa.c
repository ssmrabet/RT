/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:27:20 by smrabet           #+#    #+#             */
/*   Updated: 2017/09/09 14:27:25 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_digitnb(float nb)
{
	long	size;

	if (nb >= 0.0 && nb <= 1.0)
		return (2);
	if (nb >= -1.0 && nb < 0)
		return (3);
	nb *= 10;
	size = 0;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb > 9)
	{
		nb /= 10;
		size++;
	}
	return (++size);
}

char		*ft_ftoa(float nb)
{
	float	n;
	char	*str;
	long	length;

	n = nb;
	nb *= 10;
	length = ft_digitnb(n);
	if (!(str = (char *)malloc(sizeof(char) * (length + 2))))
		return (NULL);
	str[length + 1] = '\0';
	if (nb < 0)
		nb = -nb;
	str[length] = ((int)nb % 10) + '0';
	nb /= 10;
	str[length - 1] = '.';
	length -= 2;
	while (length >= 0)
	{
		str[length--] = ((int)nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
