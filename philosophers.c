/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:53:51 by vsimeono          #+#    #+#             */
/*   Updated: 2022/04/22 19:07:54 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



/////   For Learning Purposes   ////
void*	routine()
{
	printf("Test\n");
}


int		main(int argc, char **argv)
{
	pthread_t t1;
	pthread_create(&t1,  NULL, &routine, NULL);
	pthread_join(t1, NULL);
	
	return(0);
}