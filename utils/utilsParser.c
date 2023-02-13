/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsParser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:52:50 by afindo            #+#    #+#             */
/*   Updated: 2022/11/09 09:52:50 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_remove_quote(char *str, char c)
{
	char	*temp;
	int		len;

	temp = str;
	while (*temp)
	{
		len = ft_strlen(temp);
		if (*temp == c)
			ft_memmove(temp, temp + 1, len);
		temp++;
	}
}

char	*ft_check_quote(char **token)
{
	int	i;

	i = 0;
	if (!(*token))
		return (NULL);
	if (!ft_strncmp(*(token), "echo", 4))
		return (*token);
	if (!ft_strncmp(*(token), "export", 6))
		return (*token);
	while ((*token)[i])
	{
		if ((*token)[i] == 34)
		{
			ft_remove_quote(*token, 34);
			break ;
		}
		if ((*token)[i] == 39)
		{
			ft_remove_quote(*token, 39);
			break ;
		}	
		i++;
	}
	return (*token);
}

char	*ft_get_op(t_shell *shell, int heredoc)
{
	int		i;
	char	*res;
	char	*curr_op;

	i = 0;
	curr_op = "";
	res = "";
	while (shell->op && shell->op[i])
	{
		if (i != 0 && !ft_strcmp(shell->op[i], "|"))
			curr_op = "pipe ";
		else if (!ft_strcmp(shell->op[i], "&&"))
			curr_op = "cmdand ";
		else if (!ft_strcmp(shell->op[i], "||"))
			curr_op = "cmdor ";
		res = ft_strjoin(res, curr_op);
		i++;
	}
	if (heredoc)
		res = ft_strjoin(res, "heredoc ");
	res = ft_strjoin(res, "\b> ");
	return (res);
}

void	ft_append_cmd(t_shell *shell)
{
	char	*prompt;

	prompt = ft_get_op(shell, 0);
	shell->cmd = readline(prompt);
	while (*(shell->cmd) == '\0')
		shell->cmd = readline(prompt);
	ft_creatematrix(shell, " ", " ");
}

char	*ft_get_cmd(t_shell *shell)
{
	static int		i = 0;
	static int		in_cmd_mode = 1;
	static int		is_red = 0;

	if (i == -2 || i == ft_strlen(shell->cmd))
	{
		i = 0;
		in_cmd_mode = 1;
		return (NULL);
	}
	shell->start = ft_get_cmd_aux(shell->cmd, &i);
	return (ft_get_cmd2(shell, &i, &in_cmd_mode, &is_red));
}
