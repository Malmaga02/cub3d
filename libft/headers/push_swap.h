/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:50:39 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/30 18:09:06 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "checker.h"
# include <limits.h>

typedef enum e_moves
{
	STAY,
	MOVE_A,
	MOVE_B,
	MOVE_BOTH,
	PUSH,
	ROTATE,
	R_ROTATE,
	SWAP
}	t_moves;

typedef struct s_bestmoves
{
	int	rot_a;
	int	rot_b;
	int	rot_both;
	int	r_rot_a;
	int	r_rot_b;
	int	r_rot_both;
	int	tot_moves;
}		t_bestmoves;

/* Minisort */

int			find_move(t_dll *pStack);
void		solve_3(t_dll **pStack);
void		solve_4(t_dll **pStack, t_dll **stack_b);
void		solve_5(t_dll **pStack, t_dll **stack_b);
void		minisort(t_dll **stack_a, t_dll **stack_b);

/* Algo */
void		final_sorting(t_dll **stack_a);
void		get_rotate(t_dll **stack_a, t_dll **stack_b, t_bestmoves moves);
void		get_r_rotate(t_dll **stack_a, t_dll **stack_b, t_bestmoves moves);
void		do_moves(t_dll **stack_a, t_dll **stack_b);
void		solve_all(t_dll **stack_a, t_dll **stack_b);

/* Find_bestmoves */

t_bestmoves	check_moves_b(t_dll *stack_b, int value_b, t_bestmoves moves);
t_bestmoves	check_moves_a(t_dll *stack_a, int value_b, t_bestmoves moves);
t_bestmoves	organize_moves(t_bestmoves moves);
t_bestmoves	get_moves(t_dll *stack_a, t_dll *stack_b, int value_b);
t_bestmoves	get_best_moves(t_dll *stack_a, t_dll *stack_b);

/* Parsing */

t_dll		*get_list_head(char **mtx);
t_dll		*parse_input_string(int ac, char *av);
t_dll		*parse_input_args(int ac, char **av);
t_dll		*parse_input(int ac, char **av);

/* Utils */

int			check_duplicates(char **mtx);
int			is_sorted(t_dll *pStack);
int			mtx_check(char **mtx);
t_bestmoves	bestmoves_cpy(t_bestmoves moves);
t_bestmoves	bestmoves_operations(t_bestmoves moves, int flag_move);
void		solver(t_dll **stack_a);

/* Moves */

void		swap_op(t_dll **node1);
void		swap(t_dll **stack_a, t_dll **stack_b, int flag);
void		rotate_op(t_dll **stack);
void		rotate(t_dll **stack_a, t_dll **stack_b, int flag);
void		r_rotate_op(t_dll **stack);
void		r_rotate(t_dll **stack_a, t_dll **stack_b, int flag);
void		pa(t_dll **stack_a, t_dll **stack_b);
void		pb(t_dll **stack_b, t_dll **stack_a);

/* Lis */

t_dll		*get_stack_lis(t_dll **stack_a);
t_dll		*handling_lis(t_dll **stack_a, int *index_a, int lis_size);
int			*lis_algo(t_dll *head, int *n);

#endif
