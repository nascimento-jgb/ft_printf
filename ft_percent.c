/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaonascimento <joaonascimento@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:58:40 by joaonascime       #+#    #+#             */
/*   Updated: 2022/11/14 18:37:35 by joaonascime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_percent_array(t_option opt, int lenght)
{
	char	*str;
	char	c;

	c = '%';
	if (!opt.flag_minus && !opt.flag_zero)
		str = ft_left_blank(opt, lenght, &c);
	else if (!opt.flag_minus && opt.flag_zero)
		str = ft_left_zero(lenght, &c);
	else
		str = ft_right_zero(lenght, &c);
	return (str);
}

int	ft_percent_type(t_option opt)
{
	char *str;
	int lenght;

	lenght = 0;
	if (opt.width == 0)
	{
		write(1, '%', 1);
		g_tcount += 1;
	}
	else
	{
		lenght += opt.width;
		str = ft_percent_array(opt, lenght);
		if(!str)
			return (0);
		ft_putstr(str, ft_strlen(str), opt); // funtion to print string
	}
	return (1);
}
