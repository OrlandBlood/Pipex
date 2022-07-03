/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oblood <oblood@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:30:20 by oblood            #+#    #+#             */
/*   Updated: 2022/02/02 23:02:36 by oblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tmp(char *tmp, char *tmp2, char *tmp3)
{
	free(tmp);
	free(tmp2);
	free(tmp3);
}

void	ft_here_doc(char **argv, char **env, int *pipe_fd)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	int		here_pipe[2];

	tmp = NULL;
	tmp2 = NULL;
	while (ft_strcmp(tmp2, argv[2]) != 0)
	{
		tmp = ft_strnjoin(tmp, tmp2);
		free(tmp2);
		write(1, "pipe heredoc> ", 15);
		tmp2 = get_next_line();
	}
	tmp3 = ft_strjoin(tmp, "\n");
	if (pipe(here_pipe) == -1)
		exit(1);
	write (here_pipe[1], tmp3, ft_strlen(tmp3));
	ft_free_tmp(tmp, tmp2, tmp3);
	if (dup2(here_pipe[0], 0) == -1 || dup2(pipe_fd[1], 1) == -1
		|| close(here_pipe[0]) == -1 || close(here_pipe[1]) == -1
		|| close(pipe_fd[0]) == -1 || close(pipe_fd[1]) == -1)
		exit(write(2, "pipex: error\n", 13));
	ft_find_path(argv[3], env);
}
