/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamohame <aamohame@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:44:23 by aamohame          #+#    #+#             */
/*   Updated: 2024/02/11 10:51:55 by aamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12

# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct variables
{
	char		*buffer;
	char		*line;
	ssize_t		bytes_read;
}				t_va;

size_t		ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
int			ft_reader(int fd, char **buffer);
int			is_there(char *str, char c);
char		*ft_substr(char *s, size_t start, size_t len, int free_s);
char		*ft_strdup(char *str);
void		line(char **remainder, char **line);
char		*get_next_line(int fd);

#endif
