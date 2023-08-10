/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_llong_range.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:55:38 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/08 15:09:52 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_return_signal(char c, int signal)
{
	if (ft_isnegative(c) || ft_ispositive(c))
	{
		if (ft_isnegative(c))
		{
			signal = -1;
		}
	}
	return (signal);
}

bool	ft_is_in_llong_range(char *nptr)
{
	unsigned long long	r;
	int					i;
	int					signal;

	r = 0;
	i = 0;
	signal = 1;
	while (ft_isspace(nptr[i]))
		i++;
	signal = ft_return_signal(nptr[i], signal);
	if (signal == -1)
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r *= 10;
		r += nptr[i] - '0';
		i++;
	}
	if (signal == -1 && (r <= LLONG_MAX
			|| ft_strcmp(nptr, "-9223372036854775808") == 0))
		return (true);
	if (r > LLONG_MAX)
		return (false);
	return (true);
}
