/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:06:27 by asoria            #+#    #+#             */
/*   Updated: 2025/12/29 15:30:58 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	process_input(char *input, t_shell *shell)
{
	(void)shell;
	(void)input;
}

/* WIP: Will extract custom PS1 from ".msrc" config file */
char	*get_prompt(t_shell *shell)
{
	(void)shell;
	return ("\033[32mStudent@42\033[34m - $ \033[0m");
}

void	read_input(t_shell *shell)
{
	char	*input;
	char	*prompt;

	input = NULL;
	prompt = get_prompt(shell);
	input = readline(prompt);
	while (input != NULL)
	{
		if (*input)
			add_history(input);
		process_input(input, shell);
		free(input);
	}
}
