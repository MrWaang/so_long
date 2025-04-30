/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:41:36 by mah-ming          #+#    #+#             */
/*   Updated: 2025/04/30 18:05:34 by mah-ming         ###   ########.fr       */
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
int	close_win(t_data *data);

#endif