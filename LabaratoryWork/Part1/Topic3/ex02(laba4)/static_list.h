#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include <iostream>

#define SIZE 10

//#ifdef INT
typedef struct	s_static_list
{
	int list[SIZE];
	int size;
}				t_static_list;

void	init(t_static_list *&list);
void	clear(t_static_list *&list);

void	push_sort(t_static_list *list, int data);

void	push_back(t_static_list *list, int data);
void	push_front(t_static_list *list, int data);
/*!
* \param2 data the element to which the addition occurs
* \param3 DATA for a new item
*/
void	push_before(t_static_list *list, int elem, int data);
void	push_after(t_static_list *list, int elem, int data);

void	pop_back(t_static_list *list);
void	pop_front(t_static_list *list);

void	pop_elem(t_static_list *list, int data);
void	pop_before(t_static_list *list, int data);
void	pop_after(t_static_list *list, int data);

void	print_static_list(t_static_list *list);
int		size(t_static_list *list);

bool	is_empty(t_static_list *list);
bool	is_full(t_static_list *list);

int		get_index(t_static_list *list, int data);
//#endif

#endif //TEST_ARRAY_LIST_H
