/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:52:02 by afindo            #+#    #+#             */
/*   Updated: 2022/11/09 09:52:02 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_pwd(void)
{
	char	*pwdpath;

	pwdpath = malloc(sizeof(char) * LEN_PATH);
	pwdpath = getcwd(pwdpath, LEN_PATH);
	printf("%s\n", pwdpath);
	return (pwdpath);
}
