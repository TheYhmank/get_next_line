/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:20:21 by ayermeko          #+#    #+#             */
/*   Updated: 2023/11/17 17:53:52 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_to_left_str(int fd, char *backup)
{
    int bytes;
    char *buff;
    
    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    bytes = 1;
    while (!ft_find_newline(buff, '\n') && bytes != '\0')
    {
        bytes = read(fd, buff, BUFFER_SIZE);
        if (bytes == -1)
        {
            free(buff);
            return (NULL);
        }
        buff[bytes] = '\0';
        backup = ft_strjoin(backup, buff);
    }
    free(buff);
    return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = ft_read_to_left_str(fd, backup);
	if (!backup)
		return (NULL);
	line = ft_get_line(backup);
	backup = ft_new_backup(backup);
	return (line);
}

