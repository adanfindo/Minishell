/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:23:42 by agenoves          #+#    #+#             */
/*   Updated: 2022/01/16 12:37:03 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkchar(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimstr;
	size_t	begin;
	size_t	end;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	begin = 0;
	while (s1[begin] != '\0' && ft_checkchar(s1[begin], set))
		begin++;
	end = ft_strlen(s1);
	while (end > begin && ft_checkchar(s1[end - 1], set))
		end--;
	trimstr = (char *)malloc(sizeof(*s1) * (end - begin + 1));
	if (trimstr == NULL)
		return (NULL);
	i = 0;
	while (begin < end)
		trimstr[i++] = s1[begin++];
	trimstr[i] = 0;
	return (trimstr);
}
