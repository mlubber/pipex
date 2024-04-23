/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/16 09:52:39 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/04/23 09:19:08 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
		ft_putchar_fd(str[i++], fd);
}

void	ft_usage(void)
{
	ft_putstr_fd("Usage: ./pipex [infile] [cmd1] [cmd2] [outfile]\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_exit(char *arg)
{
	if (errno == 0)
	{
		if (arg == NULL)
		{
			ft_putstr_fd("Command '' not found \n", 2);
			exit(126);
		}
		else
			ft_putstr_fd("Error\n", 2);
	}
	else
		perror(arg);
	exit(EXIT_FAILURE);
}

void	ft_cmd_not_found(char **cmd)
{
	write(2, cmd[0], ft_strlen(cmd[0]));
	ft_putstr_fd(": command not found\n", 2);
	ft_free_list(cmd);
	exit(127);
}
