#include "get_next_line.h"

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

void	static_new_line(char **remainder, char **line)
{
	int	i;

	i = is_there(*remainder, '\n');
	*line = ft_substr(*remainder, 0, i + 1, 0);
	*remainder = ft_substr(*remainder, i + 1, ft_strlen(*remainder), 1);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(remainder), remainder = NULL, NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	if (remainder == NULL)
		remainder = ft_strdup("");
	while (bytes_read > 0)
	{
		bytes_read = ft_reader(fd, &buffer);
		if (bytes_read < 0)
			return (free(buffer), free(remainder), remainder = NULL, NULL);
		remainder = ft_strjoin(remainder, buffer);
		if (remainder != NULL && is_there(remainder, '\n') > 0)
			return (static_new_line(&remainder, &line), free(buffer), line);
	}
	if (remainder != NULL && remainder[0] != '\0')
		return (line = remainder, free(remainder), free(buffer), line);
	return (free(buffer), free(remainder), remainder = NULL, NULL);
}
