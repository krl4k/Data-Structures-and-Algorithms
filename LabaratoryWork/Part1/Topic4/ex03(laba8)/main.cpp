// CLion
// Created by Foster Grisella on 3/21/21 15:23.
//
#include "list_of_lists.h"

int main()
{
	t_list_of_lists *listOfLists = nullptr;
	init_list_of_lists(listOfLists);

	for (int i = 0; i < 3; ++i) {
		push_back_list_of_lists(listOfLists);
	}
//	exit(0);
	t_node_list_of_lists *temp = listOfLists->lists_head;
	for (int i = 0; i < 5; ++i) {
		push_back(temp->head, new_node("lol"));
	}
	temp = temp->next;
	for (int i = 0; i < 7; ++i) {
		push_back(temp->head, new_node("haha"));
	}
	temp = temp->next;
	for (int i = 0; i < 3; ++i) {
		push_back(temp->head, new_node("puet"));
	}
	printList_of_list(listOfLists);
	pop_back_list_of_lists(listOfLists);
	pop_back_list_of_lists(listOfLists);
	pop_back_list_of_lists(listOfLists);
	clear_list_of_lists(listOfLists);
}

