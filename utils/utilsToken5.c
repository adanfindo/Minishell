/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsToken5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:53:22 by afindo            #+#    #+#             */
/*   Updated: 2022/11/09 09:53:22 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_checkall(char *cmd, int i)
{
	if (cmd[i] == 34)
	{
		if (ft_quoteparent(cmd + i, 34) != 0)
			i += ft_quoteparent(cmd + i, 34);
		else
			return (-2);
	}
	if (cmd[i] == 39)
	{
		if (ft_quoteparent(cmd + i, 39) != 0)
			i += ft_quoteparent(cmd + i, 39);
		else
			return (-2);
	}
	return (i);
}
