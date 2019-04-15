/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:15:06 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/14 22:15:06 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	fill_struct(t_map **map, size_t len_array, size_t index, t_list lst)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	line = lst.content;
	while (i < lst.content_size)
	{
		if (ft_isdigit(line[i]) && j < len_array)
		{
			(*map)[j].texture = ft_atoi(&line[i]);
			(*map)[j].y = (double)index;
			(*map)[j].x = (double)j;
			j++;
		}
		else if ((line[i] > 32 && line[i] < 48)
		|| (line[i] > 57 && line[i] < 127))
			print_error(INVALID_TEXTURE_CODE);
		else if (ft_atoi(&line[i]) < 0)
			print_error(NEGATIVE_TEXTURE_CODE);
		i++;
	}
}

void		fill_map(t_wolf3d *wolf, t_list *lst)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = len_list(lst);
	while (i < size && lst)
	{
		fill_struct(&wolf->map[i], count_valid_members((char *)lst->content,
				lst->content_size), i, *lst);
		lst = lst->next;
		i++;
	}
}
