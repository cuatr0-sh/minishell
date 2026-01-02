/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:06:27 by asoria            #+#    #+#             */
/*   Updated: 2026/01/02 04:10:37 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fork_program(t_shell *shell)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	if (pid == 0) {
		execute(shell->input, shell->envp);
		exit(1);
	}
	else
		waitpid(pid, &status, 0);
}

static void	process_input(t_shell *shell)
{
	tokenize_input(shell);
	fork_program(shell);
}

/* WIP: Will extract custom PS1 from ".msrc" config file */
char	*get_prompt(t_shell *shell)
{
	(void)shell;
	return ("\033[32mStudent@42\033[34m - $ \033[0m");
}

void	read_input(t_shell *shell)
{
	char	*prompt;

	prompt = get_prompt(shell);
	while (1)
	{
		shell->input = readline(prompt);
		if (!shell->input)
			break ;
		if (*shell->input)
			add_history(shell->input);
		process_input(shell);
		//free(shell->input);
	}
}
