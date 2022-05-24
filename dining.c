/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:30:28 by vsimeono          #+#    #+#             */
/*   Updated: 2022/05/24 10:43:49 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Telling each Philosopher When to Start Eating by Assigning them the Forks */
void	*dinner(void *philo)
{
	t_philosopher	*philosopher;
	t_game			*game;
	int				left;
	int				right;

	philosopher = (t_philosopher *)philo;
	game = philosopher->to_game;
	left = philosopher->id - 1;
	right = philosopher->id;
	if (right == game->number_of_philos)
		right = 0;
	/* Edge Case 1  - If there is Only One Philospher at the Table */
	if (game->number_of_philos == 1)
	{
		pthread_mutex_lock(game->m_forks);
		print(philosopher, get_clock(game), "has taken a fork");
		return (NULL);
	}
	/* Skipping every other Philosopher so that some of them can Start eating at the Same Time,EX: Philo 1 and Philo 3 Start Eating at the Same time as they Have Two Forks Available */
	if (philosopher->id % 2 == 0)
		usleep(game->time_to_eat * 500);
	dining(game, philosopher, right, left);
	return (NULL);
}

void dining(t_game *game, t_philosopher *philosopher, int right, int left)
{
	while ((game->end == -1 && game->number_of_philos == -1) \
	|| game->meals != philosopher->meals)
	{
		pthread_mutex_lock(game->m_forks + left);
		print(philosopher, get_clock(game), "has taken a fork");
		pthread_mutex_lock(game->m_forks + right);
		print(philosopher, get_clock(game), "has taken a fork");
		pthread_mutex_lock(&(philosopher->m_eat));
		philosopher->last_meal = get_clock(game);
		philosopher->meals += 1;
		print(philosopher, philosopher->last_meal, "is eating");
		pthread_mutex_unlock(&(philosopher->m_eat));
		wake_up(game, game->time_to_eat);
		pthread_mutex_unlock(game->m_forks + left);
		pthread_mutex_unlock(game->m_forks + right);
		if (game->meals != -1 && game->meals == philosopher->meals)
			return ;
		print(philosopher, get_clock(game), "is sleeping");
		wake_up(game, game->time_to_sleep);
		print(philosopher, get_clock(game), "is thinking");
	}
}

void	dine(t_game *game)
{
	t_philosopher	*philosopher;
	int				i;
	int				nbr_of_philos;
	int				*array;

	i = 0;
	nbr_of_philos = game->number_of_philos;
	array = (int *)malloc(sizeof(int) * nbr_of_philos);
	while (i < nbr_of_philos)
	{
		array[i] = 0;
		i++;
	}
	while (game->end == -1 && ft_sum(array, game->number_of_philos) < game->number_of_philos)
	{
		i = 0;
		while (i < game->number_of_philos && game->end == -1 && ft_sum(array, game->number_of_philos) < nbr_of_philos)
		{
			philosopher = game->to_philosopher[i];
			check_if_dead(game, philosopher);
			if (philosopher->meals == game->meals)
				array[i] = 1;
			i++;
		}
	}
	free(array);
}
