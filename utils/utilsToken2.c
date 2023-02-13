/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsToken2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:53:11 by afindo            #+#    #+#             */
/*   Updated: 2022/11/09 09:53:11 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h" 

char	*ft_arg_check(char *cmd, char **envp, int redi)
{
	char	**word;
	char	*temp;

	temp = ft_strdup(cmd);
	if (temp[0] == 40)
	{
		ft_memmove(temp, temp + 1, ft_strlen(temp));
		ft_memmove(&temp[ft_strlen(temp) - 1], \
			&temp[ft_strlen(temp)], ft_strlen(temp));
	}
	word = ft_split(temp, ' ');
	if (ft_isbuiltin(word[0]) && access(word[0], F_OK) != 0 && \
			ft_pathfinder(word[0], envp) == NULL && !redi)
		printf("Minishell: command not found: %s\n", word[0]);
	free(temp);
	return (cmd);
}

int	ft_pipe_check(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != '\0')
	{
		i = ft_checkall(cmd, i);
		if (cmd[i] == '|' && cmd[i + 1] == '|')
		{
			if (cmd[i + 1] == '|' && cmd[i + 2] == '|')
			{
				perror("Pipe Check Problem: Minishell");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	ft_and_check(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != '\0')
	{
		i = ft_checkall(cmd, i);
		if (cmd[i] == '&' && cmd[i + 1] != '&' && cmd[i - 1] != '&')
		{
			perror("And Check Problem: Minishell");
			return (1);
		}
		else if (cmd[i] == '&' && cmd[i + 1] == '&')
		{
			if (cmd[i + 1] == '&' && cmd[i + 2] == '&')
			{
				perror("And Check Problem: Minishell");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	ft_quote_check_aux(char *cmd, int i)
{
	while (cmd[++i])
	{
		if (cmd[i] == 34)
		{
			if (ft_quoteparent(cmd + i, 34) != 0)
				i += ft_quoteparent(cmd + i, 34);
			else
				return (-1);
		}
		if (cmd[i] == 39)
		{
			if (ft_quoteparent(cmd + i, 39) != 0)
				i += ft_quoteparent(cmd + i, 39);
			else
				return (-1);
		}
	}
	return (0);
}

int	ft_quote_check(char *cmd)
{
	int	i;

	i = -1;
	if (ft_quote_check_aux(cmd, i) == -1)
	{
		perror("Quote Check Problem: Minishell");
		return (1);
	}
	return (0);
}
