/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:46:23 by asoria            #+#    #+#             */
/*   Updated: 2025/12/21 14:57:17 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(t_shell *shell)
{
	while (1)
	{
		read_input(shell);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;

	(void)argc;
	shell = NULL;
	init_shell(argv, envp, shell);
	minishell(shell);
	if (!shell)
		return (1);
	
	return (0);
}
