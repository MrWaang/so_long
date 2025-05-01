/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:41:36 by mah-ming          #+#    #+#             */
/*   Updated: 2025/05/01 21:33:48 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include "key.h"
# include "get_next_line.h"

typedef struct s_data
{
    char **map;
    int player[2];
    int nbr_item;
    int exit[2];
    size_t score;

    void *mlx;
    void *mlx_win;
    void *c_door;
    void *floor;
    void *item;
    void *o_door;
    void *player_door;
    void *player_floor;
    void *player_img;
    void *wall;
}              t_data;

char **parse(char *str);
unsigned int get_size_map(char *str);
void open_map(char *str, char **map, unsigned int size);
void check_map(char **map, unsigned int size);
void ft_perror();
void ft_error(char *str, char **map, int check);
void ft_free(char **map);
unsigned int ft_strlen(char *str);
void ft_check_duplicate(t_data *data);
void ft_find_point(t_data *data);
int ft_flood_fill(char **map, int i, int j);
int	key_process(int key, t_data *data);
void open_mlx_window(t_data *data);
void render_texture(t_data *data);
void *load_image(t_data *data, char *path);
void render_player(t_data *data);
void render_map(t_data *data);
void *render_pixel(t_data *data, int pixel);

#endif
