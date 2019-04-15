/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:53:56 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/15 14:36:10 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			texture_draw(t_wolf3d *wolf, double height)
{
	int32_t		i;
	int32_t		index_x;
	int32_t		d;
	int32_t		index_y;

	i = (int32_t)(-height / 2 + (double)H / 2);
	index_x = (int32_t)wolf->ray_to_draw % DEFAULT_SCALE;
	while (i < (int)height / 2 + (H / 2))
	{
		d = (int32_t)(i * 256 - H * 128 + height * 128);
		index_y = (int32_t)(((d * DEFAULT_SCALE) / height) / 256);
		if (index_x >= 0 && index_y >= 0 && (wolf->texture_to_draw > 0 &&
		wolf->texture_to_draw < TEXTURES_NUM + 1))
			put_image(wolf->mlx, (int32_t)wolf->x_column_fov, i,
			*(int *)(wolf->textures[INDEX(wolf->texture_to_draw)].image +
			(int32_t)(DEFAULT_SCALE * index_y + index_x) * 4));
		i++;
	}
	floor_celling_draw(wolf, i);
}

static void		calculate_floor_celling(t_wolf3d *wolf, t_vector vector,
				int32_t end_of_wall)
{
	double		dist_x;
	double		dist_y;
	size_t		map_x;
	size_t		map_y;

	dist_x = (int32_t)(wolf->player_coord_x + X(vector));
	dist_y = (int32_t)(wolf->player_coord_y + Y(vector));
	map_x = ((size_t)dist_x % DEFAULT_SCALE);
	map_y = ((size_t)dist_y % DEFAULT_SCALE);
	put_image(wolf->mlx, (int32_t)wolf->x_column_fov, end_of_wall,
			*(int *)(wolf->textures[5].image +
			(int32_t)(DEFAULT_SCALE * map_y + map_x) * 4));
	put_image(wolf->mlx, (int32_t)wolf->x_column_fov, H - end_of_wall,
			*(int *)(wolf->textures[1].image +
			(int32_t)(DEFAULT_SCALE * map_y + map_x) * 4));
}

void			floor_celling_draw(t_wolf3d *wolf, int32_t end_of_wall)
{
	double		dist;
	double		dist_pl;
	t_vector	vector;
	t_vector	normed_vector;

	dist_pl = get_dist();
	vector = (t_vector){0, 0, 0};
	normed_vector = norm_vector(wolf->ray);
	while (end_of_wall < H - 1)
	{
		dist = (((double)DEFAULT_SCALE / 2) * dist_pl) /
				FT_ABS((H / 2 - end_of_wall));
		dist /= cos(wolf->total_angle * M_PI / 180);
		vector = vector_scaling(normed_vector, dist);
		calculate_floor_celling(wolf, vector, end_of_wall);
		end_of_wall++;
	}
}
