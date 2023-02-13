/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:52:23 by afindo            #+#    #+#             */
/*   Updated: 2022/11/09 09:52:23 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_remove(char **matr, char **cmds, int to_remove, int bool)
{
	char	**newmatr;
	int		i;
	int		j;
	int		k;

	newmatr = malloc(sizeof(char *) * (matln(matr) - to_remove));
	i = 0;
	j = 0;
	while (matr[i])
	{
		k = 1;
		bool = 1;
		while (cmds[k])
		{
			if (ft_strncmp(ft_split(matr[i], '=')[0], cmds[k], \
					ft_strlen(cmds[k])) == 0)
				bool = 0;
			k++;
		}
		if (bool)
			newmatr[j++] = ft_strdup(matr[i]);
		i++;
	}
	newmatr[j] = 0;
	return (newmatr);
}

void	ft_check_unset(t_shell *shell)
{
	char	**s;
	char	*err;
	int		i;
	int		j;

	s = ft_split(*(shell->tok), ' ');
	i = 1;
	while (s[i])
	{
		err = s[i];
		j = 0;
		while (s[i][j])
		{
			if (!(ft_isdigit(s[i][j]) || ft_isalpha(s[i][j])))
			{
				printf("unset: %s: not a valid identifier\n", err);
				shell->exitstatus = 1;
			}
			j++;
		}
		i++;
	}
}

int	ft_inenv(t_shell *shell)
{
	int		i;
	int		j;
	int		in_env;
	char	**s;

	s = ft_split(*(shell->tok), ' ');
	i = 0;
	in_env = 0;
	while (shell->env[i])
	{
		j = 1;
		while (s[j])
		{
			if (ft_strncmp(ft_split(shell->env[i], '=')[0], s[j], \
					ft_strlen(s[j])) == 0)
				in_env++;
			j++;
		}
		i++;
	}
	return (in_env);
}

int	ft_unset(t_shell *shell)
{
	char	**cmds;

	cmds = ft_split(*(shell->tok), ' ');
	ft_check_unset(shell);
	shell->env = ft_remove(shell->env, cmds, ft_inenv(shell), 0);
	if (!shell->exitstatus)
		return (0);
	return (1);
}
