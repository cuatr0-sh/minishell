/* ************************************************************************** */
/*									    */
/*							:::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*						    +:+ +:+	 +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+	*/
/*						+#+#+#+#+#+   +#+	   */
/*   Created: 2025/12/18 19:37:34 by asoria	    #+#    #+#	     */
/*   Updated: 2025/12/20 00:46:00 by asoria           ###   ########.fr       */
/*									    */
/* ************************************************************************** */

#include "minishell.h"

int	init_shell(char **argv, char **envp, t_shell *shell)
{
	(void)argv;
	(void)envp;
	(void)shell;
	printf("Reached \033[32minit_shell\033[0m\n");
	return (0);
}
