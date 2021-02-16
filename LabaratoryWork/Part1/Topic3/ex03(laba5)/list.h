//
// Created by Foster Grisella on 2/16/21.
//

#ifndef TEST_LIST_H
#define TEST_LIST_H
#include <iostream>
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

void	print_list(t_list *list);



#endif //TEST_LIST_H
