/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oblood <oblood@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 00:05:01 by oblood            #+#    #+#             */
/*   Updated: 2022/02/03 00:23:23 by oblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*first_step(char *str)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char *) * ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (str[++i])
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

char	*ft_strnjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (first_step((char *)s2));
	res = malloc(sizeof(*res) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	res[i] = '\n';
	j = 0;
	while (s2[++j - 1])
		res[i + j] = s2[j - 1];
	res[i + j] = '\0';
	free((char *)s1);
	return (res);
}
