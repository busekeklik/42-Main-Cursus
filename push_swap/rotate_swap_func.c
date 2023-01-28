/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:40:33 by bkeklik           #+#    #+#             */
/*   Updated: 2022/10/01 19:40:33 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *data)
{
	int	i;
	int	d;

	i = 1;
	d = data->a_s[0];
	while (i < data->a_len)
	{
		data->a_s[i - 1] = data->a_s[i];
		i++;
	}
	data->a_s[data->a_len - 1] = d;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *data)
{
	int	tmp;
	int	i;
	int	d;

	i = 1;
	d = data->b_s[0];
	while (i < data->b_len)
	{
		tmp = data->b_s[i];
		data->b_s[i] = data->b_s[i - 1];
		data->b_s[i - 1] = tmp;
		i++;
	}
	data->b_s[data->b_len - 1] = d;
	write(1, "rb\n", 3);
}

void	rotate_r(t_stack *data)
{
	int	tmp;
	int	i;

	i = data->a_len - 1;
	while (i > 1)
	{
	tmp = data->a_s[i];
	data->a_s[i] = data->a_s[i - 1];
	data->a_s[i - 1] = tmp;
	i--;
	}
	i = data->b_len - 1;
	while (i > 1)
	{
	tmp = data->b_s[i];
	data->b_s[i] = data->b_s[i - 1];
	data->b_s[i - 1] = tmp;
	i--;
	}
	write(1, "rr\n", 3);
}

void	swap_a(t_stack *data)
{
	int	tmp;
	int	i;

	i = 0;
	if (data->a_len >= 2)
	{
		tmp = data->a_s[i];
		data->a_s[i] = data->a_s[i + 1];
		data->a_s[i + 1] = tmp;
		write(1, "sa\n", 3);
	}
	else
		return ;
}

void	swap_b(t_stack *data)
{
	int	tmp;
	int	i;

	i = 0;
	if (data->b_len >= 2)
	{
		tmp = data->b_s[i];
		data->b_s[i] = data->b_s[i + 1];
		data->b_s[i + 1] = tmp;
		write(1, "sb\n", 3);
	}
	else
		return ;
}
