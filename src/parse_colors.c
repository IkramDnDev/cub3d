#include "../include/cub3d.h"

static bool is_valid_color_value(int color)
{
	return (color >= 0 && color <= 255);
}

void parse_colors(char *line, t_colors *colors)
{
	int	i;
	int r;
	int g;
	int b;
	int color;
	char *rgb_start;
	char **split;

	i = 1;
	while(line[i] == ' ' || line[i] == '\t')
		i++;
	rgb_start = line + i;
	split = ft_split(rgb_start, ',');
	if (!split || !split[0] || !split[1] || !split[2])
		error_exit("Color must have exactly 3 values: R,G,B");
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	
	if (!is_valid_color_value(r) || !is_valid_color_value(g) || !is_valid_color_value(b))
		error_exit("Color values must be between 0 and 255");
	color = (r << 16) | (g << 8) | b;
	if (line[0] == 'F')
		colors->floor = color;
	else if (line[0] == 'C')
		colors->ceiling = color;
	else
		error_exit("Unknown color identifier");
	ft_free_split(split);
}
