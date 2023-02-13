/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:51:42 by afindo            #+#    #+#             */
/*   Updated: 2022/11/09 09:51:42 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_ini_subshell(t_shell *shell, t_shell *newshell, char *s)
{
	ft_envhandle(shell->env, newshell);
	newshell->home = ft_get_home(newshell);
	sig_handling_set(1);
	newshell->op = NULL;
	newshell->tok = NULL;
	newshell->exitstatus = -1;
	newshell->cmd = ft_strdup(s);
	newshell->last_operator = "";
	newshell->fd_in = shell->fd_out;
	newshell->is_subshell = 1;
	exit(ft_start(newshell));
}

void	ft_subshell(t_shell *shell, char *s)
{
	pid_t	pid;
	t_shell	newshell;
	int		status;

	pid = fork();
	if (!pid)
		ft_ini_subshell(shell, &newshell, s);
	else
	{
		waitpid(pid, &status, 0);
		shell->exitstatus = WEXITSTATUS(status);
		shell->tok++;
		shell->op++;
	}
}

void	ft_run_new_shell(t_shell *shell)
{
	char	**env_copy;
	t_shell	newshell;
	int		status;
	pid_t	pid;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	pid = fork();
	if (!pid)
	{
		env_copy = ft_mat_copy(shell->env);
		ft_increase_shlvl(&env_copy);
		main_loop(&newshell, env_copy);
		exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);
		shell->exitstatus = WEXITSTATUS(status);
		shell->tok++;
	}
}
