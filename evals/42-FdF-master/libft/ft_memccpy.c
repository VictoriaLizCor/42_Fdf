/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:48:36 by pbondoer          #+#    #+#             */
/*   Updated: 2023/04/16 14:11:34 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	cc;

	i = 0;
	cc = (unsigned char)c;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
		if (((unsigned char *)dst)[i - 1] == cc)
			return (&dst[i]);
	}
	return (NULL);
}
