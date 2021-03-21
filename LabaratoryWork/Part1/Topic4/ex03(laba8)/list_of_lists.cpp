// CLion
// Created by Foster Grisella on 3/21/21 15:23.
//

#include "list_of_lists.h"

void init_list_of_lists(t_list_of_lists *&list)
{
	list = new t_list_of_lists;
	list->size = 0;
	list->lists_head = nullptr;
}


bool is_empty_list_of_lists(t_list_of_lists *list)
{
	if (list)
	{
		if (list->size == 0)
			return true;
	}
	return false;
}

void			clear_list_of_lists(t_list_of_lists *&listOfLists)
{
	if (!listOfLists)
		return;
	t_node_list_of_lists *temp = listOfLists->lists_head;
	t_node_list_of_lists *next;

	while (temp)
	{
		next = temp->next;
//		if (temp->head)
			clear(temp->head);
		delete temp;
		temp = next;
	}
	listOfLists->size = 0;
	delete listOfLists;
	listOfLists = nullptr;
}

t_node_list_of_lists	*last_list_of_lists(t_list_of_lists *listOfLists)
{
	t_node_list_of_lists *temp = listOfLists->lists_head;
	if(!temp)
		return (nullptr);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_node_list_of_lists					*new_list_of_lists(t_list_of_lists *main_List)
{
	t_node_list_of_lists *listOfLists = new t_node_list_of_lists;
	t_list *list;
	init(list);
	listOfLists->head = list;
	listOfLists->next = nullptr;
	listOfLists->index = main_List->size;
	return listOfLists;
}

void			push_back_list_of_lists(t_list_of_lists *listOfLists)
{
	if(listOfLists)
	{
		if(listOfLists->lists_head)
			last_list_of_lists(listOfLists)->next = new_list_of_lists(listOfLists);
		else
			listOfLists->lists_head = new_list_of_lists(listOfLists);
		listOfLists->size++;
	}
}

t_node_list_of_lists *getBeforeLast_lists(t_node_list_of_lists *temp)
{
	if(!temp->next)
		return nullptr;
	while (temp->next->next)
	{
		temp = temp->next;
	}
	return temp;
}

void			pop_back_list_of_lists(t_list_of_lists *listOfLists)
{
	if (!listOfLists || !listOfLists->lists_head)
		return;
	t_node_list_of_lists *temp = getBeforeLast_lists(listOfLists->lists_head);
	if(temp == nullptr)
	{
//		if (temp->head)
//			clear(temp->head);
		clear(listOfLists->lists_head->head);
		delete listOfLists->lists_head;
		listOfLists->lists_head = nullptr;
	}
	else
	{
		clear(temp->next->head);
		delete temp->next;
		temp->next = nullptr;
	}
	listOfLists->size--;
}

void			printList_of_list(t_list_of_lists *listOfLists)
{
	t_node_list_of_lists *temp = listOfLists->lists_head;
	while (temp)
	{
		std::cout << "index = " << temp->index<< std::endl;
		list_print(temp->head);
		std::cout << "----------------------------------------------------" << std::endl;
		temp = temp->next;
	}
}

void			push_back_to_list(t_list_of_lists *listOfLists, int index, const std::string &data)
{
	if (!listOfLists || !listOfLists->lists_head || index > listOfLists->size - 1)
		return;

	int i = 0;
	t_node_list_of_lists *temp = listOfLists->lists_head;
	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}
	push_back(temp->head, new_node(data.c_str()));
}

void			pop_back_in_list(t_list_of_lists *listOfLists, int index)
{
	if (!listOfLists || !listOfLists->lists_head || index > listOfLists->size - 1)
		return;
	int i;
	t_node_list_of_lists *temp = listOfLists->lists_head;
	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}
	pop_back(temp->head);
}

t_t_node *getElem_lists(t_list_of_lists *listOfLists, const std::string &elem)
{
	t_node_list_of_lists *temp = listOfLists->lists_head;
	t_t_node *temp_node;
	while (temp)
	{
		temp_node = temp->head->head->next;
		if (temp_node)
		{
			while (temp_node)
			{
				if (temp_node->data)
				{
					if (std::strcmp(temp_node->data ,elem.c_str()) == 0)
						return temp_node;
				}
				temp_node = temp_node->next;
			}
		}
		temp = temp->next;
	}
	return nullptr;
}