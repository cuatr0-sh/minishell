/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:48:33 by asoria            #+#    #+#             */
/*   Updated: 2026/01/06 02:46:07 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_cmd *cmd, char **envp)
{
	(void)envp;
	if (strncmp("pwd", cmd->args[0], 3) == 0)
		return (1);
	return (0);
}

int	execute_builtin(t_shell *shell, t_cmd *cmd, char **envp)
{
	(void)envp;
	if (ft_strncmp(cmd->args[0], "pwd", 3) == 0)
		ms_pwd();
	if (ft_strncmp(cmd->args[0], "exit", 4) == 0)
	{
		if (cmd->arg_count > 1)
			ms_exit(ft_atoi(cmd->args[1]), shell);
		else
			ms_exit(0, shell);
	}
	return (1);
}

void	execute_external(t_cmd *cmd, char **envp)
{
	char	*path;

	path = find_path(cmd->args[0], envp);
	if (!path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	if (execve(path, cmd->args, envp) == -1)
	{
		free(path);
		perror("execve");
		exit(126);
	}
}

void	execute_command(t_cmd *cmd, char **envp, t_shell *shell)
{
	if (!cmd || !cmd->args || !cmd->args[0])
		exit(127);
	if (is_builtin(cmd, envp))
		execute_builtin(shell, cmd, envp);
	else if (!is_builtin(cmd, envp))
		execute_external(cmd, envp);
}

void	execute_pipeline(t_shell *shell)
{
	int		prev_fd;
	int		pipe_fd[2];
	t_cmd	*cmd;

	if (!shell->cmd_list)
		return ;
	prev_fd = -1;
	cmd = shell->cmd_list;
	while (cmd)
	{
		if (cmd->operator && ft_strncmp(cmd->operator, "|", 1) == 0)
			pipe(pipe_fd);
		if (fork() == 0)
		{
			setup_pipe_fds(cmd, prev_fd, pipe_fd);
			execute_command(cmd, shell->envp, shell);
		}
		if (prev_fd != -1)
			close(prev_fd);
		check_if_pipe(cmd->operator, &prev_fd, &pipe_fd);
		cmd = cmd->next;
	}
	while (wait(NULL) > 0)
		;
}
