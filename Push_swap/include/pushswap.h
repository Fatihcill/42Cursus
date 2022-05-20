/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:48:54 by fcil              #+#    #+#             */
/*   Updated: 2022/05/20 14:55:33 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "ft_printf.h"
# include "limits.h"

# define SETUP 1
# define FLAG_A 2
# define FLAG_B 4
//stack
typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				value;
	int				rank;
}					t_node;

typedef struct s_stack
{
	t_node	*first;
	int		len;
}					t_stack;
//----------------------------------------------------------------
//sequence
typedef enum e_move
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

typedef struct s_instruction
{
	struct s_instruction	*next;
	t_move					move;
}				t_instruction;

typedef struct s_seq
{
	t_instruction	*first;
	t_instruction	*last;
	int				len;
}				t_seq;
//---------

//QUICKSORT 
void	quick_sort(t_stack *a, t_stack *b);
typedef struct s_quick
{
	int		alen;
	int		blen;
	int		minrank;
	int		maxrank;
	int		topush;
	int		pushed;
	int		mid;
	int		isthisa;
	int		reclvl;
	int		offset;
}				t_quick;

//a stackinde pivotdan itibaren artan şekilde sıralıyoruz.
void	quick_sort_a_ascending(t_stack *a, t_stack *b, t_quick *data);
//b stackinde pivotdan itibaren azalan şekilde sıralıyoruz.
void	quick_sort_b_descending(t_stack *a, t_stack *b, t_quick *data);
//----------------------------------------------------------------

//----------------------------------------------------------------
//stack functions
void	stack_free(t_stack *stack);
int		build_stack(t_stack *stack, int *arr, int len);

//array functions
int		*params_to_array(int *len, char **av);
int		*arr_checkdoubles(int *arr, int len);
int		check_error(char **array);

//stackmoves
void	px(int flag, t_stack *a, t_stack *b, t_seq *seq);
void	rrx(int flag, t_stack *a, t_stack *b, t_seq *seq);
void	rx(int flag, t_stack *a, t_stack *b, t_seq *seq);
void	sx(int flag, t_stack *a, t_stack *b, t_seq *seq);
void	stackmoves_setup(t_stack *a, t_stack *b, t_seq *seq);
t_node	*stack_init(t_stack *stack, t_node *node);
t_node	*stack_add_end(t_stack *stack, t_node *node);
t_node	*stack_add_first(t_stack *stack, t_node *node);
int		is_stack_sorted(t_stack *stack);
int		stacks_sort(t_stack *a, t_stack *b);
//----------------------------------------------------------------
//sequence
void	seq_add(t_seq *seq, t_move move);
void	seq_print(t_seq *seq);
void	seq_optimize(t_seq *seq);
//----------------------------------------------------------------
/*
** moves
*/
void	pa(void);
void	pb(void);
void	sa(void);
void	sb(void);
void	ss(void);
void	ra(void);
void	rb(void);
void	rr(void);
void	rra(void);
void	rrb(void);
void	rrr(void);
//reverse moves
void	n_pa(int n);
void	n_pb(int n);
void	n_rra(int n);
void	n_rrb(int n);
//----------------------------------------------------------------
#endif
