#include "bi_list.h"

void init(t_list *&list)
{
	list = new t_list;
	list->head = new t_node;
	list->head->data = nullptr;
	list->head->next = nullptr;
	list->head = ;
	list->tail = nullptr;
	list->size = 0;
}
