
#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define DEFAULT_DICT_FILE "dictionary/numbers.dict"

int	chk_number(char *num, char *line);
void	ft_charcat(char *dest, char c);
int	it_is_alpha(char c);
void	ft_putline(char *line);

#endif
