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


// void    read_cub_file(t_config *config)
// {
//     int     fd;
//     char    *line;
//     bool    map_started;
//     char    *trimmed;
//     t_list  *map_lines;

//     map_lines = NULL;
//     map_started = false;
//     fd = open(config->filename, O_RDONLY);
//     if (fd == -1)
//         error_exit("File not found");
//     line = get_next_line(fd);
//     while((line = get_next_line(fd)))
//     {
//         trimmed = ft_strtrim(line, " \t");
//         free(line);
//         if (trimmed[0] == '\0')
//         {
//             free(trimmed);
//             continue;
//         }
//         printf("trimmed : %s\n", trimmed);
//         if (!map_started && is_texture_line(trimmed))
//             parse_textures(trimmed, &config->textures);
//         else if (!map_started && is_color_line(trimmed))
//         {
//             printf("color\n");
//             // parse_color(trimmed, &config->colors);
//         }
//         else
//         {
//             if (!all_textures_are_set(&config->textures))
//                 error_exit("Textures must be defined before map");
//             map_started = true;
//             ft_lstadd_back(&map_lines, ft_lstnew(trimmed));
//             printf("map\n");
//         }
//     }
//     close(fd);
//     if (!map_lines)            
//         error_exit("map not found in .cub file");
//     // parse_map(map_lines, config);
//     ft_lstclear(&map_lines, free);
// }
