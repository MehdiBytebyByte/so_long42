/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:37:26 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/28 15:57:35 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include <stdio.h>
#include <math.h>

typedef struct	s_mlx {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_mlx;

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

void		freemap(t_struct data);
void		namecheck(t_struct data);
void		cleaner(t_struct data);
void		numcheck(t_struct data);
void		iexit(t_struct data, int i);
char		*get_next_line(int fd);
char		*ft_cutfront(char *line);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_cutback(char *line);
char		**ft_split(char const *s, char c);
char		*ft_strdup(char *s1);
int			firstandlast(char *str);
int			midlines(t_struct data);
int			newcheck(char *str);
int			opencheck(t_struct data);
int			diffkeyscheck(t_struct data);
int 		window(t_struct data);
size_t		ft_strlen(char *str);
size_t		ft_strlcpy(char	*dst, char	*src, size_t	dstsize);
t_struct 	shapecheck(t_struct data);
t_struct	mapreader(t_struct data);
t_struct	Bigcheckfunc(t_struct data);
t_struct 	doublenewcheck(t_struct data);
t_struct	findposition(t_struct data);
t_struct 	pathcheck(t_struct data);
t_struct 	newmapallocater(t_struct data);
t_struct 	FFcheck(t_struct data);
t_struct 	isetonull(t_struct data);
t_struct 	Datafiller(t_struct data);
#endif