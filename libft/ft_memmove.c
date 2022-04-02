/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:37:32 by bferny            #+#    #+#             */
/*   Updated: 2022/04/02 15:37:34 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char *)dest;
	src = (unsigned char *)source;
	if (dest == NULL && source == NULL)
		return (NULL);
	if (src < dst)
	{
		while (n > 0)
		{
			n--;
			dst[n] = src[n];
		}
	}
	else
		ft_memcpy(dest, source, n);
	return (dest);
}
