/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:14:50 by bkeklik           #+#    #+#             */
/*   Updated: 2022/10/13 18:16:11 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoip(const char *str, t_stack *data)
{
	int		i;
	int		sign;
	long	number;

	sign = 1;
	number = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = (number * 10) + (str[i] - 48) * sign;
		if (number > 2147483647)
			error(data);
		if (number < -2147483648)
			error(data);
		i++;
	}
	return (number);
}
