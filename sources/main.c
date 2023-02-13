/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:51:36 by afindo            #+#    #+#             */
/*   Updated: 2022/11/09 09:51:36 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_initializer(t_shell *shell)
{
	shell->op = NULL;
	shell->tok = NULL;
	shell->exitstatus = -1;
	shell->cmd = readline(PROMPT);
	shell->fd_in = 0;
	shell->fd_out = 1;
	shell->last_operator = "";
	shell->is_subshell = 0;
}

int	main_loop(t_shell *shell, char **envp)
{
	ft_envhandle(envp, shell);
	shell->home = ft_get_home(shell);
	while (1)
	{
		sig_handling_set(1);
		ft_initializer(shell);
		if (!shell->cmd)
			return (write (1, "\n", 1));
		if (shell->cmd)
			add_history(shell->cmd);
		if (ft_check_operator(shell->cmd))
			printf("Waiting for new command...\n");
		else
			ft_start(shell);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void) argc;
	(void) argv;
	main_loop(&shell, envp);
}
