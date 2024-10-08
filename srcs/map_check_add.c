/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:18:09 by rsainas           #+#    #+#             */
/*   Updated: 2024/10/08 16:56:53 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	element_to_null(t_data *data)
{
	int	i;

	i = 0;
	data->no_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->ea_path = NULL;
	data->map = NULL;
	data->map_start = 0;
	data->player.player_found = 0;
	while (i < 4)
	{
		data->check[i] = NULL;
		i++;
	}
}

int	adv_strncmp(const char *s1, const char *s2)
{
	if (!ft_strncmp(s1, s2, ft_strlen(s1))
		&& !ft_strncmp(s1, s2, ft_strlen(s2)))
		return (0);
	return (1);
}

void	rgb_parsing(char *line, t_data *data, int c)
{
	int	i;
	int	parts;

	i = 0;
	parts = 0;
	while (line[i])
	{
		while (line[i] && !ft_isdigit(line[i]))
			i++;
		while (line[i] && ft_isdigit(line[i]))
		{
			i++;
			if (!ft_isdigit(line[i]))
				parts++;
		}
	}
	if (parts == 3 && !check_rgb_content(line) && c == 'F')
		set_color_floor(line, data);
	else if (parts == 3 && !check_rgb_content(line) && c == 'C')
		set_color_ceiling(line, data);
	else if (parts != 3 || check_rgb_content(line))
	{
		free (line);
		err_msg("Invalid RGB configuration", data, 1);
	}
}

int	check_rgb_content(char *line)
{
	int	i;
	int	comma;

	i = 1;
	comma = 0;
	while (line[i] == 32)
		i++;
	if (!ft_isdigit(line[i]))
		return (1);
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		if (!ft_isdigit(line[i]) && line[i] != 32 && line[i] != ',' && line[i] != '\n')
		{
			//printf("%c -< ici\n", line[i]);
			return (1);
		}
		i++;
	}
	if (comma != 2)
	{
		//printf("test");
		return (1);
	}
	return (0);
}

/*
int	set_textures(t_data **data, char *path)
{
	int			x;
	int			y;
	static int	i;

	(*data)->check[i] = mlx_xpm_file_to_image((*data)->mlx, path, &x, &y);
	if (!(*data)->check[i])
		return (1);
	i++;
	return (0);
}

void	destroy_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->check[i] != NULL)
			mlx_destroy_image(data->mlx, data->check[i]);
		i++;
	}
}

int	check_path(t_data *data)
{
	if (set_textures(&data, data->no_path)
		|| set_textures(&data, data->so_path) 
		|| set_textures(&data, data->ea_path)
		|| set_textures(&data, data->we_path))
	{
		return (1);
	}
	return (0);
}*/
