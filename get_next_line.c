/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:12:28 by chaidel           #+#    #+#             */
/*   Updated: 2021/11/30 17:27:56 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static 	t_line ld;

	if (fd == -1)
		return (NULL);
	ft_read_line(fd, ld);
	read(fd, ld.line, ld.count);
	printf("start : %zu\ncount : %zu\n", ld.start, ld.count);
	return (ld.line);
}

int main(void)
{
	int fd;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		printf("Error\n");
	printf("line : %s\n", get_next_line(fd));
	return (0);
}
