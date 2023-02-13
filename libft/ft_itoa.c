/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:18:10 by agenoves          #+#    #+#             */
/*   Updated: 2022/01/16 17:18:16 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	numlen(int n)
{
	size_t	num;

	num = 0;
	if (n == 0)
		num++;
	while (n)
	{
		n = n / 10;
		num++;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char		*strnum;
	size_t		nlen;
	size_t		number;

	number = n;
	nlen = numlen(n);
	if (n < 0)
	{
		number = number * -1;
		nlen++;
	}
	strnum = (char *)malloc(sizeof(char) * (nlen + 1));
	if (strnum == NULL)
		return (NULL);
	*(strnum + nlen) = '\0';
	while (nlen--)
	{
		*(strnum + nlen) = number % 10 + '0';
		number = number / 10;
	}
	if (n < 0)
		*(strnum + 0) = '-';
	return (strnum);
}
