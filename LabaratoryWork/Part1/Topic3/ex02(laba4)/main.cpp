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
	std::cout << "|Exit       		:  4|" << std::endl;

//	std::cout << "|PushBefore 	:  3|" << std::endl;
//	std::cout << "|PushAfter  	:  4|" << std::endl;
//	std::cout << "|Pop        	:  5|" << std::endl;
//	std::cout << "|PopBack    	:  6|" << std::endl;
//	std::cout << "|PopFront   	:  7|" << std::endl;
//	std::cout << "|PopBefore  	:  8|" << std::endl;
//	std::cout << "|PopAfter   	:  9|" << std::endl;
//	std::cout << "|Print List 	: 10|" << std::endl;
//	std::cout << "|Exit       	: 11|" << std::endl;
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

int main(void)
{
	t_static_list *list;
	init(list);
	std::cout << "This works for 99.9999999999999999999999999999999999999999999990% ~ 100%" << std::endl;
	int op_num;
	char *num;
	int n;
	while (1)
	{
		op_num = menu();
		switch (op_num)
		{
			case (1):
				std::cout << "Enter elem to add: ";
				if(!(num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				n = get_int_number(num);
				free(num);
				//add push function
				push_sort(list, n);
				break;
			case 2:
				std::cout << "Enter elem to delete: ";
				if(!(num = get_s_number()))
				{
					std::cout << "Bad input" << std::endl;
					break;
				}
				n = get_int_number(num);
                free(num);
                pop_elem(list, n);
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