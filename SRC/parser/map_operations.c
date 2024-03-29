/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:51:52 by fsoymaz           #+#    #+#             */
/*   Updated: 2024/03/09 15:52:16 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_map2(int *i, t_data *game)
{
	int	j;

	j = (*i);
	while (game->map.map[*i])
		(*i)++;
	game->map.map2 = malloc(sizeof(char *) * (*i - j + 1));
	(*i) = j + 1;
	j = 0;
	while (game->map.map[*i])
	{
		game->map.map2[j] = game->map.map[*i];
		(*i)++;
		j++;
	}
	game->map.map2[j] = 0;
	game->map.map_row = j;
}

void	text_nswe(t_data *game)
{
	int	i;

	i = -1;
	while (game->map.map[++i])
	{
		if (ft_sp_ctrl(game->map.map[i]) == 0)
			ft_err();
		ft_nosw(game->map.map[i], game);
		control2(game, game->map.map[i]);
		free(game->map.map[i]);
		if (game->map.no && game->map.so && game->map.we && game->map.ea
			&& game->map.c && game->map.f)
			break ;
	}
	ft_map2(&i, game);
}

void	ft_get_map(char *str, t_data *game)
{
	int	fd;
	int	i;
	int	j;

	i = -1;
	j = map_lines(str);
	fd = open(str, O_RDONLY, 0777);
	game->map.map = malloc(sizeof(char *) * (j + 1));
	while (++i < j)
		game->map.map[i] = get_next_line(fd);
	game->map.map[i] = NULL;
	close(fd);
	text_nswe(game);
}
