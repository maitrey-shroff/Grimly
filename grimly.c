/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:27:26 by bbixby            #+#    #+#             */
/*   Updated: 2018/10/22 14:27:28 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"
#include "grimly.h"

/*
**  TO DO: check the map error line see if it's necessary
*/
char    *ft_readsdin(void)
{
    int     ret;
    char    *str;
    int     i;
    char    temp[1];

    if (!(str = (char *)malloc(sizeof(char) * 2000000001)))
        return (NULL);
    i = 0;
    while ((ret = read(0, temp, 1)))
        str[i++] = *temp;
    if (str[i - 1] != '\n')
    {
        ft_putstr("MAP ERROR\n");
        return (0);
    }
    str[i] = '\0';
    ft_putstr(str);
    return (str);
}

/*
** max labrynth size is a billion, but allocating 2 billion, map could be 1 billion rows and 
** need to account for new line charachters
** TO DO: efficiently read files, not 1 charachter at a time
*/
char    *ft_readfile(char *file)
{
    int     ret;
    char    *str;
    int     fd;

    if (!(str = (char *)malloc(sizeof(char) * 2000000001)))
        return (NULL);
    fd = open(file, O_RDONLY);
    while ((ret = read(fd, str, 2000000000)))
        str[ret] = '\0';
    ft_putstr(str);
    return (str);
}

/*
** ./gen 5 10 "* o12"
*/
int     main(int argc, char **argv)
{
    int i;
    int fd;

    i = 0;
    ft_putstr("hi\n");
    if (argc > 1)
    {
        while (++i > argc)
        {
            if (i > 1)
                ft_putchar('\n');
            fd = open(argv[i], O_RDONLY);
            fd < 0 ? (ft_putstr("MAP ERROR\n")) :
                (ft_verify(ft_readfile(argv[i]), 0, 0, 1));
            close(fd);
        }
    }
    else
        ft_verify(ft_readsdin(), 0, 0, 1);
    return (0);
}