/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:55:50 by agenoves          #+#    #+#             */
/*   Updated: 2022/01/16 12:59:48 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	numcar;

	if (!s)
		return ;
	numcar = 0;
	while (s[numcar] != '\0')
	{
		ft_putchar_fd(s[numcar], fd);
		numcar++;
	}
}
