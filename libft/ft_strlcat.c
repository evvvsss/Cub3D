/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:38:12 by bferny            #+#    #+#             */
/*   Updated: 2022/04/02 15:38:13 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[n] != '\0' && (i + n + 1) < size)
	{
		dst[i + n] = src[n];
		n++;
	}
	if (i != size)
		dst[i + n] = '\0';
	return (i + ft_strlen(src));
}
