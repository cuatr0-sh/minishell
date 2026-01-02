/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:07:48 by asoria            #+#    #+#             */
/*   Updated: 2026/01/02 21:08:36 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cmd_list(t_cmd *cmd_list)
{
	t_cmd	*current;
	int		i;
	int		cmd_num;

	current = cmd_list;
	cmd_num = 1;
	while (current)
	{
		printf("Command %d: [", cmd_num);
		i = 0;
		while (current->args[i])
		{
			printf("%s", current->args[i]);
			if (current->args[i + 1])
				printf(" ");
			i++;
		}
		printf("]");
		if (current->operator)
			printf(" %s", current->operator);
		printf("\n");
		current = current->next;
		cmd_num++;
	}
}

void	print_envp(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->envp[i])
	{
		printf("%s\n", shell->envp[i]);
		i++;
	}
}
