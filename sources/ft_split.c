/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/16 09:59:12 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/04/22 07:12:30 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**ft_free_list(char **strlist)
{
	int	i;

	i = 0;
	while (strlist[i])
		free(strlist[i++]);
	free(strlist);
	return (NULL);
}

static int	ft_count_words(const char *str, char c)
{
	int	wordcount;
	int	delimiter;
	int	i;

	wordcount = 0;
	delimiter = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && delimiter == 1)
		{
			delimiter = 0;
			wordcount++;
		}
		else if (str[i] == c)
			delimiter = 1;
		i++;
	}
	return (wordcount);
}

static char	*ft_copy_word(const char *src, int n)
{
	int		i;
	char	*dest;

	if (n == 0)
		return (NULL);
	dest = (char *)malloc((n + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(const char *str, char c)
{
	char	**strlist;
	int		i;
	int		j;
	int		save;

	strlist = (char **)malloc((ft_count_words(str, c) + 1) * sizeof(char *));
	if (strlist == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_count_words(str, c) && str[j] != '\0')
	{
		while (str[j] == c)
			j++;
		save = j;
		while (str[j] != c && str[j] != '\0')
			j++;
		strlist[i] = ft_copy_word(&str[save], j - save);
		if (strlist[i] == 0)
			return (ft_free_list(strlist));
		i++;
	}
	strlist[i] = NULL;
	return (strlist);
}
