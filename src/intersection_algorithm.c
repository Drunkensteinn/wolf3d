/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_algorithm.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:55:39 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/15 11:14:43 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		first_inter_x(t_wolf3d *wolf)
{
	if (Y(wolf->ray) < 0)
	{
		wolf->inter.y = (int32_t)(wolf->player_coord_y / DEFAULT_SCALE) *
				DEFAULT_SCALE - 1;
		wolf->current_delta_y = -DEFAULT_SCALE;
	}
	else
	{
		wolf->inter.y = (int32_t)(wolf->player_coord_y / DEFAULT_SCALE) *
				DEFAULT_SCALE + DEFAULT_SCALE;
		wolf->current_delta_y = DEFAULT_SCALE;
	}
	if (X(wolf->ray) < 0)
	{
		wolf->inter.x = wolf->player_coord_x - FT_ABS((wolf->player_coord_y -
				wolf->inter.y) / wolf->curr_tan) + 1;
		wolf->current_delta_x = (-DEFAULT_SCALE / wolf->curr_tan);
	}
	else
	{
		wolf->inter.x = wolf->player_coord_x + FT_ABS((wolf->player_coord_y -
				wolf->inter.y) / wolf->curr_tan);
		wolf->current_delta_x = (DEFAULT_SCALE) / wolf->curr_tan;
	}
}

void		first_inter_y(t_wolf3d *wolf)
{
	if (X(wolf->ray) < 0)
	{
		wolf->inter.x = ((int32_t)(wolf->player_coord_x / DEFAULT_SCALE)) *
				DEFAULT_SCALE - 1;
		wolf->current_delta_x = -DEFAULT_SCALE;
	}
	else
	{
		wolf->inter.x = ((int32_t)(wolf->player_coord_x / DEFAULT_SCALE)) *
				DEFAULT_SCALE + DEFAULT_SCALE;
		wolf->current_delta_x = DEFAULT_SCALE;
	}
	if (Y(wolf->ray) < 0)
	{
		wolf->inter.y = (wolf->player_coord_y - FT_ABS(((wolf->player_coord_x -
				wolf->inter.x) * wolf->curr_tan))) + 1;
		wolf->current_delta_y = (-DEFAULT_SCALE * wolf->curr_tan);
	}
	else
	{
		wolf->inter.y = wolf->player_coord_y + FT_ABS(((wolf->player_coord_x -
				wolf->inter.x) * wolf->curr_tan));
		wolf->current_delta_y = (DEFAULT_SCALE) * wolf->curr_tan;
	}
}

inline void	check(t_wolf3d *wolf, double x, double y, int32_t *hit)
{
	wolf->y = transfer_coords_y(wolf, y);
	wolf->x = transfer_coords_x(wolf, x);
	*hit = wolf->map[wolf->y][wolf->x].texture;
}

void		hit_coords(t_wolf3d *wolf, const void *f, double x0, double y0)
{
	if (f == &first_inter_x)
		wolf->hit_coords_x = (int32_t)x0;
	else
		wolf->hit_coords_x = x0;
	if (f == &first_inter_y)
		wolf->hit_coords_y = (int32_t)y0;
	else
		wolf->hit_coords_y = y0;
}

t_map		find_a_hit(t_wolf3d *wolf, void (*f)(t_wolf3d *))
{
	int32_t	hit;
	double	x0;
	double	y0;

	f(wolf);
	hit = 0;
	x0 = wolf->inter.x;
	y0 = wolf->inter.y;
	while (!hit)
	{
		check(wolf, x0, y0, &hit);
		if (!hit)
		{
			x0 += wolf->current_delta_x;
			y0 += wolf->current_delta_y;
		}
	}
	hit_coords(wolf, f, x0, y0);
	return (wolf->map[wolf->y][wolf->x]);
}
