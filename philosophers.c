/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:53:51 by vsimeono          #+#    #+#             */
/*   Updated: 2022/05/16 21:17:04 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]


int	main(int argc, char **argv)
{
	t_game			table;
	pthread_t		*thread;
	t_philosopher	*philo;
	int				i;

	i = 0;
	if (!is_number_of_args_four(argc, argv) || !is_args_positive(argc, argv) \
	|| !ft_isdigit(argc, argv))
		return (-1);
	if (!init)
	return (0);
}

int	initialize_table(t_game *table, int argc, char **argv)
{
	table->number_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->meals = -1;
	if (argc == 6)
		table->meals = ft_atoi(argv[5]);
	table->end = -1;
	

	gettimeofday(&(table->start), NULL);
	printf("%d", table->start);
}













/////   For Learning Purposes   ////
/*
int mails = 0;
pthread_t mutex;

void	*routine()
{
	int i;
	
	i = 0;
	while (i < 1000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		i++;
		pthread_mutex_unlock(&mutex);
	}
	// printf("Test\n");
	// sleep(2);
	// printf("Second Print\n");
}


int		main()
{
	pthread_t t[4];
	int		i;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 4)
	{
		if (pthread_create(&t[i], NULL, &routine, NULL) != 0)
		{
			return (1);
		}
		printf("Thread %d Created\n", i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(t[i], NULL) != 0)
		{
			return 2;
		}
		printf("Finished Joining Thread %d\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf("The Final Number of %d\n", mails);
	return(0);
}

*/