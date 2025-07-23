/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 09:57:01 by idahhan           #+#    #+#             */
/*   Updated: 2025/07/20 18:55:54 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <mlx.h>

// ───────────── TEXTURE PATHS ─────────────
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

typedef struct s_textures
{
	char	*north;	// Path to north texture
	char	*south;	// Path to south texture
	char	*east;	// Path to east texture
	char	*west;	// Path to west texture
}	t_textures;

// ───────────── FLOOR & CEILING COLORS ─────────────
typedef struct s_colors
{
	int		floor;		// Stored as 0xRRGGBB
	int		ceiling;
}	t_colors;

// ───────────── PLAYER STRUCT ─────────────
typedef struct s_player
{
	double	px;		// Player x-position (in units)
	double	py;		// Player y-position
	int		map_x;	// Player cell x (for grid map)
	int		map_y;	// Player cell y
	char	dir;	// Direction 'N', 'S', 'E', 'W'
	double	angle;	// View angle in radians (for raycasting)
}	t_player;

// ───────────── CONFIG STRUCT (PARSING PART) ─────────────
typedef struct s_config
{
	char		*filename;
	t_textures	textures;		// Texture paths
	t_colors	colors;			// Floor / Ceiling RGB
	char		**map;			// 2D array (map[y][x])
	int			map_width;
	int			map_height;
	t_player	player;			// Initial player setup

	// Validation flags (used to check if data is set)
	int			has_texture[4];	// NO=0, SO=1, WE=2, EA=3
	int			has_floor;
	int			has_ceiling;
	int			player_found;
}	t_config;

// ───────────── GAME STRUCT (USED BY RENDERING PART) ─────────────
typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_config	config;			// Data parsed from .cub file
}	t_game;

void    error_exit(char *msg);
void	check_map(t_config *config);
int		is_texture_line(char *line);
int		is_color_line(char *line);
int		is_map_line(char *line);
char	*get_next_line(int fd);

//libft functions

char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));

#endif