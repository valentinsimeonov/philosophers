

#include "philosophers.h"

/* Putting the Arguments into the Game Struct,
Initialising Pthread, Getting the System Time */

int	initialize_table(t_game *game, int argc, char **argv)
{
	game->number_of_philos = ft_atoi(argv[1]);
	game->time_to_die = ft_atoi(argv[2]);
	game->time_to_eat = ft_atoi(argv[3]);
	game->time_to_sleep = ft_atoi(argv[4]);
	game->meals = -1;
	if (argc == 6)
		game->meals = ft_atoi(argv[5]);
	game->end = -1;
	
	pthread_mutex_init(&(game->m_print), NULL);
	initialize_forks(game);

	game->to_philosopher = (t_philosopher **)malloc(game->number_of_philos * sizeof(t_philosopher *));
	gettimeofday(&(game->start), NULL);
	// printf("%d", game->start);
	initialize_philosophers(game);

	return (1);
}

/* Outting the Argumets into the Philosopher Struct,
Initialising the Mutex*/

void	initialize_philosophers(t_game *game)
{
	t_philosopher	*philosopher;
	int				i;

	i = 0;
	while (i < game->number_of_philos)
	{
		philosopher = (t_philosopher *)malloc(sizeof(t_philosopher));
		philosopher->to_game = game;
		philosopher->id = i + 1;
		philosopher->last_meal = 0;
		philosopher->meals = 0;
		pthread_mutex_init(&(philosopher->m_eat), NULL);
		game->to_philosopher[i] = philosopher;
		i++;
	}
}

/* Determining how many Forks should there be,
Initialising the Mutex for Forks*/

void	initialize_forks(t_game *game)
{
	int		j;

	j = 0;
	game->m_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * game->number_of_philos);
	while (j < game->number_of_philos)
	{
		pthread_mutex_init(game->m_forks + j, NULL);
		j++;
	}
}
