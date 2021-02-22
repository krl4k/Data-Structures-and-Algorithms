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
		return true;
	if(list->size == 1)
		return true;
	return false;
}

bool is_full(t_list *list)
{
	if(!list)
		return false;
	if(list->size == SIZE + 1)
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

/*!
**  \return index of last element of list
*/
static int find_empty_index(t_list *list)
{
	int temp = list->node[0].next;
	int prev = 0;
	//найти ячейку (последняя) которая ссылается на -1
	while (temp != -1)
	{
		prev = temp;
		temp = list->node[temp].next;
	}
	return (prev);
}

/*!
 *
 * @param list
 * @param index
 * @return empty node (for push in it)
 */
static int find_empty_node(t_list *list, int index)
{
	int i = 1;
	//найти пустую ячейку
	while (i < SIZE)
	{
		if(list->node[i].next == -1 && i != index)
			return i;
		i++;
	}
	return (i);
}

void push_back(t_list *list, std::string string)
{
	if(is_full(list))
	{
		std::cout << "List is full!" << std::endl;
		return;
	}
	if(list->size == 1)
	{
		list->node[0].next = 1;
		list->node[1].data = string;
	}
	else
	{
		int last_node = find_empty_index(list);
		int empty_node_index = find_empty_node(list, last_node);
		list->node[last_node].next = empty_node_index;
		list->node[empty_node_index].data = string;
		list->node[empty_node_index].next = -1;
	}
	list->size++;
}

void push_front(t_list *list, std::string string)
{
	if(is_full(list))
	{
		std::cout << "List is full!" << std::endl;
		return;
	}
	if(list->size == 1)
	{
		list->node[0].next = 1;
		list->node[1].data = string;
	}
	else
	{
		int old_head = list->node[0].next;
		int empty_node = find_empty_node(list, find_empty_index(list));
		list->node[empty_node].data = string;
		list->node[empty_node].next = old_head;
		list->node[0].next = empty_node;
	}
	list->size++;
}

void	push_before(t_list *list, std::string elem, std::string data)
{
	if(is_full(list))
	{
		std::cout << "List is full!" << std::endl;
		return;
	}
	if (is_empty(list))
	{
		std::cout << "Elem not found!" << std::endl;
		return;
	}
	int i = 1;
	int temp = list->node[0].next;
	int before_new;
	while(temp != -1)
	{
		if(list->node[temp].data == elem)
			break;
		i++;
		before_new = temp;
		temp = list->node[temp].next;
	}
	if (i == list->size)
	{
		std::cout << "Elem not in list!" << std::endl;
		return;
	}
	if(i == 1)
	{
		push_front(list, data);
		return;
	}
	int new_node = find_empty_node(list, find_empty_index(list));
	list->node[new_node].data = data;
	list->node[new_node].next = temp;
	list->node[before_new].next = new_node;
	list->size++;
}

void	push_after(t_list *list, std::string elem, std::string data)
{
	if(is_full(list))
	{
		std::cout << "List is full!" << std::endl;
		return;
	}
	if (is_empty(list))
	{
		std::cout << "Elem not found!" << std::endl;
		return;
	}
	int i = 1;
	int temp = list->node[0].next;
	while(temp != -1)
	{
		if(list->node[temp].data == elem)
			break;
		temp = list->node[temp].next;
		i++;
	}
	if (i == list->size)
	{
		std::cout << "Elem not in list!" << std::endl;
		return;
	}
	int new_node = find_empty_node(list, find_empty_index(list));
	list->node[new_node].data = data;
	list->node[new_node].next = list->node[temp].next;
	list->node[temp].next = new_node;
	list->size++;
}

void pop_elem(t_list *list, std::string elem)
{
	if (is_empty(list))
	{
		std::cout << "List is empty!" << std::endl;
		return;
	}
	int i = 1;
	int before_deleted;
	int temp = list->node[0].next;
	while (temp != -1)
	{
		if (list->node[temp].data == elem)
			break;
		before_deleted = temp;
		temp = list->node[temp].next;
		i++;
	}
	if (i == list->size)
	{
		std::cout << "Elem not in list!" << std::endl;
		return;
	}
	if (i == 1)
	{
		pop_front(list);
		return;
	}
	list->node[before_deleted].next = list->node[temp].next;
	list->node[temp].next = -1;
	list->size--;
}

void pop_front(t_list *list)
{
	if (is_empty(list))
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	int first_node = list->node[0].next;
	int after_first_node = list->node[first_node].next;

	list->node[0].next = after_first_node;
	list->node[first_node].next = -1;
	list->size--;
}

void pop_back(t_list *list)
{
	if (is_empty(list))
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	int i = 1;
	int temp = list->node[0].next;
	while (i < list->size - 2)
	{
		temp = list->node[temp].next;
		i++;
	}
	if (i == 1)
		list->node[temp].next = -1;
	else
		list->node[temp].next = -1;
	list->size--;
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
	while (temp != -1)
	{
		std::cout << list->node[temp].data << "  ";
		temp = list->node[temp].next;
	}
	std::cout << "\n--------------------------" << std::endl;
}

int get_index(t_list *list, std::string elem)
{
	int i = 1;
	int temp;
	temp = list->node[0].next;
	while (temp != -1)
	{
		if (list->node[temp].data == elem)
			return (i);
		temp = list->node[temp].next;
		i++;
	}
	return (-1);
}



/*

int main()
{
	t_list *list;
	init(list);
	for (int i = 0; i < 6; ++i)
	{
		if (i % 2 == 0)
			push_back(list, std::to_string(i));
		else
			push_front(list, std::to_string(i));
	}

	print_list(list);

	for (int i = 0; i < 1; ++i)
	{
		pop_back(list);
	}
	print_list(list);
	return 0;
	pop_elem(list, "123");

	int temp = list->node[0].next;
	int i = 1;
	std::cout << "list[" << 0 << "] = " << list->node[0].data << ", next = " << list->node[0].next << std::endl;
	while (temp != -1)
	{
		std::cout << "list[" << temp << "] = " << list->node[temp].data << ", next = " << list->node[temp].next
				  << std::endl;
		temp = list->node[temp].next;
		i++;
	}

//		for (int i = 0; i < SIZE; ++i)
//		{
//			std::cout << "list[" << i << "] = " << list->node[i].data << ", next = " << list->node[i].next << std::endl;
//		}

	clear(list);

//	print_list(list);
}
*/
