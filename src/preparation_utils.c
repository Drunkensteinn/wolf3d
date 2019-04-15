/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:19:44 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/14 16:48:14 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_vector		cell_dir_x(t_wolf3d *wolf, t_vector vector,
				double x0, double x1)
{
	if (wolf->ray[1] < 0)
	{
		X(vector) = x0 - x1;
		Y(vector) = 0;
	}
	else
	{
		X(vector) = x1 - x0;
		Y(vector) = 0;
	}
	return (vector);
}

t_vector		cell_dir_y(t_wolf3d *wolf,
				t_vector vector, double y0, double y1)
{
	if (wolf->ray[0] < 0)
	{
		X(vector) = 0;
		Y(vector) = y0 - y1;
	}
	else
	{
		X(vector) = 0;
		Y(vector) = y1 - y0;
	}
	return (vector);
}

t_vector		find_cell(t_wolf3d *wolf, double x, double y)
{
	t_vector	vector;
	double		x0;
	double		y0;
	double		x1;
	double		y1;

	x0 = (size_t)(wolf->hit_coords_x / (DEFAULT_SCALE - 1)) *
			(DEFAULT_SCALE - 1);
	y0 = (size_t)(wolf->hit_coords_y / (DEFAULT_SCALE - 1)) *
			(DEFAULT_SCALE - 1);
	x1 = x0 + DEFAULT_SCALE;
	y1 = y0 + DEFAULT_SCALE;
	vector = (t_vector){0, 0, 0};
	if (x)
		vector += cell_dir_x(wolf, vector, x0, x1);
	if (y)
		vector += cell_dir_y(wolf, vector, y0, y1);
	return (vector);
}

void			fill_players_coords(t_wolf3d *wolf, size_t x, size_t y)
{
	wolf->player_coord_y = y * DEFAULT_SCALE + (double)DEFAULT_SCALE / 2;
	wolf->player_coord_x = x * DEFAULT_SCALE + (double)DEFAULT_SCALE / 2;
}
