/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:56:00 by fsoymaz           #+#    #+#             */
/*   Updated: 2024/03/09 19:30:40 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	del_wspace(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*str)[i])
	{
		if ((*str)[i] != ' ')
		{
			(*str)[j] = (*str)[i];
			j++;
		}
		i++;
	}
	(*str)[j] = '\0';
}

void	free_func2(t_data *data)
{
	free(data->map.f);
	free(data->map.c);
	free(data->player);
	free(data->img_data->img);
	free(data->img_data->addr);
	free(data->img_data);
	free(data->mlx);
	free(data->mlx_win);
	free(data);
}

void	free_func(t_data *data)
{
	int	i;

	if (data->no_img)
		mlx_destroy_image(data->mlx, data->no_img);
	if (data->so_img)
		mlx_destroy_image(data->mlx, data->so_img);
	if (data->ea_img)
		mlx_destroy_image(data->mlx, data->ea_img);
	if (data->we_img)
		mlx_destroy_image(data->mlx, data->we_img);
	i = -1;
	while (data->map.map2[++i])
		free(data->map.map2[i]);
	i = -1;
	free(data->map.map);
	free(data->map.map2);
	free(data->map.ea);
	free(data->map.so);
	free(data->map.no);
	free(data->map.we);
}

void	space_full(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (ft_wh_sp(str[i][j]))
				str[i][j] = '*';
		}
	}
}

void	empty_line(char **str, int *k, t_data *data)
{
	int	i;

	i = *k - 1;
	while (str[++i] && i < data->map.map_row - 1)
		if (str[i][0] == '\n' && (str[i + 1][0] == '1' || str[i + 1][0] == 32))
			ft_err();
}
