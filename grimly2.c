/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:12:24 by bbixby            #+#    #+#             */
/*   Updated: 2018/10/22 15:12:26 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"
#include "grimly.h"
#include <stdio.h>

/*
**  HEADER: full, empty, path, enter, exit
*/
char        *setheader(t_puzzle **pz, char *buf, int *counter)
{
    int     i;
    int     j;
    char    *rows;

    i = -1;
    j = 1;
    while (buf[j] != '\n')
        j++;
    while (++i < 5)
        (*pz)->header[4 - i] = buf[j - i - 1];
    if (!(rows = (char *)malloc(sizeof(*rows) * (j + 1))))
        return (NULL);
    i = -1;
    while (++i <=  j)
    {
        rows[i] = *buf++;
        (*counter)++;
    }
    rows[j] = '\0';
    (*pz)->rows = ft_atoi(rows);
    free(rows);
    return (buf);
}

int         showerror(void)
{
    ft_putstr("MAP ERROR\n");
    return (0);
}