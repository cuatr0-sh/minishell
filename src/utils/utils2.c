/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 04:41:16 by asoria            #+#    #+#             */
/*   Updated: 2026/03/04 00:52:24 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ms_getenv(char **envp, const char *name)
{
	size_t	len;
	int		i;

	len = ft_strlen(name);
	i = 0;
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], name, len)
			&& envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

t_token	*last_token(t_token	*start)
{
	t_token	*end;

	if (!start)
		return (NULL);
	end = start;
	while (end->next != NULL)
		end = end->next;
	return (end);
}

void	newl_and_sigint(void)
{
	if (g_signal == SIGINT)
	{
		write(1, "\n", 1);
		g_signal = 0;
	}
}
