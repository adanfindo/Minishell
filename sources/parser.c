/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:51:47 by afindo            #+#    #+#             */
/*   Updated: 2022/11/09 09:51:47 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_switch_op(t_shell *shell)
{
	if (ft_strcmp(*(shell->tok), "./minishell") == 0)
		ft_run_new_shell(shell);
	else if (ft_strchr(*(shell->tok), '*') && ft_strcmp(*(shell->op), "|") != 0)
		ft_wild(shell);
	else if (!ft_strcmp(*(shell->op), "|"))
		ft_exec_pipe(shell, ft_count_pipe(shell));
	else if (ft_is_subshell(&(*(shell->tok))))
		ft_subshell(shell, *(shell->tok));
	else if (!ft_strcmp(*(shell->op), "||"))
		ft_or(shell);
	else if (!ft_strcmp(*(shell->op), "&&"))
		ft_and(shell);
	else if (!ft_strcmp(*(shell->op), ">") || !ft_strcmp(*(shell->op), ">>"))
		ft_right_redir(shell);
	else if (!ft_strcmp(*(shell->op), "<"))
		ft_left_redir(shell);
	else if (*(shell->op) == NULL && *(shell->tok) != NULL)
		ft_exec_cmd(shell);
	if (!ft_strcmp(*(shell->op), ">") || !ft_strcmp(*(shell->op), ">>"))
		ft_skip_redirection(shell);
}

void	ft_creatematrix(t_shell *shell, char *token, char *operator)
{
	while (token != NULL && operator != NULL)
	{
		if (ft_strcmp(operator, "<<"))
		{
			token = ft_get_cmd(shell);
			token = ft_strip(&token);
			token = ft_check_quote(&token);
			shell->tok = ft_addelement(shell->tok, token);
		}
		if (!token)
			break ;
		operator = ft_get_cmd(shell);
		operator = ft_strip(&operator);
		if (!ft_strcmp(operator, "<<"))
			ft_heredoc(shell);
		else
			shell->op = ft_addelement(shell->op, operator);
	}
	if (shell->tok && shell->op && matln(shell->tok) == matln(shell->op))
		ft_append_cmd(shell);
}

int	ft_start(t_shell *shell)
{
	ft_creatematrix(shell, " ", " ");
	shell->op_temp = shell->op;
	shell->tok_temp = shell->tok;
	ft_redirection(shell);
	while (*(shell->tok))
		ft_switch_op(shell);
	free(shell->cmd);
	free_matrix(shell->tok_temp);
	free_matrix(shell->op_temp);
	return (shell->exitstatus);
}
