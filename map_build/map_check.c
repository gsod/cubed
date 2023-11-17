/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:52:26 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/17 12:29:02 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_cub(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (path[i - 1] != 'b' || path[i - 2] != 'u'
		|| path[i - 3] != 'c' || path[i - 4] != '.')
		return (1);
	return (0);
}
void	ft_exit(char *str)
{
	perror(str);
	exit(1);
}

int is_parameter(char *str)
{
	if((str[0] == 'N' && str[1] == 'O')
	|| (str[0] == 'S' && str[1] == 'O')
	|| (str[0] == 'W' && str[1] == 'E')
	|| (str[0] == 'E' && str[1] == 'A')
	|| (str[0] == 'C' && str[1] == ' ')
	|| (str[0] == 'F' && str[1] == ' '))
	{
		return (1);
	}
	return (0);
}

int param_full(char *tmp, t_cub3d *cub3d)
{
	int i;

	i = 0;
	if(cub3d->NO != NULL)
		i++;
	if(cub3d->SO != NULL)
		i++;
	if(cub3d->WE != NULL)
		i++;
	if(cub3d->EA != NULL)
		i++;
	if(cub3d->floor != NULL)
		i++;
	if(cub3d->ceiling != NULL)
		i++;
	return (i);
}

void	add_parameter(char *tmp, t_cub3d *cub3d)
{
	if(tmp[0] == 'N' && tmp[1] == 'O' && cub3d->NO == NULL)
		cub3d->NO = ft_strtrim(ft_strdup(tmp + 2), " ");
	if(tmp[0] == 'S' && tmp[1] == 'O' && cub3d->SO == NULL)
		cub3d->SO = ft_strtrim(ft_strdup(tmp + 2), " ");
	if(tmp[0] == 'W' && tmp[1] == 'E' && cub3d->WE == NULL)
		cub3d->WE = ft_strtrim(ft_strdup(tmp + 2), " ");
	if(tmp[0] == 'E' && tmp[1] == 'A' && cub3d->EA == NULL)
		cub3d->EA = ft_strtrim(ft_strdup(tmp + 2), " ");
	if(tmp[0] == 'F' && tmp[1] == ' ' && cub3d->floor == NULL)
		cub3d->floor = ft_strtrim(ft_strdup(tmp + 2), " ");
	if(tmp[0] == 'C' && tmp[1] == ' ' && cub3d->ceiling == NULL)
		cub3d->ceiling = ft_strtrim(ft_strdup(tmp + 2), " ");
}

int is_param_not_present(char *tmp, t_cub3d *cub3d)
{
	if(tmp[0] == 'N' && tmp[1] == 'O' && cub3d->NO == NULL)
		return (1);
	if(tmp[0] == 'S' && tmp[1] == 'O' && cub3d->SO == NULL)
		return (1);
	if(tmp[0] == 'W' && tmp[1] == 'E' && cub3d->WE == NULL)
		return (1);
	if(tmp[0] == 'E' && tmp[1] == 'A' && cub3d->EA == NULL)
		return (1);
	if(tmp[0] == 'F' && tmp[1] == ' ' && cub3d->floor == NULL)
		return (1);
	if(tmp[0] == 'C' && tmp[1] == ' ' && cub3d->ceiling == NULL)
		return (1);
	return (0);
}
void check_parameter(int argc, char **argv, t_cub3d *cub3d)
{
	char	*tmp;
	int		fd;

	if(argc > 2 || argc < 2 || argv[1] == NULL || argv[1][0] == '\0')
		ft_exit("Wrong arguments");
	if(check_cub(argv[1]))
		ft_exit("Wrong file extension");
	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
		ft_exit("Error opening file");
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
	if(tmp != NULL)
		free(tmp);
	close(fd);
	if(param_full(tmp, cub3d) < 6)
		ft_exit("Wrong parameter");
}
