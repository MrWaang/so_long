/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 04:56:39 by tbraud            #+#    #+#             */
/*   Updated: 2025/05/19 17:34:33 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_up(t_ptr *ptr)
{
	void	*img;

	if (ptr->map[ptr->player[1] - 1][ptr->player[0]] == '1')
		return ;
	ptr->index++;
	ft_putnbr(ptr->index);
	write(1, "\n", 1);
	if (ptr->map[ptr->player[1] - 1][ptr->player[0]] == 'o'
		|| ptr->map[ptr->player[1] - 1][ptr->player[0]] == 'c')
		img = ptr->img[3];
	if (ptr->map[ptr->player[1] - 1][ptr->player[0]] == 'c')
		ptr->item--;
	if (ptr->map[ptr->player[1] - 1][ptr->player[0]] == 'e' && ptr->item == 0)
		ft_exit_mlx(ptr, 0);
	if (ptr->map[ptr->player[1] - 1][ptr->player[0]] == 'e')
		img = ptr->img[6];
	mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, img, ptr->player[0] * 32,
		(ptr->player[1] - 1) * 32);
	if (ptr->player[0] == ptr->exit[0] && ptr->player[1] == ptr->exit[1])
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[4],
			ptr->player[0] * 32, ptr->player[1] * 32);
	else
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[7],
			ptr->player[0] * 32, ptr->player[1] * 32);
	ptr->player[1]--;
}

static void	ft_down(t_ptr *ptr)
{
	void	*img;

	if (ptr->map[ptr->player[1] + 1][ptr->player[0]] == '1')
		return ;
	ptr->index++;
	ft_putnbr(ptr->index);
	write(1, "\n", 1);
	if (ptr->map[ptr->player[1] + 1][ptr->player[0]] == 'o'
		|| ptr->map[ptr->player[1] + 1][ptr->player[0]] == 'c')
		img = ptr->img[3];
	if (ptr->map[ptr->player[1] + 1][ptr->player[0]] == 'c')
		ptr->item--;
	if (ptr->map[ptr->player[1] + 1][ptr->player[0]] == 'e' && ptr->item == 0)
		ft_exit_mlx(ptr, 0);
	if (ptr->map[ptr->player[1] + 1][ptr->player[0]] == 'e')
		img = ptr->img[6];
	mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, img, ptr->player[0] * 32,
		(ptr->player[1] + 1) * 32);
	if (ptr->player[0] == ptr->exit[0] && ptr->player[1] == ptr->exit[1])
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[4],
			ptr->player[0] * 32, ptr->player[1] * 32);
	else
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[7],
			ptr->player[0] * 32, ptr->player[1] * 32);
	ptr->player[1]++;
}

static void	ft_left(t_ptr *ptr)
{
	void	*img;

	if (ptr->map[ptr->player[1]][ptr->player[0] - 1] == '1')
		return ;
	ptr->index++;
	ft_putnbr(ptr->index);
	write(1, "\n", 1);
	if (ptr->map[ptr->player[1]][ptr->player[0] - 1] == 'o'
		|| ptr->map[ptr->player[1]][ptr->player[0] - 1] == 'c')
		img = ptr->img[3];
	if (ptr->map[ptr->player[1]][ptr->player[0] - 1] == 'c')
		ptr->item--;
	if (ptr->map[ptr->player[1]][ptr->player[0] - 1] == 'e' && ptr->item == 0)
		ft_exit_mlx(ptr, 0);
	if (ptr->map[ptr->player[1]][ptr->player[0] - 1] == 'e')
		img = ptr->img[6];
	mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, img, (ptr->player[0] - 1)
		* 32, ptr->player[1] * 32);
	if (ptr->player[0] == ptr->exit[0] && ptr->player[1] == ptr->exit[1])
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[4],
			ptr->player[0] * 32, ptr->player[1] * 32);
	else
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[7],
			ptr->player[0] * 32, ptr->player[1] * 32);
	ptr->player[0]--;
}

static void	ft_right(t_ptr *ptr)
{
	void	*img;

	if (ptr->map[ptr->player[1]][ptr->player[0] + 1] == '1')
		return ;
	ptr->index++;
	ft_putnbr(ptr->index);
	write(1, "\n", 1);
	if (ptr->map[ptr->player[1]][ptr->player[0] + 1] == 'o'
		|| ptr->map[ptr->player[1]][ptr->player[0] + 1] == 'c')
		img = ptr->img[3];
	if (ptr->map[ptr->player[1]][ptr->player[0] + 1] == 'c')
		ptr->item--;
	if (ptr->map[ptr->player[1]][ptr->player[0] + 1] == 'e' && ptr->item == 0)
		ft_exit_mlx(ptr, 0);
	if (ptr->map[ptr->player[1]][ptr->player[0] + 1] == 'e')
		img = ptr->img[6];
	mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, img, (ptr->player[0] + 1)
		* 32, ptr->player[1] * 32);
	if (ptr->player[0] == ptr->exit[0] && ptr->player[1] == ptr->exit[1])
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[4],
			ptr->player[0] * 32, ptr->player[1] * 32);
	else
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[7],
			ptr->player[0] * 32, ptr->player[1] * 32);
	ptr->player[0]++;
}

void	ft_choose(int keycode, t_ptr *ptr) // faire un fonction plus global
{
	if (keycode == 'w')
		ft_up(ptr);
	else if (keycode == 's')
		ft_down(ptr);
	else if (keycode == 'a')
		ft_left(ptr);
	else if (keycode == 'd')
		ft_right(ptr);
}

int	ft_event(int keycode, t_ptr *ptr)
{
	if (keycode == ESCAPE)
		ft_exit_mlx(ptr, 0);
	ft_choose(keycode, ptr);
	if (ptr->map[ptr->player[1]][ptr->player[0]] == 'c')
		ptr->map[ptr->player[1]][ptr->player[0]] = 'o';
	if (ptr->item == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[5],
			ptr->exit[0] * 32, ptr->exit[1] * 32);
	return (0);
}
