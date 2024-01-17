/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamohame <aamohame@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:16:07 by aamohame          #+#    #+#             */
/*   Updated: 2024/01/17 12:12:57 by aamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int		fd = open("text.txt", O_RDWR | O_CREAT, 0777);
    lseek(fd, 0, SEEK_SET);
    char	*str = get_next_line(fd);
    printf("%s", str);
    free(str);
}