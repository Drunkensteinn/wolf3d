/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 21:12:24 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/14 22:17:38 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		check_row(t_wolf3d *wolf, size_t row, t_bool *changes)
{
	size_t	i;

	i = 0;
	while (i < wolf->len_array_x)
	{
		if (wolf->map[row][i].texture != DEFAULT_TEXTURE)
		{
			wolf->map[row][i].texture = DEFAULT_TEXTURE;
			*changes = true;
		}
		i++;
	}
}

void		check_column(t_wolf3d *wolf, size_t column, t_bool *changes)
{
	if (wolf->map[column][0].texture != DEFAULT_TEXTURE)
	{
		wolf->map[column][0].texture = DEFAULT_TEXTURE;
		*changes = true;
	}
	if (wolf->map[column][INDEX(wolf->len_array_x)].texture != DEFAULT_TEXTURE)
	{
		wolf->map[column][INDEX(wolf->len_array_x)].texture = DEFAULT_TEXTURE;
		*changes = true;
	}
}

void		invalid_textures(t_wolf3d *wolf)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < wolf->len_array_y)
	{
		j = 0;
		while (j < wolf->len_array_x)
		{
			if ((wolf->map[i][j].texture < 0) ||
			(wolf->map[i][j].texture > (TEXTURES_NUM + 1)))
				print_error(INVALID_TEXTURE_CODE);
			j++;
		}
		i++;
	}
}

void		validate_map(t_wolf3d *wolf, int32_t fd, char *path)
{
	t_bool	changes;
	size_t	i;

	i = 0;
	changes = false;
	while (i < wolf->len_array_y)
	{
		if (i == 0 || i == wolf->len_array_y - 1)
			check_row(wolf, i, &changes);
		else
			check_column(wolf, i, &changes);
		i++;
	}
	invalid_textures(wolf);
	if (changes)
		validation_source(wolf, fd, path);
}

void		read_and_valid(t_wolf3d *wolf, char *path)
{
	char	*line;
	int32_t	fd;
	t_list	*lst;

	lst = NULL;
	if (!(fd = open(path, O_RDWR)) || fd < 0)
		print_error(BAD_ACCESS);
	while (get_next_line(fd, &line))
	{
		tmp_list(&lst, (void *)line, ft_strlen(line));
		ft_strdel(&line);
	}
	if (lst)
	{
		alloc_map(wolf, lst);
		fill_map(wolf, lst);
		validate_map(wolf, fd, path);
		del_list(lst);
	}
	else
		print_error(INVALID_MAP);
}
