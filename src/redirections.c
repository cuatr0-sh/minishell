/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:00:21 by edblazqu          #+#    #+#             */
/*   Updated: 2026/01/07 14:00:22 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_type	select_redirections(t_token	*tokens)
{
	t_token_type	*redirections;
	size_t			i;
	size_t			j;
	size_t			count;

	i = 0;
	count = 0;
	while (tokens[i].value != NULL)
	{
		if (tokens[i].type > 0)
			count++;
		i++;
	}
	redirections = ft_calloc(count, sizeof(t_token_type));
	if (!redirections)
		return (NULL);
	i = 0;
	while (tokens[i].value != NULL)
	{
		if (tokens[i].type > 0)
			redirections[j++] = tokens[i].type;
		i++;
	}
	return (redirections);
}

void	execute_redirections(t_shell *shell, t_token_type *redirections)
{
	
}
