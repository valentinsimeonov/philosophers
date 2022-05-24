/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_keeping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 19:28:08 by vsimeono          #+#    #+#             */
/*   Updated: 2022/05/24 10:09:41 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_if_dead(t_game *game, t_philosopher *philosopher)
{
	int	miliseconds;
	
	pthread_mutex_lock(&(philosopher->m_eat));
	miliseconds = get_clock(game);
	if (miliseconds > philosopher->last_meal + game->time_to_die)
	{
		game->end = 1;
		print(philosopher, miliseconds, "died");
		pthread_mutex_unlock(&(philosopher->m_eat));
	}
	else
	{
		pthread_mutex_unlock(&(philosopher->m_eat));
		game->end = -1;
	}
}

int		get_clock(t_game *game)
{
	struct timeval	current_time;
	int				miliseconds;

	gettimeofday(&(current_time), NULL);
	if ((game->start).tv_usec < current_time.tv_usec)
	{
		miliseconds = (current_time.tv_usec - (game->start).tv_usec) / 1000;
		miliseconds += (current_time.tv_sec - (game->start).tv_sec) * 1000;
	}
	else
	{
		miliseconds = 1000 + (current_time.tv_usec - (game->start).tv_usec) / 1000;
		miliseconds += (current_time.tv_sec - (game->start).tv_sec - 1) * 1000;
	}
	return (miliseconds);
}

void	wake_up(t_game *game, int seconds)
{
	int	wake;

	wake = get_clock(game) + seconds;
	while (game->end == -1 && get_clock(game) < wake)
	{
		usleep(50);
	}
}
