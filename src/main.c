/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 09:56:55 by idahhan           #+#    #+#             */
/*   Updated: 2025/07/20 15:52:05 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void initialization(t_config *config, char **av)
{
    config->filename = av[1];
    config->textures.north = NULL;
    config->textures.south = NULL;
    config->textures.west = NULL;
    config->textures.east = NULL;
}

int main(int ac, char **av)
{
    t_game  game;

    if (ac != 2)
        error_exit("Usage : ./cub3d map.cub");
    initialization(&game.config, av);
    check_map(&game.config);
    return (0);
}
