/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 01:51:27 by asoria            #+#    #+#             */
/*   Updated: 2025/12/28 16:47:20 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_shell(char **argv, char **envp, t_shell *shell)
{
	int	i;
	int	j;

	(void)argv;
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
	shell->config_file = ".msrc";
	return (0);
}
