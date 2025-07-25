#include "../include/cub3d.h"

static void    assign_textures(char **dir, char *content)
{
    int i;

    i = 0;
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
    else
        write(2, "invalid texture\n", 15);
}
