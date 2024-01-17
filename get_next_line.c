/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamohame <aamohame@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:32:33 by aamohame          #+#    #+#             */
/*   Updated: 2024/01/17 20:50:17 by aamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*static_new_line(char **remainder, char **line)
{
	int	i;

	i = is_there(*remainder, '\n');
	*line = ft_substr(*remainder, 0, i);
	*remainder = ft_substr(*remainder, i + 1, ft_strlen(*remainder) - i);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (remainder == NULL)
		remainder = ft_strdup("");
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (is_there(remainder, '\n') > 0)
		{
			static_new_line(&remainder, &line);
			return (line);
		}
	}
	free(buffer);
	if (bytes_read < 0 || remainder[0] == '\0')
	{
		if (remainder != NULL)
			free(remainder);
		return (NULL);
	}
	line = ft_strdup(remainder);
	free(remainder);
	remainder = NULL;
	return (line);
}
