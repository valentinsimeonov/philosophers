/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:53:51 by vsimeono          #+#    #+#             */
/*   Updated: 2022/05/16 14:39:26 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



/////   For Learning Purposes   ////

int mails;
pthread_t mutex;

mails = 0;


void	*routine()
{
	int i;
	
	i = 0;
	while (i < 10000000)
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
	pthread_t t1;
	pthread_t t2;
	
	pthread_mutex_init(&mutex, NULL);
	
	if (pthread_create(&t1,  NULL, &routine, NULL) != 0)
	{
		return 1;
	}
	if (pthread_join(t1, NULL) != 0)
	{
		return 12;
	}
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
	{
		return 2;
	}
	if (pthread_join(t2, NULL) != 0)
	{
		return 21;
	}
	pthread_mutex_destroy(&mutex);
	printf("The Final Number of %d\n", mails);
	return(0);
}