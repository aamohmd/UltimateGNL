#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3

# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_reader(int fd, char **buffer);
int		is_there(char *str, char c);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char *s, size_t start, size_t len, int free_s);
char	*ft_strdup(char *str);
void	static_new_line(char **remainder, char **line);
char	*get_next_line(int fd);

#endif
