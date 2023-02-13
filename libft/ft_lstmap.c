/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:43:29 by agenoves          #+#    #+#             */
/*   Updated: 2022/01/17 19:50:31 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*lsttemp;

	if (lst == NULL || f == NULL)
		return (NULL);
	lst2 = ft_lstnew((*f)(lst->content));
	lst = lst->next;
	while (lst)
	{
		lsttemp = ft_lstnew((*f)(lst->content));
		if (lsttemp == NULL)
		{
			ft_lstclear(&lst2, del);
			break ;
		}
		if (lst2 != NULL)
			ft_lstadd_back(&lst2, lsttemp);
		lst = lst->next;
	}
	return (lst2);
}
