/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:20:38 by chaidel           #+#    #+#             */
/*   Updated: 2021/12/01 16:54:15 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> /* A RETIRER */
# include <stdio.h> /* A RETIRER */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
typedef struct s_line {
	char	*rest;
}	t_line;

char	*get_next_line(int fd);
char	*ft_extract_line(int fd, t_line *ld);
size_t	ft_strlen(char const *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *dest, const char *src);
#endif

