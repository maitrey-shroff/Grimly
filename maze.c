/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 02:46:00 by bbixby            #+#    #+#             */
/*   Updated: 2018/10/23 02:46:01 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"
#include "grimly.h"

int     ft_shortestPath(t_maze **pz)
{
    int     i;
    char    **dup;

    i = -1;
    if (!((*pz)->exits = (int **)malloc(sizeof(int **) * (*pz)->exCount)))
        return (0);
    while (++i < (*pz)->exCount)
        if (!((*pz)->exits[i] = (int *)malloc(sizeof(int *) * 2)))
            return (0);
    dup = ft_duplicateMaze(pz, dup);
    ft_printDup(dup, (*pz)->rows);
    return (0);
}

char    **ft_duplicateMaze(t_maze **pz, char **dup)
{
    int i;
    int j;
    int k;

	i = -1;
    k = -1;
	if (!(dup = (char **)malloc(sizeof(char *) * ((*pz)->rows + 1))))
        return (NULL);
	while (++i < ((*pz)->rows))
		if (!(dup[i] = (char *)malloc(sizeof(char) * ((*pz)->cols + 2))))
            return (NULL);
    dup[i] = NULL;
    i = -1;
    while (++i < (*pz)->cols)
    {
        j = -1;
        while (++j < (*pz)->cols + 2)
        {
            dup[i][j] = (*pz)->body[i][j];
            if (dup[i][j] == (*pz)->header[4])
            {
                (*pz)->exits[++k][0] = i;
                (*pz)->exits[k][1] = j;
            }
        }
    }
    return (dup);
}

int     ft_printMaze(t_maze **pz)
{
    int i;

    i = -1;
    while (++i < (*pz)->cols)
        ft_putstr((*pz)->body[i]);
    return (0);
}

int     ft_printDup(char **dup, int rows)
{
    int i;

    i = -1;
    while (++i < rows)
        ft_putstr(dup[i]);
    return (0);
}