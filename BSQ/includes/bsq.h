#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define ERR_MSG "Map Error"

void			ft_putstr(char *str);
void			ft_putchar(char c);
unsigned int	count_col(char *symbol);
unsigned int	get_size(int fd);
unsigned int	count_row(char *map);
unsigned int	get_sym_size(char *argv);
void			disp_map(char **map, unsigned int col);
void			ft_charcat(char *str, char c);
void			bsq(char *argv);
void			get_map(char **map, int fd);

#endif
