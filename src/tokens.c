/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:43:20 by asoria            #+#    #+#             */
/*   Updated: 2026/01/02 04:09:24 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*skip_whitespace(char *input)
{
	while (*input == ' ' || *input == '\t')
		input++;
	return (input);
}

static char	*get_token(t_shell *shell, int i)
{
	int	j;
	int	k;
	char	*start;

	start = shell->input;
	j = 0;
	while (*shell->input != ' ' && *shell->input != '\t'
		&& *shell->input != '\0')
	{	
		shell->input++;
		j++;
	}
	shell->token[i] = malloc(sizeof(char) * (j + 1));
	if (!shell->token[i])
		return (NULL);
	k = 0;
	while (k < j)
	{
		shell->token[i][k] = start[k];
		k++;
	}
	shell->token[i][j] = '\0';
	return (shell->input);
}

void	tokenize_input(t_shell *shell)
{
	int	i;
	char	*start;

	start = shell->input;
	shell->token = malloc(sizeof(char *) * MAX_TOKENS);
	i = 0;
	while (*shell->input != '\0')
	{
		shell->input = skip_whitespace(shell->input);
		if (*shell->input == '\0')
			break ;
		get_token(shell, i);
		i++;
	}
	shell->input = start;
}
