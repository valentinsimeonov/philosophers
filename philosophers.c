/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:53:51 by vsimeono          #+#    #+#             */
/*   Updated: 2022/05/24 14:47:03 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_game			game;
	pthread_t		*thread;
	t_philosopher	*philosopher;
	int				i;

	i = 0;
	if (!is_number_of_args(argc) || !ft_isdigit(argc, argv))
		return (-1);
	if (!initialize_table(&game, argc, argv))
		return (-2);
	thread = malloc(sizeof(pthread_t *) * game.number_of_philos);
	if (!thread)
		return (-3);
	while (i < game.number_of_philos)
	{
		philosopher = game.to_philosopher[i];
		pthread_create(&thread[i], NULL, &dinner, philosopher);
		i++;
	}
	dine(&game);
	goodnight(&game, thread);
	usleep(50);
	printf("Reached the end of Main");
	return (0);
}
