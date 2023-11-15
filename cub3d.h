/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsodano <gsodano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:42:57 by gsodano           #+#    #+#             */
/*   Updated: 2023/11/13 20:42:57 by gsodano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"

# define WIN_WIDTH 1280.0
# define WIN_HEIGHT 720.0

# define RAD 0.0174533

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define SHIFT 65505
# define SPACE 32

typedef struct s_player
{
	float	ascisse_x;
	float	ordinate_y;
	float	pov;
}	t_player;

typedef struct s_cub3d
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			t_right;
	int			t_left;

	int			orientation[(int) WIN_WIDTH];
	char		**map;
	float		wall_height;
	float		radius_dim[(int) WIN_WIDTH];

	t_player	player;

}	t_cub3d;

int		keys(int keycode, t_cub3d *cub3d);
void	ft_rad(t_cub3d *cub3d);
void	ft_pgtowall_dist(t_cub3d *cub3d, float angle, int i);
void	ft_orientation(t_cub3d *cub3d, float angle, float dist, int i);

#endif