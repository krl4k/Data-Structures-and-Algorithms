#include "LinkedList.h"

void ft_lstadd_back(t_list **lst, t_list *newElem)
{
	if(lst && newElem)
	{
		if(*lst)
			ft_lstlast(*lst)->next = newElem;
		else
			*lst = newElem;
	}
}

void ft_lstadd_front(t_list **lst, t_list *newElem)
{
	t_list *new_head;

	if(newElem)
	{
		new_head = newElem;
		if((!(*lst)))
			*lst = new_head;
		else
		{
			new_head->next = *lst;
			*lst = new_head;
		}
	}
}

void ft_lstclear(t_list **head)
{
	t_list *temp;
	t_list *next;

	temp = *head;
	if(temp)
	{
		while (temp)
		{
			next = temp->next;
			delete temp;
			temp = next;
		}
		*head = nullptr;
	}
}

t_list *ft_lstlast(t_list *temp)
{
	if(!temp)
		return (nullptr);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_list *ft_lstnew(int data)
{
	t_list *newElem = new t_list;

	newElem->data = data;
	newElem->next = nullptr;
	return (newElem);
}

int ft_lstsize(t_list *temp)
{
	int size = 0;

	if(temp)
	{
		while (temp)
		{
			temp = temp->next;
			size++;
		}
	}
	return (size);
}

void ft_lstprint(t_list *lst)
{
	if(!lst)
		return;
	while (lst)
	{
		std::cout << lst->data << " ";
		lst = lst->next;
	}
	std::cout << '\n';
}

t_list *getBeforeLast(t_list *temp)
{
	if(!temp->next || !temp->next->next)
		return nullptr;
	while (temp->next->next)
	{
		temp = temp->next;
	}
	return temp;
}

void ft_lstpopBack(t_list *&head)
{
	if(!head)
		return;
	t_list *temp = getBeforeLast(head);
	if(temp == nullptr)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		delete temp->next;
		temp->next = nullptr;
	}

}

void ft_lstpopFront(t_list *&head)
{
	if(!head)
		return;
	t_list *tmp = head;
	head = head->next;
	delete tmp;
}

void merge(t_list *a, t_list *b, t_list *&list)
{
	if(!a)
	{
		list = b;
		return;
	}
	if(!b)
	{
		list = a;
		return;
	}
	if(a->data < b->data)
	{
		list = a;
		a = a->next;
	}
	else
	{
		list = b;
		b = b->next;
	}
	t_list *head = list;
	while (a && b)
	{
		if(a->data < b->data)
		{
			list->next = a;
			a = a->next;
		}
		else
		{
			list->next = b;
			b = b->next;
		}
		list = list->next;
	}
	if(a)
	{
		while (a)
		{
			list->next = a;
			list = list->next;
			a = a->next;
		}
	}
	if(b)
	{
		while (b)
		{
			list->next = b;
			list = list->next;
			b = b->next;
		}
	}
	list = head;
}

void searchMide(t_list *src, t_list *&left, t_list *&mid)
{
	t_list *fast = nullptr;
	t_list *slow = nullptr;

	if(!src || !src->next)
	{
		left = src;
		mid = nullptr;
		return;
	}
	slow = src;
	fast = src->next;
	while (fast)
	{
		fast = fast->next;
		if(fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	left = src;
	mid = slow->next;
	slow->next = nullptr;
}

void mergeSort(t_list *&head)
{
	t_list *left = nullptr;
	t_list *mid = nullptr;

	if(!head || !head->next)
		return;

	searchMide(head, left, mid);

	mergeSort(left);
	mergeSort(mid);

	merge(left, mid, head);
}