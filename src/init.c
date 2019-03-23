/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:35:54 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/20 20:56:30 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static t_mlx *init_mlx(void)
{
	t_mlx *member;

	if (!(member = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	member->mlx_ptr = mlx_init();
	member->image_ptr = mlx_new_image(member->mlx_ptr, W, H);
	member->mlx_window = mlx_new_window(member->mlx_ptr, W, H, "Wolf3D");
	member->data_buff = mlx_get_data_addr(member->image_ptr, &member->bpp,
			&member->size_line, &member->endian);
	member->bpp /= 8;
	return (member);
}

t_map *init_member(size_t size)
{
	t_map *member;

	if (!(member = (t_map *)ft_memalloc(sizeof(t_map) * size)))
		return (NULL);
	return (member);
}

t_map **init_map(size_t size)
{
	t_map	**member;

	if (!(member = (t_map **)ft_memalloc(sizeof(t_map *) * size)))
		return (NULL);
	return (member);
}

t_wolf3d *init_wolf3d(void)
{
	t_wolf3d *member;

	if (!(member = (t_wolf3d *)ft_memalloc(sizeof(t_wolf3d))))
		return (NULL);
	member->mlx = init_mlx();
	return (member);
}