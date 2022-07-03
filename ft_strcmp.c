/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oblood <oblood@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:45:23 by oblood            #+#    #+#             */
/*   Updated: 2021/10/26 22:51:54 by oblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	if (s1 == NULL)
		return (1);
	while (*us1 || *us2)
	{
		if (*us1 != *us2)
			return (1);
		us1 ++;
		us2 ++;
	}
	return (0);
}
