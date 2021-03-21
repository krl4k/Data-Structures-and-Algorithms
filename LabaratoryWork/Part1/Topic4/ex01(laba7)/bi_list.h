#ifndef TEST_BI_LIST_H
#define TEST_BI_LIST_H
#include <iostream>
#include <cstring>

typedef struct s_node
{
	int data;
	struct s_node *next;
	struct s_node *prev;
}               t_node;

typedef struct	s_dbllist
{
	int     size;
	t_node	*head;
	t_node	*tail;
}				    t_dbllist;

void	init(t_dbllist *&list);
int		front(t_dbllist *list);
int		back(t_dbllist *list);
int		size(t_dbllist *list);
void	push_before(t_dbllist *list, int elem, t_node *new_node);
void	push_after(t_dbllist *list, int elem, t_node *new_node);
void	push_back(t_dbllist *list, int data);
void	push_front(t_dbllist *list, int data);
void	insert(t_dbllist *list, int index, int data);

void	pop_back(t_dbllist *list);
void	pop_front(t_dbllist *list);
void	deleteAt(t_dbllist *list, int index);
void	clear(t_dbllist *&list);

int		getIndex(t_dbllist *list, int data);
t_node	*getElem(t_dbllist *list, int index);

void printList(t_dbllist *list);
void printReverseList(t_dbllist *list);

#endif