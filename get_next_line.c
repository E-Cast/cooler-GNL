/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 07:38:00 by ecastong          #+#    #+#             */
/*   Updated: 2023/09/22 07:49:12 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*sanitize_line(char *stash, char *line)
{
	// clean up line to be returned and put leftovers into stash
}

static char	*fill_line(int fd, char *line)
{
	// allocate enough space into line to fit line + buffer_size
	// read into "line" until it either contains a '\n' or read returns 0
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;

	// call fill_line to make a line
	// if return value indicates end of file and no line to return, return NULL
	// else call sanitize_line

	return (line);
}
