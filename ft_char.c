/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaonascimento <joaonascimento@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:12:14 by joaonascime       #+#    #+#             */
/*   Updated: 2022/11/14 18:37:29 by joaonascime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(char *str, int len, t_option opt)
{
	int		aux;
	char	c;

	aux = 0;
	if (opt.type == 'X')
	{
		while (str[aux])
		{
			ft_putchar(ft_toupper(str[aux++]));
			g_tcount++;
		}
	}
	else
	{
		while (aux < len)
		{
			ft_putchar(str[aux++]);
			g_tcount++;
		}
	}
	free(str);
}

char	*ft_arr_char(t_option opt, int len, char c)
{
	char *aux;

	if (!opt.flag_minus)
		aux = ft_left_blank((opt, len, &c));
	else
		aux = ft_right_blank((opt, len, &c))
	return (aux);
}

int	ft_char_type(t_option opt, va_list arg)
{
	char	*aux;
	char	c;
	int		len;

	c = va_arg(arg, char);
	if (opt.precision != -1)
		return (0);
	if (opt.flag_zero)
		return (0);
	if (opt.width == 0)
	{
		g_tcount++;
		write (1, &c, 1);
	}
	else
	{
		len += opt.width;
		if (!(aux = ft_arr_char(opt, len, c)))
			return (0);
		ft_printstr(aux, len, opt);
	}
	return (1);
}
