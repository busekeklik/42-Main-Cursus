/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:44:31 by bkeklik           #+#    #+#             */
/*   Updated: 2022/07/05 07:14:00 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_variable(va_list list, const char a);
int	ft_put_char(int c);
int	ft_put_string(char *str);
int	ft_putnbr(int n);
int	ft_put_unumber(unsigned int n);
int	ft_hex(unsigned long p, char *base, int check, int base_len);

#endif
