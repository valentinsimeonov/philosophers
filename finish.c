/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:03:34 by vsimeono          #+#    #+#             */
/*   Updated: 2022/05/24 14:42:18 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutexes(t_game *game)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(game->m_print));
	while (i < game->number_of_philos)
	{
		pthread_mutex_destroy(game->m_forks + i);
		pthread_mutex_destroy(&(game->to_philosopher[i]->m_eat));
		i++;
	}
}

void	join_threads(t_game *game, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < game->number_of_philos)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}

void	free_philosophers(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->number_of_philos)
	{
		free(game->to_philosopher[i]);
		i++;
	}
}

void	goodnight(t_game *game, pthread_t *thread)
{
	join_threads(game, thread);
	destroy_mutexes(game);
	free_philosophers(game);
	free(game->to_philosopher);
	free(game->m_forks);
	free(thread);
}
