/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:37:19 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/15 13:51:16 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

int		ft_print_percent(void);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_nbr(int nbr);
int		ft_hex_len(unsigned int nbr);
void	ft_put_hex(unsigned int nbr, const char format);
int		ft_print_hex(unsigned int nbr, const char format);
int		ft_unsigned_len(unsigned int nbr);
char	*ft_unsigned_itoa(unsigned int nbr);
int		ft_print_unsigned(unsigned int nbr);
int		ft_ptr_len(uintptr_t ptr);
void	ft_put_ptr(uintptr_t ptr);
int		ft_print_ptr(unsigned long long ptr);

void		ft_putchar_fd(char c, int fd);
static int	len(long nb);
char		*ft_itoa(int n);

#endif
