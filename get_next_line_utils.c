/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:47:18 by chaidel           #+#    #+#             */
/*   Updated: 2021/12/16 05:23:14 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
	{
		i = ft_strlen(s);
		return ((char *)(s + i));
	}
	return (NULL);
}

char	*ft_strjoin(char *rest, char const *brut)
{
	char	*one;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!rest)
	{
		rest = (char *)malloc(sizeof(char));
		if (!rest)
			return (NULL);
		rest[0] = '\0';
	}
	if (!brut)
		return (NULL);
	one = malloc(sizeof(char) * (ft_strlen(rest) + ft_strlen(brut) + 1));
	if (!one)
		return (NULL);
	while (rest[++i])
		one[i] = rest[i];
	while (brut[j])
		one[i++] = brut[j++];
	one[i] = '\0';
	free(rest);
	return (one);
}
