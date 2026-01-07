/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 02:47:47 by asoria            #+#    #+#             */
/*   Updated: 2026/01/07 03:50:03 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

# define MAX_TOKENS 1000
# define MAX_BUFFER 4096

typedef enum e_token_type
{
	T_WORD,
	T_ENDLINE,
	T_PIPE,
	T_INFILE,
	T_OUTFILE,
	T_APPEND,
	T_HEREDOC,
	T_AND,
	T_OR
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}	t_token;

typedef struct s_cmd
{
	char			**args;
	int				arg_count;
	char			*operator;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_shell
{
	bool	is_alive;
	int		exit_code;
	char	**envp;
	char	*prompt;
	char	*input;
	t_token	*token;
	t_cmd	*cmd_list;
	char	*config_file;
	char	*history_file;
}		t_shell;

typedef struct s_redirect
{
	int		prev_fd;
	int		heredoc;
	int		ext_files[2];
	int		fd[2];
	pid_t	*child;
}	t_redirect;

/* init.c */
char	*find_path(char *cmd, char **envp);
void	process_input(t_shell *shell);
int		init_shell(char **argv, char **envp, t_shell *shell);

/* parsing.c */
char	*get_prompt(t_shell *shell);
void	read_input(t_shell *shell);

/* debug.c */
void	print_cmd_list(t_cmd *cmd_list);
void	print_envp(t_shell *shell);

/* cleanup.c */
void	free_envp(char ***envp);
void	free_split(char **tokens);
void	free_cmd_list(t_cmd **cmd_list);
void	black_hole(t_shell *shell);

/* executing.c  */
int		is_builtin(t_cmd *cmd, char **envp);
int		execute_builtin(t_shell *shell, t_cmd *cmd, char **envp);
void	execute_external(t_cmd *cmd, char **envp);
void	execute_command(t_cmd *cmd, char **envp, t_shell *shell);
int		count_commands(t_cmd *cmd_list);

/* tokens.c */
void	tokenize_input(t_shell *shell);

/* clusters.c */
int		typify_token(t_token *token);
void	clusterize_tokens(t_shell *shell);

/* builtin.c */
int		is_builtin(t_cmd *cmd, char **envp);

/* BUILTINS */
char	*ms_cd(t_shell *shell);
void	ms_pwd(void);
void	ms_exit(int status, t_shell	*shell);

/* pipes */
void	check_if_pipe(char *op, int *prev_fd, int (*pipe_fd)[2]);
void	execute_pipeline(t_shell *shell);
void	setup_pipe_fds(t_cmd *cmd, int prev_fd, int pipe_fd[2]);

#endif
