/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:47:18 by chaidel           #+#    #+#             */
/*   Updated: 2021/12/02 12:12:14 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t  i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)(s));
		s++;
	}
	if (c == '\0')
		return ((char *)(s));
	return (NULL);
}

char    *ft_strjoin(char *rest, char const *brut)
{
	char	*one;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!brut)
		return (NULL);
	if (!rest)
	{
		rest = (char *)malloc(sizeof(char));
		if (!rest)
			return (NULL);
		rest[0] = '\0';
	}
	one = (char *)malloc(sizeof(char) * (ft_strlen(rest) + ft_strlen(brut) + 1));
	if (!one)
		return (NULL);
	if (rest)
		while (rest[i])
		{
			one[i] = rest[i];
			i++;
		}
	while (brut[j])
	{
		one[i] = brut[j];
		i++;
		j++;
	}
	one[i] = '\0';
	free(rest);
	return (one);
}
