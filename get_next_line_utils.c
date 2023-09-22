/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 07:37:42 by ecastong          #+#    #+#             */
/*   Updated: 2023/09/22 08:39:47 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	p_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

char	*ft_strchr(const char *str, int chr)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)chr)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)chr)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;

	if (!src)
		return (NULL);
	dest = (char *)malloc(ft_strlen(src) + 1);
	if (!dest)
		return (p_free((void *)src), NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
