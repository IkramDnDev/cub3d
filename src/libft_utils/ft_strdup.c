/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:30:07 by idahhan           #+#    #+#             */
/*   Updated: 2025/07/20 15:46:06 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	len;
	char	*ptr;

	len = ft_strlen(src);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ptr = copy;
	while (*src)
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (copy);
}
