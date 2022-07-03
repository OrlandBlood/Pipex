/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oblood <oblood@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:40:57 by oblood            #+#    #+#             */
/*   Updated: 2022/01/29 10:02:16 by oblood           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

size_t	ft_strlen(const char *s);

int		ft_strcmp(const char *s1, const char *s2);

char	*get_next_line(void);
char	**ft_split(char const *s, char c);
char	*ft_get_path(char *cmd, char **env);
char	*ft_search_path(char **paths, char *cmd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *h, const char *n, size_t len);
char	*ft_strnjoin(char const *s1, char const *s2);
char	*first_step(char *str);

void	ft_free(char **paths);
void	ft_free_tmp(char *tmp, char *tmp2, char *tmp3);
void	ft_find_path(char *argv, char **env);
void	ft_child_proc(char **argv, char **env, int *fd);
void	ft_parent_proc(int argc, char **argv, char **env, int *fd);
void	ft_here_doc(char **argv, char **env, int *pipe_fd);

#endif
