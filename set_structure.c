/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaonascimento <joaonascimento@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:06:14 by joaonascime       #+#    #+#             */
/*   Updated: 2022/11/12 15:03:24 by joaonascime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_set_width(const char *start, t_option *opt, va_list args)
{
	const char *aux;

	aux = start;
	if (aux == '*')
	{
		opt->width = va_arg(args, int);
		if (opt->width < 0)
		{
			opt->width *= -1;
			opt->flag_minus = 1;
		}
	}
	else
	{
		while(*aux >= '0' && *aux <= '9')
		{
			opt->width *= 10;
			opt->width += *aux - '0';
			aux++;
		}
	}
	return (aux);
}

const char	*ft_set_precision(const char *start, t_option *opt, va_list args)
{
	const char	*pntr;
	int			aux;

	opt->dot = 1;
	aux = 0;
	pntr = start + 1;
	if (*pntr == '*')
	{
		opt->precision = va_arg(args, int);
		if(opt->precision < 0)
			opt->flag_pre_var = 1;
		pntr++;
	}
	else
	{
		while((*pntr >= '0' && *pntr <= '9') && (opt->type != '%' && opt->type != 'c'))
		{
			aux *= 10;
			aux += *pntr - '0';
			pntr++;
			opt->precision = aux;
		}
	}
	return (pntr);
}

char	 ft_check_type(char c)
{
	char *str;

	str = TYPE;
	while (*str)
	{
		if (c == str)
			return c;
		str++;
	}
	return (0);
}

int	ft_apply_type(t_option opt, va_list args)
{
	char	aux;
	int 	i;

	aux = opt.type;
	i = 0;
	if (aux == '%')
		i = ft_percent_type(opt, args);
	else if (aux == 'c')
		i = ft_char_type(opt, args);
	else if (aux == 's')
		i = ft_string_type(opt, args);
	else if (aux == 'p')
		i = ft_pointer_type(opt, args);
	else
		i = ft_number_type(opt, args);
	return (i);
}

static char	set_format(const char *pntr, va_list args)
{
	const char *start;
	t_option opt;

	start = pntr;
	ft_initialize(&opt);
	while (pntr == '-' || pntr == '0')
	{
		if (pntr == '-')
			opt.flag_minus = 1;
		else
			opt.flag_zero = 1;
		pntr++;
	}
	start = ft_set_width(start, &opt, args);
	if (*start == '.')
		start = ft_set_precision(start, &opt, args);
	//ft_has_type(*start);
	if (!ft_check_type(*start))
		return (NULL);
	opt.type = *start;
	//ft_apply_type(opt, args);
	if (!ft_apply_type(opt,args))
		return (NULL);
	return (start);
}
