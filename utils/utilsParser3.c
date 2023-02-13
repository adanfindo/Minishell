/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsParser3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:53:00 by afindo            #+#    #+#             */
/*   Updated: 2022/11/09 09:53:00 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_get_cmd2(t_shell *shell, int *i, int *in_cmd_mode, int *is_red)
{
	char	*temp;

	while (shell->cmd[*i])
	{
		if (ft_has(shell->cmd[(*i)], "<>"))
			*is_red = 1;
		if (*in_cmd_mode && ft_has(shell->cmd[(*i)], "\"\'"))
			return (ft_cmd2(shell, i, in_cmd_mode, is_red));
		if (*in_cmd_mode && ft_has(shell->cmd[(*i)], "("))
			return (ft_cmd3(shell, i, in_cmd_mode, is_red));
		if (*in_cmd_mode && !ft_strncmp(shell->cmd + *i, "echo", 4) \
			&& ft_get_echo2(shell->cmd + *i) != NULL)
			return (ft_cmd1(shell, i, in_cmd_mode, is_red));
		else if (*in_cmd_mode && !ft_isdigit(shell->cmd[(*i)]) && \
			!ft_isalpha(shell->cmd[(*i)]) && ft_has(shell->cmd[(*i)], "|&><"))
			return (ft_cmd4(shell, i, in_cmd_mode, is_red));
		else if (!(*in_cmd_mode) && !ft_has(shell->cmd[(*i)], "|&><"))
			return (ft_cmd5(shell, i, in_cmd_mode));
		(*i)++;
	}
	*i = -2;
	temp = getsub(shell->cmd, shell->start, ft_strlen(shell->cmd));
	if (*temp)
		return (ft_arg_check(temp, shell->env, *is_red));
	return (NULL);
}
