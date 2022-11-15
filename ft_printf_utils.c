/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:45:23 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/15 13:57:01 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(void)
{
	return (write(1, "%", 1));
}

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	i;

	if (str == NULL)
	{
		write (1, "NULL", 6);
		return (6);
	}
	i = 0;
	while (str != '\0')
	{
		ft_print_char(str[i]);
		i++;
		str++;
	}
	return (i);
}

int	ft_print_nbr(int nbr)
{
	char	*aux;
	int		len;

	len = 0;
	aux = ft_itoa(nbr);
	len = ft_print_str(aux);
	free(aux);
	return (len);
}
