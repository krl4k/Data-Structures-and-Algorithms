#include <list>
#include <iostream>
#include "static_list.h"

void	init(t_static_list *&list)
{
	list = new t_static_list;
	list->size = 0;
}
bool	is_empty(t_static_list *list);

bool	is_full(t_static_list *list);


int		size(t_static_list *list)
{
	if (!list)
		return 0;
	return (list->size);
}

void	push_back(t_static_list *list, int data);
void	push_front(t_static_list *list, int data);
void	push_before(t_static_list *list, int index, int data);
void	push_after(t_static_list *list, int index, int data);

void	pop_back(t_static_list *list, int index);
void	pop_front(t_static_list *list, int index);
void	pop_before(t_static_list *list, int index);
void	pop_after(t_static_list *list, int data);

void	clear(t_static_list *&list);
void	print_static_list(t_static_list *list);



int main()
{

}
