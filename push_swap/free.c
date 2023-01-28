/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:31:26 by bkeklik           #+#    #+#             */
/*   Updated: 2022/10/04 21:31:26 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error1(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error(t_stack *data)
{
	ft_free(data);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(t_stack *data)
{
	int	i;

	i = 0;
	if (data->a_s)
		free (data->a_s);
	if (data->b_s)
		free (data->b_s);
	free (data->tmps);
	while (data->numbers[i])
	{
		free(data->numbers[i]);
		i++;
	}
	free(data->numbers);
	free (data);
}
