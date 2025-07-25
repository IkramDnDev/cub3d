#include "../include/cub3d.h"

void	read_cub_file(t_config *config)
{
	int		fd;
	char	*line;
	char	*trimmed;
	bool	map_started = false;

	fd = open(config->filename, O_RDONLY);
	if (fd < 0)
		error_exit("File not found");

	while ((line = get_next_line(fd)))
	{
		if (!map_started)
		{
			trimmed = ft_strtrim(line, " \t\n\r");
			if (trimmed[0] == '\0')
			{
				free(trimmed);
				free(line);
				continue;
			}
			if (is_texture_line(trimmed))
			{
				parse_textures(trimmed, &config->textures);
				free(trimmed);
				free(line);
				continue;
			}
			else if (is_color_line(trimmed))
			{
				parse_colors(trimmed, &config->colors);
				// printf("%s\n", trimmed);
				free(trimmed);
				free(line);
				continue;
			}
			map_started = true;
			free(trimmed);
		}
		else
		{
			trimmed = ft_strtrim(line, " \t\n\r");
			if (trimmed[0] == '\0')
			{
				free(trimmed);
				free(line);
				error_exit("Empty line inside map is not allowed");
			}
			free(trimmed);
		}
	}
	printf("F : %X\n", config->colors.floor);
	printf("C : %X\n", config->colors.ceiling);
	printf("north : %s\n", config->textures.north);
	printf("south : %s\n", config->textures.south);
	printf("east : %s\n", config->textures.east);
	printf("north : %s\n", config->textures.north);
	close(fd);
}