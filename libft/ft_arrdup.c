/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:00:57 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/07 20:00:57 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t		*ft_arrdup(const int32_t *dst, size_t len)
{
	int		*ptr;
	size_t	index;

	index = 0;
	if (!(ptr = (int *)ft_memalloc(sizeof(int) * len + 1)))
		return (NULL);
	while (index < len)
	{
		ptr[index] = dst[index];
		index++;
	}
	return (ptr);
}
