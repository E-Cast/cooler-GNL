/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 07:38:00 by ecastong          #+#    #+#             */
/*   Updated: 2023/09/22 19:01:59 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	read_fd(int fd, char *stash, char **line)
{
	int	b_read;

	b_read = 1;
	if (!stash[0])
	{
		b_read = read(fd, stash, BUFFER_SIZE);
		if (b_read == 0)
			return (0);
		if (b_read == -1)
		{
			safe_free(*line);
			return (-1);
		}
	}
	else
	{
		*line = str_utils(*line, stash, NULL);
		if (*line == NULL)
			return (-1);
		ft_bzero(stash, BUFFER_SIZE);
	}
	return (b_read);
}

char	*get_next_line(int fd)
{
	static char	stash[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			errcode;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	line = NULL;
	while (!ft_strchr(line, '\n'))
	{
		errcode = read_fd(fd, stash[fd], &line);
		if (errcode == 0)
			return (line);
		if (errcode == -1)
			return (NULL);
	}
	str_utils(NULL, &line[ft_strchr(line, '\n') - line + 1], stash[fd]);
	line[ft_strchr(line, '\n') - line + 1] = '\0';
	return (str_utils(line, NULL, NULL));
}
