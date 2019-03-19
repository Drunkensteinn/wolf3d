/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:37:34 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/19 18:50:15 by ablizniu         ###   ########.fr       */
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
# define DEFAULT_SCALE			1
# define FIELD_OF_VIEW			66
# define DISTANCE				(W / 2) / (tan((FIELD_OF_VIEW * M_PI / 180) / 2))
# define ANGLE_NEIBORING_RAYS	FIELD_OF_VIEW / W
# define H 600
# define W 960

typedef enum	e_texture
{
	none,
	red,
	blue,
	green,
	brick
}				t_texture;

typedef struct	s_mlx
{
	int32_t		bpp;
	int32_t		size_line;
	int32_t		endian;
	char		*data_buff;
	void		*mlx_ptr;
	void		*mlx_window;
	void		*image_ptr;
}				t_mlx;

typedef	struct	s_map
{
	double	x;
	double	y;
	int32_t texture;
}				t_map;

typedef struct	s_intersection
{
	double x;
	double y;
}				t_intersection;

typedef	struct	s_vectors
{
	double	dist_x;
	double	dist_y;
	double 	plane_x;
	double 	plane_y;
	double 	delta_x;
	double 	delta_y;
}				t_vectors;

typedef struct			s_wolf3d
{
	struct s_map		**map;
	struct s_mlx		*mlx;
	struct s_vectors	*vectors;
	size_t 				x_column_fov;
	size_t				len_array_y;
	size_t				len_array_x;
	double				cam;
	double				curr_angle;;
	double				player_coord_x;
	double				player_coord_y;
	t_texture			textures;
	t_intersection		intersection_x;
	t_intersection		intersection_y;

}						t_wolf3d;

void		main_draw_function(t_wolf3d *wolf);

void		put_image(t_mlx *mlx, int x, int y, int color);

void		preparation(t_wolf3d *wolf);

void		write_line(t_wolf3d *wolf, int32_t from, int32_t to, int32_t attribute);

void		source_rewrite(t_wolf3d *wolf, int32_t fd, char *path);

void		map_rewrite(t_wolf3d *wolf, size_t row, int32_t pos);

t_map		*init_member(size_t size);

t_map		**init_map(size_t size);

t_vectors 	*init_vectors(void);

void		read_and_valid(t_wolf3d *wolf, char *path);

t_wolf3d	*init_wolf3d(void);

void		print_error(const char *error);

#endif
