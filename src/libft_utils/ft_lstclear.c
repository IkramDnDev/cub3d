/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:47:26 by idahhan           #+#    #+#             */
/*   Updated: 2025/07/20 18:47:53 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*debut;
	t_list	*temp;

	if (!lst || !del)
		return ;
	debut = *lst;
	while (debut)
	{
		temp = debut;
		debut = debut -> next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}
