#include "../ex06/dynamic_queue.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#define TIME 5

/*!
 * Функция srand() устанавливает передаваемое пользователем значение в качестве стартового.
 * функция time(), возвращает в качестве времени общее количество секунд, прошедшее от полуночи 1 января 1970 года.
 */

void init_random()
{
	srand(time(NULL));
	std::cout << "Random init" << std::endl;
}


int get_random_int(int min, int max)
{
	int random = min + rand() % (max + 1 - min);
	return random;
}

int continuation_of_work()
{
	std::cout<< "Сontinue (y/n): ";
	char c;
	int n_count = 0;
	while (1)
	{
		c = getchar();
		if (c == '\n')
		{
			n_count++;
			if (n_count == 2)
				return 1;
		}
		else
		{
			if (c == 'y')
				return 1;
			if (c == 'n')
				return 0;
			if (c == 'q')
				return 0;
			n_count--;
		}
	}
}

void work_proccess(t_queue *&queue)
{
	int op_num;
	int n;
	int elem;
	time_t pref_time_start = time(0);
	while (1)
	{
		time_t pref_time_finish = time(0);
		/*check time (TYIME second)*/
		if (pref_time_finish - pref_time_start > TIME*2)
		{
			std::cout << "Time is over!" << std::endl;
			break;
		}
		op_num = get_random_int(0, 100);
		if (op_num % 2 == 0)
		{
			n = get_random_int(1, 3);
			std::cout << "Added " << n << " elements!" << std::endl;
			for (int i = 0; i < n; ++i)
			{
				elem = get_random_int(65, 90);
				push(queue, elem);
			}
		}
		if (op_num % 2 == 1)
		{
			n = get_random_int(1, 3);
			if (size(queue) < n)
				n = size(queue);
//			std::cout << "Deleted " << n << " elements!" << std::endl;
			for (int i = 0; i < n; ++i)
			{
				if (!isEmpty(queue))
					pop(queue);
				else
				{
					std::cout << "Queue is empty"  << std::endl;
					break;
				}
			}
		}
		printQueue(queue);
		sleep(1);
	}
}

int main(void)
{
	std::cout << "This works for 99.9999999999999999999999999999999999999999999990% ~ 100%" << std::endl;
	init_random();
	t_queue *queue = nullptr;
	init(queue);
	while (1)
	{
		work_proccess(queue);
		if (!continuation_of_work())
		{
			deleteQueue(queue);
			std::cout << "Queue deleted!" << std::endl;
			return (0);
		}
	}
}
