#include "bi_list.h"

void init(t_dbllist *&list) {
	list = new t_dbllist;
	list->tail = nullptr;
	list->head = nullptr;
	list->size = 0;
}

std::string front(t_dbllist *list) {
//	if(list) {
//		if(list->tail)
			return (list->head->data);
//	}
}

std::string back(t_dbllist *list) {
//	if(list) {
//		if(list->tail)
			return (list->tail->data);
//	}
}

template<typename T>
t_node *createElem(T data)
{
	t_node *newElem = new t_node;
	newElem->data = data;
	newElem->next = nullptr;
	newElem->prev = nullptr;
	return newElem;
}

int size(t_dbllist *list) {
	if(list->head)
		return ((list)->size);
	return 0;
}

void push_back(t_dbllist *list, const std::string & data) {
	if(!list)
		return;
	t_node *newElem = createElem(data);
	if(size(list) == 0)
	{
		list->head = newElem;
		list->tail = list->head;
	}
	else
	{
		newElem->prev = (list)->tail;
		(list)->tail->next = newElem;
		(list)->tail = newElem;
		list->tail->next = list->head;
		list->head->prev = list->tail;
	}
	list->size++;
}

void push_front(t_dbllist *list, const std::string & data) {
	if(!list)
		return;
	t_node *newElem = createElem(data);
	if(size(list) == 0)
	{
		list->head = newElem;
		list->tail = list->head;
	}
	else {
		newElem->next = list->head;
		list->head->prev = newElem;
		list->head = newElem;
		list->head->prev = list->tail;
//		newElem->prev = list->tail;
	}
	(list)->size++;
}

void pop_back(t_dbllist *list) {
	if(!list)
		return;
	if(size(list) > 0) {
		t_node *tmp = list->tail;
		list->tail = list->tail->prev;
		if(list->tail)
			list->tail->next = nullptr;
		if(tmp == list->head)
			list->head = nullptr;
		delete tmp;
		list->size--;
	}
}

void pop_front(t_dbllist *list) {
	if(!list)
		return;
	if(size(list) > 0) {
		t_node *tmp = list->head;
		list->head = list->head->next;
		if(list->head)
			list->head->prev = nullptr;
		if(tmp == list->tail)
			list->tail = nullptr;
		delete tmp;
		list->size--;
	}

}


void clear(t_dbllist *&list) {
	if(!list)
		return;
	t_node *tmp = list->head;
	t_node *next = nullptr;
	while (tmp) {
		next = tmp->next;
		delete tmp;
		tmp = next;
	}
	delete list;
	list = nullptr;
}

int getIndex(t_dbllist *list, const std::string & data) {
	int index = 0;
	t_node *tmp = list->head;
	while (tmp) {
		if(tmp->data == data)
			return index;
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

void printList(t_dbllist *list) {
	if (!list)
		return;
	std::cout << "list(straight) = ";
	t_node *head = list->head;
	while (head) {
		std::cout << head->data << ' ';
		head = head->next;
	}
	std::cout << '\n';
}

void printReverseList(t_dbllist *list) {
	if (!list)
		return;
	std::cout << "list(reverse)  = ";
	t_node *head = list->tail;
	while (head) {
		std::cout << head->data << ' ';
		head = head->prev;
	}
	std::cout << '\n';
}

t_node *getElem(t_dbllist *list, int index) {
	t_node *tmp;
	int i;
	if(index > size(list))
		return nullptr;
	if(index > (size(list) / 2) + 1) {
		tmp = list->tail;
		i = size(list) - 1;
		while (tmp) {
			if(i == index)
				return tmp;
			tmp = tmp->prev;
			i--;
		}
	} else {
		tmp = list->head;
		i = 0;
		while (tmp && i <= index) {
			if(i == index)
				return tmp;
			tmp = tmp->next;
			i++;
		}
	}
	return nullptr;
}

void insert(t_dbllist *list, int index, const std::string & data) {
	if(!list || index > size(list) || index < 0)
		return;
	if(index >= size(list)) {
		push_back(list, data);
	} else if(index == 0) {
		push_front(list, data);
	} else {
		t_node *newElem = createElem(data);
		t_node *tmp = getElem(list, index);
		newElem->next = tmp;
		newElem->prev = tmp->prev;
		tmp->prev->next = newElem;
		tmp->prev = newElem;
		list->size++;
	}
}

void deleteAt(t_dbllist *list, int index)
{
	if(!list || index >= size(list) || index < 0)
		return;
	if(index == size(list) - 1) {
		pop_back(list);
	} else if(index == 0) {
		pop_front(list);
	} else {
		t_node *tmp = getElem(list, index);
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		delete tmp;
		list->size--;
	}
}

void push_after(t_dbllist *list, const std::string &elem, const std::string &data) {
	t_node *temp = list->head;
	int i = 0;
	if (list->size == 0)
	{
		push_back(list, data);
		return;
	}
	while (temp && i < list->size)
	{
		if (elem == temp->data)
		{
			if (i + 1 <  list->size)
				insert(list, i + 1, data);
			else
				push_back(list, data);
			return;
		}
		temp = temp->next;
		i++;
	}
}

void push_before(t_dbllist *list, const std::string &elem, const std::string &data) {
	t_node *temp = list->head;
	int i = 0;
	if (list->size == 0)
	{
		push_back(list, data);
		return;
	}
	while (temp && i < list->size)
	{
		if (elem == temp->data)
		{
			if (i - 1 > 0)
				insert(list, i, data);
			else
				push_front(list, data);
			return;
		}
		temp = temp->next;
		i++;
	}
}

void	deleteElem(t_dbllist *list, const std::string &elem)
{
	t_node *temp = list->head;
	int i = 0;
	while (temp)
	{
		if (temp->data == elem)
		{
			deleteAt(list, i);
			return;
		}
		temp = temp->next;
		i++;
	}
}


t_node *iterator_list(t_node *node)
{
	if (node)
		return (node->next);
	return nullptr;
}
t_node *reverse_iterator_list(t_node *node)
{
	if (node)
		return (node->prev);
	return nullptr;
}


void printList(t_node *head, t_node *(iter)(t_node*), int size)
{
	if (!head)
		return;
	int i = 0;
	while (head && i < size) {
		std::cout << head->data << ' ';
		head = iter(head);
		i++;
	}
	std::cout << '\n';
}


t_node	*getElem(t_dbllist *list, t_node *node, const std::string &elem, t_node*(iter)(t_node *))
{
	if (!list || !node)
		return nullptr;
	int i = 0;
	while (node && i < list->size) {
		if (node->data == elem)
		{
			std::cout << "Iter count = " << i << std::endl;
			return (node);
		}
		node = iter(node);
		i++;
	}
	return nullptr;
//	std::cout << '\n';
}
