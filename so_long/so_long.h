/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:34:34 by bkeklik           #+#    #+#             */
/*   Updated: 2022/09/06 18:34:37 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "./mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

# define DOWN "./xpm/back.xpm"
# define LEFT "./xpm/left.xpm"
# define RIGHT "./xpm/right.xpm"
# define UP "./xpm/front.xpm"
# define GND "./xpm/background.xpm"
# define CLT "./xpm/collectible.xpm"
# define GATE "./xpm/gate.xpm"
# define SIDE "./xpm/side.xpm"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_window;
	void	*wall;
	void	*gate1;
	void	*p_front;
	void	*p_right;
	void	*p_left;
	void	*p_back;
	void	*collectible;
	void	*bckground;
	void	*side;
	int		imgx;
	int		imgy;
	int		player;
	int		px;
	int		py;
	int		posit;
	int		map_x;
	int		map_y;
	int		coll;
	int		coll2;
	int		gate;
	int		map_is_true;
	int		walk_count;
	char	p_snap;
	char	*walk_count_on_screen;
	char	**map;
	char	**copy_map;

}	t_data;

void	read_map(char *address, t_data *data);
int		ber_control(char *str, t_data *data);
void	rectangular_control(t_data *data);
void	special_characters(char *str, t_data *data);
void	ft_error_data(char *str, t_data *data);
void	where_is_p(t_data *data);
void	valid_map(t_data *data, int x, int y);
void	check_collectible_and_exit(t_data *data);
void	copy_map_error(t_data *data);
void	x_y(t_data *data);
void	image(t_data *data);
void	up(t_data *data);
void	down(t_data *data);
void	left(t_data *data);
void	right(t_data *data);
void	put_image(void *image, t_data *data, int posit, int posit2);
void	image_put_func(t_data *data, int i, int j, int c);
void	map_put(t_data *data);
void	ft_destroy_mlx(t_data *data);
void	put_score(t_data *data);
int		ft_free_data(t_data *data);
int		key_event(int keycode, t_data *data);

#endif
