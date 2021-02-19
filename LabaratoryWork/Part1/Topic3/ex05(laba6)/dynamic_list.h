#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H
#include "iostream"
typedef struct s_node
{
	char *data;
	struct s_node *next;
}				t_node;

typedef struct s_list
{
	t_node *head;
	int 	size;
}			t_list;


//t_list			*ft_lstnew(int data);
void init(t_list *&list);

int				size(t_list *temp);

/*!
 *
 * @param temp
 * @return link last node in list
 */
t_node			*last(t_list *temp);

t_node			*new_node(const char *data);
void			push_before(t_list *list, const char *elem, t_node *new_node);
void			push_after(t_list *list, const char *elem, t_node *new_node);
void			push_front(t_list *list, t_node *new_node);
void			push_back(t_list *list, t_node *new_node);

void			clear(t_list **lst);
void            list_print(t_list *lst);

void            pop_elem(t_list	*list, const char *elem);
void            pop_back(t_list *list);
void            pop_front(t_list	*list);



#endif