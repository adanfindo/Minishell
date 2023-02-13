/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:29:14 by agenoves          #+#    #+#             */
/*   Updated: 2022/01/12 16:10:25 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*value;

	len = ft_strlen(s);
	value = 0;
	while (len >= 0 && s[len] >= 0)
	{
		if (s[len] == (char )c)
		{
			value = &((char *)s)[len];
			break ;
		}
		len--;
	}
	return (value);
}
