/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:17:04 by bkeklik           #+#    #+#             */
/*   Updated: 2022/08/19 13:17:16 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_success(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("The signal communication is working.\n");
}

int	ft_atoi(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i = (i * 10) + (*str - '0');
		str++;
	}
	return (i);
}

void	ft_bit_and_shift(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill (pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("There is a problem, you have to enter 3 arguments.");
		return (0);
	}
	signal(SIGUSR1, ft_success);
	ft_bit_and_shift(ft_atoi(argv[1]), argv[2]);
}
