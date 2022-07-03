/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oblood <oblood@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:33:25 by oblood            #+#    #+#             */
/*   Updated: 2022/02/03 00:02:01 by oblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include <stdio.h>

void	ft_parent(int argc, char **argv, char **env, int *pipe_fd)
{
	int	fd_file;

	if (ft_strcmp(argv[1], "here_doc") == 0)
		fd_file = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		fd_file = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd_file == -1)
	{
		perror("pipex");
		exit(1);
	}
	if (dup2(pipe_fd[0], 0) == -1 || dup2(fd_file, 1) == -1
		|| close(fd_file) == -1 || close(pipe_fd[0]) == -1
		|| close(pipe_fd[1]) == -1)
		exit (write(2, "pipex:error\n", 13));
	ft_find_path(argv[argc - 2], env);
}	

void	ft_child(char **argv, char **env, int *pipe_fd)
{
	int	fd_file;

	if (ft_strcmp(argv[1], "here_doc") == 0)
		ft_here_doc(argv, env, pipe_fd);
	else
	{	
		if (access(argv[1], F_OK) != 0 || access(argv[1], R_OK) != 0)
		{
			perror("pipex");
			exit(1);
		}	
		else if (!ft_strcmp(argv[1], argv[4]))
		{
			unlink(argv[1]);
			fd_file = open(argv[1], O_RDONLY | O_CREAT, 0644);
		}	
		fd_file = open(argv[1], O_RDONLY);
		if (dup2(fd_file, 0) == -1 || dup2(pipe_fd[1], 1) == -1
			|| close(fd_file) == -1 || close(pipe_fd[0]) == -1
			|| close(pipe_fd[1]) == -1)
			exit(write(2, "pipex: error\n", 13));
		ft_find_path(argv[2], env);
	}
}	

int	main(int argc, char **argv, char **env)
{
	int	pid;
	int	pipe_fd[2];

	if (argc < 4 || !env)
		return (1);
	if (pipe(pipe_fd) == -1)
	{
		perror("pipex");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("pipex");
		exit(1);
	}
	if (pid == 0)
		ft_child(argv, env, pipe_fd);
	ft_parent(argc, argv, env, pipe_fd);
	return (0);
}
