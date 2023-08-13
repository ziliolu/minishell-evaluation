/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_broken_cmds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:02:28 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/08/13 07:39:12 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_broken_cmds(t_ms *ms, char *str)
{
	t_broken_cmds	b;

	b. = ft_strlen(str) - 1;
	b.prompt_tmp = NULL;
	b.new_str = NULL;
	b.tmp = NULL;
	b.prompt = "> ";
	if (str[0] == '|')
	{
		ft_error(ms, "syntax error near unexpected token `|'", NULL, 2);
		return (NULL);
	}	
	if (str[b.] == '|')
	{
		b.--;
		while (str[b.] == ' ')
			b.--;
		if (str[b.] == '|' || str[b.] == '>'
			|| str[b.] == '<' || str[b.] == '&')
		{
			ft_error(ms, "syntax error near unexpected token `|'", NULL, 2);
			return (NULL);
		}
		return (ft_is_broken_cmds_pipe(ms, str, &b));
	}
	return (ft_strdup(str));
}
