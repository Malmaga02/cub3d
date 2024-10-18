/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:08:59 by mgalmari          #+#    #+#             */
/*   Updated: 2024/04/30 18:09:06 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int		read_moves(t_dll **stack_a, t_dll **stack_b);
int		do_the_moves(t_dll **stack_a, t_dll **stack_b, char *str);

// Rotate
void	checker_r_rotate_op(t_dll **stack);
void	checker_r_rotate(t_dll **stack_a, t_dll **stack_b, int flag);

//R-Rotate
void	checker_rotate(t_dll **stack_a, t_dll **stack_b, int flag);
void	checker_rotate_op(t_dll **stack);

//Swap
void	checker_swap_op(t_dll **stack);
void	checker_swap(t_dll **stack_a, t_dll **stack_b, int flag);

//Push
void	checker_pa(t_dll **stack_a, t_dll **stack_b);
void	checker_pb(t_dll **stack_b, t_dll **stack_a);

//Parsing
t_dll	*checker_get_list_head(char **mtx);
t_dll	*checker_parse_input_string(int ac, char *av);
t_dll	*checker_parse_input_args(int ac, char **av);
t_dll	*checker_parse_input(int ac, char **av);

#endif
