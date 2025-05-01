/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:41:46 by mah-ming          #+#    #+#             */
/*   Updated: 2025/05/01 21:33:48 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int ac, char **av)
{
    t_data data;

    if (ac != 2)
    {
        write(2, "Error\n", 7);
        return (1);
    }
    data.map = parse(av[1]);
    ft_check_duplicate(&data);
    ft_find_point(&data);
    if (ft_flood_fill(data.map, data.player[0], data.player[1]) == 0)
        ft_error("error flood fill\n", data.map, 1);
    open_mlx_window(&data);
    mlx_hook(data.mlx_win, 2, (1L<<0), key_process, &data);
	render_texture(&data);
    render_map(&data);
	render_player(&data);
    mlx_loop(data.mlx);
    return (0);
}
