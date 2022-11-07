/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:01:15 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/10/18 15:48:52 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		elems;
	va_list	params;

	elems = 0;
	va_start (params, str);
	elems = ft_writeparams(str, elems, params);
	va_end (params);
	return (elems);
}

/*int	main(void)
{
	ft_printf("char: %c\nstr: %s\nnbr1: %d\nnbr2: %i\nporcentaje: %%\nuns: %u\n
		hexmin: %x", 'L', "hello", -2147483648, 10, 13, 42);
	return (0);
}*/