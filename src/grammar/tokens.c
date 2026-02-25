/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:43:20 by asoria            #+#    #+#             */
/*   Updated: 2026/02/25 01:49:55 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "minishell.h"

static t_token_type	get_type(char *s, int len)
{
	if (len == 1 && s[0] == '|')
		return (T_PIPE);
	if (len == 1 && s[0] == '<')
		return (T_INFILE);
	if (len == 1 && s[0] == '>')
		return (T_OUTFILE);
	if (len == 2 && s[0] == '<' && s[1] == '<')
		return (T_HEREDOC);
	if (len == 2 && s[0] == '>' && s[1] == '>')
		return (T_APPEND);
	return (T_WORD);
}

static int	add_token(t_shell *shell, char *s, int len)
{
	t_token_type	type;
	char			*value;
	t_token			*tok;

	type = get_type(s, len);
	if (type == T_WORD)
		value = strip_quotes(s, len);
	else
		value = ft_substr(s, 0, len);
	if (!value)
		return (0);
	tok = new_token(value);
	if (!tok)
		return (free(value), 0);
	tok->type = type;
	add_token_to_list(&shell->first, tok);
	return (1);
}

int	tokenize_input(t_shell *shell)
{
	char	*s;
	int		len;

	s = shell->input;
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		if (!*s)
			break ;
		len = raw_token_len(s);
		if (len < 0)
		{
			ft_putstr_fd("minishell: syntax error: unclosed quote\n", 2);
			return (0);
		}
		if (len == 0)
			break ;
		if (!add_token(shell, s, len))
			return (0);
		s += len;
	}
	return (1);
}
