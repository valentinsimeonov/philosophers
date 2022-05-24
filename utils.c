/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:33:40 by vsimeono          #+#    #+#             */
/*   Updated: 2022/05/24 10:23:26 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int	ft_sum(int *arr, int len)
{
	int		i;
	int		sum;
	
	i = 0;
	sum = 0;
	while (i < len)
	{
		sum += arr[i];
		i++;
	}
	return (sum);
}

void	print(t_philosopher *philosopher, int msec, char *str)
{
	pthread_mutex_lock(&(philosopher->to_game->m_print));
	if (philosopher->to_game->end == -1 || ft_strncmp(str, "died", 4) == 0)
		printf("%i %i %s\n", msec, philosopher->id, str);
	pthread_mutex_unlock(&(philosopher->to_game->m_print));
}

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (s1[i] == s2[i]) && s1[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
