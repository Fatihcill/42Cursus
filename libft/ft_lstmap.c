/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:58:57 by fcil              #+#    #+#             */
/*   Updated: 2022/02/02 16:43:28 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			while (first)
			{
				new = first->next;
				(*del)(first->content);
				free(first);
				first = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}

// lst nin tum elemanlarina f fonksiyonu uygulanir
// uygulama sonucunda olusan yeni elemanlar ile (25. satir)
// yeni bir liste olusturulur 25 ve 38. satir
// gerekli durumlarda (lst bittikten sonra) veya f null dondurunce
// yeni olusturulan first degiskeninin icerisi temizlenir 
// ve  delete ile silinir.