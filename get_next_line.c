/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:20:21 by ayermeko          #+#    #+#             */
/*   Updated: 2023/11/16 23:28:08 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_line(t_list list)
{
    int str_len;
    char *next_str;

    if (!list)
        return (NULL);
    str_len = len_to_newline(list);
    next_str = malloc(str_len + 1);
    if (!next_str)
        return (NULL);
    copy_str(kustm next_str);
    return (next_str);
}

void append_node(t_list *list, char *buf)
{
    t_list *last_node;
    t_list *new_node;

    new_node = malloc(sizeof(t_list));
    last_node = find_lastnode(*list);
    if (!new_node)
        return ;
    if (!last_node)
        *last_node = new_node;
    else
        last_node->next = new_node;
    new_node->str_buf = buf;
    new_node->next = NULL;
}

void create_list(t_list **list, int fd)
{
    char *buffer;
    int char_num;

    while (!find_nextline(*list))
    {
        buffer = malloc(BUFFER_SIZE + 1);
        if (!buffer)
            return ;
        char_num = read(fd, buffer, BUFFER_SIZE);
        if (!char_num)
            return ;
        buffer[char_num] = '\0';
        append_node(list, buffer);
    }
}

char *get_next_line(int fd)
{
    static t_list *list = NULL;
    char *new_line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, new_line, 0) < 0)
        return (NULL);
    create_list(&list, fd);
    if (list == NULL)
        return (NULL);
    new_line = get_line(list);

    return (new_line);
}

