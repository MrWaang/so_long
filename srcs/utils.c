/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:45:06 by mah-ming          #+#    #+#             */
/*   Updated: 2025/04/30 18:05:33 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int ft_strlen(char *str)
{
    unsigned int i;
    
    if (!str || !str[0])
        return (0);
    i = 0;
    while(str[i])
        i++;
    return (i);
}
int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	return (0);
}
int key_press(t_data *data)
{
    mlx_key_hook(data->mlx_win, *data);
}