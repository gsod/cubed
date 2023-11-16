/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:52:26 by abuonomo          #+#    #+#             */
/*   Updated: 2023/11/16 19:02:09 by abuonomo         ###   ########.fr       */
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
void check_parameter(int argc, char **argv, t_cub3d *cub3d)
{
	char	*tmp;
	int		fd;

	if(argc > 2 || argc < 2)
		ft_exit("Wrong arguments");
	if(check_cub(argv[1]))
		ft_exit("Wrong file extension");
	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
		ft_exit("Error opening file");
	tmp = get_next_line(fd);
	while(tmp != NULL)
	{
		tmp	= get_next_line(fd);
		if(tmp == NULL)
			break;
		printf("%s\n", tmp);
		free(tmp);
	}
	printf("arrivo");
}
