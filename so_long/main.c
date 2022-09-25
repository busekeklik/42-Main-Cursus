/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:52:47 by bkeklik           #+#    #+#             */
/*   Updated: 2022/09/14 11:52:49 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_put(t_data *data)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	image(data);
	while (i < data->map_y)
	{
		j = 0;
		while (j <= data->map_x)
		{
			if (j == data->map_x)
			{
				c = c + 64;
				data->posit = 0;
			}
			else
				image_put_func(data, i, j, c);
			j++;
		}
		i++;
	}
}

void	image(t_data *data)
{
	data->p_front = mlx_xpm_file_to_image(data->mlx, UP, \
		&data->imgx, &data->imgy);
	data->p_left = mlx_xpm_file_to_image(data->mlx, LEFT, \
		&data->imgx, &data->imgy);
	data->p_right = mlx_xpm_file_to_image(data->mlx, RIGHT, \
		&data->imgx, &data->imgy);
	data->p_back = mlx_xpm_file_to_image(data->mlx, DOWN, \
		&data->imgx, &data->imgy);
	data->collectible = mlx_xpm_file_to_image(data->mlx, CLT, \
		&data->imgx, &data->imgy);
	data->bckground = mlx_xpm_file_to_image(data->mlx, GND, \
		&data->imgx, &data->imgy);
	data->gate1 = mlx_xpm_file_to_image(data->mlx, GATE, \
		&data->imgx, &data->imgy);
	data->side = mlx_xpm_file_to_image(data->mlx, SIDE, \
		&data->imgx, &data->imgy);
}

void	put_image(void *image, t_data *data, int posit, int posit2)
{
	mlx_put_image_to_window(data->mlx, data->mlx_window, \
	data->bckground, posit, posit2);
	mlx_put_image_to_window(data->mlx, data->mlx_window, image, posit, posit2);
	data->posit += 64;
}

void	image_put_func(t_data *data, int i, int j, int c)
{
	if (data->map[i][j] == '1')
		put_image(data->side, data, data->posit, c);
	else if (data->map[i][j] == 'E')
		put_image(data->gate1, data, data->posit, c);
	else if (data->map[i][j] == 'P')
	{
		if (data->p_snap == 'w')
			put_image(data->p_back, data, data->posit, c);
		if (data->p_snap == 's')
			put_image(data->p_front, data, data->posit, c);
		if (data->p_snap == 'd')
			put_image(data->p_right, data, data->posit, c);
		if (data->p_snap == 'a')
			put_image(data->p_left, data, data->posit, c);
	}
	else if (data->map[i][j] == 'C')
		put_image(data->collectible, data, data->posit, c);
	else if (data->map[i][j] == '0')
		put_image(data->bckground, data, data->posit, c);
	else
		ft_error_data("Map has different characters", data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (ac == 2 && ber_control(av[1], data))
	{
		data->p_snap = 's';
		data->walk_count = 0;
		read_map(av[1], data);
		rectangular_control(data);
		where_is_p(data);
		check_collectible_and_exit(data);
		data->mlx = mlx_init();
		data->mlx_window = mlx_new_window(data->mlx, data->map_x * 64, \
		data->map_y * 64, "Minions");
		map_put(data);
		put_score(data);
		mlx_hook(data->mlx_window, 2, 1L << 0, key_event, data);
		mlx_hook(data->mlx_window, 17, 0, ft_free_data, data);
		mlx_loop(data->mlx);
	}
	else
		ft_error_data("You should enter 2 arguments", data);
	return (0);
}
