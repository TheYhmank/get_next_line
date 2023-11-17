/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:20:21 by ayermeko          #+#    #+#             */
/*   Updated: 2023/11/17 17:36:51 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_append(int fd, char backup)
{
    char *buff;
    int i;

    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    i = 1;
    while (!ft_strchr(backup, '\n') && i != 0)
    {
        i = read(fd, buff, BUFFER_SIZE);
        if (i == -1)
        {
            free(buff);
            return (NULL);
        }
        buff[i] = '\0';
        backup = ft_strjoin(backup, buff);
    }
    free(buff);
    return (backup);
}

char *get_next_line(int fd)
{
    char *line;
    static char *backup;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    backup = ft_read_append(fd, backup);
    if (!backup)
        return (NULL);
    line = ft_get_line(backup);
    backup = ft_new_left_str(backup);
	return (line);
}

