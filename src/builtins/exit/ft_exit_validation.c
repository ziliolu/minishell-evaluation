/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:05:23 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/08 15:29:27 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_cmd_has_pipes(t_ms *ms, t_command *cmd)
{
	if (ms->n_pipes == 0)
	{
		printf("exit\n");
		printf("minishell: exit: %s: numeric argument required\n", \
		cmd->args[1]);
		exit (2);
	}
	else
	{
		printf("minishell: exit: %s: numeric argument required\n", \
		cmd->args[1]);
		g_exit_status = 2;
	}
	return (false);
}

int	ft_count_args_actual_cmd(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
		i++;
	return (i);
}

long long	ft_atoll(const char *nptr)
{
	long long	r;
	int			i;
	int			signal;

	r = 0;
	i = 0;
	signal = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_isnegative(nptr[i]) || ft_ispositive(nptr[i]))
		if (ft_isnegative(nptr[i++]))
			signal = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r *= 10;
		r += nptr[i] - '0';
		i++;
	}
	return (r * signal);
}

bool	ft_exit_validation(t_ms *ms, t_command *cmd)
{
	long long int	nbr;

	nbr = ft_atoll(cmd->args[1]);
	ft_reset_fd_in_out(ms);
	if ((nbr == 0 && ft_strcmp(cmd->args[1], "0") != 0)
		|| (!ft_is_in_llong_range(cmd->args[1])))
		return (ft_cmd_has_pipes(ms, cmd));
	else
	{
		if (ft_count_args_actual_cmd(cmd) > 2)
		{
			if (ms->n_pipes == 0)
				printf("exit\n");
			printf("minishell: exit: too many arguments\n");
			g_exit_status = 1;
			return (false);
		}
	}
	return (true);
}
