/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:01:45 by lopezz            #+#    #+#             */
/*   Updated: 2022/10/02 20:19:47 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (((i + 1) < n) && (str1[i] == str2[i]))
		i++;
	return ((int)(str1[i] - str2[i]));
}

/* #include <stdio.h>
#include <string.h>

int main()
{
	printf("%d", ft_memcmp("abcd", "abcg", 4));
	return (0);
} */