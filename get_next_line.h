/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:20:38 by chaidel           #+#    #+#             */
/*   Updated: 2021/11/30 18:14:30 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> /* A RETIRER */
# include <stdio.h> /* A RETIRER */
# define BUFFER_SIZE 42

typedef struct s_line {
	size_t	count;
	char	line[BUFFER_SIZE + 1];
	char	*rest;
}	t_line;

char	*get_next_line(int fd);
void	ft_read_line(int fd, t_line ld);
#endif
