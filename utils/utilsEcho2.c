/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsEcho2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:49:32 by agenoves          #+#    #+#             */
/*   Updated: 2022/10/27 14:49:52 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_changeword(char *sentence, char *find, char *replace)
{
	int		len;
	char	*dest;
	char	*destptr;

	len = ft_strlen(sentence) - ft_strlen(find) + ft_strlen(replace) + 1;
	dest = malloc(len);
	destptr = dest;
	*dest = 0;
	while (*sentence)
	{
		if (!ft_strncmp(sentence, find, ft_strlen(find)))
		{
			strcat (destptr, replace);
			sentence += ft_strlen(find);
			destptr += ft_strlen(replace);
		}
		else
		{
			*destptr = *sentence;
			destptr++;
			sentence++;
		}
	}
	*destptr = 0;
	return (dest);
}
