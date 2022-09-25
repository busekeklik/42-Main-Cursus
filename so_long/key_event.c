/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:29:29 by bkeklik           #+#    #+#             */
/*   Updated: 2022/09/23 16:29:32 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_event(int keycode, t_data *data)
{
	if (keycode == 13)
	{
		data->p_snap = 'w';
		up(data);
	}
	if (keycode == 0)
	{
		data->p_snap = 'a';
		left(data);
	}
	if (keycode == 1)
	{
		data->p_snap = 's';
		down(data);
	}
	if (keycode == 2)
	{
		data->p_snap = 'd';
		right(data);
	}
	if (keycode == 53)
		ft_free_data(data);
	return (1);
}

void	up(t_data *data)
{
	if (data->map[data->py - 1][data->px] != '1' && \
	data->map[data->py - 1][data->px] != 'E')
	{
		if (data->map[data->py - 1][data->px] == 'C')
			data->coll--;
		data->map[data->py - 1][data->px] = 'P';
		data->map[data->py][data->px] = '0';
		data->py--;
		mlx_clear_window(data->mlx, data->mlx_window);
		map_put(data);
		ft_printf("Step = %d\n", ++data->walk_count);
		put_score(data);
	}
	else if (data->map[data->py - 1][data->px] == 'E')
	{
		if (data->coll == 0)
		{
			ft_printf("End Game = %d\n", ++data->walk_count);
			ft_free_data(data);
		}
	}
}

void	down(t_data *data)
{
	if (data->map[data->py + 1][data->px] != '1' && \
	data->map[data->py + 1][data->px] != 'E')
	{
		if (data->map[data->py + 1][data->px] == 'C')
			data->coll--;
		data->map[data->py + 1][data->px] = 'P';
		data->map[data->py][data->px] = '0';
		data->py++;
		mlx_clear_window(data->mlx, data->mlx_window);
		map_put(data);
		ft_printf("Step = %d\n", ++data->walk_count);
		put_score(data);
	}
	else if (data->map[data->py + 1][data->px] == 'E')
	{
		if (data->coll == 0)
		{
			ft_printf("End Game = %d\n", ++data->walk_count);
			ft_free_data(data);
		}
	}
}

void	left(t_data *data)
{
	if (data->map[data->py][data->px - 1] != '1' && \
	data->map[data->py][data->px - 1] != 'E')
	{
		if (data->map[data->py][data->px - 1] == 'C')
			data->coll--;
		data->map[data->py][data->px - 1] = 'P';
		data->map[data->py][data->px] = '0';
		data->px--;
		mlx_clear_window(data->mlx, data->mlx_window);
		map_put(data);
		ft_printf("Step = %d\n", ++data->walk_count);
		put_score(data);
	}
	else if (data->map[data->py][data->px - 1] == 'E')
	{
		if (data->coll == 0)
		{
			ft_printf("End Game = %d\n", ++data->walk_count);
			ft_free_data(data);
		}
	}
}

void	right(t_data *data)
{
	if (data->map[data->py][data->px + 1] != '1' && \
	data->map[data->py][data->px + 1] != 'E')
	{
		if (data->map[data->py][data->px + 1] == 'C')
			data->coll--;
		data->map[data->py][data->px + 1] = 'P';
		data->map[data->py][data->px] = '0';
		data->px++;
		mlx_clear_window(data->mlx, data->mlx_window);
		map_put(data);
		ft_printf("Step = %d\n", ++data->walk_count);
		put_score(data);
	}
	else if (data->map[data->py][data->px + 1] == 'E')
	{
		if (data->coll == 0)
		{
			ft_printf("End Game = %d\n", ++data->walk_count);
			ft_free_data(data);
		}
	}
}
