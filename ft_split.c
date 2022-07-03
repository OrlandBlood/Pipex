/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oblood <oblood@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:29:46 by oblood            #+#    #+#             */
/*   Updated: 2021/10/24 19:03:11 by oblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	wordcount;

	i = -1;
	wordcount = 0;
	while (s[++i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wordcount ++;
	}
	return (wordcount);
}	

int	ft_lenword(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

void	*ft_leak(char **res, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(res[i]);
		i++;
	}	
	free(res);
	return (NULL);
}

char	**ft_fill_str(char const *s, char c, char **res, int wordcount)
{
	int	i;
	int	len;
	int	j;

	i = -1;
	while (++i < wordcount)
	{
		while (*s == c)
			s++;
		len = ft_lenword(s, c);
		res[i] = malloc(len + 1);
		if (!res[i])
			return (ft_leak(res, i));
		j = 0;
		while (j < len)
			res[i][j++] = *s++;
		res[i][j] = '\0';
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word;

	if (!s)
		return (0);
	word = ft_wordcount(s, c);
	res = (char **) malloc(sizeof(char *) * (word + 1));
	if (!res)
		return (0);
	res = ft_fill_str(s, c, res, word);
	return (res);
}
