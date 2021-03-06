
#ifndef TEST_LIST_H
#define TEST_LIST_H
#include <iostream>
#include <cstring>

#define SIZE 10

typedef struct s_node
{
    std::string data;
    int next;
}               t_node;

typedef struct s_list
{
    t_node  node[SIZE + 1];
    int     size;
}               t_list;

void	init(t_list *&list);
void	clear(t_list *&list);

void	push_sort(t_list *list, std::string data);

void	push_back(t_list *list, std::string data);
void	push_front(t_list *list, std::string data);

/*!
 *
 * @param list
 * @param elem before push
 * @param data to push
 */
void	push_before(t_list *list, std::string elem, std::string data);

/*!
 *
 * @param list
 * @param elem after push
 * @param data to push
 */
void	push_after(t_list *list, std::string elem, std::string data);

void	pop_elem(t_list *list, std::string elem);
void	pop_front(t_list *list);
void	pop_back(t_list *list);

void	print_list(t_list *list);

int get_index(t_list *list, std::string elem);

#endif //TEST_LIST_H
