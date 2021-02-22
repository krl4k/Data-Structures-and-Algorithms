#include "static_list.h"

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


/*!
 *
 * @return
 * @warning free str after using!!
 */
char *get_s_number()
{
	std::string s;
	std::cin >> s;
	const char *num = s.c_str();
	if(is_valid_input(num))
	{
        return strdup(num);;
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
	std::cout << "|Push  			:  1|" << std::endl;
	std::cout << "|Pop  			:  2|" << std::endl;
	std::cout << "|Print List 		:  3|" << std::endl;
	std::cout << "|Get elem 		:  4|" << std::endl;
	std::cout << "|Exit       		:  5|" << std::endl;
	std::cout << "|Enter a 	:  ";
	std::cin >> str;
	std::cout << "|--------------------|" << std::endl;

	if(str.length() > 1)
		return 0;
	const char *num = str.c_str();
	if(is_valid_input(num))
		return atoi(num);
	return 0;
}


#if INT == 1

int push_menu()
{
	std::cout << "----------------------" << std::endl;
	std::cout << "|PushBefore 	:  1|" << std::endl;
	std::cout << "|PushAfter  	:  2|" << std::endl;
	std::cout << "|PushBack  	:  3|" << std::endl;
	std::cout << "|PushFront  	:  4|" << std::endl;
	std::cout << "|Push(sort)  	:  5|" << std::endl;
	std::cout << "|Enter a 	:  ";
	std::string str;
	std::cin >> str;
	std::cout << "----------------------" << std::endl;
	if(str.length() > 1)
		return 0;
	const char *num = str.c_str();
	if(is_valid_input(num))
		return atoi(num);
	return 0;
}

int 				push(t_static_list *list)
{
	int op;
	char *s_num;
	int i_num1;
	int i_num2;

	while (1)
	{
		op = push_menu();
		switch (op)
		{
			case 1:
				std::cout << "Enter the element BEFORE which to push : " << std::endl;
				if(!(s_num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				i_num1 = get_int_number(s_num);
				free(s_num);
				std::cout << "Enter the element to push: ";
				if(!(s_num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				i_num2 = get_int_number(s_num);
				free(s_num);
				push_before(list, i_num1, i_num2);
				return (0);
			case 2:
				std::cout << "Enter the element AFTER which to push" << std::endl;
				if(!(s_num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				i_num1 = get_int_number(s_num);
				free(s_num);
				std::cout << "Enter the element to push: ";
				if(!(s_num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				i_num2 = get_int_number(s_num);
				free(s_num);
				push_after(list, i_num1, i_num2);
				return (0);
			case 3:
				std::cout << "Enter the element to push back: ";
				if(!(s_num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				i_num1 = get_int_number(s_num);
				free(s_num);
				push_back(list, i_num1);
				return (0);
			case 4:
				std::cout << "Enter the element to push front: ";
				if(!(s_num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				i_num1 = get_int_number(s_num);
				free(s_num);
				push_front(list, i_num1);
				return (0);
			case 5:
				std::cout << "Enter the element to push: ";
				if(!(s_num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				i_num1 = get_int_number(s_num);
				free(s_num);
				push_sort(list, i_num1);
				return (0);
			default:
				std::cout << "Try again!" << std::endl;
		}
	}
	return (0);
}

int pop_menu()
{
	std::cout << "----------------------" << std::endl;
	std::cout << "|PopBefore 	:  1|" << std::endl;
	std::cout << "|PopAfter  	:  2|" << std::endl;
	std::cout << "|PopBack  	:  3|" << std::endl;
	std::cout << "|PopFront  	:  4|" << std::endl;
	std::cout << "|Pop elem  	:  5|" << std::endl;
	std::cout << "|Enter a 	:  ";
	std::string str;
	std::cin >> str;
	std::cout << "----------------------" << std::endl;
	if(str.length() > 1)
		return 0;
	const char *num = str.c_str();
	if(is_valid_input(num))
		return atoi(num);
	return 0;
}

int	pop(t_static_list *list)
{
	int op;
	char *s_num;
	int i_num1;
	int i_num2;

	while (1)
	{
		op = pop_menu();
		switch (op)
		{
			case 1:
				std::cout << "Enter the element BEFORE pop : " << std::endl;
				if(!(s_num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				i_num1 = get_int_number(s_num);
				free(s_num);
				pop_before(list, i_num1);
				return (0);
			case 2:
				std::cout << "Enter the element AFTER pop" << std::endl;
				if(!(s_num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				i_num1 = get_int_number(s_num);
				free(s_num);
				pop_after(list, i_num1);
				return (0);
			case 3:
				pop_back(list);
				return (0);
			case 4:
				pop_front(list);
				return (0);
			case 5:
				std::cout << "Enter the element to pop: ";
				if(!(s_num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				i_num1 = get_int_number(s_num);
				free(s_num);
				pop_elem(list, i_num1);
				return (0);
			default:
				std::cout << "Try again!" << std::endl;
		}
	}
	return (0);
}

int main(void)
{
	t_static_list *list;
	init(list);
	std::cout << "This works for 99.9999999999999999999999999999999999999999999990% ~ 100%" << std::endl;
	int op_num;
	char *num;
	int n;
	int index = 0;
	char *s_num;
	int i_num1;
	while (1)
	{
		op_num = menu();
		switch (op_num)
		{
			case (1):
				std::cout << "Enter the element to push: ";
				if(!(s_num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				i_num1 = get_int_number(s_num);
				free(s_num);
				push_sort(list, i_num1);
//				push(list);
				break;
			case 2:
//				pop(list);
				std::cout << "Enter the element to pop: ";
				if(!(s_num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				i_num1 = get_int_number(s_num);
				free(s_num);
				pop_elem(list, i_num1);
				break;
			case 3:
				print_static_list(list);
				break;
			case 4:
				std::cout << "Enter an element for find its index : " << std::endl;
				if(!(num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				n = get_int_number(num);
				free(num);
//				printf("n ===  %d\n",n);
				if ((index = get_index(list, n)) != -1)
					std::cout << "Elem " << n << " has index " << index << std::endl;
				else
					std::cout << "Elem not found!" << std::endl;
				break;
			case 5:
				clear(list);
				std::cout << "Clear List!" << std::endl;
				return (0);
			default:
				std::cout << "Try again!" << std::endl;
		}
	}
}

#else

int main(void)
{
    t_static_list *list;
    init(list);
    std::cout << "This works for 99.9999999999999999999999999999999999999999999990% ~ 100%" << std::endl;
    int op_num;
    std::string string;
    while (1)
    {
        op_num = menu();
        switch (op_num)
        {
            case (1):
                std::cout << "Enter elem to add: ";
                std::cin >> string;
                push_sort(list, string);
                break;
            case 2:
                std::cout << "Enter elem to delete: ";
                std::cin >> string;
                pop_elem(list, string);
                break;
            case 3:
                print_static_list(list);
                break;
            case 4:
                clear(list);
                std::cout << "Clear List!" << std::endl;
                return (0);
            default:
                std::cout << "Try again!" << std::endl;
        }
    }
}

#endif