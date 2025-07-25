/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:06:33 by idahhan           #+#    #+#             */
/*   Updated: 2025/07/22 15:47:00 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int is_texture_line(char *line)
{
    int i;

    i = 0;
    while(line[i] == ' ')
        i++;
    return(!ft_strncmp(line, "NO ", 3)
        || !ft_strncmp(line, "SO ", 3)
        || !ft_strncmp(line, "WE ", 3)
        || !ft_strncmp(line, "EA ", 3));
}

int is_color_line(char *line)
{
    int i;

    i = 0;
    while(line[i] == ' ')
        i++;
    return(!ft_strncmp(line, "F ", 2)
        || !ft_strncmp(line, "C ", 2));
}

int is_map_line(char *line)
{
    int i;

    i = 0;
    while(line[i] == ' ')
        i++;
    while (line)
    {
       if (line[i] != '1' && line[i] != '0'
            && line[i] != ' ' && line[i] != 'N'
            && line[i] != 'S' && line[i] != 'W'
            && line[i] != 'E')
            return(0);
        i++;
    }
    return(1);
}
