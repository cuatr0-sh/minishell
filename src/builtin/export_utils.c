/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:34:54 by asoria            #+#    #+#             */
/*   Updated: 2026/03/03 20:35:16 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_size(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

int	find_var(char **envp, const char *arg)
{
	size_t	name_len;
	char	*equal;
	int		i;

	equal = ft_strchr(arg, '=');
	if (!equal)
		return (-1);
	name_len = (size_t)(equal - arg);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], arg, name_len) == 0
			&& envp[i][name_len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

int	is_valid_export_arg(const char *arg)
{
	size_t	name_len;
	size_t	i;
	char	*equal;

	equal = ft_strchr(arg, '=');
	if (!equal)
		return (0);
	name_len = (size_t)(equal - arg);
	if (name_len == 0)
		return (-1);
	if (!ft_isalpha(arg[0]) && arg[0] != '_')
		return (-1);
	i = 1;
	while (i < name_len)
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (-1);
		i++;
	}
	return (1);
}
