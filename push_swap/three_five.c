/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:48:40 by bkeklik           #+#    #+#             */
/*   Updated: 2022/10/04 20:48:40 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	distribute_arg(t_stack *data)
{
	if (data->ac == 2)
		swap_a(data);
	else if (data->ac == 3)
		three(data);
	else if (data->ac == 5)
		five(data);
	else if (data->ac == 4 || data->ac >= 6)
	{
		radix(data);
		radix_2(data);
	}
	else
		return ;
}

void	three(t_stack *data)
{
	if (data-> a_s[0] < data->a_s[1] && data-> a_s[0] < data->a_s[2] \
	&& data-> a_s[1] < data->a_s[2])
		return ;
	if (data->a_s[0] < data->a_s[1] && data->a_s[2] < data->a_s[1] && \
	data->a_s[2] > data->a_s[0])
	{
		swap_a(data);
		rotate_a(data);
	}
	else if (data->a_s[0] > data->a_s[1] && data->a_s[2] > data->a_s[0] \
	&& data->a_s[1] < data->a_s[2])
		swap_a(data);
	else if (data->a_s[0] < data->a_s[1] && data->a_s[0] > data->a_s[2] \
	&& data->a_s[1] > data->a_s[2])
		rev_rotate_a(data);
	else if (data->a_s[0] > data->a_s[1] && data-> a_s[0] > data->a_s[2] \
	&& data->a_s[1] < data->a_s[2])
		rotate_a(data);
	else if (data->a_s[0] > data->a_s[1] && data->a_s[1] > data->a_s[2])
	{
		rotate_a(data);
		swap_a(data);
	}
}

void	five(t_stack *data)
{
	while (data->tmps[2] <= data->a_s[0])
		rotate_a(data);
	if (data->tmps[2] > data->a_s[0])
		push_b(data);
	while (data->tmps[2] <= data->a_s[0])
		rotate_a(data);
	if (data->tmps[2] > data->a_s[0])
		push_b(data);
	three(data);
	if (data->b_s[1] > data->b_s[0])
		swap_b(data);
	push_a(data);
	push_a(data);
}
