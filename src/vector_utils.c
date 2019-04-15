/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:52:42 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/14 22:41:41 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

inline double			len_vector(long double x0, long double x1)
{
	double size;

	size = sqrt((double)(x1 * x1 + x0 * x0));
	return (size);
}

inline t_vector			ft_zero_vector(t_vector vector)
{
	size_t i;

	i = 0;
	while (i < DIMENSION)
	{
		vector[i] = 0;
		i++;
	}
	return (vector);
}

inline t_vector			vector_scaling(t_vector vector, double num)
{
	vector[0] *= num;
	vector[1] *= num;
	vector[2] *= num;
	return (vector);
}

inline t_vector			norm_vector(t_vector vector)
{
	double				len;

	len = len_vector(vector[0], vector[1]);
	return ((t_vector){vector[0] / len, vector[1] / len, 0});
}
