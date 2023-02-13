/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:01:28 by agenoves          #+#    #+#             */
/*   Updated: 2022/10/27 10:47:32 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_check_builtin(char *input)
{
	char	**cmd;

	cmd = ft_split(input, ' ');
	if (ft_strcmp(cmd[0], "echo") == 0 || ft_strcmp(cmd[0], "pwd") == 0 \
		|| ft_strcmp(cmd[0], "exit") == 0 \
		|| ft_strcmp(cmd[0], "env") == 0 || ft_strcmp(cmd[0], "cd") == 0 \
		|| ft_strcmp(cmd[0], "unset") == 0 \
		|| ft_strcmp(cmd[0], "export") == 0)
		return (0);
	else
		return (1);
}

int	ft_builtin(char *token, int i, int check, t_shell *shell)
{
	char	**cmd;

	cmd = ft_split(token, ' ');
	if (ft_strcmp(cmd[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(cmd[0], "exit") == 0)
		ft_exit(shell, i, check);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		ft_cd(shell);
	else if (ft_strcmp(cmd[0], "env") == 0)
		ft_printenv(shell->env);
	else if (ft_strcmp(cmd[0], "echo") == 0)
		ft_echo(shell);
	else if (ft_strcmp(cmd[0], "export") == 0)
		shell->exitstatus = ft_export(*(shell->tok), shell);
	else if (ft_strcmp(cmd[0], "unset") == 0)
		shell->exitstatus = ft_unset(shell);
	else
		return (1);
	shell->exitstatus = 0;
	return (0);
}

void	ft_print_mat(char **ss)
{
	int	i;

	i = 0;
	while (ss[i])
	{
		printf("%s\n", ss[i]);
		i++;
	}
}

char	**ft_mat_copy(char **mat)
{
	char	**res;
	int		i;

	res = (char **)malloc(sizeof(char *) * matln(mat));
	i = 0;
	while (mat[i])
	{
		res[i] = ft_strdup(mat[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_increase_shlvl(char ***mat)
{
	int		i;
	char	*value;

	i = 0;
	while (ft_strncmp((*mat)[i], "SHLVL", 5))
		i++;
	value = ft_itoa(ft_atoi(&(*mat)[i][6]) + 1);
	(*mat)[i] = ft_strjoin("SHLVL=", value);
	free(value);
}
