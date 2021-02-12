#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#define SIZE 100

typedef struct	s_static_list
{
	int list[SIZE];
	int size;
}				t_static_list;

void	init(t_static_list *&list);
void	clear(t_static_list *&list);

void	push_back(t_static_list *list, int data);
void	push_front(t_static_list *list, int data);
void	push_before(t_static_list *list, int index, int data);
void	push_after(t_static_list *list, int index, int data);

void	pop_back(t_static_list *list, int index);
void	pop_front(t_static_list *list, int index);
void	pop_before(t_static_list *list, int index);
void	pop_after(t_static_list *list, int data);

void	print_static_list(t_static_list *list);
int		size(t_static_list *list);

bool	is_empty(t_static_list *list);
bool	is_full(t_static_list *list);

#endif //TEST_ARRAY_LIST_H
