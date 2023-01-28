/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_edit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:59:20 by bkeklik           #+#    #+#             */
/*   Updated: 2022/10/15 21:56:26 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_numbers(t_stack *data)
{
	int		i;
	char	*str;

	str = data->str;
	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] == ' ') || \
		str[i] == '-' || str[i] == '+'))
			error(data);
		if ((str[i] == '-' || str[i] == '+') && \
		(str[i + 1] == '-' || str[i + 1] == '+'))
			error(data);
		if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] == '-' || \
		str[i + 1] == '+'))
			error(data);
		if ((str[i] == '-' || str[i] == '+') && \
		(str[i + 1] == ' ' || str[i + 1] == ' ' || str[i + 1] == '\0'))
			error(data);
		i++;
	}
}

void	edit_stacks(t_stack *data)
{
	int	i;

	i = 0;
	while (data->numbers[i])
		i++;
	data->a_s = ft_calloc(i, sizeof(int));
	data->b_s = ft_calloc(i, sizeof(int));
	data->tmps = ft_calloc(i, sizeof(int));
	data->a_len = i;
	data->len = data->a_len;
	data->b_len = 0;
	i = 0;
	while (data->numbers[i])
	{
		data->a_s[i] = ft_atoip(data->numbers[i], data);
		data->tmps[i] = ft_atoip(data->numbers[i], data);
		i++;
	}
	data->ac = data->a_len;
}

void	repeat_numbers(t_stack *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->a_len)
	{
		j = i + 1;
		while (j < data->a_len)
		{
			if (data->a_s[i] == data->a_s[j])
				error(data);
			j++;
		}
		i++;
	}
}

void	sort_control(t_stack *data)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (i + 1 < data->len)
	{
		if (data->a_s[i] < data->a_s[i + 1])
			count++;
		i++;
	}
	if (count == data->len)
		exit(1);
}
