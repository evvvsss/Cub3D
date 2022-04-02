/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:36:49 by bferny            #+#    #+#             */
/*   Updated: 2022/04/02 15:36:51 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t n)
{
	size_t	i;
	char	*b;

	i = 0;
	b = (char *)dest;
	while (i < n)
	{
		b[i] = '\0';
		i++;
	}
}
