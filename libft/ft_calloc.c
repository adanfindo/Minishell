/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:13:46 by agenoves          #+#    #+#             */
/*   Updated: 2022/01/12 15:07:21 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	size2;

	size2 = size * count;
	ptr = malloc(size2);
	if (!(ptr))
		return (0);
	ft_memset(ptr, 0, size2);
	return (ptr);
}
