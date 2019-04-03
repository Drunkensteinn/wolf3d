/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:51:08 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/03 22:40:54 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

inline void		put_image(t_mlx *mlx, int x, int y, int color)
{
	if ((x >= 0 && x < W) && (y >= 0 && y < H))
		*(int *)(mlx->data_buff + (y * W + x) * mlx->bpp) = color;
}

void	write_line(t_wolf3d *wolf, int32_t from, int32_t to, int32_t attribute)
{
	while (from < to)
	{
		put_image(wolf->mlx, (int32_t)wolf->x_column_fov, from, attribute);
		from++;
	}
}

double	calculate_wall(t_wolf3d *wolf, double wall_dist)
{
	double distance;

	distance = get_dist();
//	distance *= cos(wolf->total_angle * M_PI / 180);
	return (((DEFAULT_SCALE) * distance) / wall_dist);
}

double_t get_dist(void)
{
	return (((double)W / 2) / (tan((double)FIELD_OF_VIEW / 2 * M_PI / 180)));
}

void	matrix_mult(t_wolf3d *wolf)
{
	wolf->player[0][0] = (Y(B(wolf->player)) * Z(A(wolf->player)) -
			Z(B(wolf->player)) * Y(A(wolf->player)));
	wolf->player[0][1] = (Z(B(wolf->player)) * X(A(wolf->player)) -
			X(B(wolf->player)) * Z(A(wolf->player)));
	wolf->player[0][2] = (X(B(wolf->player)) * Y(A(wolf->player)) -
			Y(B(wolf->player)) * X(A(wolf->player)));
}

double	len_vector(long double x0, long double x1)
{
	double size;

	size = sqrt((double)(x1 * x1 + x0 * x0));
	return (size);
}

t_vector 	ft_zero_vector(t_vector vector)
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

t_vector vector_scaling(t_vector vector, double num)
{
	vector[0] *= num;
	vector[1] *= num;
	vector[2] *= num;
	return (vector);
}

void	define_ray_angle(t_wolf3d *wolf)
{
	wolf->ray = ft_zero_vector(wolf->ray);
	wolf->ray = vector_scaling(X(wolf->player), wolf->x_column_fov - ((double)W / 2));
	wolf->ray += vector_scaling(Y(wolf->player), get_dist());
	wolf->curr_tan = FT_ABS(Y(wolf->ray) / X(wolf->ray));//могут быть траблы из-за тангенса inf или ноль
}

void first_inter_x(t_wolf3d *wolf)
{
	double buff = -(DEFAULT_SCALE);
	if (Y(wolf->ray) < 0)
	{
		wolf->intersection.y = (int32_t)(wolf->player_coord_y / DEFAULT_SCALE) * DEFAULT_SCALE - 1;
		wolf->current_delta_y = -DEFAULT_SCALE;
	}
	else
	{
		wolf->intersection.y = (int32_t)(wolf->player_coord_y / DEFAULT_SCALE) * DEFAULT_SCALE + DEFAULT_SCALE;
		wolf->current_delta_y = DEFAULT_SCALE;
	}
	if (X(wolf->ray) < 0)
	{
		wolf->intersection.x = wolf->player_coord_x - FT_ABS((wolf->player_coord_y - wolf->intersection.y) / wolf->curr_tan);
		wolf->current_delta_x = buff / wolf->curr_tan;
	}
	else
	{
		wolf->intersection.x = wolf->player_coord_x + FT_ABS((wolf->player_coord_y - wolf->intersection.y) / wolf->curr_tan);
		wolf->current_delta_x =  (DEFAULT_SCALE) / wolf->curr_tan;
	}
	printf("inter X |   y - %f   x - %f \n", wolf->intersection.y, wolf->intersection.x);
}

void first_inter_y(t_wolf3d *wolf)
{
	if (X(wolf->ray) < 0)
	{
		wolf->intersection.x = ((int32_t)(wolf->player_coord_x / DEFAULT_SCALE)) * DEFAULT_SCALE - 1;
		wolf->current_delta_x = -DEFAULT_SCALE;
	}
	else
	{
		wolf->intersection.x = ((int32_t)(wolf->player_coord_x / DEFAULT_SCALE)) * DEFAULT_SCALE + DEFAULT_SCALE;
		wolf->current_delta_x = DEFAULT_SCALE;
	}
	if (Y(wolf->ray) < 0)
	{
		wolf->intersection.y = wolf->player_coord_y - FT_ABS(((wolf->player_coord_x - wolf->intersection.x) * wolf->curr_tan));
		wolf->current_delta_y = (-DEFAULT_SCALE) * wolf->curr_tan;
	}
	else
	{
		wolf->intersection.y = wolf->player_coord_y + FT_ABS(((wolf->player_coord_x - wolf->intersection.x) * wolf->curr_tan));
		wolf->current_delta_y = (DEFAULT_SCALE) * wolf->curr_tan;
	}
	printf("inter Y |   y - %f   x - %f \n", wolf->intersection.y, wolf->intersection.x);
}

