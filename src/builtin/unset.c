/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 06:32:00 by asoria            #+#    #+#             */
/*   Updated: 2026/03/03 23:36:37 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_identifier(const char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	find_env_index(char **envp, const char *name)
{
	int		i;
	size_t	len;

	if (!envp || !*name)
		return (-1);
	len = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

static void	remove_env_var(char **envp, int index)
{
	free(envp[index]);
	while (envp[index])
	{
		envp[index] = envp[index + 1];
		index++;
	}
}

int	ms_unset(char ***envp, t_token *args)
{
	int	idx;
	int	ret;

	if (!envp || !*envp)
		return (1);
	ret = 0;
	while (args)
	{
		if (!is_valid_identifier(args->value))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(args->value, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			ret = 1;
		}
		else
		{
			idx = find_env_index(*envp, args->value);
			if (idx != -1)
				remove_env_var(*envp, idx);
		}
		args = args->next;
	}
	return (ret);
}
