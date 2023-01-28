/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 02:33:54 by bkeklik           #+#    #+#             */
/*   Updated: 2022/12/09 15:36:20 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;

	if (ft_argcheck(argc, argv) == ERROR)
	{
		printf("invalid argument");
		return (1);
	}
	philo = malloc(sizeof(*philo) * ft_atol(argv[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atol(argv[1]));
	death = malloc(sizeof(pthread_mutex_t));
	if (!philo || !forks || !death)
		return (ERROR);
	ft_philo_init(philo, argv, argc);
	create_init_mutex(philo, forks, death);
	ft_distribute_threads(philo, argv);
	ft_free(philo, forks, death);
	return (0);
}
