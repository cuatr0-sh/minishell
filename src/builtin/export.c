/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 00:48:30 by asoria            #+#    #+#             */
/*   Updated: 2026/03/03 20:34:43 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_export(char **envp)
{
	char	*equal;
	int		i;

	i = 0;
	while (envp[i])
	{
		equal = ft_strchr(envp[i], '=');
		if (equal)
			printf("declare -x %.*s=\"%s\"\n",
				(int)(equal - envp[i]), envp[i], equal + 1);
		else
			printf("declare -x %s\n", envp[i]);
		i++;
	}
}

static int	update_var(char *arg, int index, char ***envp)
{
	char	*new_val;

	new_val = ft_strdup(arg);
	if (!new_val)
		return (1);
	free((*envp)[index]);
	(*envp)[index] = new_val;
	return (0);
}

static int	add_var(char *arg, char ***envp)
{
	int		size;
	char	**new_env;
	int		i;

	size = env_size(*envp);
	new_env = malloc(sizeof(char *) * (size + 2));
	if (!new_env)
		return (1);
	i = 0;
	while (i < size)
	{
		new_env[i] = (*envp)[i];
		i++;
	}
	new_env[i] = ft_strdup(arg);
	if (!new_env[i])
	{
		free(new_env);
		return (1);
	}
	new_env[i + 1] = NULL;
	free(*envp);
	*envp = new_env;
	return (0);
}

static int	export_one(char *arg, char ***envp)
{
	int	index;

	index = find_var(*envp, arg);
	if (index != -1)
		return (update_var(arg, index, envp));
	return (add_var(arg, envp));
}

int	ms_export(t_token *args, char ***envp)
{
	int		ret;
	int		valid;

	if (!args)
		return (print_export(*envp), 0);
	ret = 0;
	while (args)
	{
		valid = is_valid_export_arg(args->value);
		if (valid == -1)
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(args->value, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			ret = 1;
		}
		else if (valid == 1)
		{
			if (export_one(args->value, envp))
				ret = 1;
		}
		args = args->next;
	}
	return (ret);
}
