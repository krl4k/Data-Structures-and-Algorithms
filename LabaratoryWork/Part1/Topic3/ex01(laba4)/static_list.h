#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#define SIZE 10

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
* \param3 data for a new item
*/
void	push_before(t_static_list *list, int elem, int data);
void	push_after(t_static_list *list, int elem, int data);

void	pop_back(t_static_list *list);
void	pop_front(t_static_list *list);


void	pop_before(t_static_list *list, int index);
void	pop_after(t_static_list *list, int data);

void	print_static_list(t_static_list *list);
int		size(t_static_list *list);

bool	is_empty(t_static_list *list);
bool	is_full(t_static_list *list);

int		get_index(t_static_list *list, int data);

#endif //TEST_ARRAY_LIST_H
