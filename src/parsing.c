/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:00:54 by idahhan           #+#    #+#             */
/*   Updated: 2025/07/22 18:18:21 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_file(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (file[len - 1] != 'b' || file[len - 2] != 'u' || file[len - 3] != 'c'
		|| file[len - 4] != '.')
	{
		write(2, "Error\nfile not valid\n", 21);
		exit(EXIT_FAILURE);
	}
}

// bool    all_textures_are_set(t_textures *textures)
// {
//     return (textures->north && textures->south &&
//         textures->west && textures->east);
// }

void    check_map(t_config *config)
{
    check_file(config->filename); 
    read_cub_file(config);
}
