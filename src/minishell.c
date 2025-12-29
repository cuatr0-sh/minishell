/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:46:23 by asoria            #+#    #+#             */
/*   Updated: 2025/12/29 13:01:12 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(t_shell *shell)
{
		//print_envp(shell);
		read_input(shell);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	ft_bzero(&shell, sizeof(t_shell));
	if (init_shell(argv, envp, &shell))
		return (1);
	minishell(&shell);
	black_hole(&shell);
	return (0);
}
