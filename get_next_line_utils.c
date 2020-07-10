/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:17:03 by fassani           #+#    #+#             */
/*   Updated: 2020/02/05 14:57:45 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != (char)c)
	{
		i++;
	}
	if (!(char)c && s[i] == 0)
		return ((char *)&s[i]);
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		i;

	i = 0;
	if (!(tab = malloc(sizeof(*tab) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[i] != 0)
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;

	if (!s)
		return (0);
	if (!(str = malloc(len * sizeof(char) + 1)))
		return (0);
	i = 0;
	if (!(start > ft_strlen(s)))
	{
		while (i < len && s[start + i])
		{
			str[i] = s[start + i];
			i++;
		}
	}
	str[i] = 0;
	return (str);
}

char	*newline(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = 0;
	str = malloc(size * sizeof(char *) + 1);
	if (str == 0)
		return (0);
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	str[size] = 0;
	return (str);
}
