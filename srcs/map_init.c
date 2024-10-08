/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:09:19 by lpetit            #+#    #+#             */
/*   Updated: 2024/10/08 09:50:57 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*char    *skip_to_map(int fd, t_data *data)
{
    char    *line;
    int     i;

    i = 0;
    line = get_next_line(fd);
    if (!line)
        return (NULL);
    while (line && i < data->map_start)
    {
        i++;
        free(line);
        line = get_next_line(fd);
    }
    return (line);
}*/

void	set_color_ceiling(char *line, t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = line;
	tmp++;
	while (i < 3)
	{
		while (*tmp == 32 || *tmp == ',')
			tmp++;
		if (i == 0 && !check_rgb(tmp, &(data->ceiling)))
			data->ceiling.r = ft_atoi(tmp);
		else if (i == 1 && !check_rgb(tmp, &(data->ceiling)))
			data->ceiling.g = ft_atoi(tmp);
		else if (i == 2 && !check_rgb(tmp, &(data->ceiling)))
			data->ceiling.b = ft_atoi(tmp);
		else
		{
			free(line);
			err_msg("Invalid RGB configuration", data, 1);
		}
		while (tmp && ft_isdigit(*tmp))
			tmp++;
		i++;
	}
}

void	set_color_floor(char *line, t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = line;
	tmp++;
	while (i < 3)
	{
		while (*tmp == 32 || *tmp == ',')
			tmp++;
		if (i == 0 && !check_rgb(tmp, &(data->floor)))
			data->floor.r = ft_atoi(tmp);
		else if (i == 1 && !check_rgb(tmp, &(data->floor)))
			data->floor.g = ft_atoi(tmp);
		else if (i == 2 && !check_rgb(tmp, &(data->floor)))
			data->floor.b = ft_atoi(tmp);
		else
		{
			free(line);
			err_msg("Invalid RGB configuration", data, 1);
		}
		while (tmp && ft_isdigit(*tmp))
			tmp++;
		i++;
	}
}

char	*set_path(char *line, t_data *data, char *path)
{
	char	*tmp;
	char	*dup;

	if (path != NULL)
	{
		free(line);
		err_msg("Invalid element configuration", data, 1);
	}
	tmp = line;
	tmp++;
	tmp++;
	while (*tmp == 32)
		tmp++;
	tmp[ft_strlen(tmp) - 1] = '\0';
	dup = ft_strdup(tmp);
	if (!dup)
	{
		free(line);
		err_msg("Could not allocate memory for the elements", data, 1);
	}
	return (dup);
}

char	*init_element(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	element_to_null(data);
	while (i < 6)
	{
		line = skip_empty(data->fd, data);
		if (!line)
			return (NULL);
		parse_element(line, data);
		if (line)
			free(line);
		i++;
	}
	return (skip_empty(data->fd, data));
}

void	map_init(char *path, t_data *data)
{
	char	*line;

	data->fd = open(path, O_RDONLY);
    if (data->fd < 0)
        err_msg("Can't open map file", data, 0);
    data->ceiling.set = 0;
    data->floor.set = 0;
	line = init_element(data);
	if (!line)
		err_msg("Invalid map configuration", data, 1);
	map_content(line, data);
	/*if (check_path(data) == 1)
		err_msg("Invalid element or texture path", data, 1);*/
	if (data->player.player_found == 0)
		err_msg("Invalid map configuration, no player found", data, 1);
	if (!data->map)
		err_msg("Could not allocate memory for the map", data, 1);
	close(data->fd);
}
