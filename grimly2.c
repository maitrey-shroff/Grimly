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
/*
**  header[] = full, empty, path, enter, exit
*/
char        *ft_setheader(t_maze **pz, char *buf)
{
    int     i;
    int     j;
    char    *descrRow;

    i = -1;
    j = 1;
    while (buf[j] != '\n')
        j++;
    while (++i < 5)
        (*pz)->header[4 - i] = buf[j - i - 1];
    if (!(descrRow = (char *)malloc(sizeof(*descrRow) * (j + 1))))
        return (NULL);
    i = -1;
    while (++i <=  j)
        descrRow[i] = *buf++;
    descrRow[j] = '\0';
    (*pz)->rows = ft_atoi(descrRow);
    (*pz)->cols = ft_setcols(descrRow, j);
    (*pz)->exCount = 0;
    free(descrRow);
    printf("%s", buf);
    return (&*buf);
}

/*
**  returns cols for t_maze header
*/
int         ft_setcols(char *topline, int len)
{
    topline[len - 5] = '\0';
    while (*topline && *topline != 'x')
        topline++;
    return (!*topline ? (ft_showerror(NULL)) : (ft_atoi(&topline[1])));
}

/*
**  displays an error and returns 0 for invalid map
*/
int         ft_showerror(char *str)
{
    if (str)
        free(str);
    ft_putstr("MAP ERROR\n");
    return (0);
}