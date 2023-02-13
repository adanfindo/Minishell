/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:10:33 by agenoves          #+#    #+#             */
/*   Updated: 2022/10/27 10:47:31 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_envhandle(char **envp, t_shell *shell)
{
	int		i;

	shell->env = malloc(sizeof(char *) * (matln(envp) + 1));
	i = -1;
	if (!shell->env)
		exit(printf("Error allocating env\n"));
	while (envp[++i])
	{
		shell->env[i] = ft_strdup(envp[i]);
		if (!shell->env)
			exit(printf("Error setting env\n"));
	}
	shell->env[i] = 0;
}

void	ft_printenv(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i] != 0)
		printf("%s\n", envp[i]);
}
