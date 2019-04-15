/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:49:00 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/15 11:33:07 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			matrix_mult(t_wolf3d *wolf)
{
	wolf->player[0][0] = (Y(B(wolf->player)) * Z(A(wolf->player)) -
			Z(B(wolf->player)) * Y(A(wolf->player)));
	wolf->player[0][1] = (Z(B(wolf->player)) * X(A(wolf->player)) -
			X(B(wolf->player)) * Z(A(wolf->player)));
	wolf->player[0][2] = (X(B(wolf->player)) * Y(A(wolf->player)) -
			Y(B(wolf->player)) * X(A(wolf->player)));
}

void			define_ray_angle(t_wolf3d *wolf)
{
	wolf->ray = ft_zero_vector(wolf->ray);
	wolf->ray = vector_scaling(X(wolf->player),
			wolf->x_column_fov - ((double)W / 2));
	wolf->ray += vector_scaling(Y(wolf->player), get_dist());
	wolf->curr_tan = FT_ABS(Y(wolf->ray) / X(wolf->ray));
}

inline double	distance_to_player(t_wolf3d *wolf)
{
	double		y;
	double		x;
	double		len;

	x = (wolf->player_coord_x - wolf->hit_coords_x);
	y = (wolf->player_coord_y - wolf->hit_coords_y);
	len = len_vector(y, x);
	return (len);
}

inline double	calculate_len_ray(t_wolf3d *wolf, void (*f)(t_wolf3d *))
{
	t_map		point;

	point = find_a_hit(wolf, f);
	if (point.texture > 0 && point.texture < 10)
		wolf->texture_to_draw = (uint32_t)point.texture;
	else
		print_error(INVALID_TEXTURE_CODE);
	return (distance_to_player(wolf));
}
