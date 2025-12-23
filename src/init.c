/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 01:51:27 by asoria            #+#    #+#             */
/*   Updated: 2025/12/23 01:51:29 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_shell(char **argv, char **envp, t_shell *shell)
{
	shell->envp = envp;

	(void)path;
//	shell->path = get_path();
	
	(void)prompt;
//	shell->prompt = get_prompt();
	return (0);
}
