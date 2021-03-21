// CLion
// Created by Foster Grisella on 3/21/21 11:05.
//

#include "bi_list.h"

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
	std::cout << "|Push Before      :  1|" << std::endl;
	std::cout << "|Push After       :  2|" << std::endl;
	std::cout << "|Print            :  3|" << std::endl;
	std::cout << "|Reverse Print    :  4|" << std::endl;
	std::cout << "|Get elem         :  5|" << std::endl;
	std::cout << "|Get elem(reverse):  6|" << std::endl;
	std::cout << "|Delete Elem      :  7|" << std::endl;
	std::cout << "|Exit             :  8|" << std::endl;
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
	t_dbllist *list = nullptr;
	init(list);
	std::cout << "This works for 99.9999999999999999999999999999999999999999999990% ~ 100%" << std::endl;
	int op_num;
	std::string str;
//	char *num;
//	int n;
//	int index;
	std::string elem;
	std::string data;
	while (true)
	{
		op_num = menu();
		switch (op_num)
		{
			case 1:
				std::cout << "Enter elem before push: " << std::endl;
				std::cin >> elem;
				std::cout << "Enter data for elem: " << std::endl;
				std::cin >> data;
				push_before(list, elem, data);
				break;
			case 2:
				std::cout << "Enter elem after push: " << std::endl;
				std::cin >> elem;
				std::cout << "Enter data for elem: " << std::endl;
				std::cin >> data;
				push_after(list, elem, data);
				break;
			case 3:
				std::cout << "--------List-info)---------------"<< std::endl;
				printList(list->head, iterator_list, list->size);
				std::cout << "--------------------------------"<< std::endl;
				break;
			case 4:
				std::cout << "---------List-info(reverse)-------------"<< std::endl;
				printList(list->tail, reverse_iterator_list, list->size);
				std::cout << "--------------------------------"<< std::endl;
				break;
			case 5:
				std::cout << "Enter an element for find : " << std::endl;
				std::cin >> elem;
				if (getElem(list, list->head, elem, iterator_list) != nullptr);
				else
					std::cout << "Elem not found!" << std::endl;
				break;
			case 6:
				std::cout << "Enter an element for find : " << std::endl;
				std::cin >> elem;
				if (getElem(list, list->tail, elem, reverse_iterator_list) != nullptr);
				else
					std::cout << "Elem not found!" << std::endl;
				break;
			case 7:
				std::cout << "Enter elem to delete: " << std::endl;
				std::cin >> elem;
				deleteElem(list, elem);
				break;
			case 8:
				clear(list);
				std::cout << "Clear List!" << std::endl;
				return (0);
			default:
				std::cout << "Try again!" << std::endl;
		}
	}
}