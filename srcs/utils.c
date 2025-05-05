/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:45:06 by mah-ming          #+#    #+#             */
/*   Updated: 2025/05/05 21:49:13 by mah-ming         ###   ########.fr       */
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
    int width;
	int height;

	width = ft_strlen(data->map[0]) * 32;
	height = 0;
	while (data->map[height])
		height++;
	height *= 32;

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, width, height, "so_long");
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
    data->c_door = load_image(data, "./textures/c_door.xpm");
    data->floor = load_image(data, "./textures/floor.xpm");
    data->item = load_image(data, "./textures/item.xpm");
    data->o_door = load_image(data, "./textures/o_door.xpm");
    data->player_door = load_image(data, "./textures/player_door.xpm");
    data->player_floor = load_image(data, "./textures/player_floor.xpm");
    data->player_img = load_image(data, "./textures/player.xpm");
    data->wall = load_image(data, "./textures/wall.xpm");
}

void *render_pixel(t_data *data, int pixel)
{
	void *img;

	img = NULL;
	if(pixel == '1')
		img = data->wall;
	else if (pixel == 'o')
		img = data->floor;
	else if (pixel == 'e')
		img = data->c_door;
	else if (pixel == 'c')
		img = data->item;
    else if (pixel == 'P')
        img = data->player_img;
    return (img);
}

void render_map(t_data *data)
{
	int index[2];
	void *img;

	index[0] = 0;
    while (data->map[index[0]])
    {
        index[1] = 0;
        while (data->map[index[0]][index[1]])
        {
            img = render_pixel(data, data->map[index[0]][index[1]]);
			mlx_put_image_to_window(data->mlx, data->mlx_win, img, index[1] * 32, index[0] * 32);
            index[1]++;
        }
        index[0]++;
    }
}

void render_player(t_data *data)
{
	int x = data->player[0];
	int y = data->player[1];

	mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, x * 32, y * 32);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_img, x * 32, y * 32);
}
