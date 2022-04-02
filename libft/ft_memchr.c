/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:37:18 by bferny            #+#    #+#             */
/*   Updated: 2022/04/02 15:37:19 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*ar;
	size_t			i;

	ar = (unsigned char *)arr;
	i = 0;
	while (i < n)
	{
		if (ar[i] == (unsigned char)c)
		{
			ar = &ar[i];
			return ((unsigned char *)ar);
		}
		i++;
	}
	return (NULL);
}
