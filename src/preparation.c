/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:05:03 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/14 16:48:51 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			define_players_coord(t_wolf3d *wolf)
{
	size_t		i;
	size_t		j;
	size_t		x;
	size_t		y;

	i = 0;
	x = 0;
	y = 0;
	while (i < wolf->len_array_y)
	{
		j = 0;
		while (j < wolf->len_array_x)
		{
			if (wolf->map[i][j].texture == 0)
			{
				y = i;
				x = j;
			}
			j++;
		}
		i++;
	}
	if (!x && !y)
		print_error(NO_PLAYER_POS);
	fill_players_coords(wolf, x, y);
}

void			scaling(t_wolf3d *wolf)
{
	size_t		i;
	size_t		j;

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

void			prepare_multi_size(t_wolf3d *wolf,
				double x_coord, double y_coord)
{
	t_vector	vector;

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

void			preparation(t_wolf3d *wolf)
{
	scaling(wolf);
	define_players_coord(wolf);
}
