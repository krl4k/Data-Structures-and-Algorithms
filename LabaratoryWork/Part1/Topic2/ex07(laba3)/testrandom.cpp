#include <iostream>
#include <string>
#include <cstdlib>

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

int main()
{
//	init_random();
//
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("num == %d\n", get_random_int(1, 3));
//	}
	char c;

	char str[128];
	int c_count = 0;
//	c = getchar();
	printf("enter :");
	while (1)
	{
		c = getchar();
//		gets(str);
//		if (!str)
//			return 1;
//		if (strlen(str) == 1)
		{
//			c=str[0];
			if (c == '\n')
			{
				c_count++;
				if (c_count == 2)
				{
					printf("enter!\n");
					break;
				}
			}
			else
			{
				if (c == 'q')
				{
					printf("q exit\n");
					break;
				}
				c_count--;
			}

		}

	}

}