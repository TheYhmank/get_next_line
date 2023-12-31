/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:39:55 by ayermeko          #+#    #+#             */
/*   Updated: 2023/11/18 14:44:55 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_new_backup(char *backup);
char	*ft_get_line(char *backup);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *backup, char *buff);
char	*ft_strchr(char *s, int c);
char	*ft_read_append(int fd, char *backup);
char	*get_next_line(int fd);

#endif