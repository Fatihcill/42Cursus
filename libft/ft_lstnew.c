/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:29:57 by fcil              #+#    #+#             */
/*   Updated: 2022/02/02 16:27:14 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
// BU BIR BAGLI LISTEDIR.
//fonksiyon cagrildiginda verilen icerik (content)
//structimizin content bolumune kaydedilir.
// ilk olusturuldugu icinde next degeri NULL dur
// ve olusturulan yeni struct return edilir.