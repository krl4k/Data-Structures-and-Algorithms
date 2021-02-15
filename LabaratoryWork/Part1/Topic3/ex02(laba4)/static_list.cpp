#include "static_list.h"

void init(t_static_list *&list)
{
	list = new t_static_list;
	list->size = 0;
}

void clear(t_static_list *&list)
{
	delete list;
	list = nullptr;
}

bool is_empty(t_static_list *list)
{
	if (!list)
		return true;
	if (list->size == 0)
		return true;
	return false;
}

bool is_full(t_static_list *list)
{
	if (list->size == SIZE)
		return true;
	return false;
}

int size(t_static_list *list)
{
	if (!list)
		return 0;
	return (list->size);
}

void push_back(t_static_list *list, int data)
{
	if (is_full(list))
	{
		std::cout << "List is full" << std::endl;
		return;
	} else
	{
		list->list[list->size] = data;
		list->size++;
	}
}

void push_front(t_static_list *list, int data)
{
	if (is_full(list))
	{
		std::cout << "List is full" << std::endl;
		return;
	}
	if (list->size == 0)
	{
		list->list[list->size] = data;
		list->size++;
	}
	else
	{
		list->size++;
		for (int i = list->size - 1; i > 0; i--)
			list->list[i] = list->list[i - 1];
		list->list[0] = data;
	}
}

void push_before(t_static_list *list, int elem, int data)
{
	if (is_full(list))
	{
		std::cout << "List is full" << std::endl;
		return;
	}
	int i = 0;
	while (i < list->size)
	{
		if (list->list[i] == elem)
			break;
		i++;
	}
	if (i == list->size)
	{
		std::cout << "Elem not found!" << std::endl;
		return;
	}
	list->size++;
	for (int j = list->size - 1; j >= i; j--)
	{
		list->list[j] = list->list[j - 1];
	}
	list->list[i] = data;
}

void push_after(t_static_list *list, int elem, int data)
{
	if (is_full(list))
	{
		std::cout << "List is full" << std::endl;
		return;
	}
	int i = 0;
	while (i < list->size)
	{
		if (list->list[i] == elem)
			break;
		i++;
	}
	if (i== list->size)
	{
		std::cout << "Elem not found!" << std::endl;
		return;
	}
	i++;
	list->size++;
	for (int j = list->size - 1; j >= i; j--)
	{
		list->list[j] = list->list[j - 1];
	}
	list->list[i] = data;
}

void pop_back(t_static_list *list)
{
	if (is_empty(list))
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	list->size--;
}

void pop_front(t_static_list *list)
{
	if (is_empty(list))
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	for (int j = 0; j < list->size; j++)
	{
		list->list[j] = list->list[j + 1];
	}
	list->size--;
}

void	pop_elem(t_static_list *list, int elem)
{
	if (is_empty(list))
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	int i = 0;
	while (i < list->size)
	{
		if (list->list[i] == elem)
			break;
		i++;
	}
	if (i == 0)
	{
		pop_front(list);
		return;
	}
	if (i == list->size)
	{
//		pop_back(list);
		return;
	}
	for (; i < list->size; i++)
	{
		list->list[i] = list->list[i+1];
	}
	list->size--;
}

void pop_before(t_static_list *list, int elem)
{
	if (is_empty(list))
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	int i = 0;
	while (i < list->size)
	{
		if (list->list[i] == elem)
			break;
		i++;
	}
	if (i == 0)
	{
		std::cout << "Before Head elem!" << std::endl;
		return;
	}
	if (i == list->size)
	{
		std::cout << "Elem not found!" << std::endl;
		return;
	}
	i--;
	for (; i < list->size; i++)
	{
		list->list[i] = list->list[i+1];
	}
	list->size--;

}

void pop_after(t_static_list *list, int elem)
{
	if (is_empty(list))
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	int i = 0;
	while (i < list->size)
	{
		if (list->list[i] == elem)
			break;
		i++;
	}
	i++;
	if (i >= list->size)
	{
		std::cout << "Elem not found!" << std::endl;
		return;
	}
	for (; i < list->size; i++)
	{
		list->list[i] = list->list[i+1];
	}
	list->size--;
}


void print_static_list(t_static_list *list)
{
	std::cout << "Static list" << std::endl;
	std::cout << "list size = " << list->size << std::endl;

	for (int i = 0; i < list->size; i++)
	{
		std::cout << list->list[i] << ' ';
	}
	std::cout << std::endl;
}

int		get_index(t_static_list *list, int data)
{
	int i = 0;
	while (i < list->size)
	{
		if (list->list[i] == data)
			return (i);
		i++;
	}
	return (-1);
}

void	push_sort(t_static_list *list, int data)
{
	if (!list)
	{
		std::cout << "List not allocated!" << std::endl;
		return;
	}
	if (is_full(list))
	{
		std::cout << "List is full" << std::endl;
		return;
	}
	if (list->size == 0)
	{
		printf("push front!\n");
		push_front(list, data);
		return;
	}
	int i = 0;
	while (i < list->size)
	{
		if (data < list->list[i])
		{
			push_before(list, list->list[i], data);
			return;
		}
		i++;
	}
	if (i == list->size)
	{
		push_back(list, data);
		return;
	}
}


/*

int main()
{
	t_static_list *staticList = nullptr;
	init(staticList);

	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		push_sort(staticList, i);
//		push_sort(staticList, rand() % 100);
	}

	for (int i = 10; i < 15; ++i)
	{
		push_sort(staticList, i);
//		push_sort(staticList, rand() % 100);
	}

	print_static_list(staticList);

	for (int i = 12; i < 15; ++i)
	{
		pop_elem(staticList, i);
	}

//	for (int i = 20; i > 7; i--)
//	{
//		pop_elem(staticList, i);
//	}
//	pop_elem(staticList, 0);
	print_static_list(staticList);

}
*/
