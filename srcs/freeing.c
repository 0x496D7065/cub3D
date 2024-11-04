/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:30:20 by rsainas           #+#    #+#             */
/*   Updated: 2024/10/22 14:11:34 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_data *data)
{
	int	i;

	i = -1;
	while (i++, i < 4)
		free(data->textures[i]);
}

void	free_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	free_texture_path(data);
	free_array(data->map);
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			free(str[i++]);
		free(str);
	}
}

int	close_window(t_data *data)
{
	ft_putstr_fd("EXIT", 1);
	ft_putstr_fd(", Window X pressed.\n", 1);
	free_mlx(data);
	free_textures(data);
	exit (EXIT_SUCCESS);
}
