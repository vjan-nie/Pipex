/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjan-nie <vjan-nie@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:10:47 by vjan-nie          #+#    #+#             */
/*   Updated: 2025/02/05 19:23:52 by vjan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list -> content = content;
	new_list -> next = NULL;
	return (new_list);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
    int		number = 55;
    t_list	*list = ft_lstnew(&number);

    printf("Content: %d\n", *(int *)list->content);
	printf("Next list: %p\n", (void *)list->next);
    free(list);

    return (0);
} */