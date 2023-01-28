/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:06:50 by bkeklik           #+#    #+#             */
/*   Updated: 2022/10/15 20:54:21 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_stack *data)
{
	int	i;
	int	min;
	int	j;
	int	tmp;

	i = 0;
	while (i < data->a_len)
	{
		min = i;
		j = i + 1;
		while (j < data->a_len)
		{
			if (data->tmps[j] < data->tmps[min])
				min = j;
			j++;
		}
		tmp = data->tmps[i];
		data->tmps[i] = data->tmps[min];
		data->tmps[min] = tmp;
		i++;
	}
}
