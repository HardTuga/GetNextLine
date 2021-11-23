/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:47:54 by pcampos-          #+#    #+#             */
/*   Updated: 2021/11/11 14:59:52 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_part(char **s, char *b, int l)
{
	char	*new;
	char	*tmp;
	int		sl;

	if (*s)
		sl = ft_strlen(*s);
	else
		sl = 0;
	new = malloc(sizeof(char) * (l + sl + 1));
	if (!new)
		return (NULL);
	ft_memcpy(new, *s, sl);
	ft_memcpy(new + sl, b, l);
	new[l + sl] = '\0';
	tmp = ft_strdup(b + l);
	if (*s)
		free(*s);
	*s = tmp;
	return (new);
}

static char	*get_line(char **s, char *b, int c)
{
	char	*tmp;
	char	*new;

	new = NULL;
	if (c <= 0)
	{
		if (c == 0 && *s && ft_strlen(*s) != 0)
		{
			new = (*s);
			(*s) = NULL;
		}
		return (new);
	}
	b[c] = '\0';
	tmp = ft_strchr(b, '\n');
	if (tmp)
		new = get_part(s, b, (tmp - b) + 1);
	else
	{
		tmp = ft_strjoin(*s, b);
		if (*s)
			free(*s);
		*s = tmp;
	}
	return (new);
}

static char	*get_storage(char **s, int l)
{
	char	*new;
	char	*tmp;
	int		i;

	new = malloc(sizeof(char) * (l + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < l)
	{
		new[i] = (*s)[i];
		i++;
	}
	new[i] = '\0';
	tmp = ft_strdup(*s + i);
	free(*s);
	(*s) = tmp;
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*line;
	int			check;

	check = 1;
	line = NULL;
	if (read(fd, 0, 0) == -1 || fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_strchr(storage, '\n');
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		while (line == NULL && check > 0)
		{
			check = read(fd, buffer, BUFFER_SIZE);
			line = get_line(&storage, buffer, check);
		}
		free(buffer);
	}
	else
		line = get_storage(&storage, (buffer - storage) + 1);
	return (line);
}
