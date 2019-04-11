/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:51:08 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/11 14:13:59 by ablizniu         ###   ########.fr       */
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

inline t_vector  norm_vector(t_vector vector)
{
	double len;

	len = len_vector(vector[0],vector[1]);
	return ((t_vector){vector[0] / len, vector[1] / len, 0});
}

inline double	calculate_wall(t_wolf3d *wolf, double wall_dist)
{
	double distance;

	distance = get_dist();
	wall_dist = wall_dist * cos(wolf->total_angle * M_PI / 180);
	return (((DEFAULT_SCALE) * distance) / wall_dist);
}

inline double_t get_dist(void)
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

inline double	len_vector(long double x0, long double x1)
{
	double size;

	size = sqrt((double)(x1 * x1 + x0 * x0));
	return (size);
}

inline t_vector 	ft_zero_vector(t_vector vector)
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

inline t_vector vector_scaling(t_vector vector, double num)
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
	wolf->curr_tan = FT_ABS(Y(wolf->ray) / X(wolf->ray));
}

void first_inter_x(t_wolf3d *wolf)
{
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
		wolf->intersection.x = wolf->player_coord_x - FT_ABS((wolf->player_coord_y - wolf->intersection.y) / wolf->curr_tan) + 1;
		wolf->current_delta_x = (-DEFAULT_SCALE / wolf->curr_tan);
	}
	else
	{
		wolf->intersection.x = wolf->player_coord_x + FT_ABS((wolf->player_coord_y - wolf->intersection.y) / wolf->curr_tan);
		wolf->current_delta_x =  (DEFAULT_SCALE) / wolf->curr_tan;
	}
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
		wolf->intersection.y = (wolf->player_coord_y - FT_ABS(((wolf->player_coord_x - wolf->intersection.x) * wolf->curr_tan))) + 1;
		wolf->current_delta_y = (-DEFAULT_SCALE * wolf->curr_tan);
	}
	else
	{
		wolf->intersection.y = wolf->player_coord_y + FT_ABS(((wolf->player_coord_x - wolf->intersection.x) * wolf->curr_tan));
		wolf->current_delta_y = (DEFAULT_SCALE) * wolf->curr_tan;
	}
}

inline double 	distance_to_player(t_wolf3d *wolf)
{
	double	y;
	double 	x;
	double	len;

	x = (wolf->player_coord_x - wolf->hit_coords_x);
	y = (wolf->player_coord_y - wolf->hit_coords_y);
	len = len_vector(y, x);
	return (len);
}

inline double	calculate_len_ray(t_wolf3d *wolf, void (*f)(t_wolf3d *))
{
	t_map	point;

	point = find_a_hit(wolf, f);
	wolf->texture_to_draw = (uint32_t)point.texture;
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
	wolf->y = transfer_coords_y(wolf, y);
	wolf->x = transfer_coords_x(wolf, x);
	*hit = wolf->map[wolf->y][wolf->x].texture;
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
	if (f == &first_inter_x)
		wolf->hit_coords_x = (int32_t)x0;
	else
		wolf->hit_coords_x = x0;
	if (f == &first_inter_y)
		wolf->hit_coords_y = (int32_t)y0;
	else
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

double	wall_config(t_wolf3d *wolf, double ray_x, double ray_y)
{
	if (ray_x < ray_y)
	{
		wolf->ray_to_draw = wolf->saved_ray_x.x;
		wolf->texture_to_draw = (uint32_t)wolf->saved_ray_x.hit_texture;
		if (wolf->texture_to_draw == 9)
			prepare_multi_size(wolf, wolf->saved_ray_x.x, 0);
		return (ray_x);
	}
	else
	{
		wolf->ray_to_draw = wolf->saved_ray_y.y;
		wolf->texture_to_draw = (uint32_t)wolf->saved_ray_y.hit_texture;
		if (wolf->texture_to_draw == 9)
			prepare_multi_size(wolf, 0, wolf->saved_ray_y.y);
		return (ray_y);
	}
}

void	texture_draw(t_wolf3d *wolf,const double len_ray, const double height)
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
		put_image(wolf->mlx, (int32_t)wolf->x_column_fov, i, *(int *)(wolf->textures[INDEX(wolf->texture_to_draw)].image + (int32_t)(DEFAULT_SCALE * index_y + index_x) * 4));
		i++;
	}
	floor_draw(wolf, i, height, len_ray);

}

void	floor_draw(t_wolf3d *wolf, int32_t end_of_wall, double heigth, double len_ray)
{
	double	dist;
	double	dist_pl;
	double	dist_x;
	double	dist_y;
	size_t 	map_x;
	size_t 	map_y;
	t_vector vector;
	t_vector normed_vector;

	dist_pl = get_dist();
	vector = ft_zero_vector(vector);
	normed_vector = norm_vector(wolf->ray);
	while (end_of_wall < H - 1)
	{
		dist = (((double)DEFAULT_SCALE / 2) * dist_pl) / FT_ABS((H / 2 - end_of_wall));
		dist /= cos(wolf->total_angle * M_PI / 180);
		vector = normed_vector;
		vector = vector_scaling(vector, dist);
		dist_x = (int32_t)(wolf->player_coord_x + X(vector));
		dist_y = (int32_t)(wolf->player_coord_y + Y(vector));
		map_x = (size_t)((size_t)dist_x % DEFAULT_SCALE);
		map_y = (size_t)((size_t)dist_y % DEFAULT_SCALE);

		put_image(wolf->mlx, (int32_t)wolf->x_column_fov, end_of_wall, *(int *)(wolf->textures[5].image + (int32_t)(DEFAULT_SCALE * map_y + map_x) * 4));
		put_image(wolf->mlx, (int32_t)wolf->x_column_fov, H - end_of_wall, *(int *)(wolf->textures[1].image + (int32_t)(DEFAULT_SCALE * map_y + map_x) * 4));
		end_of_wall++;
	}
}

void	main_draw_function(t_wolf3d *wolf)
{
	double ray_x;
	double ray_y;
	double resulted;

	wolf->x_column_fov = 0;
	wolf->total_angle = -((double)FIELD_OF_VIEW / 2);
	parse_textures(wolf);
	while (wolf->x_column_fov < W - 1)
	{
		define_ray_angle(wolf);
		ray_y = calculate_len_ray(wolf, &first_inter_y);
		wolf->saved_ray_y.x = wolf->hit_coords_x;
		wolf->saved_ray_y.y = wolf->hit_coords_y;
		wolf->saved_ray_y.hit_texture = wolf->texture_to_draw;
		ray_x = calculate_len_ray(wolf, &first_inter_x);
		wolf->saved_ray_x.x = wolf->hit_coords_x;
		wolf->saved_ray_x.y = wolf->hit_coords_y;
		wolf->saved_ray_x.hit_texture = wolf->texture_to_draw;
		resulted = wall_config(wolf, ray_x, ray_y);
		texture_draw(wolf, resulted, calculate_wall(wolf, resulted));
		wolf->x_column_fov++;
		wolf->total_angle += ANGLE_BETWEEN_RAYS;
	}
	mlx_put_image_to_window(wolf->mlx->mlx_ptr,
			wolf->mlx->mlx_window, wolf->mlx->image_ptr, 0, 0);
}
