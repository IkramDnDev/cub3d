/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:43:44 by idahhan           #+#    #+#             */
/*   Updated: 2025/07/20 18:44:02 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_noeud;

	new_noeud = (t_list *)malloc(sizeof(t_list));
	if (new_noeud == NULL)
		return (NULL);
	new_noeud -> content = content;
	new_noeud -> next = NULL;
	return (new_noeud);
}
