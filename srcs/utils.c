/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:45:06 by mah-ming          #+#    #+#             */
/*   Updated: 2025/05/01 17:48:12 by mah-ming         ###   ########.fr       */
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

void open_mlx_window(t_data *data)
{
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "so_long");
}

int	key_process(int key, t_data *data)
{
    if (key == ESC || key == CROSS)
	    mlx_destroy_window(data->mlx, data->mlx_win);
	return (0);
}

void *load_image(t_data *data, char *path)
{
    void *img;
    int i;
    int j;

    img = mlx_xpm_file_to_image(data->mlx, path, &i, &j);
    return (img);
}

void render_texture(t_data *data)
{
    data->c_door = load_image(data, "./textutes/c_door.xpm");
    data->floor = load_image(data, "./textures/floor.xpm");
    data->item = load_image(data, "./textures/item.xpm");
    data->o_door = load_image(data, "./textures/o_door.xpm");
    data->player_door = load_image(data, "./textures/player_door.xpm");
    data->player_floor = load_image(data, "./textures/player_floor.xpm");
    data->player_img = load_image(data, "./textures/player.xpm");
    data->wall = load_image(data, "./textures/wall.xpm");
}

void render_player(t_data *data)
{
    if (data->map[data->player[0]][data->player[1]] == 'E')
    {
        mlx_put_image_to_window(data->mlx, data->mlx_win, data->o_door, data->player[0], data->player[1])
    }
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_img, data->player[0], data->player[1])
}

void *render_pixel(t_data *data, int pixel)
{
	void *img;

	img = NULL;
	if(pixel == '1')
		img = data->wall;
	else if (pixel == '0')
		img = data->floor;
	else if (pixel == 'E')
		img = data->c_door;
	else if (pixel == 'C')
		img = data->item;
	return (img);
}

void render_map(t_data *data)
{
	int i;
	int j;
	void *img;

	i = 0;
	while(data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			img = render_pixel(data, data->map[i][j])
			mlx_put_image_to_window(data->mlx, data->mlx_win, img, i, j);
			j++;
		}
		i++;
	}
}
