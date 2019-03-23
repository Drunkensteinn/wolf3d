/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:37:34 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/23 21:11:39 by ablizniu         ###   ########.fr       */
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

# define DEFAULT_TEXTURE		1
# define DIMENSION				3
# define DEFAULT_SCALE			64
# define FIELD_OF_VIEW			66
# define DISTANCE				(W / 2) / (tan((FIELD_OF_VIEW * M_PI / 180) / 2))
# define ANGLE_NEIBORING_RAYS	FIELD_OF_VIEW / W
# define Z(f) f[2]
# define Y(f) f[1]
# define X(f) f[0]
# define A(f) f[1]
# define B(f) f[2]
# define H 600
# define W 960

typedef long double t_vector __attribute__((vector_size(sizeof(long double) * 3)));
typedef float  t_dir_vect __attribute__((vector_size(sizeof(float) * 2)));
typedef int t_map_coord __attribute__((vector_size(sizeof(int) * 2)));

typedef enum			e_texture
{
	none,
	red,
	blue,
	green,
	brick
}						t_texture;

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
	size_t x_map;
	size_t y_map;
}						t_intersection;

typedef struct	__attribute__((packed))	s_wolf3d
{
	struct s_map		**map;
	struct s_mlx		*mlx;
	size_t				half_plane;
	double 				x_column_fov;
	size_t				len_array_y;
	size_t				len_array_x;
	double				curr_tan;
	double				player_coord_x;
	double				player_coord_y;
	double 				pos_delta_x;
	double 				pos_delta_y;
	double 				current_delta_x;
	double 				current_delta_y;
	double 				init_len_x;
	double 				init_len_y;
	size_t 				map_pos_x;
	size_t 				map_pos_y;
	t_vector			ray;
	t_vector			direction;
	t_vector			player[DIMENSION];
	t_vector			basis[DIMENSION - 1];
	t_texture			textures;
	t_intersection		intersection;

}						t_wolf3d;

void		first_inter_y(t_wolf3d *wolf, t_bool sign);

void		first_inter_x(t_wolf3d *wolf, t_bool sign);

t_map		find_a_hit(t_wolf3d *wolf, t_bool sign, void (*f)(t_wolf3d *, t_bool));

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
