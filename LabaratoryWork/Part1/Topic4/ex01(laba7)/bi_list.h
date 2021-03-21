#ifndef TEST_BI_LIST_H
#define TEST_BI_LIST_H
#include <iostream>
#include <cstring>


typedef struct s_node
{
	std::string data;
	struct s_node *next;
	struct s_node *prev;
}               t_node;

typedef struct		s_dbllist
{
	int     size;
	t_node	*head;
	t_node	*tail;
}				    t_dbllist;

void	init(t_dbllist *&list);
std::string		front(t_dbllist *list);
std::string	back(t_dbllist *list);
int 	size(t_dbllist *list);

/*!
* @param 2 -elem
* @param 3 -data
*/
void	push_before(t_dbllist *list, const std::string &elem, const std::string &data);

/*!
* @param 2 -elem
* @param 3 -data
*/
void	push_after(t_dbllist *list, const std::string &elem, const std::string &data);
void	push_back(t_dbllist *list, const std::string &data);
void	push_front(t_dbllist *list, const std::string &data);
void	insert(t_dbllist *list, int index, const std::string &data);

void	pop_back(t_dbllist *list);
void	pop_front(t_dbllist *list);
void	deleteAt(t_dbllist *list, int index);
void	deleteElem(t_dbllist *list, const std::string &elem);
void	clear(t_dbllist *&list);

int		getIndex(t_dbllist *list, const std::string &data);
//t_node	*getElem(t_dbllist *list, int index);

t_node	*getElem(t_dbllist *list, t_node *node, const std::string &elem, t_node*(iter)(t_node *));


void printList(t_node *node, t_node *(iter)(t_node*), int size);
t_node *iterator_list(t_node *node);
t_node *reverse_iterator_list(t_node *node);

//void printList(t_dbllist *list);
//void printReverseList(t_dbllist *list);

#endif