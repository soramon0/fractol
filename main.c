/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/10/25 22:21:05 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol_set	set;
	void			*mlx_ptr;

	set = parse_selected_set(argc, argv);
	if (set == SET_UNKNOWN)
		exit_usage();
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		exit_msg(STDERR_FILENO, "could not init graphics\n");
	void *window = mlx_new_window(mlx_ptr, 400, 300, fractol_set_str(set));
	if (window == NULL)
		exit_msg(STDERR_FILENO, "could not create window\n");
	while (1){}
	return (0);
}
