/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:12:28 by chaidel           #+#    #+#             */
/*   Updated: 2021/12/01 17:56:05 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(int fd, t_line *ld)
{
	size_t			len;
	char			brut[BUFFER_SIZE + 1];
	char			*line;

	len = 0;
	line = malloc(sizeof(char) * 1);
	while (!ft_strchr(brut, '\n'))
	{
		if (read(fd, brut, BUFFER_SIZE) <= 0)
			return (NULL);
		line = ft_strjoin(line, brut);
	}
	while (line[len] != '\n')
		len++;
	ld->rest = ft_substr(line, len + 1, ft_strlen(line) - len);
	line = ft_substr(line, 0, len);
	return (line);
}

char	*get_next_line(int fd)
{
	static 	t_line ld;
	size_t	i;
	char	*line;

	i = 0;
	if (fd == -1 || BUFFER_SIZE < 0 || !fd)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	if (ld.rest)
	{
		if (ft_strchr(ld.rest, '\n'))
		{
			while (ld.rest[i] != '\n')
				i++;
			line = ft_substr(ld.rest, 0, i);
			ld.rest = ft_substr(ld.rest, i + 1, ft_strlen(ld.rest) - i);
		}
		else
			line = ft_strjoin(ld.rest, ft_extract_line(fd, &ld));
	}
	else
	{
		line = ft_extract_line(fd, &ld);
		if (!line)
			return (NULL);
	}
	return (line);
}

/*int main(void)
{
	int fd;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		printf("Error\n");
	char *str = get_next_line(fd);
	printf("\nline finale : %s", str);
	printf("\n\n----------      --------\n\n");


	str = get_next_line(fd);
	printf("\nline finale : %s", str);
	printf("\n\n----------      --------\n\n");

	str = get_next_line(fd);
	printf("\nline finale : %s", str);
	printf("\n\n----------      --------\n\n");

	str = get_next_line(fd);
	printf("\nline finale : %s", str);
	printf("\n\n----------      --------\n\n");
	return (0);
}*/
