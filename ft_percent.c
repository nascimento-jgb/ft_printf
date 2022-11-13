/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaonascimento <joaonascimento@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:58:40 by joaonascime       #+#    #+#             */
/*   Updated: 2022/11/13 17:17:39 by joaonascime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_percent_array(t_option opt, int lenght)
{

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
