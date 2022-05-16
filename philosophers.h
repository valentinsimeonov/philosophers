/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:53:55 by vsimeono          #+#    #+#             */
/*   Updated: 2022/05/16 21:23:13 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H   /// The Name has is Singular not Plural
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
// #include <time.h>    //// TO DELETE
#include <sys/time.h>
#include <stdio.h>

struct s_philosopher;

typedef struct s_game
{
	struct s_philosopher **to_philo;
	pthread_mutex_t		m_print;
	pthread_mutex_t		*m_forks;
	struct timeval		start;

	int					number_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meals;
	int					end;
	int					game;
} t_game;

typedef struct s_philosopher
{
	pthread_mutex_t			m_eat;
	t_game					*to_settings;

	int						last_meal;
	int						meals;
	int						id;
	int						philosopher;					
} t_philosopher;


/* Checkers */
int		is_number_of_args_four(int argc, char** argv);
int		is_args_positive(int argc, char **argv);
int	ft_isdigit(int argc, char **argv);

/* Utils */
long	ft_atoi(const char *str);

/* Initialising = Putting the Arguments in Structs */
int	initialize_table(t_game *table, int argc, char **argv);



#endif