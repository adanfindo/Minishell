/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:52:33 by afindo            #+#    #+#             */
/*   Updated: 2022/11/09 09:52:33 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_heredoc(t_shell *shell)
{
	char	*prompt;
	char	*input;
	char	*next_tok;

	next_tok = ft_get_cmd(shell);
	next_tok = ft_strip(&next_tok);
	prompt = ft_get_op(shell, 1);
	input = readline(prompt);
	while (ft_strcmp(input, next_tok))
		input = readline(prompt);
}
