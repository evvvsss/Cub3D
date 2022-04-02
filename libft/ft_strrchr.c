/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:38:38 by bferny            #+#    #+#             */
/*   Updated: 2022/04/02 15:38:39 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	int		i;
	char	k;

	k = c;
	s = (char *)str;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == k)
			return (&s[i]);
		i--;
	}
	return (NULL);
}
