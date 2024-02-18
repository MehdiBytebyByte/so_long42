/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:13:27 by mboughra          #+#    #+#             */
/*   Updated: 2024/02/18 21:35:08 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_struct
{
	int fd;
	char *name;
	char *map;
	char **map2d;

}t_struct;

#include <stdlib.h>
#include <libc.h>


size_t		ft_strlen(char *str);
size_t		ft_strlcpy(char	*dst, char	*src, size_t	dstsize);
int			newcheck(char *str);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char	*s1, char	*s2);
char		*ft_cutback(char *line);
char		*ft_cutfront(char *line);
char		*get_next_line2(char **line, char **rem, char **buf, int fd);
char		*get_next_line(int fd);
t_struct	reader(t_struct data);
void		namecheck(t_struct data);
void		ft_exit(t_struct data, int i);
#endif