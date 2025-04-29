/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:41:46 by mah-ming          #+#    #+#             */
/*   Updated: 2025/04/29 18:39:49 by mah-ming         ###   ########.fr       */
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
    printf("player :%d,%d, exit:%d,%d", data.player[0], data.player[1], data.exit[0], data.exit[1]);
    ft_error("test", data.map, 1);
    return (0);
}