/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <ablizniu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:51:43 by ablizniu          #+#    #+#             */
/*   Updated: 2017/12/04 21:51:58 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		warning(char const *str, size_t i, int *point)
{
	while (str[i] == '\n' || str[i] == '\t' ||
	str[i] == '\r' || str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*point = 1;
		if (str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		i++;
	}
	return (i);
}

int					ft_atoi(const char *str)
{
	size_t			i;
	long long int	res;
	int				point;

	i = 0;
	res = 0;
	point = 0;
	i = warning((char *)str, i, &point);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 - (str[i++] - 48);
		if (res >= 922337203685477580 && point == 0)
			return (-1);
		else if (res > 922337203685477580 && point == 1)
			return (0);
	}
	return ((int)(point ? res : -res));
}
