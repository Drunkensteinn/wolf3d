/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 21:12:24 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/19 19:13:06 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

size_t	count_valid_members(char *line, size_t size)
{
	size_t val;
	size_t i;

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

size_t len_list(t_list *lst)
{
	size_t len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}


int32_t start_end_column(t_map *map, size_t len)
{
	size_t	i;
	int32_t	counter_begin;
	int32_t	counter_end;

	i = 0;
	counter_begin = 0;
	counter_end = 0;
	while (i < len - 1 && map[i].texture == DEFAULT_TEXTURE)
	{
		counter_begin++;
		i++;
	}
	i = len - 1;
	while (i > 0 && map[i].texture == DEFAULT_TEXTURE)
	{
		counter_end++;
		i--;
	}
	if (counter_begin > counter_end)
		return (counter_end - counter_begin);
	else if (counter_begin < counter_end)
		return (counter_end - counter_begin);
	return (0);
}

t_bool	start_end_raw(t_wolf3d *wolf)
{
	size_t i;

	i = 0;
	while (i < wolf->len_array_x)
	{
		 if (wolf->map[INDEX(1)][i].texture != DEFAULT_TEXTURE)
		 {
			 map_rewrite(wolf, INDEX(1), 0);
			 return (true);
		 }
		 i++;
	}
	i = 0;
	while (i < wolf->len_array_x)
	{
		if (wolf->map[INDEX(wolf->len_array_y)][i].texture != DEFAULT_TEXTURE)
		{
			map_rewrite(wolf, INDEX(wolf->len_array_y), 0);
			return (true);
		}
		i++;
	}
	return (false);
}

void	source_rewrite(t_wolf3d *wolf, int32_t fd, char *path)
{
	size_t	i;
	size_t	j;

	/*
	** open and close fd, no lseek, F**K the Subject
	*/

	i = 0;
	close(fd);
	if (!(fd = open(path, O_RDWR)) || fd < 0)
		print_error(BAD_ACCESS);
	while (i < wolf->len_array_y)
	{
		j = 0;
		while (j < wolf->len_array_x)
		{
			ft_putnbr_fd(wolf->map[i][j].texture, fd);
			ft_putchar_fd(' ', fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
}

void	map_rewrite(t_wolf3d *wolf, size_t row, int32_t pos)
{
	size_t index;
	size_t limit;

	index = 0;
	limit = wolf->len_array_x;
	if (pos < 0)
		index = wolf->len_array_x - FT_ABS(pos);
	else if (pos == 0)
		index = 0;
	else if (pos > 0)
	{
		limit = (size_t)pos;
		index = 0;
	}
	while (index < limit)
	{
		wolf->map[row][index].texture = DEFAULT_TEXTURE;
		index++;
	}
}

void	validate_map(t_wolf3d *wolf, int32_t fd, char *path)
{
	t_bool	changes;
	int32_t	to_valid_pos;
	size_t	to_valid_row;
	size_t	i;

	i = 0;
	changes = false;
	if (start_end_raw(wolf))
		changes = true;
	while (i < wolf->len_array_y)
	{
		if ((to_valid_pos = start_end_column(wolf->map[i], wolf->len_array_x)))
		{
			to_valid_row = i;
			changes = true;
			map_rewrite(wolf, to_valid_row, to_valid_pos);
		}
		i++;
	}
	if (changes)
		source_rewrite(wolf, fd, path);
}

size_t	find_maximum_valid_num(t_list *lst)
{
	size_t	num;
	size_t	curr;

	num = count_valid_members((char *)lst->content, lst->content_size);
	while (lst)
	{
		if ((curr = count_valid_members((char *)lst->content, lst->content_size)) > num)
			num = curr;
		lst = lst->next;
	}
	return (num);
}

void	alloc_map(t_wolf3d *wolf, t_list *lst)
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

void fill_struct(t_map **map, size_t len_array, size_t index, t_list lst)
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
		i++;
	}
}

void fill_map(t_wolf3d *wolf, t_list *lst)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = len_list(lst);
	while (i < size && lst)
	{
		fill_struct(&wolf->map[i], count_valid_members((char *)lst->content, lst->content_size), i, *lst);
		lst = lst->next;
		i++;
	}
}

void	tmp_list(t_list **lst, const void *content, const size_t content_size)
{
	t_list *tmp;

	if (!*lst)
		*lst = ft_lstnew(content, content_size);
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(content, content_size);
	}
}

void	del_list(t_list *lst)
{
	t_list *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		ft_memdel(&tmp->content);
		ft_memdel((void *)&tmp);
	}
}

void	read_and_valid(t_wolf3d *wolf, char *path)
{
	char	*line;
	int32_t fd;
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