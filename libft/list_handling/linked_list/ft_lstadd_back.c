/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:31:16 by mgalmari          #+#    #+#             */
/*   Updated: 2024/01/08 15:57:02 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!lst || !*lst)
	{
		*lst = new;
		return ;
	}
	t = *lst;
	ft_lstlast(t)->next = new;
}

/* int main()
{
	char s[] = "ciao";
	char st[] = "cacca";
 	t_list *lst = ft_lstnew(s);
	t_list *new = ft_lstnew(st);
	t_list *t = lst;
	ft_lstadd_back(&lst, new);
	while (t->next)
		t = t->next;
	printf("%p\n", t);
	printf("%p", new);
	return (0);
} */
