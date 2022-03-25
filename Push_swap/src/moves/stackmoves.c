/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmoves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:57:05 by fcil              #+#    #+#             */
/*   Updated: 2022/03/25 12:26:38 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stackmoves_setup(t_stack *a, t_stack *b, t_seq *seq)
{
	sx(SETUP, a, b, seq);
	px(SETUP, a, b, seq);
	rx(SETUP, a, b, seq);
	rrx(SETUP, a, b, seq);
}
