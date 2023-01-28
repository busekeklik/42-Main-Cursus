/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:23:08 by bkeklik           #+#    #+#             */
/*   Updated: 2022/08/22 22:23:13 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"

int		ft_atoi(char *str);
void	ft_success(int signal);
void	ft_bit_and_shift(int pid, char *str);
void	ft_signal_catch(int x, siginfo_t *info, void *unused);

#endif
