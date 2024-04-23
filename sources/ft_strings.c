/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strings.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/16 09:55:11 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/04/22 16:16:09 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0' || little == NULL)
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == 0)
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

// char	*ft_get_env(char *cmd)
// {
// 	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
// 		return (cmd);
// 	else
// 		return (NULL);
// }

// int	main(void)
// {
// 	char	*cmd;
// 	char	*res;
// 	int		i;

// 	cmd = "nonexistingcommand";
// 	res = ft_get_env(cmd);
// 	if (res != NULL)
// 	{
// 		printf("%s\n", res);
// 	}
// 	else
// 		printf("NULL\n");
// 	return (0);
// }
