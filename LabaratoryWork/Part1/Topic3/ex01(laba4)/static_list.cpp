#include <list>
#include <iostream>
#include "static_list.h"

void	init(t_static_list *&list)
{
	list = new t_static_list;
	list->size = 0;
}

bool	is_empty(t_static_list *list);

bool	is_full(t_static_list *list)
{
	if (list->size == SIZE)
		return true;
	return false;
}


int		size(t_static_list *list)
{
	if (!list)
		return 0;
	return (list->size);
}

void	push_back(t_static_list *list, int data)
{
	if (is_full(list))
	{
		std::cout << "List is full" << std::endl;
		return;
	}
	else
	{
		list->list[list->size] = data;
		list->size++;
	}
}

void	push_front(t_static_list *list, int data)
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
//		for (int i = 1; i < list->size; i++)
//		{
//			list->list[list->size - i] = list->list[list->size - 1 - i];
//		}
		for (int i = list->size; i > 1; i++)
		{
			list->list[i] = list->list[i - 1];
		}
		list->list[0] = data;
	}
}


/*!
* \param2 data the element to which the addition occurs
* \param data for a new item
*/

void	push_before(t_static_list *list, int elem, int data)
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
//	if (i == list->size)
//	{
//		push_back(list, data);
//		return;
//	}
//	else if (i == 0)
//	{
//		push_front(list, data);
//		return;
//	}

	{
		printf("tut\n");
		list->size++;
		if (list->size == SIZE)
			return;
		int j = list->size;
		for (int k = i; k < list->size - 1; k++)
		{
			list->list[k + 1] = list->list[k];
		}
//		for (; j > i; j--)
//		{
//			list->list[j] = list->list[j - 1];
//		}
		list->list[i] = data;
	}
}
void	push_after(t_static_list *list, int index, int data);

void	pop_back(t_static_list *list, int index);
void	pop_front(t_static_list *list, int index);
void	pop_before(t_static_list *list, int index);
void	pop_after(t_static_list *list, int data);

void	clear(t_static_list *&list)
{
	delete list;
	list = nullptr;
}
void	print_static_list(t_static_list *list)
{
	std::cout << "Static list" << std::endl;
	for (int i = 0; i < list->size; i++)
	{
		std::cout << list->list[i] << ' ';
	}
	std::cout << std::endl;
}


int main()
{
	t_static_list *staticList = nullptr;
	init(staticList);

//	push_back(staticList, 1);
//	push_back(staticList, 2);

	for (int i = 0; i <4;)
	{
		push_back(staticList, i);
		i++;
	}
	print_static_list(staticList);

	push_before(staticList, 3, 666);
	push_before(staticList, 3, 666);
	push_before(staticList, 3, 666);
	push_before(staticList, 3, 666);
	push_before(staticList, 3, 666);
	push_before(staticList, 3, 666);
	printf("size = %d\n", staticList->size);
//	push_before(staticList, 3, 666);
//	push_before(staticList, 3, 666);
//	for (int i = 5; i < 10;)
//	{
//		push_front(staticList, i);
//		i++;
//	}
//	push_front(staticList, 1000);

//	printf("size = %d\n", staticList->size);
	print_static_list(staticList);
}
