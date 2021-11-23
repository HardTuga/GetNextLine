/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:09:59 by pcampos-          #+#    #+#             */
/*   Updated: 2021/11/09 16:14:50 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (str)
	{
		i = 0;
		if (str[i] == (char)c)
			return ((char *)str);
		while (str[i++])
			if (str[i] == (char)c)
				return ((char *)str + i);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = malloc(sizeof(char *) * (len1 + len2 + 1));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s1, len1);
	ft_memcpy(new + len1, s2, len2);
	new[len1 + len2] = '\0';
	return (new);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (0);
	d = dest;
	s = src;
	while (n-- > 0)
		*d++ = *s++;
	return (dest);
}

int	ft_strlen(const char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*new;
	int		len;
	int		i;

	if (str)
	{
		i = 0;
		len = ft_strlen(str);
		if (!len)
			return (NULL);
		new = malloc(sizeof(char *) * (len + 1));
		if (new == NULL)
			return (NULL);
		while (str[i])
		{
			new[i] = str[i];
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
