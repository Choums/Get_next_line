/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:47:18 by chaidel           #+#    #+#             */
/*   Updated: 2021/11/30 17:35:13 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read_line(int fd, t_line ld)
{
	char *c;
	int ret;

	ld.start += ld.count;
	while (read(fd, c, 1))
	{
		ld.count++;
	}
}
