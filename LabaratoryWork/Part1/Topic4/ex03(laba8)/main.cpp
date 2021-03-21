// CLion
// Created by Foster Grisella on 3/21/21 15:23.
//
#include "list_of_lists.h"
//
//int main()
//{
//	t_list_of_lists *listOfLists = nullptr;
//	init_list_of_lists(listOfLists);
//
//	for (int i = 0; i < 3; ++i) {
//		push_back_list_of_lists(listOfLists);
//	}
////	exit(0);
//	t_node_list_of_lists *temp = listOfLists->lists_head;
//	for (int i = 0; i < 5; ++i) {
//		push_back(temp->head, new_node("lol"));
//	}
//	temp = temp->next;
//	for (int i = 0; i < 7; ++i) {
//		push_back(temp->head, new_node("haha"));
//	}
//	temp = temp->next;
//	for (int i = 0; i < 3; ++i) {
//		push_back(temp->head, new_node("puet"));
//	}
//	printList_of_list(listOfLists);
//	pop_back_list_of_lists(listOfLists);
//	pop_back_list_of_lists(listOfLists);
//	pop_back_list_of_lists(listOfLists);
//	clear_list_of_lists(listOfLists);
//}
//

int is_valid_input(const char *s)
{
	int i;

	i = 0;
	while (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if(!isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

char *get_s_number()
{
	std::string s;
	std::cin >> s;
	const char *num = s.c_str();
	if(is_valid_input(num))
	{
		char *n = strdup(num);
		return n;
	}
	else
		return nullptr;
}

int get_int_number(char *num)
{
	int n = atoi(num);
	return (n);
}


int menu()
{
	std::string str;
	std::cout << "----------------------" << std::endl;
	std::cout << "|Push node_list to Lists      :  1|" << std::endl;
	std::cout << "|Push Node to List of List    :  2|" << std::endl;
	std::cout << "|Print                        :  3|" << std::endl;
	std::cout << "|Pop Node_list in List of List:  4|" << std::endl;
	std::cout << "|Pop Node in List of List     :  5|" << std::endl;
	std::cout << "|Get elem                     :  6|" << std::endl;
	std::cout << "|Exit                         :  7|" << std::endl;
	std::cout << "|Enter a 	:  ";
	std::cin >> str;
	std::cout << "|--------------------|" << std::endl;

	if(str.length() > 1)
		return 0;
	const char *num = str.c_str();
	if(is_valid_input(num))
		return std::atoi(num);
	return 0;
}

int main(void)
{
	t_list_of_lists *listOfLists = nullptr;
	init_list_of_lists(listOfLists);
	std::cout << "This works for 99.9999999999999999999999999999999999999999999990% ~ 100%" << std::endl;
	int op_num;
	std::string str;
//	char *num;
//	int n;
//	int index;
	std::string elem;
	int index;
	t_node *node_elem = nullptr;
	std::string data;
	while (true)
	{
		op_num = menu();
		switch (op_num)
		{
			case 1:
				push_back_list_of_lists(listOfLists);
				std::cout << "Node list created!" << std::endl;
				break;
			case 2:
				std::cout << "Enter index of list of Lists: " << std::endl;
				std::cin >> index;
				std::cout << "Enter elem to push: " << std::endl;
				std::cin >> data;
				push_back_to_list(listOfLists, index, data);
				break;
			case 3:
				std::cout << "--------List-info)---------------"<< std::endl;
				printList_of_list(listOfLists);
				std::cout << "--------------------------------"<< std::endl;
				break;
			case 4:
				pop_back_list_of_lists(listOfLists);
				break;
			case 5:
				std::cout << "Enter index of list of Lists: " << std::endl;
				std::cin >> index;
				pop_back_in_list(listOfLists, index);
				break;
			case 6:
				std::cout << "dont work" << std::endl;
				std::cout << "Enter an element for find : " << std::endl;
				std::cin >> elem;
				node_elem = getElem_lists(listOfLists, elem);
				if (!node_elem)
					std::cout << "Elem not found" << std::endl;
				else
					std::cout << "elem found! data = " << node_elem->data << std::endl;
				break;
			case 7:
				clear_list_of_lists(listOfLists);
				std::cout << "Clear List!" << std::endl;
				return (0);
			default:
				std::cout << "Try again!" << std::endl;
		}
	}
}