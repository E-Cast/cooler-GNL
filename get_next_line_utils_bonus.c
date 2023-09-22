/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 07:37:42 by ecastong          #+#    #+#             */
/*   Updated: 2023/09/22 15:13:13 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	safe_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

char	*str_utils(char *str1, char *str2, char *dest)
{
	ssize_t	i;
	size_t	j;

	if (ft_strlen(str1) + ft_strlen(str2) == 0)
		return (NULL);
	if (!dest)
	{
		dest = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
		if (!dest)
		{
			safe_free(str1);
			return (NULL);
		}
	}
	i = 0;
	j = 0;
	while (str1 && str1[i])
		dest[i++] = str1[j++];
	j = 0;
	while (str2 && str2[j])
		dest[i++] = str2[j++];
	dest[i] = '\0';
	safe_free(str1);
	return (dest);
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

void	ft_bzero(void *str, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!str)
		return ;
	ptr = (char *)str;
	i = 0;
	while (i < len)
		ptr[i++] = 0;
}
