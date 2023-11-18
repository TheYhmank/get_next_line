/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:35:57 by ayermeko          #+#    #+#             */
/*   Updated: 2023/11/18 16:47:02 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

char	*get_next_line(int fd);
char	*ft_read_append(int fd, char *backup);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *backup, char *buff);
char	*ft_get_line(char *backup);
char	*ft_new_backup(char *backup);

#endif