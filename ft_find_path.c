/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oblood <oblood@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:31:30 by oblood            #+#    #+#             */
/*   Updated: 2022/01/29 09:59:38 by oblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

char	*ft_get_path(char *cmd, char **env)
{
	int		i;
	char	*res;
	char	**paths;

	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == NULL)
	{
		i++;
		if (env[i] == NULL)
			return (NULL);
	}
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		return (NULL);
	res = ft_search_path(paths, cmd);
	if (!res)
	{
		ft_free(paths);
		return (NULL);
	}	
	return (res);
}	

char	*ft_search_path(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*res;

	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (NULL);
		res = ft_strjoin(tmp, cmd);
		if (!res)
			return (NULL);
		free(tmp);
		if (access(res, F_OK) == 0)
		{
			ft_free(paths);
			return (res);
		}
		else
			free(res);
	}
	return (NULL);
}	

void	ft_find_path(char *argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
	{
		perror("pipex");
		exit(1);
	}
	path = ft_get_path(cmd[0], env);
	if (!path)
	{
		ft_free(cmd);
		write(2, "pipex: bad path\n", 16);
		exit(1);
	}
	if (execve(path, cmd, env) == -1)
	{
		free(path);
		ft_free(cmd);
		perror("pipex");
		exit(1);
	}	
}
