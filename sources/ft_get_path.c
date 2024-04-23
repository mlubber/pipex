/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_path.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/16 09:51:57 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/04/23 08:48:53 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**ft_get_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*ft_get_exec_cmd(char *cmd, char **envp)
{
	char	**dir_list;
	char	*full_dir_path;
	char	*exec_cmd;
	int		i;

	i = 0;
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	dir_list = ft_get_paths(envp);
	i = -1;
	while (dir_list[++i])
	{
		full_dir_path = ft_strjoin(dir_list[i], "/");
		exec_cmd = ft_strjoin(full_dir_path, cmd);
		free(full_dir_path);
		if (access(exec_cmd, F_OK | X_OK) == 0)
		{
			ft_free_list(dir_list);
			return (exec_cmd);
		}
		free(exec_cmd);
	}
	ft_free_list(dir_list);
	return (NULL);
}
