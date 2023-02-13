/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:05:08 by agenoves          #+#    #+#             */
/*   Updated: 2022/10/27 16:32:45 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_is_subshell(char **token)
{
	if ((*token)[0] != 40)
		return (0);
	ft_memmove((*token), (*token) + 1, ft_strlen((*token)));
	ft_memmove(&(*token)[ft_strlen((*token)) - 1], \
		&(*token)[ft_strlen((*token))], ft_strlen((*token)));
	return (1);
}

int	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (!matrix)
		return (1);
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
	return (0);
}

char	*ft_pathfinder(char *cmd, char **envp)
{
	char	**mypaths;
	char	*pathnoslash;
	char	*finalpath;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	mypaths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (mypaths[i])
	{
		pathnoslash = ft_strjoin(mypaths[i], "/");
		finalpath = ft_strjoin(pathnoslash, cmd);
		free(pathnoslash);
		if (access(finalpath, F_OK) == 0)
			return (finalpath);
		free(finalpath);
		i++;
	}
	free_matrix(mypaths);
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	matln(char **s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
