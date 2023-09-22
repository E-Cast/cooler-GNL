/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 07:38:00 by ecastong          #+#    #+#             */
/*   Updated: 2023/09/22 11:16:47 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (!ft_strchr(line, '\n'))
	{
		if (!stash[0])
		{
			if (read(fd, stash, BUFFER_SIZE) == 0)
				return (line);
		}
		else
		{
			line = str_utils(line, stash, NULL);
			if (line == NULL)
				return (NULL);
			ft_bzero(stash, BUFFER_SIZE);
		}
	}
	str_utils(NULL, &line[ft_strchr(line, '\n') - line + 1], stash);
	line[ft_strchr(line, '\n') - line + 1] = '\0';
	return (str_utils(line, NULL, NULL));
}
