/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:58:37 by rsainas           #+#    #+#             */
/*   Updated: 2024/10/22 14:18:29 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
@glance		stafing a move to keep FOV in place, like a step on the side
			without player moving her head.
*/

static void	key_strafe(int key, t_data *data)
{
	if (key == 0)
	{
		if (data->map[(int)(data->player.x_i - data->ray.plane_x * data->step)]
				[(int)data->player.y_i] == '0' &&
				data->map[(int)data->player.x_i][(int)(data->player.y_i -
				data->ray.plane_y * data->step)] == '0')
		{
			data->player.x_i -= data->ray.plane_x * data->step;
			data->player.y_i -= data->ray.plane_y * data->step;
		}
	}
	if (key == 2)
	{
		if (data->map[(int)(data->player.x_i + data->ray.plane_x * data->step)]
				[(int)data->player.y_i] == '0' &&
				data->map[(int)data->player.x_i][(int)(data->player.y_i +
				data->ray.plane_y * data->step)] == '0')
		{
			data->player.x_i += data->ray.plane_x * data->step;
			data->player.y_i += data->ray.plane_y * data->step;
		}
	}
}

/*
@glance		a positive data->rot rotates counterclockwise ie left and negative
			clockwise. player is in place and to rotate the player directional
			vector and plane wectors are chnaged.
*/

static void	key_l(int key, t_data *data)
{
	double	temp_player_x;
	double	temp_plane_x;

	temp_player_x = data->ray.player_x;
	temp_plane_x = data->ray.plane_x;
	if (key == 123)
	{
		data->ray.player_x = data->ray.player_x * cos(data->rot)
			- data->ray.player_y * sin(data->rot);
		data->ray.player_y = temp_player_x * sin(data->rot)
			+ data->ray.player_y * cos(data->rot);
		data->ray.plane_x = data->ray.plane_x * cos(data->rot)
			- data->ray.plane_y * sin(data->rot);
		data->ray.plane_y = temp_plane_x * sin(data->rot)
			+ data->ray.plane_y * cos(data->rot);
	}
}

static void	key_r(int key, t_data *data)
{
	double	temp_player_x;
	double	temp_plane_x;

	temp_player_x = data->ray.player_x;
	temp_plane_x = data->ray.plane_x;
	if (key == 124)
	{
		data->ray.player_x = data->ray.player_x * cos(-data->rot)
			- data->ray.player_y * sin(-data->rot);
		data->ray.player_y = temp_player_x * sin(-data->rot)
			+ data->ray.player_y * cos(-data->rot);
		data->ray.plane_x = data->ray.plane_x * cos(-data->rot)
			- data->ray.plane_y * sin(-data->rot);
		data->ray.plane_y = temp_plane_x * sin(-data->rot)
			+ data->ray.plane_y * cos(-data->rot);
	}
}

static void	key_step_back(int key, t_data *data)
{
	if (key == 1 || key == 125)
	{
		if (data->map[(int)(data->player.x_i - data->ray.player_x * data->step)]
				[(int)data->player.y_i] == '0')
			data->player.x_i -= data->ray.player_x * data->step;
		if (data->map[(int)data->player.x_i][(int)(data->player.y_i
			- data->ray.player_y * data->step)] == '0')
			data->player.y_i -= data->ray.player_y * data->step;
	}
}

/*
@glance			mlx loop is listening for a key stroke, if key pressed
				payer postion of plane vector is changed and the 
				image is rendered again.
@render()		refresh the image on window
*/

int	key_stroke(int key, t_data *data)
{
	if (key == 53)
	{
		ft_putstr_fd(", ESC key pressed.\n", 1);
		free_textures(data);
		free_mlx(data);
		exit (EXIT_SUCCESS);
	}
	if (key == 13 || key == 126)
	{
		if (data->map[(int)(data->player.x_i + data->ray.player_x * data->step)]
				[(int)data->player.y_i] == '0')
			data->player.x_i += data->ray.player_x * data->step;
		if (data->map[(int)data->player.x_i][(int)(data->player.y_i
			+ data->ray.player_y * data->step)] == '0')
			data->player.y_i += data->ray.player_y * data->step;
	}
	key_step_back(key, data);
	key_strafe(key, data);
	key_l(key, data);
	key_r(key, data);
	if (key == 13 || key == 1 || key == 0 || key == 2
		|| key == 126 || key == 125 || key == 123 || key == 124)
		render(data);
	return (0);
}
