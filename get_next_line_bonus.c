/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamohame <aamohame@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:42:37 by aamohame          #+#    #+#             */
/*   Updated: 2024/02/11 11:20:03 by aamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char *s, size_t start, size_t len, int free_s)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
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
	if (free_s == 1)
		free(s);
	return (str);
}

int	ft_reader(int fd, char **buffer)
{
	int	bytes_read;

	bytes_read = read(fd, *buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (-1);
	(*buffer)[bytes_read] = '\0';
	return (bytes_read);
}

void	line(char **remainder, char **line)
{
	int	i;

	i = is_there(*remainder, '\n');
	*line = ft_substr(*remainder, 0, i + 1, 0);
	*remainder = ft_substr(*remainder, i + 1, ft_strlen(*remainder), 1);
}

char	*get_next_line(int fd)
{
	static char	*rem[OPEN_MAX];
	t_va		var;

	if (fd < 0)
		return (NULL);
	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (free(rem[fd]), rem[fd] = NULL, NULL);
	var.buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (var.buffer == NULL)
		return (NULL);
	var.bytes_read = 1;
	if (rem[fd] == NULL)
		rem[fd] = ft_strdup("");
	while (var.bytes_read > 0)
	{
		var.bytes_read = ft_reader(fd, &(var.buffer));
		if (var.bytes_read < 0 || rem[fd] == NULL)
			return (free(var.buffer), free(rem[fd]), rem[fd] = NULL, NULL);
		rem[fd] = ft_strjoin(rem[fd], var.buffer);
		if (rem[fd] != NULL && is_there(rem[fd], '\n') >= 0)
			return (line(&rem[fd], &(var.line)), free(var.buffer), var.line);
	}
	if (rem[fd] != NULL && rem[fd][0] != '\0')
		return (var.line = rem[fd], rem[fd] = NULL, free(var.buffer), var.line);
	return (free(var.buffer), free(rem[fd]), rem[fd] = NULL, NULL);
}
