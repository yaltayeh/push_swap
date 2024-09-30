#include "libft.h"

t_list	*ft_lstpop_back(t_list **lst)
{
	t_list	*head;
	t_list	*tmp;

	head = *lst;
	while (head && head->next && head->next->next)
		head = head->next;
	if (!head->next)
		return ((*lst = NULL), head);
	tmp = head->next;
	return ((head->next = NULL), tmp);
}