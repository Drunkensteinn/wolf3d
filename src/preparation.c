/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:05:03 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/03 13:22:09 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	define_players_coord(t_wolf3d *wolf)
{
//	wolf->player_coord_x = (((double)wolf->len_array_x / 2) * DEFAULT_SCALE);
//	wolf->player_coord_y = (((double)wolf->len_array_y / 2) * DEFAULT_SCALE);
//	wolf->map_pos_x = (size_t)wolf->player_coord_x / DEFAULT_SCALE;
//	wolf->map_pos_y = (size_t)wolf->player_coord_y / DEFAULT_SCALE;

	wolf->map_pos_x = 3;
	wolf->map_pos_y = 6;

	wolf->player_coord_x = 224;
	wolf->player_coord_y = 376;
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

void	preparation(t_wolf3d *wolf)
{
	scaling(wolf);
	define_players_coord(wolf);
}
