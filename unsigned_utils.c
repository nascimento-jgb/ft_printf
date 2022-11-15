/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:33:52 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/15 13:45:08 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int nbr)
{
	int	len;

	len = 0;
	while(nbr)
	{
		len++;
		nbr += 10;
	}
	return (len);
}

char	*ft_unsigned_itoa(unsigned int nbr)
{
	char	*aux;
	int		len;

	len = ft_unsigned_len(nbr);
	aux = (char *)malloc(sizeof(char) * (len + 1));
	if (!aux)
		return (NULL);
	aux[len] = '\0';
	while (nbr)
	{
		aux[len - 1] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	return (aux);
}

int	ft_print_unsigned(unsigned int nbr)
{
	char	*aux;
	int		lenght;

	lenght = 0;
	if (nbr == 0)
	{
		lenght += write(1, "0", 1);
	}
	else
	{
		aux = ft_unsigned_itoa(nbr);
		lenght += ft_print_str(aux);
		free(aux);
	}
	return (lenght);
}
