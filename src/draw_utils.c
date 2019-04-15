/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:52:44 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/13 18:52:44 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

inline void		put_image(t_mlx *mlx, int x, int y, int color)
{
	if (mlx->data_buff && (x >= 0 && x < W) && (y >= 0 && y < H))
		*(int *)(mlx->data_buff + (y * W + x) * mlx->bpp) = color;
}

inline void		write_line(t_wolf3d *wolf, int32_t from,
				int32_t to, int32_t attribute)
{
	while (from < to)
	{
		put_image(wolf->mlx, (int32_t)wolf->x_column_fov, from, attribute);
		from++;
	}
}

inline double	calculate_wall(t_wolf3d *wolf, double wall_dist)
{
	double		distance;

	distance = get_dist();
	wall_dist = wall_dist * cos(wolf->total_angle * M_PI / 180);
	return (((DEFAULT_SCALE) * distance) / wall_dist);
}

inline double_t	get_dist(void)
{
	return (((double)W / 2) / (tan((double)FIELD_OF_VIEW / 2 * M_PI / 180)));
}
