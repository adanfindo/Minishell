/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsEcho.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:52:42 by afindo            #+#    #+#             */
/*   Updated: 2022/11/09 09:52:42 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_quoteparent(char *s, char c)
{
	int	i;

	i = 1;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_charjoin(char *s1, char s2)
{
	size_t	i;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1)
		return (NULL);
	str = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	str[i++] = s2;
	str[ft_strlen(s1) + 1] = '\0';
	return (str);
}

char	*return_s(char *temp, char *last_quote, char *echo, char *copy)
{
	int	i;

	(void) last_quote;
	(void) temp;
	(void) copy;
	if (!ft_strcmp(echo, "echo $?"))
		return (echo);
	i = 5;
	while (echo[i])
	{
		if (echo[i] == 34)
			while (echo[++i] != 34)
				;
		else if (echo[i] == 39)
			while (echo[++i] != 39)
				;
		if (ft_has(echo[i], "&|<>"))
			break ;
		i++;
	}
	return (getsub(echo, 0, i));
}

char	*ft_get_echo(char *s, char *last_quote, char *echo)
{
	char	*temp;
	char	*copy;

	copy = ft_strdup(s);
	echo = ft_strnstr(copy, "echo", ft_strlen(copy));
	if (!echo)
		return (NULL);
	temp = echo;
	while (*temp)
	{
		if (*temp == 34)
		{
			last_quote = ft_strrchr(echo, 34);
			break ;
		}
		if (*temp == 39)
		{
			last_quote = ft_strrchr(echo, 39);
			break ;
		}
		if (ft_has(*temp, "&|<>"))
			break ;
		temp++;
	}
	return (return_s(temp, last_quote, echo, copy));
}
