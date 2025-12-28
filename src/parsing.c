/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:06:27 by asoria            #+#    #+#             */
/*   Updated: 2025/12/28 21:09:25 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	process_input(char *input, t_shell *shell)
{
	(void)shell;
	printf("Input: %s\n", input);
}

char	*get_prompt(void)
{
	int	i;
	int	fd;
	char	*prompt;
	char	*config_file;

	i = 0;
	config_file = ".msrc";
	prompt = "minishell";
	fd = open(config_file, O_RDONLY | O_CREAT,  644);
	if (fd < 0)
	{
		perror("open");
		close(fd);
		return (prompt);
	}
	while (ft_strnstr(config_file, "prompt", 6) == 0)
		i++;
	close(fd);
	return (prompt);
}

void    read_input(t_shell *shell)
{
	char    *input;
	char    *prompt;
//	char    *command;

        (void)shell;
        input = NULL;
	/* this will have to change to get_prompt() to get custom colors, prompt and all that bs */
	prompt = "\033[32mstudent@42\033[34m - $ \033[0m";
        while ((input = readline(prompt)) != NULL)
        {  
                if (*input) add_history(input);
			process_input(input, shell);
                free(input);
        }  
}
