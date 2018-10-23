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


t_puzzle    *create_puzzle(void)
{
    t_puzzle    *pz;

    pz = malloc(sizeof(t_puzzle));
    return (pz);
}

/*
**  TO DO:
*/
int     ft_verify(char *str, int counter, int i, int line_n)
{
    t_puzzle    *pz;

    pz = create_puzzle();
    if (!str)
        return (0);
    str = setheader(&pz, str, &counter);
    while (str[i])
    {
        if (str[i] == '\n')
        {
            line_n++;
            if ((pz)->rows != line_n - 1)
                return (showerror());
            i = -1;
        }
        i++;
        counter++;
    }
    return (0);
}