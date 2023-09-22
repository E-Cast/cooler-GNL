/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 07:38:00 by ecastong          #+#    #+#             */
/*   Updated: 2023/09/22 08:38:54 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// clean up line for it to be returned and put leftovers into stash
static char	*sanitize_line(char *stash, char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (line[i] == '\0')
		return (p_free(line), NULL);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (ft_strdup(line));
	j = 0;
	while (line[i] != '\0')
	{
		stash[j++] = line[i];
		line[i++] = '\0';
	}
	return (ft_strdup(line));
}

// reads into line till it contains a '\n' or read reaches end of file
static char	*fill_line(int fd, char *line)
{
	char	*tmp;
	ssize_t	i;

	tmp = line;
	line = malloc((ft_strlen(line) + BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (p_free(tmp), NULL);
	i = 0;
	while (tmp && tmp[i] != '\0')
	{
		line[i] = tmp[i];
		i++;
	}
	p_free(tmp);
	i = read(fd, &line[i], BUFFER_SIZE);
	if (i == -1)
		return (NULL);
	if (i != 0 && ft_strchr(line, '\n') == NULL)
		fill_line(fd, line);
	return (line);
}

// puts all of stash into line
static char	*stash_to_line(char *stash, char *line)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	tmp = line;
	line = malloc((ft_strlen(line) + ft_strlen(stash) + 1) * sizeof(char));
	if (!line)
		return (p_free(tmp), NULL);
	i = 0;
	while (tmp && tmp[i] != '\0')
	{
		line[i] = tmp[i];
		i++;
	}
	p_free(tmp);
	j = 0;
	while (stash[j] != '\0')
	{
		line[i++] = stash[j];
		stash[j++] = '\0';
	}
	line[i] = stash[j];
	return (line);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (stash[0] != '\0')
		if (stash_to_line(stash, line) == NULL)
			return (NULL);
	if (ft_strchr(line, '\n') == NULL)
		if (fill_line(fd, line) == NULL)
			return (NULL);
	return (sanitize_line(stash, line));
}
