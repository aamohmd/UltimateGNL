/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamohame <aamohame@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:34:26 by aamohame          #+#    #+#             */
/*   Updated: 2024/01/17 10:46:02 by aamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int		is_there(char *str, char c);
char	*ft_strdup(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char *s, size_t start, size_t len);
char	*ft_strdup(char *str);
char	*static_new_line(char **remainder);
char	*new_line(char *line, char *buffer);
char	*process_buffer(char *buffer, char **remainder);
char	*get_next_line(int fd);

#endif
