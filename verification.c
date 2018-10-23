/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:58:46 by bbixby            #+#    #+#             */
/*   Updated: 2018/10/22 14:58:48 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"
#include "grimly.h"

/*
**  TO DO:
*/
void		ft_mallocbody(t_maze **pz)
{
	int i;

	i = -1;
	if (!((*pz)->body = (char **)malloc(sizeof(char *) * ((*pz)->rows + 1))))
        return ;
	while (++i < ((*pz)->rows))
		if (!((*pz)->body[i] = (char *)malloc(sizeof(char) * ((*pz)->cols + 2))))
            return ;
    (*pz)->body[i] = NULL;
}

/*
**  TO DO:
*/
t_maze    *ft_createMaze(void)
{
    t_maze    *pz;

    if (!(pz = (t_maze *)malloc(sizeof(*pz))))
        return (NULL);
    return (pz);
}

/*
** only chars in first line, '\n' &end of each line, row * col <= billion, exits >= 1, entrances = 1, rows and cols adhere to first line.
** trc is total, row and col
** TO DO: creat function to free and make sure if you return error midway through you still free everything
*/
int     ft_verify(char *str, int *trc, int entCount)
{
    t_maze    *pz;
    char        *str2;

    if (!str)
        return (0);
    pz = ft_createMaze();
    str2 = ft_setheader(&pz, str);
    ft_mallocbody(&pz);
    while (str2[++trc[1]])
    {
        pz->body[trc[2]][trc[0]] = (str2[trc[1]] == pz->header[2] ? (pz->header[1]) : (str2[trc[1]]));
        if (pz->body[trc[2]][trc[0]] == pz->header[3])
        {
            pz->entr[0] = (int)trc[2];
            pz->entr[1] = (int)trc[0];
            entCount++;
        }
        else if (pz->body[trc[2]][trc[0]] == pz->header[4])
            pz->exCount++;
        else if (str2[trc[1]] == '\n')
        {
            if (trc[0] != (pz)->cols || entCount > 1)
                return (ft_showerror(str));
            pz->body[trc[2]][trc[0] + 1] = '\0';
            trc[0] = -1;
            trc[2]++;
        }
        else if (pz->body[trc[2]][trc[0]] != pz->header[0] && pz->body[trc[2]][trc[0]] != pz->header[1])
            return (ft_showerror(str));
        trc[0]++;
    }
    free(str);
    return ((trc[2] != pz->rows || !pz->exCount || entCount != 1 || pz->rows * pz->cols > 1000000000) ? (ft_showerror(NULL)) : (ft_shortestPath(&pz)));
}
