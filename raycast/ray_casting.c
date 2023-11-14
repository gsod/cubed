/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsodano <gsodano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:01:55 by gsodano           #+#    #+#             */
/*   Updated: 2023/11/13 21:01:55 by gsodano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_rad(t_cub3d *cub3d) // la vista del tuo giocatore
{
	int	i;
	int	angle;

	angle = cub3d->player.pov - 30.0;
	i = 0;
	while(i < WIN_WIDTH)
	{
		ft_pgtowall_dist(cub3d, angle, i);
		angle += 60.0 / WIN_WIDTH;
		i++;
	} 
}

void ft_pgtowall_dist(t_cub3d *cub3d, float angle, int i) // distanza tra il giocatore e il muro
{
	float	sin_v;
	float	cos_v;
	float	dist;

	sin_v = sin(angle);
	cos_v = cos(angle);
	dist = 0.01;

	while(1)
	{
		if (cub3d->map[(int) (cub3d->ascisse_x + dist * cos_v)][(int) (cub3d->ascisse_y + dist * sin_v)] == '1')
			break;
		dist += 0.01;
	}
	cub3d->radius_dim[i] = dist * cos(angle - (cub3d->player.pov * RAD)); //RAD dichiarato come la conversione di un grado in radianti(perchè le funzioni sin e cos vogliono i gradi in radianti)
	ft_orientation(cub3d, angle, dist, i);
} //La distanza viene incrementata gradualmente fino a quando il punto sulla mappa raggiunto dalla proiezione del raggio colpisce un muro 

void ft_orientation(t_cub3d *cub3d, float angle, float dist, int i) // orientamento del muro colpito dal raggio (nord,sud, est o ovest)
{
	float	cos_value;
	float	sin_value;
	float	ascisse_x;
	float	ordinate_y;

	cos_value = cos(angle);
	sin_value = sin(angle);
	ascisse_x = cub3d->ascisse_x + dist * cos_value + 0.01;
	ordinate_y = cub3d->ordinate_y + dist * sin_value;
	if (cub3d->map[(int)(ordinate_y - 0.01)][(int)ascisse_x] == '1')
		cub3d->orientation[i] = 0;
	else if (cub3d->map[(int)(ordinate_y + 0.01)][(int)ascisse_x] == '1')
		cub3d->orientation[i] = 1;
	else if (cub3d->map[(int)ordinate_y][(int)(ascisse_x - 0.01)] == '1')
		cub3d->orientation[i] = 2;
	else
		cub3d->orientation[i] = 3;
} //L'orientamento viene assegnato a cub3d->orientation[i]. (quindi se il muro è a nord, sud, est o ovest)