/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_list_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:56:56 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/14 22:19:34 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		tmp_list(t_list **lst, const void *content,
			const size_t content_size)
{
	t_list	*tmp;

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

void		del_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		ft_memdel(&tmp->content);
		ft_memdel((void *)&tmp);
	}
}
