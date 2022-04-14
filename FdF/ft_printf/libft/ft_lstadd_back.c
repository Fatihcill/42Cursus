/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:51:38 by fcil              #+#    #+#             */
/*   Updated: 2022/02/06 19:27:30 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

//19da lst bos ise direkt ilk eleman new atanir.
//24de  ptr nin en sonuna dek gider ptr next null oldugunda 
// 26 da new parametresi en sona atanir ve new in nexti null yapilir.
// cunku new->next null olmali en sona new.