/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:20:11 by ayermeko          #+#    #+#             */
/*   Updated: 2023/11/17 18:30:28 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *s)
{
    size_t i;
    
    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

char *ft_strjoin(char *backup, char *buff)
{
	size_t i;
	size_t j;
	char *str;
	
    if (!backup)
    {
        backup = (char *)malloc(1 * sizeof(char));
        backup[i] = "\0";
    }
	if (!backup || !buff)
        return (NULL);
    
	
}