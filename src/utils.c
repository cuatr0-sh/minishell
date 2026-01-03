/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:34:34 by asoria            #+#    #+#             */
/*   Updated: 2026/01/03 19:36:54 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     is_operator(char *token)
{
        if (!token)
                return (0);
        if (ft_strncmp(token, "&&", MAX_BUFFER) == 0)
                return (1);
        if (ft_strncmp(token, "||", MAX_BUFFER) == 0)
                return (1);
        if (ft_strncmp(token, "|", MAX_BUFFER) == 0)
                return (1);
        if (ft_strncmp(token, ";", MAX_BUFFER) == 0)
                return (1);
        if (ft_strncmp(token, ">", MAX_BUFFER) == 0)
                return (1);
        if (ft_strncmp(token, "<", MAX_BUFFER) == 0)
                return (1);
        if (ft_strncmp(token, ">>", MAX_BUFFER) == 0)
                return (1);
        if (ft_strncmp(token, "<<", MAX_BUFFER) == 0)
                return (1);
        return (0);
}
