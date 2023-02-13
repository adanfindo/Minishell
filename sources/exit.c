/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:51:20 by afindo            #+#    #+#             */
/*   Updated: 2022/11/09 09:51:20 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(t_shell *shell, int check, int i)
{
	char	**cmds;

	cmds = ft_split(*(shell->tok), ' ');
	printf("exit\n");
	if (matln(cmds) > 2)
		printf("too many arguments\n");
	else if (matln(cmds) == 2)
	{
		while (cmds[1][i])
		{
			if (!ft_isdigit(cmds[1][i]))
			{
				check = 1;
				break ;
			}
			i++;
		}
		if (check)
			printf("minishell: exit: %s: numeric arg required\n", cmds[1]);
		exit(ft_atoi(cmds[1]));
	}
	exit(0);
}
