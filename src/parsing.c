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
void    assign_textures(char **dir, char *content)
{
    int i;

    i = 0;
    while (content[i] == ' ')
        i++;
    if (*dir)
        error_exit("Duplicate textures assignement");
    *dir = ft_strdup(&content[i]);
    if (!*dir)
        error_exit("Memory allocation failed");
}

void    parse_textures(char *textures_line, t_textures *textures)
{
    if (ft_strncmp(textures_line, "NO ", 3) == 0)
        assign_textures(&textures->north, textures_line + 3);
    else if (ft_strncmp(textures_line, "SO ", 3) == 0)
        assign_textures(&textures->south, textures_line + 3);
    else if (ft_strncmp(textures_line, "WE ", 3) == 0)
        assign_textures(&textures->west, textures_line + 3);
    else if (ft_strncmp(textures_line, "EA ", 3) == 0)
        assign_textures(&textures->east, textures_line + 3);
    
}

bool    all_textures_are_set(t_textures *textures)
{
    return (textures->north && textures->south &&
        textures->west && textures->east);
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


void test(t_config *config)
{
	int		fd;
	char	*line;
    char    *trimmed;

	fd = open(config->filename, O_RDONLY);
	if (fd < 0)
		error_exit("File not found");
	line = get_next_line(fd);
	while (line)
	{
        trimmed = ft_strtrim(line, " \t");
        free(line);
        if (trimmed[0] == '\0')
        {
            free(trimmed);
            continue;
        }
        printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
}

void    check_map(t_config *config)
{
    check_file(config->filename); 
    // read_cub_file(config);
    test(config);
}
