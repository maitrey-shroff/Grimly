/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:26:01 by bbixby            #+#    #+#             */
/*   Updated: 2018/10/22 14:26:04 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GRIMLY_H
# define GRIMLY_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct      s_maze
{
    int             rows;
    int             cols;
    char            header[5];
    char            **body;
    int             entr[2];
    int             **exits;
    int             exCount;
}                   t_maze;

// grimly
char                *ft_readsdin(void);
char                *ft_readfile(char *file);

// grimly2
char                *ft_setheader(t_maze **pz, char *buf);
int                 ft_showerror(char *str);
int                 ft_setcols(char *topline, int len);

// verify
int                 ft_verify(char *str, int *trc, int entCount);
t_maze              *ft_createMaze(void);
void		        ft_mallocbody(t_maze **pz);

// maze
int                 ft_shortestPath(t_maze **pz);
int                 ft_printMaze(t_maze **pz);
int                 ft_printDup(char **dup, int rows);
char                **ft_duplicateMaze(t_maze **pz, char **dup);

#endif
