/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:32:43 by mgalmari          #+#    #+#             */
/*   Updated: 2024/01/16 22:36:40 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*fin;
	t_list	*tmp_fin;
	t_list	*tmp;
	void	*funz;

	if (!lst || !f || !del)
		return (NULL);
	fin = NULL;
	tmp = lst;
	while (tmp)
	{
		funz = f(tmp->content);
		tmp_fin = ft_lstnew(funz);
		if (!tmp_fin)
		{
			ft_lstclear(&fin, del);
			del(funz);
			return (NULL);
		}
		ft_lstadd_back(&fin, tmp_fin);
		tmp = tmp->next;
	}
	return (fin);
}

/* void	del(void *content)
{
	free(content);
}
void	*f(void *content)
{
	int* res;

	res = ft_calloc(1, sizeof(int));
	*res = *(int *)content + 4;
	return(res);
}
int main()
{
	t_list *lst;
	t_list *tmp;
	int i = 0;
	int s[] = {1, 3, 5, 7};
	int *z;

	lst = NULL;
	while (i < 4)
	{
		z = ft_calloc(1, sizeof(int));
		*z = s[i];
		t_list *new = ft_lstnew(z);
		ft_lstadd_back(&lst, new);
		i++;
	}
	tmp = lst;
	while (tmp)
	{
		printf("%i\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
	t_list* tmp2;
	tmp = ft_lstmap(lst, f, del);
	tmp2 = tmp;
	while (tmp)
	{
		printf("%i\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&lst, del);
	ft_lstclear(&tmp2, del);

	return (0);
}





 */