#include "../ex06/dynamic_queue.h"
#include <iostream>
#include <string>
#include <cstdlib>


int is_valid_input(const char *s)
{
	int i;

	i = 0;
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
		return (char *) num;
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
	std::cout << "|Add Elem in Queue: 1|" << std::endl;
	std::cout << "|Pop Elem in Queue: 2|" << std::endl;
	std::cout << "|Print Queue:       3|" << std::endl;
	std::cout << "|Empty Check Queue: 4|" << std::endl;
	std::cout << "|Exit:              5|" << std::endl;
	std::cout << "|Enter a number: ";
	std::cin >> str;
	std::cout << "|--------------------|" << std::endl;

	if(str.length() > 1)
		return 0;
	const char *num = str.c_str();
	if(is_valid_input(num))
		return atoi(num);
	return 0;
}

void init_random()
{
	srand(time(NULL));
	std::cout << "Random init" << std::endl;
}


//бесконечный уикл на минутуб после исполнения вывести очередь
// спросить стоит ли щаврешить или продолжить
// разобрать тайм  и рандом!!

int main(void)
{
	std::cout << "This works for 99.9999999999999999999999999999999999999999999990% ~ 100%" << std::endl;
	int op_num;
	char *num;
	int n;
	t_queue *queue = nullptr;
	init(queue);
	init_random();
	time_t pref_time_start = time(0);
	while (1)
	{
		op_num = menu();
		time_t pref_time_finish = time(0);
		/*check time*/
		if (pref_time_finish - pref_time_start > 5)
			break;
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
				push(queue, n);
				break;
			case 2:
				if (!isEmpty(queue))
					pop(queue);
				break;
			case 3:
				printQueue(queue);
				break;
			case 4:
				if(isEmpty(queue))
					std::cout << "Queue is empty!" << std::endl;
				else
					std::cout << "Queue not empty!" << std::endl;
				break;
			case 5:
				deleteQueue(queue);
				std::cout << "Clear Stack!" << std::endl;
				return (0);
			default:
				std::cout << "Try again!" << std::endl;
		}
	}
}
