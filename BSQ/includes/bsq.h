/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojpark <soojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 10:36:50 by soojpark          #+#    #+#             */
/*   Updated: 2020/12/09 22:26:26 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define ERR_MSG "map error\n"

void			ft_putstr(char *str);
void			ft_strcpy(char *dest, char *src);
unsigned int	ft_strlen(char *str);
int				count_col(char *symbol);
int				symbol_chk(char *symbol);
void			disp_map(char **map, int col);
void			find_square(void);
int				read_map(int fd, int temp);
void			free_map(int col);
void			size_check(int chk_size, int size);

#endif
