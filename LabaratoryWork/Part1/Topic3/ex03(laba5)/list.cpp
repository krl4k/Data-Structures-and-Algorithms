#include "list.h"

void init(t_list *&list)
{
	list = new t_list;
	list->node[0].data = "head_node";
	list->node[0].next = 0;
	list->size = 1;
	for (int i = 1; i < SIZE; i++)
	{
		list->node[i].next = -1;
	}
}

bool is_empty(t_list *list)
{
	if(!list)
	{
		return false;
	}
	if(list->size == 1)
		return true;
	return false;
}

bool is_full(t_list *list)
{
	if(!list)
		return false;
	if(list->size == SIZE)
		return true;
	return false;
}

void clear(t_list *&list)
{
	for (int i = 0; i < list->size; ++i)
	{
		list->node[i].next = -1;
	}
	delete list;
	list = nullptr;
}

static void push_first(t_list *list, std::string string)
{
	list->node[0].next = 1;
	list->node[1].data = string;
	list->node[1].next = 2;
	list->size = 2;
}

void push_back(t_list *list, std::string string)
{
	if(is_full(list))
		std::cout << "List is full!" << std::endl;
	else if(is_empty(list))
		push_first(list, string);
	else
	{
		int i = 1;
		for (; i < list->size; i++)
			if(list->node[i].next == -1)
				break;
		list->node[list->size].data = string;
		list->node[list->size].next = i + 1;
		list->size++;
	}
}

void push_front(t_list *list, std::string string)
{
	if(is_full(list))
		std::cout << "List is full!" << std::endl;
	else if(is_empty(list))
		push_first(list, string);
	else
	{
		int i = 1;
		for (; i < list->size; i++)
		{
			if(list->node[i].next == -1)
				break;
		}
		list->node[list->size].data = string;
		list->node[list->size].next = list->node[0].next;
		list->node[0].next = i;
		list->size++;
	}
}

void print_list(t_list *list)
{
	std::cout << "----------LIST INFO-------" << std::endl;
	std::cout << "List size = " << list->size << std::endl;
	if(is_empty(list))
		return;
	int i = 1;
	int temp;
	temp = list->node[0].next;
	while (i < list->size && temp != -1)
	{
		std::cout << list->node[temp].data << " ";
		temp = list->node[temp].next;
		i++;
	}
	std::cout << "\n--------------------------" << std::endl;
}

int main()
{
	t_list *list;
	init(list);
	//    for (int i = 0; i < 5; ++i) {
	push_back(list, "lol");
	push_back(list, "lol1");
	push_back(list, "lol2");
	push_back(list, "lol3");

	push_front(list, "pop2");
	push_front(list, "pop3");
	//    }

	for (int i = 0; i < list->size; ++i)
	{
		std::cout << "list[" << i << "] = " << list->node[i].data << ", next = " << list->node[i].next << std::endl;
//		std::cout << "list[" << i << "] = " << list->node[i].next << std::endl;
	}


	print_list(list);
}