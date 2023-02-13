/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:30:18 by agenoves          #+#    #+#             */
/*   Updated: 2022/01/16 12:10:25 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*p;
	const char	*p2;

	if (dst == NULL && src == NULL)
		return (NULL);
	p = (char *)dst;
	p2 = (const char *)src;
	i = 0;
	while (i < n)
	{
		p[i] = p2[i];
		i++;
	}
	return (dst);
}
