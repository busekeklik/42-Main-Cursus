/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:58:55 by bkeklik           #+#    #+#             */
/*   Updated: 2022/09/15 14:00:46 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_data(char *str, t_data *data)
{
	int	i;

	i = 0;
	ft_printf("%s\n", str);
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	free(data);
	exit(EXIT_FAILURE);
}

int	ft_free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	ft_destroy_mlx(data);
	free(data);
	exit(EXIT_SUCCESS);
	return (1);
}

void	copy_map_error(t_data *data)
{
	int	i;

	i = 0;
	if (data->copy_map)
	{
		while (data->copy_map[i])
		{
			free(data->copy_map[i]);
			i++;
		}
		free(data->copy_map);
	}
	ft_error_data("You have trouble with map!", data);
}

void	ft_destroy_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->p_back);
	mlx_destroy_image(data->mlx, data->p_front);
	mlx_destroy_image(data->mlx, data->p_left);
	mlx_destroy_image(data->mlx, data->p_right);
	mlx_destroy_image(data->mlx, data->gate1);
	mlx_destroy_image(data->mlx, data->side);
	mlx_destroy_image(data->mlx, data->bckground);
	mlx_destroy_window(data->mlx, data->mlx_window);
}

void	put_score(t_data *data)
{
	data->walk_count_on_screen = ft_itoa(data->walk_count);
	mlx_string_put(data->mlx, data->mlx_window, 5, 30, 0x000000, "Step : ");
	mlx_string_put(data->mlx, data->mlx_window, 50, 30, 0x000000, \
	data->walk_count_on_screen);
	free(data->walk_count_on_screen);
}
