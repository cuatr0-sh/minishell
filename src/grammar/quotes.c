/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:55:42 by asoria            #+#    #+#             */
/*   Updated: 2026/02/25 01:35:52 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	scan_word_len(char *s)
{
	char	q;
	int		i;

	q = 0;
	i = 0;
	while (s[i])
	{
		if (!q && (s[i] == '\'' || s[i] == '"'))
			q = s[i];
		else if (q && s[i] == q)
			q = 0;
		else if (!q && (s[i] == ' ' || s[i] == '\t'))
			break ;
		else if (!q && (s[i] == '|' || s[i] == '>' || s[i] == '<'))
			break ;
		i++;
	}
	if (q)
		return (-1);
	return (i);
}

int	raw_token_len(char *s)
{
	if (s[0] == '|')
		return (1);
	if ((s[0] == '>' || s[0] == '<') && s[1] == s[0])
		return (2);
	if (s[0] == '>' || s[0] == '<')
		return (1);
	return (scan_word_len(s));
}

static void	fill_stripped(char *out, char *s, int len)
{
	char	q;
	int		i;
	int		j;

	q = 0;
	i = 0;
	j = 0;
	while (i < len)
	{
		if (!q && (s[i] == '\'' || s[i] == '"'))
			q = s[i];
		else if (q && s[i] == q)
			q = 0;
		else
			out[j++] = s[i];
		i++;
	}
	out[j] = '\0';
}

char	*strip_quotes(char *s, int len)
{
	char	*out;

	out = malloc(len + 1);
	if (!out)
		return (NULL);
	fill_stripped(out, s, len);
	return (out);
}

int	has_unclosed_quote(char *s)
{
	char	q;
	int		i;

	q = 0;
	i = 0;
	while (s[i])
	{
		if (!q && (s[i] == '\'' || s[i] == '"'))
			q = s[i];
		else if (q && s[i] == q)
			q = 0;
		i++;
	}
	return (q != 0);
}
