/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oblood <oblood@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 00:23:52 by oblood            #+#    #+#             */
/*   Updated: 2022/07/03 10:51:18 by oblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_next_line(void)
{
	int		j;
	char	*buf;
	char	*line;
	char	*tmp;

	line = NULL;
	while (1)
	{
		buf = malloc(sizeof(char) + 1);
		j = read(0, buf, 1);
		if (j == 0)
			return (NULL);
		if (buf[0] == '\n' || buf[0] == '\0')
			break ;
		buf[1] = '\0';
		tmp = ft_strjoin(line, buf);
		free(line);
		line = tmp;
		free(buf);
	}	
	free(buf);
	return (line);
}
