/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:33:57 by bkeklik           #+#    #+#             */
/*   Updated: 2022/09/14 14:12:34 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_control(char *str, t_data *data)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (len >= 9 && str[len] == 'r' && str[len - 1] == 'e' && \
		str[len - 2] == 'b' && str[len - 3] == '.')
		return (1);
	else
		ft_error_data("The entered file name must have the ber extension.", \
		data);
	return (0);
}

void	read_map(char *address, t_data *data)
{
	char	*str;
	char	*tmp;
	int		fd;

	fd = open(address, O_RDONLY);
	if (fd < 0)
		ft_error_data("File not found.", data);
	tmp = get_next_line(fd);
	str = ft_strdup("");
	while (tmp)
	{
		str = ft_strjoin(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	data->map = ft_split(str, '\n');
	data->copy_map = ft_split(str, '\n');
	x_y(data);
	special_characters (str, data);
	free(str);
	close(fd);
}

void	x_y(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i][j])
		j++;
	data->map_x = j;
	while (data->map[i])
		i++;
	data->map_y = i;
}

void	rectangular_control(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[0][j] == '1')
		j++;
	j--;
	while (i < data->map_y && data->map[i][0] == '1' && \
	data->map[i][j] == '1' && (ft_strlen(data->map[i]) - 1) == j)
		i++;
	while (j >= 0 && data->map[i - 1][j] == '1')
		j--;
	if (j != -1 || i != data->map_y)
		ft_error_data("Map is not rectangular", data);
}

void	special_characters(char *str, t_data *data)
{
	static int	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == 'E')
			data->gate++;
		else if (str[i] == 'P')
			data->player++;
		else if (str[i] == 'C')
			data->coll++;
		else if (str[i] != '1' && str[i] != '0' && str[i] != '\n')
			ft_error_data("Map has different characters", data);
		i++;
	}
	if (data->gate != 1 || data->player != 1 || data->coll < 1)
		ft_error_data("Map should have 1 gate, 1 player and collactible/s", \
		data);
	data->coll2 = data->coll;
}
