/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:37:26 by mboughra          #+#    #+#             */
/*   Updated: 2024/03/04 16:45:21 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define FLOOR "./textures/floor.xpm"
# define WALL "./textures/wall.xpm"
# define PLAYER "./textures/player.xpm"
# define COL "./textures/collect.xpm"
# define END "./textures/end.xpm"

# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>

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
	int		co_count;
	int		*colx;
	int		*coly;
	int		moves;
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*floor;
	void	*wall;
	void	*col;
	void	*end;
}	t_struct;

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
int			window(t_struct data);
size_t		ft_strlen(char *str);
size_t		ft_strlcpy(char	*dst, char	*src, size_t	dstsize);
t_struct	shapecheck(t_struct data);
t_struct	mapreader(t_struct data);
t_struct	bigcheckfunc(t_struct data);
t_struct	doublenewcheck(t_struct data);
t_struct	findposition(t_struct data);
t_struct	pathcheck(t_struct data);
t_struct	newmapallocater(t_struct data);
t_struct	ffcheck(t_struct data);
t_struct	datafiller(t_struct data);
void		mapinit(t_struct data);
void		collectinit(t_struct data);
int			click(int keycode, void *param);
t_struct	collectioncount(t_struct data);
void		end(t_struct *data);
t_struct	*move_right(t_struct *data);
t_struct	*move_left(t_struct *data);
t_struct	*move_up(t_struct *data);
t_struct	*move_down(t_struct *data);
t_struct	allmlxinit(t_struct data);
int			ft_printf(const char *str, ...);
int			ft_putchar(char c);
int			ft_putnbr(long n);
int			ft_putnbr2(long n);
int			ft_putstr(char *s);
int			ft_hexaconv(unsigned int a, char c);
int			ft_hexapointer(unsigned long a);
#endif