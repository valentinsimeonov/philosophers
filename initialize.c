

#include "philosophers.h"

/* Putting the Arguments into the Game Struct,
Initialising Pthread, Getting the System Time */

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
	
	pthread_mutex_init(&(table->m_print), NULL);
	initialize_forks(table);

	table->to_philosopher = (t_philosopher **)malloc(table->number_of_philos * sizeof(t_philosopher *));
	gettimeofday(&(table->start), NULL);
	// printf("%d", table->start);
	initialize_philosophers(table);

	return (1);
}

/* Outting the Argumets into the Philosopher Struct,
Initialising the Mutex*/

void	initialize_philosophers(t_game *table)
{
	t_philosopher	*philosopher;
	int				i;

	i = 0;
	while (i < table->number_of_philos)
	{
		philosopher = (t_philosopher *)malloc(sizeof(t_philosopher));
		philosopher->to_game = table;
		philosopher->id = i + 1;
		philosopher->last_meal = 0;
		philosopher->meals = 0;
		pthread_mutex_init(&(philosopher->m_eat), NULL);
		table->to_philosopher[i] = philosopher;
		i++;
	}
}

/* Determining how many Forks should there be,
Initialising the Mutex for Forks*/

void	initialize_forks(t_game *table)
{
	int		j;

	j = 0;
	table->m_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->number_of_philos);
	while (j < table->number_of_philos)
	{
		pthread_mutex_init(table->m_forks + j, NULL);
		j++;
	}
}
