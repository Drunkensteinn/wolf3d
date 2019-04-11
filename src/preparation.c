/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:05:03 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/08 20:43:17 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	define_players_coord(t_wolf3d *wolf)
{
	wolf->player_coord_x = 195;
	wolf->player_coord_y = 195;
}

void	scaling(t_wolf3d *wolf)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < wolf->len_array_y)
	{
		j = 0;
		while (j < wolf->len_array_x)
		{
			wolf->map[i][j].x *= DEFAULT_SCALE;
			wolf->map[i][j].y *= DEFAULT_SCALE;
			j++;
		}
		i++;
	}
}

t_vector		find_cell(t_wolf3d *wolf, double x, double y)
{
	t_vector	vector;
	double		x0;
	double		y0;
	double		x1;
	double		y1;

	x0 = (size_t)(wolf->hit_coords_x / (DEFAULT_SCALE - 1)) * (DEFAULT_SCALE - 1);
	y0 = (size_t)(wolf->hit_coords_y / (DEFAULT_SCALE - 1)) * (DEFAULT_SCALE - 1);
	x1 = x0 + DEFAULT_SCALE;
	y1 = y0 + DEFAULT_SCALE;
	vector = (t_vector){0, 0, 0};
	if (x)
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
	}
	if (y)
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
	}
	return (vector);
}

void		prepare_multi_size(t_wolf3d *wolf, double x_coord, double y_coord)
{
	t_vector  vector;

	vector = find_cell(wolf, x_coord, y_coord);
	if (x_coord)
	{
		if (vector[0] < 0)
			wolf->texture_to_draw = 1;
		else
			wolf->texture_to_draw = 3;
	}
	else if (y_coord)
	{
		if (vector[1] < 0)
			wolf->texture_to_draw = 5;
		else
			wolf->texture_to_draw = 7;
	}
}

void	preparation(t_wolf3d *wolf)
{
	scaling(wolf);
	define_players_coord(wolf);
}
