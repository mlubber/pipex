/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/16 09:50:03 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/04/22 09:49:31 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

char	*ft_get_exec_cmd(char *cmd, char **envp);
void	ft_usage(void);
void	ft_exit(char *arg);
char	**ft_free_list(char **strlist);
void	ft_cmd_not_found(char **cmd);
int		ft_strlen(char *str);
char	*ft_strnstr(const char	*big, const char *little, size_t len);
char	**ft_split(const char *str, char c);
char	*ft_strjoin(char *s1, char *s2);

#endif
