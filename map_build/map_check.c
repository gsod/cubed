/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:41:27 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/17 14:09:50 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void map_check(char *path, t_cub3d *cub3d)
{
	int fd;
	char *line;
	int i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit("Error\nFile not found");
	while(1)
	{
		tmp = get_next_line(fd);
		if(tmp == NULL)
			break;
		if(is_parameter(tmp))
		{
			if(is_param_not_present(tmp, cub3d))
				add_parameter(tmp, cub3d);
			else
				break;
		}
		else
		{
			if(tmp[0] != '\n' && param_full(tmp,cub3d) < 6)
				break;
		}
		free(tmp);
	}
	close(fd);
}

