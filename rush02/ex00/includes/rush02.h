/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:46:13 by teom              #+#    #+#             */
/*   Updated: 2020/12/06 20:50:02 by teom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

void			print_error(void);
int				var_check(char *var);
void			rush02_with_space(char *str);
void			print_init(char *hund);
void			ft_charcat_3(char *hund, char *ten, char *one, char *str);
void			rush02(char *argv);
unsigned int	find_max_num(char *dict, unsigned int max_size);
char			*dict_path(char *argv);
void			print_thou(char *str);
int				chk_number(char *num, char *line);
void			ft_charcat(char *dest, char c);
void			ft_strcat(char *dest, char *src);
unsigned int	ft_strlen(char *str);
int				it_is_alpha(char c);
void			ft_putline(char *line);
void			print_hund(char *str, int size);

#endif
