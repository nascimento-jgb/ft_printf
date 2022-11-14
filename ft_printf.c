/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaonascimento <joaonascimento@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:05:10 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/14 18:37:40 by joaonascime      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_tcount;

void	ft_initialize(t_option *opt)
{
	opt->flag_minus = 0;
	opt->flag_zero = 0;
	opt->width = 0;
	opt->dot= 0; //to check precision
	opt->precision = -1; //set as -1 instead of 0
	opt->flag_pre_var = 0; //if precision is a variable argument
	opt->neg_num = 0; //is a negative number?
	opt->type = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	g_tcount = 0;
	va_start(args, format);
	while (*format)
	{
		if(format != '%')
		{
			write(1, format, 1);
			g_tcount++;
		}
		else
		{
			format = ft_format(format + 1, args);
			if(!format)
				return (-1);
		}
		++format;
	}
	va_end(args);
	return(g_tcount);
}


/*
int	check_args(va_list args, char arg)
{
	int	number;

	number = 0;
	if (arg == 'c')
		number += ft_putchr(va_arg(args, char));
	if (arg == 's')
		number += ft_putstr(va_arg(args, char *));
	if (arg == 'd' || arg == 'i')
		number += ft_putnbr(va_arg(args, int));
	if (arg == 'p')
	{
		write(1, "0x", 2);
		number += print_ptr(va_arg(args, unsigned long long));
	}
	if (arg == 'u')
		number += print_unsign(va_arg(args, unsigned int));
	if (arg == 'x' || arg == 'X')
		number += hexa_case(va_arg(args, unsigned long long), arg);
	if (arg == '%')
		number += print_percentage();
	return (number);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_count;

	print_count = 0;
	va_start(args, format);
	while (*format)
	{
		if(format != '%')
			print_count += ft_putchar(format);
		else
		{
			print_count += check_args(args, format + 1);
			format++;
		}
		++format;
	}
	va_end(args);
	return (print_count);
}
*/
