/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:06:27 by asoria            #+#    #+#             */
/*   Updated: 2026/02/25 01:52:50 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*get_prompt(t_shell *shell)
{
	(void)shell;
	return ("\033[32mStudent@42\033[34m - $ \033[0m");
}

void	process_input(t_shell *shell)
{
	if (!shell->input)
		return ;
	expand_parameters(shell, &shell->input);
	refresh_path(shell);
	if (!tokenize_input(shell))
		return ;
	if (init_ast(shell))
		execute_pipeline(shell);
	else
		shell->program_exit = 2;
}

static char	*append_line(char *base, char *line)
{
	char	*tmp;
	char	*joined;

	tmp = ft_strjoin(base, "\n");
	free(base);
	if (!tmp)
		return (NULL);
	joined = ft_strjoin(tmp, line);
	free(tmp);
	return (joined);
}

static void	continue_input(t_shell *shell)
{
	char	*line;

	while (has_unclosed_quote(shell->input))
	{
		line = readline("> ");
		if (g_signal == SIGINT || !line)
		{
			free(line);
			free(shell->input);
			shell->input = NULL;
			return ;
		}
		shell->input = append_line(shell->input, line);
		free(line);
		if (!shell->input)
			return ;
	}
}

void	read_input(t_shell *shell)
{
	shell->input = readline(shell->prompt);
	if (!shell->input)
	{
		g_signal = 0;
		shell->is_alive = 0;
		return ;
	}
	if (!*shell->input)
	{
		free(shell->input);
		shell->input = NULL;
		g_signal = 0;
		return ;
	}
	continue_input(shell);
	if (shell->input)
		add_history(shell->input);
}
