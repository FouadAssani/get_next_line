/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:16:38 by fassani           #+#    #+#             */
/*   Updated: 2020/02/05 15:29:14 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	if (!(str = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char *) + 1)))
		return (0);
	while (s1[i] != 0)
	{
		str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != 0)
	{
		str[j++] = s2[i++];
	}
	str[j] = 0;
	return (str);
}

int		set_line(char **line, char **static_storage)
{
	int		size;
	char	*tmp;

	free(*line);
	if (ft_strchr(*static_storage, '\n') != 0)
	{
		size = ft_strchr(*static_storage, '\n') - *static_storage;
		*line = ft_substr(*static_storage, 0, size);
		tmp = ft_strdup(ft_strchr(*static_storage, '\n') + 1);
		free(*static_storage);
		*static_storage = tmp;
		return (1);
	}
	*line = ft_strdup(*static_storage);
	free(*static_storage);
	*static_storage = 0;
	return (0);
}

int		read_file(const int fd, char *str, char **line, char **static_storage)
{
	char	*tmp;
	int		size;
	int		index_file;

	while ((index_file = read(fd, str, BUFFER_SIZE)))
	{
		if (index_file == -1)
			return (index_file);
		str[index_file] = 0;
		tmp = *line;
		*line = ft_strjoin(tmp, str);
		free(tmp);
		if (ft_strchr(*line, '\n'))
		{
			size = ft_strchr(*line, '\n') - *line;
			*static_storage = ft_strdup(ft_strchr(*line, '\n') + 1);
			tmp = ft_strdup(*line);
			free(*line);
			*line = ft_substr(tmp, 0, size);
			free(tmp);
			break ;
		}
	}
	return (index_file);
}

int		get_next_line(int fd, char **line)
{
	int			index_file;
	static char	*static_storage = 0;
	char		*str;

	if (line == 0 || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!(*line = newline(BUFFER_SIZE)))
		return (-1);
	if (static_storage != 0)
		if (set_line(line, &static_storage))
			return (1);
	if (!(str = newline(BUFFER_SIZE)))
		return (-1);
	if ((index_file = read_file(fd, str, line, &static_storage)) == -1)
		return (-1);
	free(str);
	if (index_file == 0 || (index_file == 0 && ft_strlen(*line) == 0))
		return (0);
	return (1);
}
