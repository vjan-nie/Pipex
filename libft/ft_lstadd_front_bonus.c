/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:01:12 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/05 18:13:13 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new -> next = *lst;
	*lst = new;
	return ;
}
/* 
#include <stdio.h>
#include <stdlib.h>
// First, we give as an adress to the new's next node 
// the adress pointed by
// the POINTER TO THE FIRST ELEMENT (*lst). After this, we update
// the adress of the POINTER TO THE FIRST ELEMENT setting it 
// as the new element's adress.
int 	main(void)
{
	t_list 	*list = NULL;
	int		a = 42;
	int		b = 36;
	int		c = 99;

	t_list *root = ft_lstnew(&a);
	t_list *node2 = ft_lstnew(&b);
	t_list *node3 = ft_lstnew(&c);

	ft_lstadd_front(&list, root);
	ft_lstadd_front(&list, node2);
	ft_lstadd_front(&list, node3);

	while (list)
	{
		printf("%d -> ", *(int *) list -> content);
		list = list -> next;
	}
	printf("end of list(NULL)\n");

	free(root);
	free(node2);
	free(node3);

	return (0);
} */