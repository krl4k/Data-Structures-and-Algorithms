// CLion
// Created by Foster Grisella on 3/21/21 15:23.
//


#ifndef TEST_LIST_OF_LISTS_H
#define TEST_LIST_OF_LISTS_H

#include "list_of_lists.h"
#include "dynamic_list.h"

typedef struct s_node_list_of_lists
{
	int							index;
	t_list						*head;
	struct s_node_list_of_lists	*next;
}				t_node_list_of_lists;


typedef struct s_list_of_lists
{
	t_node_list_of_lists 	*lists_head;
	int						size;
}			t_list_of_lists;


void init_list_of_lists(t_list_of_lists *&list);
bool is_empty_list_of_lists(t_list_of_lists *list);

/*!
 *
 * @param temp
 * @return link last list of  list_of_list
 */
t_node_list_of_lists	*last_list_of_lists(t_list_of_lists *temp);
t_node_list_of_lists					*new_list_of_lists();




void			clear_list_of_lists(t_list_of_lists *&list);
void			push_back_list_of_lists(t_list_of_lists *listOfLists);
void			push_back_to_list(t_list_of_lists *listOfLists, int index, const std::string &data);
void			pop_back_list_of_lists(t_list_of_lists *listOfLists);
void			pop_back_in_list(t_list_of_lists *listOfLists, int index);
void			printList_of_list(t_list_of_lists *listOfLists);
t_node			*getElem_lists(t_list_of_lists *listOfLists, const std::string &elem);

#endif //TEST_LIST_OF_LISTS_H
