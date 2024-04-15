/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamohame <aamohame@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:34:26 by aamohame          #+#    #+#             */
/*   Updated: 2024/04/15 10:04:45 by aamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

# include <unistd.h>
# include <stdlib.h>

size_t		ft_strlen_gnl(char *str);
char		*ft_strjoin_gnl(char *s1, char *s2);
int			ft_reader(int fd, char **buffer);
int			is_there(char *str, char c);
char		*ft_substr_gnl(char *s, size_t start, size_t len, int free_s);
char		*ft_strdup_gnl(char *str);
void		static_new_line(char **remainder, char **line);
char		*get_next_line(int fd);

#endif
