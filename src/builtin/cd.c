/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:49:10 by asoria            #+#    #+#             */
/*   Updated: 2026/01/02 21:22:58 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ms_cd(t_shell *shell)
{
	char	old_wd[PATH_MAX];
	char	new_wd[PATH_MAX];

	(void)shell;
	if (!getcwd(old_wd, PATH_MAX))
	{
		perror("cwd");
		return (NULL);
	}
	printf("old_wd: %s\n", old_wd);
	ft_strlcpy(new_wd, old_wd, PATH_MAX);
	printf("new_wd: %s\n", new_wd);
	return (NULL);
}
