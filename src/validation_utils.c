/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:48:51 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/14 22:21:15 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

size_t		count_valid_members(char *line, size_t size)
{
	size_t	val;
	size_t	i;

	i = 0;
	val = 0;
	while (i < size)
	{
		if (line[i] && ft_isdigit(line[i]))
		{
			val++;
			while (ft_isdigit(line[i]) && line[i])
				i++;
		}
		i++;
	}
	return (val);
}

size_t		len_list(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

size_t		find_maximum_valid_num(t_list *lst)
{
	size_t	num;
	size_t	curr;

	num = count_valid_members((char *)lst->content, lst->content_size);
	while (lst)
	{
		if ((curr = count_valid_members((char *)lst->content,
				lst->content_size)) > num)
			num = curr;
		lst = lst->next;
	}
	return (num);
}

void		alloc_map(t_wolf3d *wolf, t_list *lst)
{
	size_t	size;
	size_t	len;
	size_t	i;

	i = 0;
	len = find_maximum_valid_num(lst);
	size = len_list(lst);
	wolf->map = init_map(size);
	while (i < size)
	{
		wolf->map[i] = init_member(len);
		i++;
	}
	wolf->len_array_y = size;
	wolf->len_array_x = len;
}
