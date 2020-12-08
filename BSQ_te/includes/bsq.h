#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define ERR_MSG "Map Error\n"

void			ft_putstr(char *str);
void			ft_putchar(char c);
unsigned int	count_col(char *symbol);
unsigned int	get_size(int fd);
unsigned int	count_row(char *map);
unsigned int	get_sym_size(char *argv);
unsigned int	ft_strlen(char *str);
void			disp_map(char **map, unsigned int col);
void			ft_charcat(char *str, char c);
void			bsq(char *argv);
void			get_map(char **map, int fd);
void			find_square();
void			read_map(int fd, char **map);
void			ft_strcat(char *dest, char *src);
void			ft_strcpy(char *dest, char *src);

#endif
