/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsParser2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:54:41 by agenoves          #+#    #+#             */
/*   Updated: 2022/10/27 16:26:01 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_cmd1(t_shell *shell, int *i, int *in_cmd_mode, int *is_red)
{
	int	curr_ind;

	curr_ind = *i;
	*in_cmd_mode = 0;
	*i += ft_strlen(ft_get_echo(shell->cmd + *i, "", NULL));
	return (ft_arg_check(ft_get_echo2(shell->cmd + curr_ind), \
		shell->env, *is_red));
}

char	*ft_cmd2(t_shell *shell, int *i, int *in_cmd_mode, int *is_red)
{
	*in_cmd_mode = 0;
	*is_red = 0;
	*i = findparenth(shell->cmd, shell->start, "\"\'") + 1;
	return (ft_arg_check(getsub(shell->cmd, shell->start, *i), \
		shell->env, *is_red));
}

char	*ft_cmd3(t_shell *shell, int *i, int *in_cmd_mode, int *is_red)
{
	*in_cmd_mode = 0;
	*is_red = 0;
	*i = findparenth(shell->cmd, shell->start, ")") + 1;
	return (ft_arg_check(getsub(shell->cmd, shell->start, *i), \
		shell->env, *is_red));
}

char	*ft_cmd4(t_shell *shell, int *i, int *in_cmd_mode, int *is_red)
{
	*in_cmd_mode = 0;
	return (ft_arg_check(getsub(shell->cmd, shell->start, *i), \
		shell->env, *is_red));
}

char	*ft_cmd5(t_shell *shell, int *i, int *in_cmd_mode)
{
	*in_cmd_mode = 1;
	return (getsub(shell->cmd, shell->start, *i));
}
