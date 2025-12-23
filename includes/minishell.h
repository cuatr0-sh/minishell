/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:47:47 by asoria            #+#    #+#             */
/*   Updated: 2025/12/21 14:58:12 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

typedef struct	s_shell
{
	char	**envp;
	char	**path;
	char	*prompt;
}		t_shell;

int	init_shell(char **argv, char **envp, t_shell *shell);
void	read_input(t_shell *shell);


#endif

