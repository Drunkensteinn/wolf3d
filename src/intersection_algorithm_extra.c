/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_algorithm_extra.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 23:02:38 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/14 23:02:38 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

inline size_t	transfer_coords_x(t_wolf3d *wolf, double x)
{
	size_t		arr;

	arr = 0;
	if (x > 0.0 && x < wolf->len_array_x * DEFAULT_SCALE)
		arr = ((size_t)x / DEFAULT_SCALE);
	else if (x >= wolf->len_array_x * DEFAULT_SCALE)
		arr = wolf->len_array_x - 1;
	return (arr);
}

inline size_t	transfer_coords_y(t_wolf3d *wolf, double y)
{
	size_t		arr;

	arr = 0;
	if (y > 0.0 && y < wolf->len_array_y * DEFAULT_SCALE)
		arr = ((size_t)y / DEFAULT_SCALE);
	else if (y >= wolf->len_array_y * DEFAULT_SCALE)
		arr = wolf->len_array_y - 1;
	return (arr);
}
