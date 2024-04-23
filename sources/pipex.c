/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/16 09:48:57 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/04/23 10:31:39 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_exec(char **argv, int i, char **envp)
{
	char	**cmd_list;

	cmd_list = ft_split(argv[i], ' ');
	if (cmd_list[0] == NULL)
		cmd_list[0] = "cat\0";
	if (cmd_list[0] && ft_get_exec_cmd(cmd_list[0], envp))
		execve(ft_get_exec_cmd(cmd_list[0], envp), cmd_list, envp);
	ft_cmd_not_found(cmd_list);
}

void	ft_child_in(int *pipe_fd, char **argv, char **envp)
{
	int		pid;
	int		fd;

	pid = fork();
	if (pid == -1)
		ft_exit("fork");
	if (pid == 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_exit(argv[1]);
		close(pipe_fd[0]);
		dup2(fd, STDIN_FILENO);
		close(fd);
		dup2(pipe_fd[1], STDOUT_FILENO);
		ft_exec(argv, 2, envp);
	}
}

void	ft_child_out(int *pipe_fd, char **argv, char **envp)
{
	int		pid;
	int		fd;

	pid = fork();
	if (pid == -1)
		ft_exit("fork");
	if (pid == 0)
	{
		fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			ft_exit(argv[4]);
		close(pipe_fd[1]);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		dup2(pipe_fd[0], STDIN_FILENO);
		ft_exec(argv, 3, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int	status;
	int	exit_code;

	errno = 0;
	if (argc != 5)
		ft_usage();
	if (pipe(pipe_fd) == -1)
		ft_exit(NULL);
	ft_child_in(pipe_fd, argv, envp);
	ft_child_out(pipe_fd, argv, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	if (WIFEXITED(status))
	{
		exit_code = WEXITSTATUS(status);
		if (exit_code != 0)
			return (exit_code);
	}
	return (0);
}
