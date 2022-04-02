/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:37:59 by bferny            #+#    #+#             */
/*   Updated: 2022/04/02 15:38:00 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;
	char	k;

	k = c;
	s = (char *)str;
	i = 0;
	if (k == '\0')
	{
		while (s[i] != '\0')
			i++;
		return (&s[i]);
	}
	while ((s[i] != '\0') && (s[i] != k))
		i++;
	if (s[i] == '\0')
		return (NULL);
	return (&s[i]);
}
