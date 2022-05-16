/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:53:51 by vsimeono          #+#    #+#             */
/*   Updated: 2022/05/16 15:03:30 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



/////   For Learning Purposes   ////

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


int		main(int argc, char **argv)
{
	pthread_t t[4];
	// pthread_t t2;
	// pthread_t t3;
	// pthread_t t4;
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