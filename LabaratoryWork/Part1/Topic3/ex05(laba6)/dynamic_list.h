#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H
#include <iostream>
#include <cstring>
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


/*!
 *
 * @param list - list address
 * @warning be sure to clean after use
 */
void init(t_list *&list);
bool is_empty(t_list *list);

int				size(t_list *list);

/*!
 *
 * @param temp
 * @return link last node in list
 */
t_node			*last(t_list *temp);

/*!
 *
 * @param data - for new_node
 * @return new_node for list
 */
t_node			*new_node(const char *data);

void			push_before(t_list *list, const char *elem, t_node *new_node);
void			push_after(t_list *list, const char *elem, t_node *new_node);
void			push_front(t_list *list, t_node *new_node);
void			push_back(t_list *list, t_node *new_node);
void			clear(t_list *&list);
void            list_print(t_list *lst);

void            pop_elem(t_list	*list, const char *elem);
void            pop_back(t_list *list);
void            pop_front(t_list	*list);
int				get_index(t_list *list, const char *elem);

/*!
 *
 * @param list - pointer to the list from which to pop the element
 * @param stack - pointer to the stack into which to push the item
 */
void			pop_back_to_stack(t_list *list, t_list *stack);

/*!
 *
 * @param list - pointer to the list from which to pop the element
 * @param stack - pointer to the stack into which to push the item
 */
void			pop_front_to_stack(t_list *list, t_list *stack);

/*!
 *
 * @param list - pointer to the list from which to pop the element
 * @param stack - pointer to the stack into which to push the item
 * @param data - information about the item to pop
 */
void			pop_elem_to_stack(t_list *list, t_list *stack, const char *data);

#endif