#include "dynamic_list.h"

void init(t_list *&list)
{
	list = new t_list;
	list->head = new t_node;
	list->head->next = nullptr;
	list->size = 0;
}

void			clear(t_list **list)
{
	if (!(*list) || !(*list)->head)
		return;
	t_node *temp = (*list)->head;
	t_node *next;
	while (temp)
	{
		next = temp->next;
		free(temp->data);
		temp->data = nullptr;
		free(temp);
		temp = next;
	}
	free(*list);
	(*list) = nullptr;
}

t_node *new_node(const char *data)
{
	t_node *newElem = new t_node;
	newElem->data = strdup(data);
	newElem->next = nullptr;
	return (newElem);
}

t_node			*last(t_list *list)
{
	t_node *temp = list->head->next;
	if(!temp)
		return (nullptr);
	while (temp->next)
		temp = temp->next;
	return (temp);
}


/*!
 *
 * @param list
 * @param new_node , create node with new_node() func
 */
void			push_front(t_list *list, t_node *new_node)
{
	t_node *new_head;

	if(new_node)
	{
		new_head = new_node;
		if(!(list->head))
			list->head->next = new_head;
		else
		{
			new_head->next = list->head->next;
			list->head->next = new_head;
		}
		list->size++;
	}
}


/*!
 *
 * @param list
 * @param new_node , create node with new_node() func
 */
void push_back(t_list *list, t_node *new_node)
{
	if(list && list->head && new_node)
	{
		if(list->head->next)
			last(list)->next = new_node;
		else
		{
			list->head->next = new_node;
		}
		list->size++;
	}
}

t_node *find_before(t_list *list, const char *elem)
{
	t_node * temp = list->head;
	while (temp->next)
	{
		if (strcmp(temp->next->data, elem) == 0)
			return temp;
		temp=temp->next;
	}
	return (nullptr);
}

t_node *find_after(t_list *list, const char *elem)
{
	t_node * temp = list->head->next;
	while (temp)
	{
		if (strcmp(temp->data, elem) == 0)
			return temp;
		temp = temp->next;
	}
	return (nullptr);
}

void			push_before(t_list *list, const char *elem, t_node *new_node)
{
	if (list && list->head && new_node)
	{
//		if (list->head->next == nullptr)
//			list->head->next = new_node;
//		else
		{
			t_node *temp;
			if (!(temp = find_before(list, elem)))
			{
				free(new_node->data);
				delete new_node;
				return;
			}
			new_node->next = temp->next;
			temp->next = new_node;
		}
		list->size++;
	}
}

void			push_after(t_list *list, const char *elem, t_node *new_node)
{
	if (list && list->head && new_node)
	{
		if (list->head->next == nullptr)
			list->head->next = new_node;
		else
		{
			t_node *temp;
			if (!(temp = find_after(list, elem)))
			{
				free(new_node->data);
				delete new_node;
				return;
			}
			printf("temp = %s\n", temp->data);
			new_node->next = temp->next;
			temp->next = new_node;
		}
		list->size++;
	}
}

t_node *getBeforeLast(t_node *temp)
{
	if(!temp->next || !temp->next->next)
		return nullptr;
	while (temp->next->next)
	{
		temp = temp->next;
	}
	return temp;
}

void            pop_elem(t_list	*list, const char *elem)
{
	if (list && list->head)
	{
		t_node *temp;
		if (!(temp = find_before(list, elem)))
			return;
		else
		{
			t_node *deleted = temp->next;
			temp->next = deleted->next;
			free(deleted->data);
			deleted->data = nullptr;
			delete deleted;
			deleted = nullptr;
		}
		list->size--;
	}
}

void            pop_back(t_list *list)
{
	if (!list || !list->head || !list->head->next)
		return;
	t_node *temp = getBeforeLast(list->head);
	if(temp == nullptr)
	{
		free(list->head->next->data);
		list->head->next->data = nullptr;
		delete list->head->next;
		list->head->next = nullptr;
	}
	else
	{
		free(temp->next->data);
		delete temp->next;
		temp->next = nullptr;
	}
	list->size--;
}
void            pop_front(t_list *list)
{
	if (!list || !list->head || !list->head->next)
		return;
	t_node *tmp = list->head->next;
	list->head->next = list->head->next->next;
	free(tmp->data);
	tmp->data = nullptr;
	delete tmp;
	tmp = nullptr;
}

void            list_print(t_list *list)
{
	if (!list || !list->head || !list->head->next)
		return;

	std::cout << "List size = " << list->size << "\n";
	t_node *temp_node = list->head->next;
	while (temp_node)
	{
		std::cout << temp_node->data << "  ";
		temp_node = temp_node->next;
	}
	std::cout << "\n";
}

int				get_index(t_list *list, const char *elem)
{
	if (!list || !list->head || !list->head->next)
		return -1;
	t_node *temp = list->head->next;
	int i = 0;
	while (temp)
	{
		if (strcmp(temp->data, elem) == 0)
			return i;
		temp = temp->next;
		i++;
	}
	return (-1);
}


void			pop_back_to_stack(t_list *list, t_list *stack)
{
	if (!list || !stack || !list->head || !stack->head)
		return;
	t_node *moving_elem = list->head->next;
	t_node *before_moving = list->head;
	if (!moving_elem)
		return;
	while (moving_elem->next)
	{
		before_moving = moving_elem;
		moving_elem = moving_elem->next;
	}
	before_moving->next = nullptr;

	if (!stack->head->next)
		stack->head->next = moving_elem;
	else
	{
		t_node *temp = stack->head->next;
		stack->head->next = moving_elem;
		moving_elem->next = temp;
	}
	stack->size++;
	list->size--;
}

void			pop_front_to_stack(t_list *list, t_list *stack)
{
	if (!list || !stack || !list->head || !stack->head)
		return;
	t_node *moving_elem = list->head->next;
	t_node *after_moving = moving_elem->next;
	moving_elem->next = nullptr;
	if (!moving_elem)
		return;
	list->head->next = after_moving;
	if (!stack->head->next)
		stack->head->next = moving_elem;
	else
	{
		t_node *temp = stack->head->next;
		stack->head->next = moving_elem;
		moving_elem->next = temp;
	}
	stack->size++;
	list->size--;
}

/*
int main()
{
	t_list *list;
	init(list);

	push_after(list, "2", new_node("st"));


	push_back(list, new_node("1"));
	push_back(list, new_node("2"));
	push_back(list, new_node("3"));
	push_back(list, new_node("4"));
	push_back(list, new_node("5"));
	push_back(list, new_node("6"));
//	push_after(list, "6", new_node("lol"));
//	push_after(list, "st", new_node("lol"));

	pop_elem(list, "st");
	list_print(list);

//	push_before(list, "2", new_node("kir"));
//	push_before(list, "1", new_node("lol"));
//	push_before(list, "6", new_node("123"));

	list_print(list);
//	while (1);
}*/
