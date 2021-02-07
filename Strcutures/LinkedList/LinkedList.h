#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

typedef struct	s_list
{
	int 			data;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(int data);
int				ft_lstsize(t_list *temp);
t_list			*ft_lstlast(t_list *temp);
void			ft_lstadd_front(t_list **lst, t_list *newElem);
void			ft_lstadd_back(t_list **lst, t_list *newElem);
void			ft_lstclear(t_list **lst);
void            ft_lstprint(t_list *lst);
void            ft_lstpopBack(t_list* &lst);
void            ft_lstpopFront(t_list* &head);
void			mergeSort(t_list  *&head);

#endif