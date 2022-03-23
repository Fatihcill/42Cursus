/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:48:54 by fcil              #+#    #+#             */
/*   Updated: 2022/03/23 00:14:03 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "ft_printf.h"

//stack
typedef struct		s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int					value;
	int					rank;
}					t_node;

typedef struct		s_stack
{
	t_node	*first;
	int			len;
}					t_stack;
//-----------------

//sequence
typedef enum	e_move
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}				t_move;

typedef struct	s_instruction
{
	struct s_instruction	*next;
	t_move					move;
}				t_instruction;

typedef struct	s_seq
{
	t_instruction	*first;
	t_instruction	*last;
	int				len;
}				t_seq;
//---------
//array functions
int		*params_to_array(int ac, char **av);
int		*arr_checkdoubles(int *arr, int len);

void			core_px(int flag, t_stack *a, t_stack *b, t_seq *seq);
void			core_rrx(int flag, t_stack *a, t_stack *b, t_seq *seq);
void			core_rx(int flag, t_stack *a, t_stack *b, t_seq *seq);
void			core_sx(int flag, t_stack *a, t_stack *b, t_seq *seq);
void			stacks_setup(t_stack *a, t_stack *b, t_seq *seq);

/*
** quick functions (static variables black magic)
*/

void				pa(void);
void				pb(void);
void				sa(void);
void				sb(void);
void				ss(void);
void				ra(void);
void				rb(void);
void				rr(void);
void				rra(void);
void				rrb(void);
void				rrr(void);

#endif
