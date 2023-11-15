/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:20:21 by ayermeko          #+#    #+#             */
/*   Updated: 2023/11/15 14:09:00 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void append_node(t_list **list, char *buffer)
{
    t_list *new_node;
    t_list *last_node;
    last_node = find_last_node();
    new_node = malloc(sizeof(*list));
    if (new_node)
        return (NULL);
    
}

void create_list(t_list **list, int fd)
{
    int char_read;
    char *buffer;

    while (!catch_newline(*list))
    {
        buffer = malloc(BUFFER_SIZE + 1);
        if (!buffer)
            return ;
        char_read = read(fd, buffer, BUFFER_SIZE);
        if (!char_read)
        {
            free(buf);
            return ;
        }
        buf[char_read] = '\0';
        append_node(list, buf); // append the node.
    }
}

char *get_next_line(int fd)
{
    char *next_line;
    static t_list *list = NULL;

    if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, &next_line, BUFFER_SIZE) < 0)
        return (NULL);
    create_list(&list, fd);
    if(list == NULL)
        return (NULL);
}

