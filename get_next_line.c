/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nexchar *.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:12:28 by chaidel           #+#    #+#             */
/*   Updated: 2021/12/02 16:48:43 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract(int fd, char *rest)
{
	char	*brut;
	int		ret;

	ret = 1;
	brut = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!brut)
		return (NULL);
	while (!ft_strchr(brut, '\n') && ret)
	{
		ret = read(fd, brut, BUFFER_SIZE);
		if (ret == -1)
		{
			free(brut);
			return (NULL);
		}
		brut[ret] = '\0';
		rest = ft_strjoin(rest, brut);
		if (!rest)
		{
			free(brut);
			return (NULL);
		}
	}
	free(brut);
	return (rest);
}

char	*ft_get_line(char *rest)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!rest[len])
		return (NULL);
	while (rest[len] != '\n' && rest[len])
		len++;
	if (rest[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = rest[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_cut(char *rest)
{
	size_t	pos;
	size_t	i;
	char	*cut;

	i = 0;
	pos = 0;
	while (rest[pos] != '\n' && rest[pos])
		pos++;
	if (!rest)
	{
		free(rest);
		return (NULL);
	}
	pos++;
	cut = (char *)malloc(sizeof(char) * (ft_strlen(rest) - pos + 1));
	if (!rest)
		return (NULL);
	while (rest[pos])
	{
		cut[i] = rest[pos];
		i++;
		pos++;
	}
	cut[i] = '\0';
	free(rest);
	return (cut);
}

char	*get_next_line(int fd)
{
	static 	char	*rest;
	char			*line;

	if (fd <= 0 || BUFFER_SIZE < 1)
		return (NULL);
	rest = ft_extract(fd, rest);	
	if (!rest)
		return (NULL);
	line = ft_get_line(rest);
	if (!line)
		return (NULL);
	rest = ft_cut(rest);
	return (line);
}
/*
int main(void)
{
	int fd;

	fd = open("file.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("final line : |%s|", str);	
	return (0);
}*/
