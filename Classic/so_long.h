/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:37:26 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/25 19:34:22 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_struct
{
	int		fd;
	int		len;
	int		lines;
	int		colums;
	char	*name;
	char	*map;
	char	**map2;
	char	**newmap;
	int		px;
	int		py;
}t_struct;

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include <stdio.h>
#include <math.h>


size_t		ft_strlen(char *str);
size_t		ft_strlcpy(char	*dst, char	*src, size_t	dstsize);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);
int			newcheck(char *str);
char		*ft_cutfront(char *line);
char		*ft_cutback(char *line);
char		*ft_strdup(char *s1);
t_struct	Bigcheckfunc(t_struct data);
void		namecheck(t_struct data);
int			opencheck(t_struct data);
void		window(void);
t_struct	mapreader(t_struct data);
char		**ft_split(char const *s, char c);
t_struct 	shapecheck(t_struct data);
void		numcheck(t_struct data);
int			firstandlast(char *str);
int			midlines(t_struct data);
void		iexit(t_struct data, int i);
int			diffkeyscheck(t_struct data);
// int linescheck(t_struct data);
t_struct 	doublenewcheck(t_struct data);
// t_struct	floodFill(t_struct data, int x, int y);
t_struct	findposition(t_struct data);
// t_struct ft_secondmap(t_struct data);
t_struct pathcheck(t_struct data);
t_struct newmapallocater(t_struct data);


#endif