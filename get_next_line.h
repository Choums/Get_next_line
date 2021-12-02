/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:20:38 by chaidel           #+#    #+#             */
/*   Updated: 2021/12/02 13:42:51 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> /* A RETIRER */
# include <stdio.h> /* A RETIRER */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_extract(int fd, char *rest);
char	*ft_get_line(char *rest);
char	*ft_cut(char *rest);
size_t	ft_strlen(char const *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *rest, char const *brut);

#endif
