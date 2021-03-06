/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:37:36 by bferny            #+#    #+#             */
/*   Updated: 2022/04/02 15:37:38 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	i;
	char	*b;

	i = 0;
	b = (char *)dest;
	while (i < n)
	{
		b[i] = c;
		i++;
	}
	return (b);
}
