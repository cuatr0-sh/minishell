/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:47:40 by edblazqu          #+#    #+#             */
/*   Updated: 2026/03/04 01:41:12 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_invalid(int fd[2])
{
	fd[0] = -1;
	fd[1] = -1;
}

void	setup_pipe_fds(int in_fd, int *out_fd)
{
	if (out_fd[0] != -1)
		close(out_fd[0]);
	if (in_fd != -1)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	if (out_fd[1] != -1)
	{
		dup2(out_fd[1], STDOUT_FILENO);
		close(out_fd[1]);
	}
}

void	child_exec(t_cmd *cmd, t_shell *shell)
{
	char	*path;

	setup_signals_child();
	if (!cmd || !check_redirs(cmd) || !cmd->execute)
	{
		child_black_hole(shell, NULL);
		exit(1);
	}
	if (dup2_manager(cmd->redir) == 0)
	{
		child_black_hole(shell, NULL);
		exit(1);
	}
	path = search_cmd(cmd->execute[0], shell);
	if (!path)
	{
		perror("minishell");
		child_black_hole(shell, NULL);
		exit(127);
	}
	execve(path, cmd->execute, shell->envp);
	child_black_hole(shell, path);
	exit(127);
}

char	*search_cmd(char *cmd, t_shell *shell)
{
	char	*route;
	size_t	i;

	if (!cmd)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	if (!shell ||!shell->path)
		return (NULL);
	i = 0;
	while (shell->path[i])
	{
		route = ft_strjoin(shell->path[i], cmd);
		if (access(route, X_OK) == 0)
			return (route);
		free(route);
		route = NULL;
		i++;
	}
	return (NULL);
}
