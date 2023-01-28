/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <bkeklik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:58 by bkeklik           #+#    #+#             */
/*   Updated: 2022/10/15 22:14:17 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int		*a_s;
	int		*b_s;
	int		*tmps;
	int		ac;
	int		a_len;
	int		b_len;
	int		max_bit;
	int		min_indx;
	int		min;
	char	*str;
	char	**numbers;
	int		len;
}	t_stack;

void	repeat_numbers(t_stack *data);
void	edit_stacks(t_stack *data);
void	check_numbers(t_stack *data);
void	error(t_stack *data);
void	error1(void);
void	rev_rotate_r(t_stack *data);
void	selection_sort(t_stack *data);
int		find_index(t_stack *data, int nbr);
int		space_null_control(char *str);
void	find_index2(t_stack *data);
void	sort_control(t_stack *data);
void	distribute_arg(t_stack *data);
void	argv_control(char **str);
void	main_helper(t_stack *data);
void	ft_argv_together(t_stack *data, char *str);
void	three(t_stack *data);
void	four(t_stack *data);
void	five(t_stack *data);
void	swap_a(t_stack *data);
void	swap_b(t_stack *data);
void	push_b(t_stack *data);
void	push_a(t_stack *data);
void	rotate_a(t_stack *data);
void	rotate_b(t_stack *data);
void	rotate_r(t_stack *data);
void	rev_rotate_a(t_stack *data);
void	rev_rotate_b(t_stack *data);
void	rev_rotate_r(t_stack *data);
void	radix(t_stack *data);
void	radix_2(t_stack *data);
void	ft_free(t_stack *data);
int		*push_down(int *arr, int len);
int		*push_up(int *arr, int len);
int		ft_atoip(const char *str, t_stack *data);
#endif