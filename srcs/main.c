/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:49:45 by lpetit            #+#    #+#             */
/*   Updated: 2024/10/22 14:12:38 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		err_msg("Invalid number of argument", &data, 0);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
		err_msg("Invalid map extension", &data, 0);
	map_init(argv[1], &data);
	if (check_if_closed(&data) == 1)
		err_msg("Map is not closed", &data, 1);
	data.name = argv[1];
	init_graphics(&data);
	render(&data);
	mlx_loop(data.mlx);
	free_all_tab(data.map);
	free_texture_path(&data);
	free_textures(&data);
	return (0);
}
