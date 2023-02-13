/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:34:45 by agenoves          #+#    #+#             */
/*   Updated: 2022/11/09 09:50:29 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_or(t_shell *shell)
{
	if (shell->exitstatus > 0 && !ft_strncmp(*(shell->op + 1), "|", 1))
	{
		shell->op++;
		ft_exec_pipe(shell, ft_count_pipe(shell));
	}
	if (shell->exitstatus > 0 || (shell->last_operator)[0] == '\0' || \
		!ft_strcmp((shell->last_operator), "&&"))
		ft_exec_cmd(shell);
	if (shell->exitstatus == 0)
	{
		if (ft_strcmp(*(shell->op), "||") == 0)
			shell->op++;
		while (ft_strcmp(*(shell->op), "|") == 0 || \
			ft_strcmp(*(shell->op), "||") == 0)
		{
			shell->tok++;
			shell->op++;
		}
		if (*(shell->tok))
			shell->tok++;
	}
}

void	ft_and(t_shell *shell)
{
	if (ft_strcmp(*(shell->op + 1), "|") == 0)
	{
		ft_exec_cmd(shell);
		ft_exec_pipe(shell, ft_count_pipe(shell));
	}
	if (*(shell->tok))
		ft_exec_cmd(shell);
	if (shell->exitstatus == 0 && *(shell->tok) != NULL)
		ft_switch_op(shell);
	else if (shell->exitstatus > 0)
	{
		while (ft_strcmp(*(shell->op), "&&") == 0)
		{
			shell->tok++;
			shell->op++;
		}
		if (*(shell->tok))
			shell->tok++;
	}
}
