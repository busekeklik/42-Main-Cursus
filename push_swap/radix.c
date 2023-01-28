/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:33:49 by bkeklik           #+#    #+#             */
/*   Updated: 2022/10/04 21:33:49 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack *data, int nbr)
{
	int	i;

	i = -1;
	while (++i < data->len)
	{
		if (data->tmps[i] == nbr)
		{
			return (i);
		}
	}
	return (0);
}

void	radix(t_stack *data)
{
	int	max;

	max = data->a_len - 1;
	while (max > 0)
	{
		data->max_bit++;
		max /= 2;
	}
}

void	radix_2(t_stack *data)
{
	int	i;
	int	x;
	int	alen;

	i = 0;
	alen = data->a_len;
	while (i < data->max_bit)
	{
		x = 0;
		while (x < alen)
		{
			if ((find_index(data, data->a_s[0]) >> i & 1))
				rotate_a(data);
			else
				push_b(data);
			x++;
		}
		while (data->b_len)
			push_a(data);
		i++;
	}
}
