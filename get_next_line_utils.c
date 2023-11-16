/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:20:11 by ayermeko          #+#    #+#             */
/*   Updated: 2023/11/15 19:29:23 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list find_lastnode(t_list *list)
{
    if (!list)
        return (NULL);
    while (list->next)
        list = list->next;
    return (list);
}