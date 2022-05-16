/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:29:25 by vsimeono          #+#    #+#             */
/*   Updated: 2022/05/16 20:44:56 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		is_number_of_args(int argc, char** argv)
{
	int		i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		printf("Invalid Number of Arguments\n, Please Try Again!\n");
		return (0);
	}
	return (1);
}

int		is_args_positive(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			printf("Please Pass Positive Values as Arguments");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_isdigit(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i <= argc)
	{
		if (ft_atoi(argv[i]) >= '0' && ft_atoi(argv[i]) <= '9')
			return (1);
		i++;
	}
	return (0);
}
