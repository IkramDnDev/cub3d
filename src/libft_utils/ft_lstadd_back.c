/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:44:47 by idahhan           #+#    #+#             */
/*   Updated: 2025/07/20 18:45:07 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		current = *lst;
		while (current -> next != NULL)
		{
			current = current -> next;
		}
		current -> next = new;
	}
}
