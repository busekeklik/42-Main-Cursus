/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:46:14 by bkeklik           #+#    #+#             */
/*   Updated: 2022/09/14 14:46:17 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	where_is_p(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->copy_map[y])
	{
		x = 0;
		while (data->copy_map[y][x])
		{	
			if (data->copy_map[y][x] == 'P')
			{
				valid_map(data, x, y);
				data->px = x;
				data->py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	valid_map(t_data *data, int x, int y)
{
	char	*point;

	point = &data->copy_map[y][x];
	if (*point == 'E')
		data->map_is_true = 1;
	if (*point != '1' && *point != 'E')
	{
		if (*point == 'C')
			data->coll2--;
		*point = '.';
		if (data->copy_map[y][x + 1] != '1'
		&& data->copy_map[y][x + 1] != '.')
			valid_map(data, x + 1, y);
		if (data->copy_map[y][x - 1] != '1'
		&& data->copy_map[y][x - 1] != '.')
			valid_map(data, x - 1, y);
		if (data->copy_map[y + 1][x] != '1'
		&& data->copy_map[y + 1][x] != '.')
			valid_map(data, x, y + 1);
		if (data->copy_map[y - 1][x] != '1'
		&& data->copy_map[y - 1][x] != '.')
			valid_map(data, x, y - 1);
	}
}

void	check_collectible_and_exit(t_data *data)
{
	int	i;

	if (data->coll2 != 0)
		copy_map_error(data);
	if (data->map_is_true == 0)
		copy_map_error(data);
	i = 0;
	while (data->copy_map[i])
	{
		free(data->copy_map[i]);
		i++;
	}
	free(data->copy_map);
}
