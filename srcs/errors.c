/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:08:49 by mah-ming          #+#    #+#             */
/*   Updated: 2025/05/05 23:02:04 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_perror()
{
    write(2, "Error\n", 7);
    perror(0);
    exit(EXIT_FAILURE);
}

void ft_error(char *str, char **map, int check)
{
    if (check == 1)
        ft_free(map);
    if (str)
        write(2, str, ft_strlen(str));
    exit(EXIT_FAILURE);
}

void ft_free(char **map)
{
    int i;

    i = 0;
    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int close_prog(void)
{
    exit(EXIT_SUCCESS);
}