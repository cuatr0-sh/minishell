/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:48:33 by asoria            #+#    #+#             */
/*   Updated: 2025/12/30 03:29:40 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	*find_path(char *tokens, char **envp)
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
		path = ft_strjoin(part_path, tokens);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (free_split(paths), path);
		free(path);
		i++;
	}
	free_split(paths);
	return (NULL);
}

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
			free_split(tokens);
		exit(127);
	}
	path = find_path(tokens[0], envp);
	if (!path)
	{
		free_split(tokens);
		exit(127);
	}
	if (execve(path, tokens, envp) == -1)
	{
		free(path);
		free_split(tokens);
		printf("minishell: %s: command not found", tokens[0]);
		exit(126);
	}
}
