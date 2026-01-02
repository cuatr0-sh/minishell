/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:47:47 by asoria            #+#    #+#             */
/*   Updated: 2026/01/02 04:07:16 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

#define MAX_TOKENS 1000

typedef struct s_shell
{
	char	**envp;
	char	**path;
	char	*prompt;
	char	*input;
	char	**token;
	char	*config_file;
	char	*history_file;
}		t_shell;

/* init.c */
int		init_shell(char **argv, char **envp, t_shell *shell);

/* parsing.c */
void	read_input(t_shell *shell);

/* debug.c */
void	print_envp(t_shell *shell);

/* cleanup.c */
void	black_hole(t_shell *shell);

/* executing.c  */
void	execute(char *argv, char **envp);

/* tokens.c */
void	tokenize_input(t_shell *shell);

/* cd.c */
char	*ms_cd(t_shell *shell);

#endif
