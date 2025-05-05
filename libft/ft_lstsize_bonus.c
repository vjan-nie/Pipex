/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:33:56 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/05 19:22:42 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		lst_count;

	if (!lst)
		return (0);
	temp = lst;
	lst_count = 0;
	while (temp)
	{
		temp = temp -> next;
		lst_count++;
	}
	return (lst_count);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*list = NULL;
	int		a = 10;
	int		b = 20;
	int		c = 30;

	t_list *root = ft_lstnew(&a);
	t_list *node2 = ft_lstnew(&b);
	t_list *node3 = ft_lstnew(&c);
	
	ft_lstadd_front(&list, node3);
	ft_lstadd_front(&list, node2);
	ft_lstadd_front(&list, root);

	printf("size of list: %d\n", ft_lstsize(list));
	return (0);
} */