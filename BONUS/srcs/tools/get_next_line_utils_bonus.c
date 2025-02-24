/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:26:59 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/24 08:11:28 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ca;
	int				i;

	i = 0;
	ca = (unsigned char )c;
	while (s[i])
	{
		if (s[i] == ca)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (s[i] == ca)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		lens;
	char		*destination;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	lens = ft_strlen(s1) + ft_strlen(s2);
	destination = (char *)malloc(lens + 1);
	if (!destination)
		return (NULL);
	while (s1[j])
		destination[i++] = s1[j++];
	j = 0;
	while (s2[j])
		destination[i++] = s2[j++];
	destination[i] = '\0';
	return (destination);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t			st_len;
	size_t			i;

	i = 0;
	st_len = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (st_len);
}

char	*ft_strdup(const char *s)
{
	char			*destination;
	unsigned int	s_len;
	unsigned int	i;

	i = 0;
	s_len = ft_strlen(s);
	destination = (char *)malloc(s_len + 1);
	if (!destination)
		return (NULL);
	while (i < s_len)
	{
		destination[i] = s[i];
		i++;
	}
	destination[s_len] = '\0';
	return (destination);
}
