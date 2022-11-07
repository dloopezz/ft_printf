/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeparams.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:39:04 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/10/26 15:52:13 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_paramcheck(char const *str, int elems, int i, va_list params)
{
	if (str[i + 1] == 'c')
		elems += ft_putchar(va_arg(params, int));
	if (str[i + 1] == 's')
		elems += ft_putstr(va_arg(params, char *));
	if (str[i + 1] == 'i' || str[i + 1] == 'd')
		elems += ft_putnbr(va_arg(params, int));
	if (str[i + 1] == '%')
		elems += ft_putchar('%');
	if (str[i + 1] == 'u')
		elems += ft_putunsnbr(va_arg(params, unsigned int));
	if (str[i + 1] == 'x')
		elems += ft_puthex(va_arg(params, int), "0123456789abcdef");
	if (str[i + 1] == 'X')
		elems += ft_puthex(va_arg(params, int), "0123456789ABCDEFG");
	if (str[i + 1] == 'p')
		elems += ft_hexpoint(va_arg(params, size_t));
	return (elems);
}

int	ft_writeparams(char const *str, int elems, va_list params)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			elems = ft_paramcheck(str, elems, i, params);
			i++;
		}
		else
			elems += write (1, &str[i], 1);
		i++;
	}
	return (elems);
}
