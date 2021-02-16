#include "list.h"

void	init(t_list *&list)
{
    list = new t_list;
    list->node[0].data = "head_node";
    list->node[0].next = 0;
    list->size = 1;
    for (int i = 1; i < SIZE; i++) {
        list->node[i].next = -1;
    }
}

bool	is_empty(t_list *list)
{
    if (!list)
    {
        return false;
    }
    if (list->size == 1)
        return true;
    return false;
}
bool	is_full(t_list *list)
{
    if (!list)
        return false;
    if (list->size == SIZE)
        return true;
    return false;
}

void	clear(t_list *&list)
{
    for (int i = 0; i < list->size; ++i) {
        list->node[i].next = -1;
    }
    delete list;
    list = nullptr;
}

void push_back(t_list *list, std::string string)
{
    if (is_full(list))
    {
        std::cout << "List is full!" << std::endl;
        return;
    }
    if (is_empty(list))
    {
        list->node[0].next = 1;
        list->node[1].data = string;
        list->node[1].next = 2;
        list->size = 2;
        return;
    }
    int i = 1;
    for (; i < list->size; i++) {
        if (list->node[i].next == -1)
            break;
    }
    list->node[list->size].data = string;
    list->node[list->size].next = i+1;
    list->size++;
}

void	print_list(t_list *list)
{
    std::cout << "----------LIST-------" << std::endl;
    if (is_empty(list))
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
//    }
    std::cout << "list = " << list->node[0].data << std::endl;
    std::cout << "list = " << list->node[1].data << std::endl;
    std::cout << "list = " << list->node[2].data << std::endl;
    std::cout << "list = " << list->node[3].data << std::endl;
    std::cout << "list = " << list->node[4].data << std::endl;

    std::cout << "list NEXT = " << list->node[0].next << std::endl;
    std::cout << "list NEXT = " << list->node[1].next << std::endl;
    std::cout << "list NEXT = " << list->node[2].next << std::endl;
    std::cout << "list NEXT = " << list->node[3].next << std::endl;
    std::cout << "list NEXT = " << list->node[4].next << std::endl;

    print_list(list);
}