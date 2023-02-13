/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:52:16 by afindo            #+#    #+#             */
/*   Updated: 2022/11/09 09:52:16 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sighand(int sig)
{
	if (sig == SIGINT)
	{
		(void)sig;
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		(void)sig;
		rl_on_new_line();
		rl_redisplay();
	}
}

void	sig_handling_set(int signals)
{
	struct termios			newterm_attr;
	static struct termios	oldterm_attr;

	if (signals == 1)
	{
		tcgetattr(0, &oldterm_attr);
		newterm_attr = oldterm_attr;
		newterm_attr.c_lflag = newterm_attr.c_lflag & ~(ECHOCTL);
		tcsetattr(0, 0, &newterm_attr);
		signal(SIGINT, sighand);
		signal(SIGQUIT, sighand);
	}
	else
		tcsetattr(STDIN_FILENO, TCSANOW, &oldterm_attr);
}
