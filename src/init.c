/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 01:51:27 by asoria            #+#    #+#             */
/*   Updated: 2025/12/29 13:20:59 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_envp(char **envp, t_shell *shell)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
		i++;
	shell->envp = malloc(sizeof(char *) * (i + 1));
	if (!shell->envp)
		return(1);
	j = 0;
	while (j < i)
	{
		shell->envp[j] = ft_strdup(envp[j]);
		if (!shell->envp[j])
		{
			while (j > 0)
				free(shell->envp[--j]);
			free(shell->envp);
			return (1);
		}
		j++;
	}
	shell->envp[j] = NULL;
	return (0);
}

static void	init_config_file(t_shell *shell)
{
	int	fd;

	shell->config_file = ".msrc";
	fd = open(shell->config_file, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
		printf("Couldn't open .msrc: %s\n", strerror(errno));
	else
		close(fd);
}

int	init_shell(char **argv, char **envp, t_shell *shell)
{
	(void)argv;
	get_envp(envp, shell);
	init_config_file(shell);
	return (0);
}
