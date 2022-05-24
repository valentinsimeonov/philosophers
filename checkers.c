/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:29:25 by vsimeono          #+#    #+#             */
/*   Updated: 2022/05/24 14:32:10 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_number_of_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid Number of Arguments\n, Please Try Again!\n");
		return (0);
	}
	return (1);
}

int	ft_isdigit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57))
			{
				printf("Please Pass Positive Integers as Arguments");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
