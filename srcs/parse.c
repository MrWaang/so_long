/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:47:45 by mah-ming          #+#    #+#             */
/*   Updated: 2025/04/30 18:05:35 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **parse(char *str)
{
   unsigned int size;
   char **map;

   size = get_size_map(str);
   map = malloc(sizeof(char *) * (size + 1));
   if(!map)
        ft_error("error malloc", 0, 0);
    map[size] = NULL;
    open_map(str, map, size);
    check_map(map, size);
    return (map);
}

unsigned int get_size_map(char *str)
{
    int fd;
    unsigned int size;
    char *line;
    
    fd = open(str, O_RDONLY);
    if (fd == -1)
        ft_perror();
    size = 0;
    while(1)
    {
         line = get_next_line(fd);
         if (!line)
            break;
        free(line);
        size++;
    }
    close(fd);
    return (size);
}

void open_map(char *str, char **map, unsigned int size)
{
    int fd;
    unsigned int i;
    char *line;

    i = 0;
    fd = open(str, O_RDONLY);
    if (fd == -1)
    {
        free(map);
        ft_perror();
    }
    while (i < size)
    {
        line = get_next_line(fd);
        if(!line)
            break;
        if(line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
        map[i] = line;
        i++;
    }
    close(fd);
}

void check_map(char **map, unsigned int size)
{
    unsigned int i;
    unsigned int j;
    unsigned int size_line;

    i = 0;
    size_line = (unsigned int)ft_strlen(map[i]);
    while(map[i])
    {
        j = 0;
        if(size_line != ft_strlen(map[i]))
            ft_error("error size map", map, 1);
        while(map[i][j])
        {
            if ((i == 0 || i == size - 1) && map[i][j] != '1')
                ft_error("map struct error", map, 1);
            if ((j == 0 || j == size_line - 1) && map[i][j] != '1')
                ft_error("map struct error", map, 1);
            if(map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'P')
                ft_error("error map", map, 1);
            j++;
        }
        i++;
    }
}

void ft_check_duplicate(t_data *data)
{
    int index_p;
    int index_e;
    int index[2];

    data->nbr_item = 0;
    index[0] = 0;
    index_p = 0;
    index_e = 0;
    while (data->map[index[0]])
    {
        index[1] = 0;
        while (data->map[index[0]][index[1]])
        {
            if (data->map[index[0]][index[1]] == 'E')
                index_e++;
            else if (data->map[index[0]][index[1]] == 'P')
                index_p++;
            else if (data->map[index[0]][index[1]] == 'C')
                data->nbr_item++;
            index[1]++;
        }
        index[0]++;
    }
    if (index_e != 1 || index_p != 1)
        ft_error("error data map", data->map, 1);
}
void ft_find_point(t_data *data)
{
    int index[2];

    data->nbr_item = 0;
    index[0] = 0;
    while (data->map[index[0]])
    {
        index[1] = 0;
        while (data->map[index[0]][index[1]])
        {
            if (data->map[index[0]][index[1]] == 'E')
            {
                data->exit[0] = index[1];
                data->exit[1] = index[0];
            } 
            else if (data->map[index[0]][index[1]] == 'P')
            {
                data->player[0] = index[1];
                data->player[1] = index[0];
            }
            index[1]++;
        }
        index[0]++;
    }
}

int ft_flood_fill(char **map, int i, int j)
{
    if (map[j][i] == '1' || map[j][i] == 'o' || map[j][i] == 'c' || map[j][i] == 'e')
        return (0);
    if (map[j][i] == 'C')
        map[j][i] = 'c';
    if (map[j][i] == '0')
        map[j][i] = 'o';
    if (map[j][i] == 'E')
    {
        map[j][i] = 'e';
        return (ft_flood_fill(map, i, j + 1) +  ft_flood_fill(map, i + 1, j) + ft_flood_fill(map, i, j - 1) + ft_flood_fill(map, i - 1, j) + 1);
    }
    return ((ft_flood_fill(map, i, j + 1) +  ft_flood_fill(map, i + 1, j) + ft_flood_fill(map, i, j - 1) + ft_flood_fill(map, i - 1, j)));
}
