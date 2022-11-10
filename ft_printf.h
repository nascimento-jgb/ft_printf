/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:13:06 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/10 17:45:58 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

typedef struct	s_option
{
	int	flag_minus;
	int	flag_zero;
	int	width;
	int	dot; //precison antecedent
	int	precision; //initially set as -1/update to 1
	int	flag_pre_var; //if precision is a variable argument
	int	neg_num; //negative number
	char	type;
}	t_option;

int	ft_printf(const char *, ...);

#endif