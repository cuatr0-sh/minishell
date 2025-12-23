/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:06:27 by asoria            #+#    #+#             */
/*   Updated: 2025/12/23 01:48:04 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	prompt = "\033[32mstudent\033[0m@42: "; /* get_prompt() */
        while ((input = readline(prompt)) != NULL)
        {  
                if (*input) add_history(input);
                free(input);
        }  
}
	
