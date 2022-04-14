/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:53:06 by fcil              #+#    #+#             */
/*   Updated: 2022/04/14 15:13:29 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_map(t_map *map)
{
	map->arr_z = NULL;
	map->width = 0;
	map->height = 0;
	map->z_min = 0;
	map->z_max = 0;
}

int	main(int argc, char **argv)
{
	t_node	*stack;
	t_map	map;

	if (argc != 2)
	{
		perror("Execution error\nUsage: ./fdf MAP_FILE");
		return (-1);
	}
	init_map(&map);

}
