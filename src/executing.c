/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:48:33 by asoria            #+#    #+#             */
/*   Updated: 2026/01/02 04:32:23 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (free_tokens(paths), path);
		free(path);
		i++;
	}
	free_tokens(paths);
	return (NULL);
}

/* 
 * WIP. after tokenize_input, this ft STILL uses whole input instead of
 * just shell->token[x][y].
 * This will have to change to execute_single_command or similar.
*/
void	execute(char *input, char **envp)
{
	char	*path;
	char	**tokens;

	if (!input || !*input)
		exit(127);
	tokens = ft_split(input, ' ');
	if (!tokens || !tokens[0] || !tokens[0][0])
	{
		if (tokens)
			free_tokens(tokens);
		exit(127);
	}
	path = find_path(tokens[0], envp);
	if (!path)
	{
		free_tokens(tokens);
		exit(127);
	}
	if (execve(path, tokens, envp) == -1)
	{
		free(path);
		free_tokens(tokens);
		printf("minishell: %s: command not found", tokens[0]);
		exit(126);
	}
}
