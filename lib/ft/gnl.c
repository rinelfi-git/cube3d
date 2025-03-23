/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:32:49 by tramanan          #+#    #+#             */
/*   Updated: 2025/03/22 17:36:19 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "libft.h"

char	*the_next_line(char *s1, char *s2)
{
	char	*dest;

	if (s1 == NULL)
		dest = ft_strdup(s2);
	else
		dest = ft_strjoin(s1, s2);
	return (free(s1), s1 = NULL, dest);
}

char	*get_next_line(int fd)
{
	char			*buff;
	char			*next_line;
	static char		rest[BUFFER_SIZE];
	int				bytes;

	bytes = 0;
	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_calloc(1, BUFFER_SIZE + 1);
	if (rest[0] != '\0')
	{
		next_line = the_next_line(next_line, rest);
		takerest(rest, rest);
	}
	while (bytes >= 0 && !ft_strchr(next_line, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if ((bytes < 0 || buff[0] == '\0') || (rest[0] == '\0' && bytes == 0))
			return (free(buff), buff = NULL, next_line);
		buff[bytes] = '\0';
		next_line = the_next_line(next_line, buff);
		takerest(buff, rest);
	}
	return (free(buff), buff = NULL, next_line);
}
