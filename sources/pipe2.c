/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:52:46 by agenoves          #+#    #+#             */
/*   Updated: 2022/11/08 11:53:02 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_count_pipe(t_shell *shell)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (ft_strcmp((shell->op)[i], "|") == 0)
	{
		count++;
		i++;
	}
	return (count);
}

void	open_pipe(int pipes[], int no_pipes)
{
	int	i;

	i = -1;
	while (++i < no_pipes)
		pipe(pipes + i * 2);
}

void	close_pipe(int pipes[], int no_pipes)
{
	int	j;

	j = 0;
	while (j < 2 * no_pipes)
		close(pipes[j++]);
}
