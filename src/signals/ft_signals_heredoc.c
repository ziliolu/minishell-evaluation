/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:55:09 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/12 19:03:15 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_handler_heredoc(int signal, t_heredoc *ptr)
{
	static t_heredoc *save = NULL;

	if (save == NULL)
		save = ptr;
	else if (signal == SIGINT)
	{
		printf("\n");
		g_exit_status = 130;
		ft_free(save->eof);
		ft_free(save->str);
		exit(g_exit_status);
	}
}

void	ft_signals_heredoc(t_heredoc *ptr)
{
	signal(SIGINT, (void *)ft_handler_heredoc);
	ft_handler_heredoc(-1, ptr);
	signal(SIGQUIT, SIG_IGN);
}
