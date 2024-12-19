/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:43:22 by lfiorell          #+#    #+#             */
/*   Updated: 2024/12/12 16:35:23 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/export/libft.h"
#include <stddef.h>
#include <unistd.h>

#ifdef _WIN32
# define PATH_SEPARATOR ';'
# define DIR_SEPARATOR "\\"
#else
# define PATH_SEPARATOR ':'
# define DIR_SEPARATOR "/"
#endif

int	ft_strends(const char *str, const char *suffix)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = ft_strlen(suffix) - 1;
	if (!str)
		return (0);
	while (j >= 0)
		if (suffix[j--] != str[i--])
			return (0);
	return (1);
}

static char	*ft_strfindstart(char *const *arr, const char *prefix)
{
	int	i;

	i = 0;
	if (!arr || !prefix)
		return (NULL);
	while (arr[i])
	{
		if (ft_strncmp(arr[i], prefix, ft_strlen(prefix)) == 0)
			return (ft_strdup(arr[i]));
		i++;
	}
	return (NULL);
}

static char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	free(s1);
	return (new);
}

static int	ft_file_exists(const char *filename)
{
	int	fd;

	fd = access(filename, F_OK);
	if (fd == 0)
		return (1);
	return (0);
}

char	*ft_pathfind(char const *name, char *const *env)
{
	char	*path;
	char	**pathv;

	if (!name || !env)
		return (NULL);
	path = ft_strfindstart(env, "PATH=");
	if (!path)
		return (NULL);
	pathv = ft_split(&path[4], PATH_SEPARATOR);
	if (!pathv)
		return (NULL);
	free(path);
	while (*pathv)
	{
		if (ft_strends(*pathv, DIR_SEPARATOR))
			path = ft_strjoin(*pathv, name);
		else
			path = ft_strjoin_free(ft_strjoin(*pathv, DIR_SEPARATOR), name);
		if (ft_file_exists(path) == 1)
			return (path);
		free(path);
		pathv++;
	}
	return (NULL);
}