double 	distance_to_player(t_wolf3d *wolf)
{
	double	y;
	double 	x;
	double	len;

	y = (wolf->player_coord_y - wolf->hit_coords_y);
	x = (wolf->player_coord_x - wolf->hit_coords_x);
	len = len_vector(y, x);
	return (len);
}

double	calculate_len_ray(t_wolf3d *wolf, void (*f)(t_wolf3d *))
{
	t_map	point;

	point = find_a_hit(wolf, f);
	return (distance_to_player(wolf));
}

inline size_t transfer_coords_x(t_wolf3d *wolf, double x)
{
	size_t arr;

	arr = 0;
	if (x > 0.0 && x < wolf->len_array_x * DEFAULT_SCALE)
			arr = ((size_t)x / DEFAULT_SCALE);
	else if (x >= wolf->len_array_x * DEFAULT_SCALE)
		arr = wolf->len_array_x - 1;
	return (arr);
}

inline size_t transfer_coords_y(t_wolf3d *wolf, double y)
{
	size_t arr;

	arr = 0;
	if (y > 0.0 && y < wolf->len_array_y * DEFAULT_SCALE)
		arr = ((size_t)y / DEFAULT_SCALE);
	else if (y >= wolf->len_array_y * DEFAULT_SCALE)
		arr = wolf->len_array_y - 1;
	return (arr);
}

inline void check(t_wolf3d *wolf, double x, double y, int32_t *hit)
{
//	wolf->y = transfer_coords_y(wolf, y);
//	wolf->x = transfer_coords_x(wolf, x);
	*hit = wolf->map[transfer_coords_y(wolf, y)][transfer_coords_x(wolf, x)].texture;
}

t_map	find_a_hit(t_wolf3d *wolf, void (*f)(t_wolf3d *))
{
	int32_t hit;
	double x0;
	double y0;

	f(wolf);
	hit = 0;
	x0 = wolf->intersection.x;
	y0 = wolf->intersection.y;
	while (!hit)
	{
		check(wolf, x0, y0, &hit);
		if (!hit)
		{
			x0 += wolf->current_delta_x;
			y0 += wolf->current_delta_y;
		}
	}
	wolf->hit_coords_x = x0;
	wolf->hit_coords_y = y0;
	return (wolf->map[wolf->y][wolf->x]);
}

void draw_wall(t_wolf3d *wolf, double len, int32_t attribute)
{
	double lineHeight;

	lineHeight = calculate_wall(wolf, len);
	int drawStart = (int)(-lineHeight / 2 + ((double)H / 2));
	if(drawStart < 0)
		drawStart = 0;
	int drawEnd = (int)lineHeight / 2 + (H / 2);
	if(drawEnd >= H)
		drawEnd = H - 1;
	write_line(wolf, drawStart, drawEnd, attribute);
}

void	wall_config(t_wolf3d *wolf, double ray_x, double ray_y)
{
	if (ray_x < ray_y)
	{
		draw_wall(wolf, ray_x, 0xff0000);
		printf("len X | %f | hit coords y - %f  x - %f \n", ray_x, wolf->hit_coords_y, wolf->hit_coords_x);
	}
	else
	{
		draw_wall(wolf, ray_y, 0xffffff);
		printf("len Y | %f | hit coords y - %f  x - %f \n", ray_y, wolf->hit_coords_y, wolf->hit_coords_x);
	}
}

void	main_draw_function(t_wolf3d *wolf)
{
	double ray_x;
	double ray_y;

	wolf->x_column_fov = 0;
	wolf->total_angle = -33;
	while (wolf->x_column_fov < W - 1)
	{
		define_ray_angle(wolf);
		ray_y = calculate_len_ray(wolf, &first_inter_y);
		ray_x = calculate_len_ray(wolf, &first_inter_x);
		wall_config(wolf, ray_x, ray_y);
		wolf->x_column_fov++;
		wolf->total_angle += ANGLE_BETWEEN_RAYS;
	}
	mlx_put_image_to_window(wolf->mlx->mlx_ptr,
			wolf->mlx->mlx_window, wolf->mlx->image_ptr, 0, 0);
}
