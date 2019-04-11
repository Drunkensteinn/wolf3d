/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:37:34 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/11 14:09:11 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
#define WOLF3D_H

#include "../libft/libft.h"
#include "mlx.h"
#include <stdint.h>
#include <limits.h>
#include <math.h>
#include "errors.h"

# define A_KEY					0
# define D_KEY					2
# define W_KEY					13
# define S_KEY					1


# define FOLDER					"../textures/"
# define ANGLE_BETWEEN_RAYS		((double)FIELD_OF_VIEW / W)
# define TEXTURES_NUM			8

# define DEFAULT_TEXTURE		1
# define DIMENSION				3
# define DEFAULT_SCALE			64
# define FIELD_OF_VIEW			66
# define Z(f) f[2]
# define Y(f) f[1]
# define X(f) f[0]
# define A(f) f[1]
# define B(f) f[2]
# define H 768
# define W 1024


typedef long double t_vector __attribute__((vector_size(sizeof(long double) * 3)));

typedef struct			s_mlx
{
	int32_t				bpp;
	int32_t				size_line;
	int32_t				endian;
	char				*data_buff;
	void				*mlx_ptr;
	void				*mlx_window;
	void				*image_ptr;
}						t_mlx;

typedef	struct	__attribute__((packed))	s_map
{
	double	x;
	double	y;
	int32_t texture;
}						t_map;

typedef struct			s_intersection
{
	double x;
	double y;
}						t_intersection;

typedef struct			s_textures
{
	void				*ptr;
	char				*image;
	int32_t				bpp;
	int32_t				size_line;
	int32_t				endian;
	int32_t				width;
	int32_t				height;
}						t_texture;

typedef struct	s_hitcoords
{
	double	x;
	double	y;
	int32_t	hit_texture;
}				t_hitcoords;

typedef struct	__attribute__((packed))	s_wolf3d
{
	double				total_angle;
	struct	s_map		**map;
	struct	s_mlx		*mlx;
	struct	s_textures	textures[TEXTURES_NUM];
	struct	s_textures	multi_side[1];
	double				x_column_fov;

	size_t				len_array_y;
	size_t				len_array_x;

	double				curr_tan;

	double				hit_coords_x;
	double				hit_coords_y;

	double				player_coord_x;
	double				player_coord_y;

	double				current_delta_x;
	double				current_delta_y;

	size_t				x;
	size_t				y;

	size_t 				map_pos_x;
	size_t 				map_pos_y;

	t_vector			ray;
	t_vector			player[DIMENSION];
	t_vector			direction[DIMENSION];
	t_intersection		intersection;
	t_hitcoords			saved_ray_x;
	t_hitcoords			saved_ray_y;
	uint32_t			texture_to_draw;
	double				ray_to_draw;

}						t_wolf3d;

double 	distance_to_player(t_wolf3d *wolf);

double	calculate_len_ray(t_wolf3d *wolf, void (*f)(t_wolf3d *));

double_t get_dist(void);

double	calculate_wall(t_wolf3d *wolf, double wall_dist);

t_vector  norm_vector(t_vector vector);

double	len_vector(long double x0, long double x1);

void		floor_draw(t_wolf3d *wolf, int32_t end_of_wall, double heigth, double len_ray);

t_vector 	ft_zero_vector(t_vector vector);

void		prepare_multi_size(t_wolf3d *wolf, double x_coord, double y_coord);

void		parse_textures(t_wolf3d *wolf);

void		draw_wall(t_wolf3d *wolf, double len, int32_t attribute);

size_t 		transfer_coords_x(t_wolf3d *wolf, double x);

size_t		transfer_coords_y(t_wolf3d *wolf, double y);

void		check(t_wolf3d *wolf, double x, double y, int32_t *hit);

void		movement(t_wolf3d *wolf, int32_t code);

void		rotating(t_wolf3d *wolf, int32_t code);

t_vector	vector_scaling(t_vector vector, double num);

void		matrix_mult(t_wolf3d *wolf);

int			keys(int code, t_wolf3d *wolf);

void		first_inter_y(t_wolf3d *wolf);

void		first_inter_x(t_wolf3d *wolf);

t_map		find_a_hit(t_wolf3d *wolf, void (*f)(t_wolf3d *));

double_t	get_dist(void);

void		main_draw_function(t_wolf3d *wolf);

void		put_image(t_mlx *mlx, int x, int y, int color);

void		preparation(t_wolf3d *wolf);

void		write_line(t_wolf3d *wolf, int32_t from, int32_t to, int32_t attribute);

void		source_rewrite(t_wolf3d *wolf, int32_t fd, char *path);

void		map_rewrite(t_wolf3d *wolf, size_t row, int32_t pos);

t_map		*init_member(size_t size);

t_map		**init_map(size_t size);

void		read_and_valid(t_wolf3d *wolf, char *path);

t_wolf3d	*init_wolf3d(void);

void		print_error(const char *error);

#endif
